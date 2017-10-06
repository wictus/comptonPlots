#include <iostream>
#include "spectrum.h"
#include "comptonSpectrum.h"
#include "crystalEnergySpectrum.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TF1.h"
#include <sstream>
#include <vector>


void smearingComparison()
{
  TCanvas* c = new TCanvas();;
  std::vector<TH1F*> histosToPlot;
  for(double i = 0; i < 2.0; i += 0.5)
  {
    c = new TCanvas();
    comptonSpectrum kiko(511, i);
    kiko.setNumberOfEvents(1E8);
    kiko.generateEvents();
    TH1F* histoik = kiko.getHisto();
    histosToPlot.push_back(histoik);
  }
  
  histosToPlot[0]->Draw();
  for( int i = 1; i < histosToPlot.size(); i++)
  {
    histosToPlot[i]->SetLineColor(i+1);
    histosToPlot[i]->Draw("same");
  }
    
  c->SaveAs("smearing.root");
}

void initalEnergyComparison()
{
  TCanvas* c = new TCanvas();;
  std::vector<TH1F*> histosToPlot;
  std::vector<double> energies;
  energies.push_back(340);
  energies.push_back(450);
  energies.push_back(511);
  std::vector<double> angles;
  angles.push_back(60);
  angles.push_back(30);
  angles.push_back(0);
  for(int i = 0; i < energies.size(); i++)
  {
    comptonSpectrum kiko(energies[i], 0);
    kiko.setNumberOfEvents(1E8);
    kiko.generateEvents();
    TH1F* histoik = kiko.getHisto();
    std::stringstream buf;
    buf << energies[i] ;
    buf << + " keV (#theta = ";
    buf << angles[i];
    buf << "^{o})";
    std::string name = "Initial energy " + buf.str()  ;
    histoik->SetName( name.c_str() );
    histoik->SetTitle( name.c_str() );
    histosToPlot.push_back(histoik);
    buf.clear();
  }
  
  histosToPlot[0]->Draw();
  for( int i = 1; i < histosToPlot.size(); i++)
  {
    histosToPlot[i]->SetLineColor(i+1);
    histosToPlot[i]->Draw("same");
  }
    
  c->SaveAs("energies.root");
}

crystalEnergySpectrum produceCrystal(double energy, double photoRatio) {
    crystalEnergySpectrum kiko (energy, 1.4);
    kiko.setNumberOfEvents(1E7);
    kiko.setComptonProbability((6.875E-03)/100.0);
    kiko.setPhotoPeakProbability(3.996E-02/100.0);
    kiko.generateEvents();
    
    return kiko;
}

void energyDepositiedVsScatterAngle()
{
  TCanvas* c = new TCanvas();
  TF1 ePrim ("ePrim", "[0]/(1+[0]/511.0*(1-cos(x*[1])))", 0, M_PI);
  ePrim.SetParameter(0,511.0);
  ePrim.SetParameter(1, M_PI/180);
  TF1* eDepAngle = new TF1("eDepAngle", "ePrim* ePrim * 2 / 511.0 / (1.0 + 2.0*ePrim/511.0)", 0, 180);
  eDepAngle->SetParameter(0,511.0);
  eDepAngle->Draw();
  c->SaveAs("depo.root");
}

int main(int argc, char **argv) {
//  smearingComparison();
//  initalEnergyComparison();
//   energyDepositiedVsScatterAngle();
  crystalEnergySpectrum clean = produceCrystal(511,1);
//   crystalEnergySpectrum scattered = produceCrystal(450);
//  crystalEnergySpectrum scatteredHeavily = produceCrystal(340);
 
 TCanvas* c = new TCanvas();
 clean.plotHisto()->Draw();
//  scattered.plotHisto()->Draw("same");
//  scatteredHeavily.plotHisto()->Draw("same");
    c->SaveAs( "crystals.root");
}




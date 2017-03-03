#include <iostream>
#include "spectrum.h"
#include "energySpectrum.h"
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
    energySpectrum kiko(511, i);
    kiko.setNumberOfEvents(1E8);
    kiko.generateEvents();
    TH1F* histoik = kiko.plotHisto();
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
    energySpectrum kiko(energies[i], 0);
    kiko.setNumberOfEvents(1E8);
    kiko.generateEvents();
    TH1F* histoik = kiko.plotHisto();
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

void crystal() {
    crystalEnergySpectrum kiko(511, 1.4);
    kiko.setNumberOfEvents(1E7);
    kiko.generateEvents();
    TH1F* histoik = kiko.plotHisto();
    TCanvas* c = new TCanvas();
    histoik->Draw();
    
    c->SaveAs( "crystals.root");
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
  energyDepositiedVsScatterAngle();
 
}




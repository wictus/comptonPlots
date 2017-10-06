#include "crystalEnergySpectrum.h"

crystalEnergySpectrum::crystalEnergySpectrum(double initialEnergy, double resolution): comptonSpectrum(initialEnergy, resolution)
{

}

void crystalEnergySpectrum::generateEvents()
{
comptonSpectrum::generateEvents();

int generatedEvents = 0;
TRandom3 generator(0); // automatically computed seed via TUUID object
while(generatedEvents <fEvents)
{
 double T = generator.Gaus(511., fResolution*sqrt(511));
 
 fSimEvents.push_back( T );
 generatedEvents++; 
}

}

TH1F* crystalEnergySpectrum::plotHisto()
{
  TH1F* histo = new TH1F("energyHisto","energyHisto",650,0,651);
  
  for( auto i : fSimEvents )
    histo->Fill(i);
  
  histo->GetXaxis()->SetTitle("Deposited energy");
  histo->GetYaxis()->SetTitle("Counts");
  
  return histo;
}



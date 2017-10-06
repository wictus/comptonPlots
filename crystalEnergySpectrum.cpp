#include "crystalEnergySpectrum.h"

crystalEnergySpectrum::crystalEnergySpectrum(double initialEnergy, double resolution):
spectrum(initialEnergy,resolution),
compton(initialEnergy,resolution),
photoPeak("energyHisto","energyHisto",651,-0.5,650.5)
{
  photoPeak.GetXaxis()->SetTitle("Deposited energy [keV]");
  photoPeak.GetYaxis()->SetTitle("Counts");
}

void crystalEnergySpectrum::generateEvents()
{


  if(fEvents == 0)
  {
     std::cout << "Set number of events to simulate\n";
     std::exit(5);
  }
  compton.setNumberOfEvents(fEvents);
  compton.generateEvents();

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
  TString title = "crystalHisto";
  title+= fInitialEnergy;
  title+= "keV";
  TH1F* histo = new TH1F(title,title,650,0,651);
  
  for( auto i : fSimEvents )
    photoPeak.Fill(i);
  
  photoPeak.Scale(photoPeakProbability/comptonProbability);
  histo = compton.getHisto();
  histo->Add(&photoPeak);
  
  return histo;
}

void crystalEnergySpectrum::setComptonProbability(const double prob)
{
  comptonProbability = prob;
}

void crystalEnergySpectrum::setPhotoPeakProbability(const double prob)
{
  photoPeakProbability = prob;
}


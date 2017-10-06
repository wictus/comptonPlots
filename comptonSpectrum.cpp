#include "comptonSpectrum.h"

comptonSpectrum::comptonSpectrum(double initialEnergy, double resolution):
spectrum(initialEnergy, resolution)
{
  fCompton = TH1F("comptonHisto","comptonHisto",651,-0.5,650.5);
  fCompton.GetXaxis()->SetTitle("Deposited energy [keV]");
  fCompton.GetYaxis()->SetTitle("Counts");
}

void comptonSpectrum::generateEvents()
{
  
  if(fEvents == 0)
  {
     std::cout << "Set number of events to simulate\n";
     std::exit(5);
  }
  
  int generatedEvents = 0;
  double R = 2.82E-13; //cm
  double maxT = fInitialEnergy * (2.0 * fInitialEnergy / 511.0 ) / (1.0 + 2.0 * fInitialEnergy / 511.0 );
  TRandom3 generator(0); // automatically computed seed via TUUID object
  
  while( generatedEvents < fEvents )
  {
      double T = generator.Rndm() * maxT;
      double genCrossSection = generator.Rndm()*4.0;
      double P = (fInitialEnergy - T) / fInitialEnergy;
      double cosine = 511.0 / fInitialEnergy +1.0 - 511.0/(fInitialEnergy - T);
      double realCrossSection = M_PI * pow(R,2.0) * pow(P,2) *( P + 1.0/P -1.0 + pow(cosine,2.0)  ) * 511.0 / pow(fInitialEnergy - T, 2.0) *1E27;
      
      if( generatedEvents % 1000000 == 0 )
	std::cout << "Progress of MC: " << (double)generatedEvents/(double)fEvents * 100.0 << std::endl;
      
      if( genCrossSection < realCrossSection )
      {
	double smearing = generator.Gaus(0., 1.0);
	smearing *= fResolution * sqrt(T);
	fSimEvents.push_back( T + smearing );
	generatedEvents++;
      }
  }

  std::cout << "Generated " << generatedEvents << " events " << std::endl;
  if( fCompton.GetEntries() == 0 )
  {
    std::cout << "Empty compton histogram, filling it with generated entries\n";
    fillSpectrum();
  }
}

void comptonSpectrum::fillSpectrum()
{
  for(auto i: fSimEvents)
    fCompton.Fill(i);
}


TH1F* comptonSpectrum::getHisto()
{
  return &fCompton;
}

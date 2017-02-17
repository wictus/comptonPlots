#ifndef ENERGY_SPECTRUM
#define ENERGY_SPECTRUM

#include "comptonSpectrum.h"
#include "TRandom3.h"
#include <math.h>
#include <vector>
#include "TH1F.h"
#include <iostream>

class energySpectrum: public comptonSpectrum
{
public:
  energySpectrum(double initialEnergy, double resolution);
  TH1F* plotHisto();
  void generateEvents();
private:
  
  std::vector<double> fSimEvents;
};

#endif //ENERGY_SPECTRUM
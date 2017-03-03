#ifndef ENERGY_SPECTRUM
#define ENERGY_SPECTRUM

#include "spectrum.h"
#include "TRandom3.h"
#include <math.h>
#include <vector>
#include "TH1F.h"
#include <iostream>

class energySpectrum: public spectrum
{
public:
  energySpectrum(double initialEnergy, double resolution);
  TH1F* plotHisto();
  void generateEvents();
protected:
  
  std::vector<double> fSimEvents;
};

#endif //ENERGY_SPECTRUM
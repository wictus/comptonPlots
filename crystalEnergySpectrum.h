#ifndef CRYSTALENERGYSPECTRUM
#define CRYSTALENERGYSPECTRUM


#include "energySpectrum.h"
#include "TRandom3.h"
#include "math.h"

class crystalEnergySpectrum: public energySpectrum
{
public:
  crystalEnergySpectrum(double initialEnergy, double resolution);
  void generateEvents();
  TH1F* plotHisto();
  
};

#endif //CRYSTALENERGYSPECTRUM


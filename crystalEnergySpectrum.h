#ifndef CRYSTALENERGYSPECTRUM
#define CRYSTALENERGYSPECTRUM


#include "spectrum.h"
#include "comptonSpectrum.h"
#include "TRandom3.h"
#include "math.h"

class crystalEnergySpectrum: public spectrum
{
public:
  crystalEnergySpectrum(double initialEnergy, double resolution);
  void generateEvents();
  TH1F* plotHisto();
protected:
  comptonSpectrum compton;
  TH1F photoPeak;
};

#endif //CRYSTALENERGYSPECTRUM


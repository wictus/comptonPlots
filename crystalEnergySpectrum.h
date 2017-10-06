#ifndef CRYSTALENERGYSPECTRUM
#define CRYSTALENERGYSPECTRUM


#include "comptonSpectrum.h"
#include "TRandom3.h"
#include "math.h"

class crystalEnergySpectrum: public comptonSpectrum
{
public:
  crystalEnergySpectrum(double initialEnergy, double resolution);
  void generateEvents();
  TH1F* plotHisto();
protected:
  TH1F compton;
  TH1F photoPeak;
};

#endif //CRYSTALENERGYSPECTRUM


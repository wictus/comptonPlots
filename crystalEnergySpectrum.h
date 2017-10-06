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
  void setPhotoPeakProbability(const double prob);
  void setComptonProbability(const double prob);
protected:
  comptonSpectrum compton;
  TH1F photoPeak;
  double photoPeakProbability = 1, comptonProbability = 1;
  
};

#endif //CRYSTALENERGYSPECTRUM


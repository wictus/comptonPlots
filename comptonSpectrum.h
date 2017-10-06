#ifndef COMPTON_SPECTRUM
#define COMPTON_SPECTRUM

#include "spectrum.h"
#include "TRandom3.h"
#include <math.h>
#include <vector>
#include "TH1F.h"
#include <iostream>

class comptonSpectrum: public spectrum
{
public:
  comptonSpectrum(double initialEnergy, double resolution);
  TH1F* getHisto();
  void generateEvents();
  
protected:
  void fillSpectrum();
  TH1F fCompton;
};

#endif //COMPTON_SPECTRUM
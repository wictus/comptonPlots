#ifndef COMPTONSPECTRUM
#define COMPTONSPECTRUM

#include "TH1F.h"

class comptonSpectrum
{
public:
  comptonSpectrum(double initialEnergy, double resolution);
  void setNumberOfEvents(const int events);
  virtual TH1F* plotHisto();
  virtual void generateEvents();
protected:
  
  double fInitialEnergy;
  double fResolution;
  int fEvents;
};

#endif //COMPTONSPECTRUM
#ifndef COMPTONSPECTRUM
#define COMPTONSPECTRUM

#include "TH1F.h"

class spectrum
{
public:
  spectrum(double initialEnergy, double resolution);
  void setNumberOfEvents(const int events);
  virtual TH1F* getHisto();
  virtual void generateEvents();
protected:
  double fInitialEnergy;
  double fResolution;
  int fEvents;
  std::vector<double> fSimEvents;
};

#endif //COMPTONSPECTRUM
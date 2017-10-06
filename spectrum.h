#ifndef COMPTONSPECTRUM
#define COMPTONSPECTRUM

#include "TH1F.h"

class spectrum
{
public:
  spectrum(double initialEnergy = 0, double resolution = 0);
  void setNumberOfEvents(const int events);
  virtual TH1F* getHisto();
  virtual void generateEvents();
protected:
  double fInitialEnergy = 0;
  double fResolution = 0;
  int fEvents = 0;
  std::vector<double> fSimEvents;
};

#endif //COMPTONSPECTRUM
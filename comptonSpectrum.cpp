#include "comptonSpectrum.h"
#include <boost/concept_check.hpp>

comptonSpectrum::comptonSpectrum(double initialEnergy, double resolution):
fInitialEnergy(initialEnergy), fResolution(resolution)
{

}

void comptonSpectrum::setNumberOfEvents(const int events)
{
  fEvents = events;
}

void comptonSpectrum::generateEvents()
{

}

TH1F* comptonSpectrum::plotHisto()
{
  return nullptr;
}



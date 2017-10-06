#include "spectrum.h"
#include <boost/concept_check.hpp>

spectrum::spectrum(double initialEnergy, double resolution):
fInitialEnergy(initialEnergy), fResolution(resolution)
{

}

void spectrum::setNumberOfEvents(const int events)
{
  fEvents = events;
}

void spectrum::generateEvents()
{

}

TH1F* spectrum::getHisto()
{
  return nullptr;
}



#include <iostream>
#include "comptonSpectrum.h"
#include "energySpectrum.h"
#include "TH1F.h"
#include "TCanvas.h"
#include <sstream>

int main(int argc, char **argv) {
    
  energySpectrum petSpectrumPure(511, 0);
  petSpectrumPure.setNumberOfEvents(1E7);
  petSpectrumPure.generateEvents();
  TH1F* pure511 = petSpectrumPure.plotHisto();   
  TCanvas* c = new TCanvas();
  pure511->Draw();
  c->SaveAs("pure.png");
  delete c;
  for(double i = 0; i < 2.0; i += 0.1)
  {
    c = new TCanvas();
    energySpectrum kiko(511, i);
    kiko.setNumberOfEvents(1E7);
    kiko.generateEvents();
    TH1F* histoik = kiko.plotHisto();
    histoik->Draw();
    std::stringstream lako;
    lako << i;
    
    c->SaveAs( (lako.str() + ".png").c_str() );
    lako.clear();
    delete histoik;
    delete c;
  }
  
  
    return 0;
}

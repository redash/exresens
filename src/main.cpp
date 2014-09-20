#include <cstdio>
#include <iostream>
#include "NeutrinoSpectrum.h"
#include "SpectrumPropagator.h"
#include "CrossSection.h"
#include "Detector.h"
#include "EventRate.h"

NeutrinoSpectrum MakeSpectrum(){ 
	return NeutrinoSpectrum();
}

CrossSection MakeCrossSection(){
	return CrossSection();
}

SpectrumPropagator MakeNuPropagator(){
	return SpectrumPropagator();
}

Detector MakeNearDetector(){
	return Detector();
}

Detector MakeFarDetector(){
	return Detector();
}

int main(int argc, char** argv){
	
	std::cout<<"Preparing objects"<<std::endl;
	NeutrinoSpectrum NearSpectrum = MakeSpectrum();
	CrossSection cstables = MakeCrossSection();
	SpectrumPropagator Propagator = MakeNuPropagator();
	
	std::cout<<"Calculating near detector event rate"<<std::endl;
	Detector NearDetector = MakeNearDetector();
	NearDetector.SetCrossSection(cstables);
	EventRate eventRateNear=NearDetector.CalculateRate(NearSpectrum);

	std::cout<<"Calculating far detector event rate"<<std::endl;
	NeutrinoSpectrum FarSpectrum=Propagator.Propagate(NearSpectrum);
	Detector FarDetector = MakeFarDetector();
	FarDetector.SetCrossSection(cstables);
	FarDetector.NormalizeTo(NearDetector);
	EventRate eventRateFar=FarDetector.CalculateRate(FarSpectrum);

	std::cout<<"Starting oscillation analysis... please wait"<<std::endl;


	return 0;
}
#ifndef SPECTRUMPROPAGATOR__H
#define SPECTRUMPROPAGATOR__H value

class NeutrinoSpectrum;

class SpectrumPropagator
{
public:
	SpectrumPropagator();
	~SpectrumPropagator();
	NeutrinoSpectrum Propagate(const NeutrinoSpectrum &);
};

#endif
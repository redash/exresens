#ifndef DETECTOR__H
#define DETECTOR__H value
class EventRate;
class NeutrinoSpectrum;

class Detector
{
public:
	Detector();
	~Detector();
	EventRate CalculateRate(const NeutrinoSpectrum &);
	void SetCrossSection(const CrossSection &);
	void NormalizeTo(const Detector &);
};
#endif
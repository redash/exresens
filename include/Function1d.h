#ifndef FUNCTION1D__H
#define FUNCTION1D__H value

class Function1d
{
public:
	Function1d(double x_min=0, double x_max=0):xMin(x_min),xMax(x_max){};
	~Function1d(){};
	double LowerLimit(){return xMin;}
	double UpperLimit(){return xMax;}
	double LimitsRange(){return xMax-xMin;}
	bool PointInLimits(double x){return (x>=xMin && x<=xMax);}
	double operator ()(double x){return x*x*x;} //FIXME
protected:
	double xMin, xMax;
};
#endif
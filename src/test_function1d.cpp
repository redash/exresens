#include "gtest/gtest.h"

#include "Function1d.h"

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
///------------------tests-------------------------
TEST ( Function1d_Test, DefaultConstructorRange){
	Function1d fun;
	EXPECT_DOUBLE_EQ(fun.LimitsRange(), 0.0);
}

TEST ( Function1d_Test, RandomConstructorRange){
	double X0=fRand(-100,100);
	double X1=fRand(-100,100);
	Function1d fun(X0,X1);
	EXPECT_DOUBLE_EQ(fun.LimitsRange(), X1-X0);
}

TEST ( Function1d_Test, PointInLimits){
	Function1d fun(0,10);
	EXPECT_TRUE(fun.PointInLimits(1));
}

TEST ( Function1d_Test, PointOutLimits){
	Function1d fun(0,10);
	EXPECT_FALSE(fun.PointInLimits(12));
}

TEST ( Function1d_Test, ValueFromPointOutLimits){
	Function1d fun(0,10);
	EXPECT_DOUBLE_EQ(fun(12), 0.0);
}

TEST ( Function1d_Test, NonNegative){
	Function1d fun(-100,100);
	double step=fun.LimitsRange()/10000;
	for(double x=fun.LowerLimit();x<fun.UpperLimit();x+=step){
		ASSERT_GE(fun(x), 0.0);
	}
}

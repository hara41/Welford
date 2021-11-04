#include "welford.hpp"
#include <math.h>

Welford::Welford()
{
	this->init();
}
void Welford::init()
{
	this->M = 0.0;
	this->S = 0.0;
	this->k = 0.0;
	this->oldM = 0.0;
}

void Welford::sample(double x)
{
	k = k+1.0;
	oldM = M;
	M = M+(x-M)/k;
	S = S+(x-M)*(x-oldM);
}

double Welford::stdev()
{
	return sqrt(S/(k-1.0));
}
double Welford::mean()
{
	return M;
}

WelfordI64::WelfordI64()
{
	this->init();
}
void WelfordI64::init()
{
	this->M = 0.0;
	this->S = 0.0;
	this->k = 0;
	this->oldM = 0;
	this->startX = 0;
	this->start_samp = 0;
}

void WelfordI64::sample(long long x)
{
	k++;
	double x2;
	if (start_samp == 0)
	{
		startX = x;
		start_samp = 1;
	}
	x2 =(double)(x- startX);
	
	oldM = M;
	M = M+(x2-M)/k;
	S = S+(x2-M)*(x2-oldM);
}

double WelfordI64::stdev()
{
	return sqrt((double)S/(k-1));
}
long long WelfordI64::mean()
{
	return (M+startX);
}


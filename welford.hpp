#pragma once
//Welford's method of computing variance
class Welford{
private:
	double M;
	double S;
	double oldM;
	double k;
public:
	Welford();
	void init();
	void sample(double x);
	double stdev();
	double mean();
	
};

class WelfordI64{
private:
	int start_samp;
	long long startX;
	double M;
	double S;
	double oldM;
	int k;
public:
	WelfordI64();
	void init();
	void sample(long long x);
	double stdev();
	long long mean();
	
};

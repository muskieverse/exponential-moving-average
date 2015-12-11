#include "exponential_moving_average.h"

// Default constructor with 10 sample window
ExponentialMovingAverage::ExponentialMovingAverage() 
	: average_(0.0)
	, alpha_(2.0 / (10 + 1))
	, sum_(0.0)
	, count_(0)
{
}

// Constructor allows specification of sample window
ExponentialMovingAverage::ExponentialMovingAverage(unsigned n) 
	: average_(0.0)
	, alpha_(2.0 / (n + 1))
	, sum_(0.0)
	, count_(0)
{
}

// Add a new sample and return the average
// For the first few samples use a sum-based method and then
// transition to the exponential method. This reduces the weight
// of the first samples.
double		ExponentialMovingAverage::Add(double value)
{
	if (count_ > 3)
	{
		average_	= (alpha_ * value) + ((1.0 - alpha_) * average_);
	}
	else
	{
		++count_;

		sum_		+= value;
		average_	= sum_ / count_;
	}

	return (average_);
}

#ifndef	__EXPONENTIAL_MOVING_AVERAGE_HPP
#define	__EXPONENTIAL_MOVING_AVERAGE_HPP

//
//	ExponentialMovingAverage
//
//			This class defines an exponential moving average computer.
//

class	ExponentialMovingAverage
{
	public:
									    ExponentialMovingAverage();
		explicit					ExponentialMovingAverage(unsigned n);

		double						Add(double value);
	
		// Properties
	
		double						Value() const						{ return (average_); }

	protected:

	private:

		double						average_;
		double						alpha_;
		double						sum_;
		unsigned					count_;
};


#endif	/* __EXPONENTIAL_MOVING_AVERAGE_HPP	*/

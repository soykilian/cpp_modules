#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int	value;
		static const int frac = 8;
	public:
		//
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &fixed);
		//bc it is an orthodox class
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif

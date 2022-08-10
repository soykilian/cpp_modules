#include <iostream>
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
		Fixed(int const num);
		Fixed(float const num);
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &fixed);
		//bc it is an orthodox class
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void)	const;
};
std::ostream & operator<<(std::ostream &out, const Fixed &fixed);
#endif

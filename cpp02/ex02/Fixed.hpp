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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void)	const;

		bool	operator>(const Fixed &f)const;
		bool	operator>=(const Fixed &f)const;
		bool	operator<=(const Fixed &f)const;
		bool	operator==(const Fixed &f)const;
		bool	operator!=(const Fixed &f)const;
		
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	operator++();
		Fixed	operator--();

		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;
		
		static const Fixed& max(const Fixed &n1, const Fixed &n2);
		static const Fixed& min(const Fixed &n1, const Fixed &n2);
		static Fixed& max(Fixed &n1, Fixed &n2);
		static Fixed& min(Fixed &n1, Fixed &n2);
};
std::ostream & operator<<(std::ostream &out, const Fixed &fixed);
#endif

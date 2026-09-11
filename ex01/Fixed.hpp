#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed{
    private:
        int num_;
        static const int fractionalBits_ = 8;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        Fixed(const int num);
        Fixed(const float num);

        float toFloat(void) const;
        int toInt( void ) const;

        void setRawBits(int const raw);
        int getRawBits(void) const;

};

// !なぜクラスの外なのか？
// !なぜ返り値はstd::ostream?
// !なぜそれらの引数なの？
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
    private:
        int num_;
        static const int fractionalBits_ = 8;//static constって？？

    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        void setRawBits(int const raw);
        int getRawBits(void) const;
};

#endif

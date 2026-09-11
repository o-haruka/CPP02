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

        // こっから追加 ---------------
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        //? 4つのインクリメント/デクリメント（前置インクリメントと後置インクリメント、前置デクリメントと後置デクリメント）演算子。→どう表現するんだ？？
        // *後置には引数にintをいれる (https://ja.cppreference.com/cpp/language/operator_incdec)
        // 戻り値の型について
        //前置（Fixed&）: 値を増やした後の「自分自身」をそのまま使い回すので、参照（&）を返します。
        //後置（Fixed）: 使うべきなのは増える前の「古い値」です。しかし自分自身の値はすでに増やしてしまっているため、増やす前に作っておいた「古い値のコピー（別物）」を返すしかありません。そのため値渡しになります。
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        // min, max 関数[cite: 1]
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

#include "Fixed.hpp"
#include <iostream>
Fixed::Fixed(): num_(0){
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called\n";
    this->num_ = other.getRawBits();
    // this->num = other.num_;
}

//! コピー代入演算子はコンストラクタではなく、「普通のメンバ関数」の特殊なバージョン:C++特有の「演算子オーバーロード」
Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called\n";

    if(this != &other) //!これが必要な理由がちゃんと言えない
        this->num_ = other.getRawBits();
    //! なぜ*thisを返すのか...例)a = b = cのとき
    //! bで受け取らないとa=bができない
    return *this; 
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

void Fixed::setRawBits(int const raw){
    this->num_ = raw;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return this->num_;
}

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// ==========================================
// 1. Orthodox Canonical Form
// ==========================================
Fixed::Fixed() : num_(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called\n";
    this->num_ = other.num_;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->num_ = other.num_;
    return *this; 
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

// ==========================================
// 2. add constructor
// ==========================================
Fixed::Fixed(const int num){
    std::cout << "Int constructor called\n";
    // 整数を左に8ビットシフト（256倍）して保存
    this->num_ = num << fractionalBits_;
}

Fixed::Fixed(const float num){
    std::cout << "Float constructor called\n";
    // 小数はビットシフトできないので、256(1 << 8)を掛けてから roundf で整数に丸める
    //TODO : roundfってどんな関数？？　#include <cmath>必須。
    this->num_ = roundf(num * (1 << fractionalBits_));
}

// ==========================================
// 3. method
// ==========================================
void Fixed::setRawBits(int const raw){
    this->num_ = raw;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return this->num_;
}

// ① 固定小数点数を普通の float に戻す
float Fixed::toFloat(void) const {
    // 保存されている整数を 256.0(浮動小数点数) で割って戻す
    return static_cast<float>(this->num_) 
            / static_cast<float>(1 << fractionalBits_);
}

// ② 固定小数点数を普通の int に戻す
int Fixed::toInt(void) const {
    // 保存されている整数を右に8ビットシフト（256で割る）して戻す
    return this->num_ >> fractionalBits_;
}

// ==========================================
// 4. overload (<<)
// ==========================================
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    // 画面に表示する時は、常にわかりやすい float 形式に変換してから出力する
    os << fixed.toFloat();
    return os;
}

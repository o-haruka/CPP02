#include "Fixed.hpp"
#include <iostream>

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
    this->num_ = num << fractionalBits_;
}

Fixed::Fixed(const float num){
    std::cout << "Float constructor called\n";
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

float Fixed::toFloat(void) const {
    return static_cast<float>(this->num_) 
            / static_cast<float>(1 << fractionalBits_);
}

int Fixed::toInt(void) const {
    return this->num_ >> fractionalBits_;
}

// ==========================================
// 4. overload
// ==========================================
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

//ex02 追加のoverload
//比較演算
bool Fixed::operator>(const Fixed& other) const{
    return this->num_ > other.num_;
}

bool Fixed::operator<(const Fixed& other) const{
    return this->num_ < other.num_;
}

bool Fixed::operator>=(const Fixed& other) const{
    return this->num_ >= other.num_;
}

bool Fixed::operator<=(const Fixed& other) const{
    return this->num_ <= other.num_;
}

bool Fixed::operator==(const Fixed& other) const{
    return this->num_ == other.num_;
}

bool Fixed::operator!=(const Fixed& other) const{
    return this->num_ != other.num_;
}

//四則演算
Fixed Fixed::operator+(const Fixed& other) const{
    Fixed result;
    result.num_ = this->num_ + other.num_;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const{
    Fixed result;
    result.num_ = this->num_ - other.num_;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const{
    return Fixed(this->toFloat() / other.toFloat());
}

// インクリメント / デクリメント
//前置インクリメント
Fixed& Fixed::operator++(){
    this->num_++; // 内部の生データに単純に1を足す
    return *this; // 自分自身の実体（参照）を返す
}

//後置インクリメント
Fixed Fixed::operator++(int){ //後置は引数にint入れる
    Fixed tmp(*this);
    this->num_++;
    return tmp;
}

//前置デクリメント
Fixed& Fixed::operator--(){
    this->num_--;
    return *this;
}

//後置デクリメント
Fixed Fixed::operator--(int){
    Fixed tmp(*this);
    this->num_--;
    return tmp;
}

// min / max
//*静的メンバ関数だけど、staticはつけない。
Fixed& Fixed::min(Fixed& a, Fixed& b){
    if(a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if(a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if(a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if(a > b)
        return a;
    return b;
}

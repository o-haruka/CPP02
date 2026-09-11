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

// ----- comparison operators -----
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

// ----- arithmetic operators -----
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

// ----- increment/decrement -----
Fixed& Fixed::operator++(){
    this->num_++;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed tmp(*this);
    this->num_++;
    return tmp;
}

Fixed& Fixed::operator--(){
    this->num_--;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed tmp(*this);
    this->num_--;
    return tmp;
}

// ----- min / max -----
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

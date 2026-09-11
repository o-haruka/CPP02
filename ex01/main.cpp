#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f ); //末尾のfは
    Fixed const d( b );
    // Fixed( 1234.4321f ) により、一時的な「名無しのオブジェクト」が作られます（Float constructor called）。  その名無しのオブジェクトの中身が、= によってすでに存在している a に上書きコピーされます（Copy assignment operator called）。  
    a = Fixed( 1234.4321f );
    //上書きが終わると、一時的な「名無しのオブジェクト」はもういらないので、すぐに破棄されます（Destructor called）。
    std::cout << "a is " << a << "\n";
    std::cout << "b is " << b << "\n";
    std::cout << "c is " << c << "\n";
    std::cout << "d is " << d << "\n";
    std::cout << "a is " << a.toInt() << " as integer" << "\n";
    std::cout << "b is " << b.toInt() << " as integer" << "\n";
    std::cout << "c is " << c.toInt() << " as integer" << "\n";
    std::cout << "d is " << d.toInt() << " as integer" << "\n";
    return 0;
}

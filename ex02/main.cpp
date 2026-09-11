#include "Fixed.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

int main( void ) {
    std::cout << "==========================================\n";
    std::cout << "1. subject test\n";
    std::cout << "==========================================\n\n";
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "\n\n==========================================\n";
    std::cout << "2. my test\n";
    std::cout << "==========================================\n\n";

    std::cout << CYAN << "\n--- 比較演算子のテスト ---\n" << RESET;
    Fixed c(2);
    Fixed d(4);

    // true / false を文字でわかりやすく出力するためのマクロ
    std::cout << std::boolalpha;
    std::cout << "c = " << c << ", d = " << d << std::endl;

    // ⚠️C++の罠： << と < が混ざるとコンパイルエラーになるので、比較は必ず () で囲むこと！
    std::cout << "c > d : " << (c > d) << "\n";
    std::cout << "c < d : " << (c < d) << "\n";
    std::cout << "c >= d : " << (c >= d) << "\n";
    std::cout << "c <= d : " << (c <= d) << "\n";
    std::cout << "c == d : " << (c == d) << "\n";
    std::cout << "c != d : " << (c != d) << "\n";
    
    std::cout << std::noboolalpha;//1 と 0 の数字表示に戻す

    std::cout << CYAN << "\n--- 四則演算のテスト ---\n" << RESET;
    
    // 小数での計算が正しく（toFloat経由で）処理されるか確認しやすい数値をセット
    Fixed e(10.5f);
    Fixed f(2.0f);

    std::cout << "e = " << e << ", f = " << f << "\n\n";

    // 演算結果はFixedオブジェクトとして返ってくるため、そのまま std::cout に渡せます
    std::cout << "e + f(期待値: 12.5) : " << (e + f) << "\n";
    std::cout << "---\n";
    std::cout << "e - f(期待値: 8.5) : " << (e - f) << "\n";
    std::cout << "---\n";
    std::cout << "e * f(期待値: 21) : " << (e * f) << "\n";
    std::cout << "---\n";
    std::cout << "e / f(期待値: 5.25) : " << (e / f) << "\n";

    std::cout << CYAN << "\n--- インクリメント / デクリメントのテスト ---\n" << RESET;
    
    Fixed g; // デフォルトコンストラクタで 0 init

    std::cout << "初期状態の g : " << g << "\n";
    std::cout << "---\n";

    // 前置：すぐに 1 (イプシロン = 0.00390625) 増えた値が返ってくるはず
    std::cout << "前置インクリメント (++g) : " << ++g << "\n"; 
    std::cout << "---\n";

    // 後置：画面には古い値が出力され、裏でこっそり増えるはず
    std::cout << "後置インクリメント (g++) : " << g++ << "\n"; 
    std::cout << "---\n";

    // 後置の直後に g の中身を確認（ここで増えていることが証明される）
    std::cout << "後置インクリメント後の g : " << g << "\n"; 
    std::cout << "---\n";

    // 前置デクリメント：すぐに減るはず
    std::cout << "前置デクリメント (--g) : " << --g << "\n"; 
    std::cout << "---\n";

    // 後置デクリメント：画面には古い値が出力され、裏でこっそり減るはず
    std::cout << "後置デクリメント (g--) : " << g-- << "\n"; 
    std::cout << "---\n";

    std::cout << "後置デクリメント後の g : " << g << "\n"; 
    std::cout << "\n";

    std::cout << CYAN << "\n--- min / max 関数のテスト ---\n" << RESET;

    // 1. 通常の参照を引数に取るバージョンのテスト
    Fixed h(10.5f);
    Fixed i(20.5f);

    std::cout << "h = " << h << ", i = " << i << "\n\n";

    std::cout << "[ 通常の min / max ]\n";
    std::cout << "min(h, i) : " << Fixed::min(h, i) << "\n"; // 期待値: 10.5
    std::cout << "max(h, i) : " << Fixed::max(h, i) << "\n"; // 期待値: 20.5
    std::cout << "---\n";

    // 2. const 参照を引数に取るバージョンのテスト
    const Fixed j(100.5f);
    const Fixed k(200.5f);

    std::cout << "const j = " << j << ", const k = " << k << "\n\n";

    std::cout << "[ const の min / max ]\n";
    std::cout << "min(j, k) : " << Fixed::min(j, k) << "\n"; // 期待値: 100.5
    std::cout << "max(j, k) : " << Fixed::max(j, k) << "\n"; // 期待値: 200.5
    std::cout << "\n";
    return 0;
}


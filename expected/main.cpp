#include <iostream>
#include <cstdint>
#include <expected>
#include <variant>

struct A {};
struct B {};
struct C {};
struct D {};


// std::expected<uint32_t, std::variant<A,B,C,D>> div(uint32_t x, uint32_t y) {
//     if(y == 0) {
//         return std::unexpected(A);
//     }
//     return x/y;
// }

std::expected<uint32_t, std::string> divide(uint32_t x, uint32_t y) {
    if(y == 0) {
        return std::unexpected("zero division");
    }
    return x/y;
}

void test() {

    std::expected r = divide(10,2);
    if (r) {
        std::cout << "10/2 = " << r.value() << std::endl;
    } else {
        std::cout << "10/2 with error: " << r.error() << std::endl;
    }

    r = divide(10,0);
    if (r) {
        std::cout << "10/0 = " << r.value() << std::endl;
    } else {
        std::cout << "10/0 with error: " << r.error() << std::endl;
    }

}

int main() {
    test();
    return 0;
}





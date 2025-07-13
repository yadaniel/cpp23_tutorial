#include <iostream>
#include <cstdint>
#include <cassert>
#include <variant>

struct A {};
struct B {};
struct C {};
struct D {
    // uint32_t n;
};

using ABCD = std::variant<A, B, C, D>;
using umask = std::variant<uint32_t, uint64_t>;
using numbers = std::variant<uint8_t, uint16_t, uint32_t, uint64_t, double>;

using std::cout, std::endl;

void test1() {
    cout << "test1 {" << endl;
    //
    cout << "sizeof(ABCD) = " << sizeof(ABCD) << endl;
    cout << "sizeof(umask) = " << sizeof(umask) << endl;
    cout << "sizeof(numbers) = " << sizeof(numbers) << endl;
    //
    cout << "test1 }\n" << endl;
}

void test2() {
    cout << "test2 {" << endl;
    //
    numbers n1 { ((uint8_t)1) };
    numbers n2 { ((uint16_t)1) };
    numbers n3 { ((uint32_t)1) };
    numbers n4 { ((uint64_t)1) };
    numbers n5 { ((double)1) };
    // numbers n = n1;
    // numbers n = n2;
    // numbers n = n3;
    // numbers n = n4;
    numbers n = n5;
    if(std::holds_alternative<uint8_t>(n)) {
        cout << " uint8_t " << endl;
    } else if(std::holds_alternative<uint16_t>(n)) {
        cout << " uint16_t " << endl;
    } else if(std::holds_alternative<uint32_t>(n)) {
        cout << " uint32_t " << endl;
    } else if(std::holds_alternative<uint64_t>(n)) {
        cout << " uint64_t " << endl;
    } else if(std::holds_alternative<double>(n)) {
        cout << " double " << endl;
    } else {
        cout << " unexpected " << endl;
        assert(0);
    }
    //
    cout << "test2 }\n" << endl;
}

int main() {
    test1();
    test2();
    return 0;
}


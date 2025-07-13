#include <iostream>
#include <cstdint>
#include <optional>

using std::optional;
using std::cout, std::endl;

optional<double> get_result(int x, int y) {
    if((x == 0) || (y == 0)) {
        return std::nullopt;
    }
    return x + y;
}

// // return type can not be deduced
// optional get_result2(int x, int y) {
//     if((x == 0) || (y == 0)) {
//         return std::nullopt;
//     }
//     return (double) x + y;
// }

void test1() {

    optional<double> c1 = get_result(0, 0);
    optional<double> c2 = get_result(0, 1);
    optional<double> c3 = get_result(1, 0);
    optional<double> c4 = get_result(1, 1);

    optional b1 = get_result(0, 0);
    optional b2 = get_result(0, 1);
    optional b3 = get_result(1, 0);
    optional b4 = get_result(1, 1);

    auto a1 = get_result(0, 0);
    auto a2 = get_result(0, 1);
    auto a3 = get_result(1, 0);
    auto a4 = get_result(1, 1);

    cout << (a1 ? "a1 is not none" : "a1 is none") << endl;
    cout << (a2 ? "a2 is not none" : "a2 is none") << endl;
    cout << (a3 ? "a3 is not none" : "a3 is none") << endl;
    cout << (a4 ? "a4 is not none" : "a4 is none") << endl;

    // if(a1) {
    //     cout << "a1" << endl;
    // } else {
    //     cout << "a1 is none" << endl;
    // }

}

int main() {
    test1();
    return 0;
}


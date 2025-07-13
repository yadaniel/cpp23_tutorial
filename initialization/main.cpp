#include <iostream>
#include <cstdint>

using std::cout, std::endl;

// aggregate
struct Data {
    uint32_t x;
    uint32_t y;
    uint32_t z;
    // Data() = default;    // user declared (not provided) constr => not aggregate
    // Data() = delete;     // user declared (not provided) constr => not aggregate
    uint32_t id = 0;
    uint32_t value {};
};

// not aggregate
struct Data_ {
    uint32_t x;
    uint32_t y;
    uint32_t z;
    Data_() = default;
    uint32_t id = 0;
    uint32_t value {};
};

void show(Data const & d) {
    cout << d.x << "," << d.y << "," << d.z << endl;
}

void show_(Data_ const & d) {
    cout << d.x << "," << d.y << "," << d.z << endl;
}

[[nodiscard]]
consteval int square(int x) {
    return x*x;
}

[[nodiscard]]
int cpp20_feature_use() {
    constexpr int val = square(10);
    return val;
    // return constexpr square(10);
    // return constexpr int square(10);
}

int main() {
    Data d;         // no initialization
    Data d0 {};     // default initialization
    Data d1 {.x = 1};
    Data d2 {.y = 1};
    Data d3 {.z = 1};
    Data d3a = {.z = 1};
    Data d4 (1);    // c++23, parenthesized aggregate initialization
    Data d5 (1,2);
    Data d6 (1,2,3);
    show(d);
    show(d0);
    show(d1);
    show(d2);
    show(d3);
    show(d4);
    show(d5);
    show(d6);

    Data_ d_;
    Data_ d1_ {};   // this works
    // Data_ d2_ {.x = 1};
    show_(d_);
    show_(d1_);

    cout << "Data aggregate = " << std::is_aggregate<Data>::value << endl;
    cout << "Data_ aggregate = " << std::is_aggregate<Data_>::value << endl;

    return 0;
}


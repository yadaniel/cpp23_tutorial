#include <iostream>
#include <cstdint>
#include <memory>

// template<typename T>
// enum class EVALUE_T : T {
//     E_ERROR0 = 0,
//     E_ERROR1 = 1,
//     E_ERROR2 = 2,
//     E_ERROR3 = 3,
//     E_ERROR_0 = 0,
//     E_ERROR_1 = 1,
//     E_ERROR_2 = 2,
//     E_ERROR_3 = 3,
// };

enum class EVALUE : uint8_t {
// enum class EVALUE : uint16_t {
// enum class EVALUE : uint32_t {
// enum class EVALUE : uint64_t {
    E_ERROR0 = 0,
    E_ERROR1 = 1,
    E_ERROR2 = 2,
    E_ERROR3 = 3,
    E_ERROR_0 = 0,
    E_ERROR_1 = 1,
    E_ERROR_2 = 2,
    E_ERROR_3 = 3,
};

uint32_t to_uint32(const EVALUE & self) {
    return uint32_t(self);
}

void test1() {
    using namespace std;

    cout << "test1" << endl;
    //
    cout << (uint32_t) EVALUE::E_ERROR0 << endl;
    cout << (uint32_t) EVALUE::E_ERROR_0 << endl;
    //
    cout << to_uint32(EVALUE::E_ERROR1) << endl;
    cout << to_uint32(EVALUE::E_ERROR_1) << endl;
    //
    cout << "sizeof(EVALUE) = " << sizeof(EVALUE) << endl;
}

class Base {};
class Derived : public Base {};

void test2() {
    std::cout << "test2" << std::endl;

    Derived d;

    uint32_t i = 100;
    std::shared_ptr<uint32_t> pi_shared;
    std::unique_ptr<uint32_t> pi_unique;
    std::weak_ptr<uint32_t> pi_weak;
    //
    std::shared_ptr<uint32_t> pi_shared1 {};
    std::unique_ptr<uint32_t> pi_unique1 {};
    std::weak_ptr<uint32_t> pi_weak1 {};
    //
    std::shared_ptr<uint32_t> pi_shared2 {nullptr};
    std::unique_ptr<uint32_t> pi_unique2 {nullptr};
    // std::weak_ptr<uint32_t> pi_weak2 {nullptr};

    // std::cout << *pi_shared << std::endl;

    // std::observer_ptr<Base> b {&d};

}

class Q {
    public:
        Q() = default;

        Q(std::string const & r) {
            std::cout << r << std::endl;
        }

        ~Q() {}
        double d;
        uint32_t val;
};

class Q1 {
    public:
        Q1() {}

        Q1(std::string const & r) {
            std::cout << r << std::endl;
        }

        ~Q1() {}
        double d;
        uint32_t val;
};

void test3() {
    std::cout << "test3" << std::endl;

    Q qa;
    Q qb("foo");

    Q1 q1a;
    Q1 q1b("bar");

    std::cout << "default " << qa.val << "," << qa.d << std::endl;
    std::cout << "Q() " << q1a.val << "," << q1a.d << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}






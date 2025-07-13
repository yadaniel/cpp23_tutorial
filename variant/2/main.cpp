#include <iostream>
// #include <print>     // GCC14
// #include <format>    // GCC13
#include <cstdint>
#include <variant>

using namespace std;

struct A {};
struct B {};
struct C { uint32_t code = 0; };
struct D { 
    uint32_t code = 0; 
    D(uint32_t code_) : code {code_} {}
    private: D() {} 
    };
// struct D {};

using ABC = std::variant<A,B,C,D>;
// using ABC = std::variant<A,B,C>;
// typedef std::variant<A,B,C> ABC_t;
typedef std::variant<A,B,C,D> ABC_t;

class Enum {
    Enum();
    // Enum() {}
    using ABCD = std::variant<A,B,C,D>;
    ABCD abcd;
    public:

    Enum(A a) : abcd {a} {}
    Enum(B b) : abcd {b} {}
    Enum(C c) : abcd {c} {}
    Enum(D d) : abcd {d} {}

    // operator ABCD() { return abcd; }
    uint32_t index() const { return abcd.index(); }

    enum : uint32_t {
        A_IDX = 0,
        B_IDX = 1,
        C_IDX = 2,
        D_IDX = 3,
    };

    enum struct IDX : uint32_t {
        A = 0,
        B = 1,
        C = 2,
        D = 3,
    };

};

void test5() {
    // Enum e;
    Enum edefault {A{}};
    Enum ea {A{}};
    Enum eb {B{}};
    Enum ec {C{}};
    Enum ed {D{10}};

    Enum e = ea;

    switch(e.index()) {
        case e.A_IDX:
            cout << "A" << endl;
            break;
        case Enum::B_IDX:
            cout << "B" << endl;
            break;
        case Enum::IDX::C:
            cout << "C" << endl;
            break;
        case Enum::IDX::D:
            cout << "D" << endl;
            break;
        default:
            cout << "assert(0)" << endl;
            break;
    }

}

// struct S {
//     int x = 0;
//     int y;
//     S() : x {0}, y {0} {}
//     S(int a, int b) : x {a}, y {b} {}
// };
// void test6() {
//     S s;
//     S s1 {};
//     S s2 {1, 2};
// }

enum : uint8_t {};
enum E : uint8_t {};
enum struct ES : uint8_t {};
enum class EC : uint8_t {};

// dispatcher checks that all variants are covered
// note, additional context must be explicitly passed
struct Dispatcher {
    void operator() (A const & a) { cout << "a" << endl; }
    void operator() (B const & b) { cout << "b" << endl; }
    void operator() (C const & c) { cout << "c" << endl; }
    void operator() (D const & d) { cout << "d" << endl; }
};

void foo(ABC const & abc) {
    std::visit(Dispatcher {}, abc);
}

void bar(ABC_t const & abc) {
    std::visit(Dispatcher {}, abc);
}

// std::visit
void test1() {

    cout << "test1 {" << endl;

    ABC a {A{}};
    ABC b {B{}};
    ABC c {C{}};
    ABC d {D{10}};

    foo(a);
    foo(b);
    foo(c);

    bar(a);
    bar(b);
    bar(c);

    cout << "test1 }\n" << endl;
}

// std::get
void test2() {
    cout << "test2 {" << endl;

    ABC abc;  // which options does it hold
    // ABC abc {};
    // ABC abc {A{}};
    // ABC abc {B{}};
    // ABC abc {C{}};

    try {
        A a = std::get<A>(abc);
        cout << "A" << endl;
    } catch (std::bad_variant_access const & exc) {
        cout << "catch ( bad_variant_access ) : " << exc.what() << endl;
    } catch (...) {
        cout << "catch (...)" << endl;
    }

    cout << "test2 }\n" << endl;

}

// std::get_if
void test3() {
    cout << "test3 {" << endl;

    // ABC abc;  // which options does it hold
    // ABC abc {};
    // ABC abc {A{}};
    // ABC abc {B{}};
    ABC abc {C{}};

    A * a = std::get_if<A>(&abc);
    B * b = std::get_if<B>(&abc);
    C * c = std::get_if<C>(&abc);
    if(a != nullptr) {
        cout << "A" << endl;
    } else if(b != nullptr) {
        cout << "B" << endl;
    } else if(c != nullptr) {
        cout << "C" << endl;
        cout << "C with " << c->code << endl;
    } else {
    }

    cout << "test3 }\n" << endl;

}

// index
void test4() {
    cout << "test4 {" << endl;

    ABC abc;  // which options does it hold
    // ABC abc {};
    // ABC abc {A{}};
    // ABC abc {B{}};
    // ABC abc {C{}};

    switch(abc.index()) {
        case 0: 
            {
                A a = std::get<A>(abc);
                cout << "a" << endl;
            }
            break;
        case 1:
            { 
                B b = std::get<B>(abc); 
                cout << "b" << endl;
            }
            break;
        case 2:
            { 
                C c = std::get<C>(abc); 
                cout << "c" << endl;
            }
            break;
        case 3:
            { 
                D d = std::get<D>(abc); 
                cout << "d" << endl;
            }
            break;
        default:
            cout << "not expected" << endl;
            break;
    }

    cout << "test4 }\n" << endl;

}

int main() {

    cout << "in main" << endl;
    // std::print("in main");
   
    std::string s {"in main"};
    // std::format("{} + {} = {}", 1, 2, 3);

    test1();
    test2();
    test3();
    test4();

    return 0;
}


#include <iostream>
#include <cstdint>
#include <variant>

using namespace std;

struct A {};
struct B {};
struct C {};

using ABC = std::variant<A,B,C>;
typedef std::variant<A,B,C> ABC_t;

struct Dispatcher {
    void operator() (A const & a) { cout << "a" << endl; }
    void operator() (B const & b) { cout << "b" << endl; }
    void operator() (C const & c) { cout << "c" << endl; }
};

void foo(ABC const & abc) {
    std::visit(Dispatcher {}, abc);
}

void bar(ABC_t const & abc) {
    std::visit(Dispatcher {}, abc);
}

void test() {
    ABC a {A{}};
    ABC b {B{}};
    ABC c {C{}};

    foo(a);
    foo(b);
    foo(c);

    bar(a);
    bar(b);
    bar(c);
}


int main() {
    cout << "in main" << endl;
    test();
    return 0;
}


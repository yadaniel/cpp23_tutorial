#include <iostream>
#include <cstdint>

using std::cout, std::endl;

template <typename ... Args>
void print(Args ... args) {
    (cout << ... << args) << '\n' << endl;
}

// framework
template <typename ... Ts> struct type_sequence {};     // sequence of types
template <typename ... Ts> struct head;                 // forward declaration of head
template <typename ... Ts> struct tail;                 // forward declaration of tail
template <typename T, typename ... Ts> struct head<type_sequence<T, Ts ...>>  { using type = T; };  // take first element
template <typename T, typename ... Ts> struct tail<type_sequence<T, Ts ...>>  { using type = type_sequence<Ts...>; };  // take rest of elements
template <typename T> using head_t = typename head<T>::type;    // take first element -> which is type
template <typename T> using tail_t = typename tail<T>::type;    // take rest of elements -> which is type

void test() {
    using ts = type_sequence<uint8_t, uint16_t, uint32_t, uint64_t>;
    using U8 = head_t<ts>;
    using U16 = head_t<tail_t<ts>>;
    using U32 = head_t<tail_t<tail_t<ts>>>;
    using U64 = head_t<tail_t<tail_t<tail_t<ts>>>>;

    U8 u8 {1};
    U16 u16 {2};
    U32 u32 {3};
    U64 u64 {4};

    printf("%d\n", u8);
    printf("%d\n", u16);
    printf("%d\n", u32);
    printf("%ld\n", u64);

    cout << typeid(U8).name() << "," << typeid(uint8_t).name() << endl;
    cout << typeid(U16).name() << "," << typeid(uint16_t).name() << endl;
    cout << typeid(U32).name() << "," << typeid(uint32_t).name() << endl;
    cout << typeid(U64).name() << "," << typeid(uint64_t).name() << endl;

}

int main() {
    print(1,2,3,4);
    test();
    return 0;
}


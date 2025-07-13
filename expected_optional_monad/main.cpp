#include <iostream>
#include <cstdint>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <tuple>
#include <optional>
#include <variant>
#include <expected>
#include <span>
#include <string_view>
#include <ranges>
#include <print>

// using std::expected, std::unexpected;

using std::cout, std::endl;
using std::expected, std::unexpected;
using std::optional, std::nullopt;
using std::variant;

enum struct error : uint32_t {
    NO_MOUNT,
    NO_FILE,
    UNDEF,
};

[[nodiscard]]
expected<uint32_t, error> get_num_from_file() {
    if(rand() % 10 > 5) {
        return unexpected(error::NO_MOUNT);
    }
    if(rand() % 10 > 5) {
        return unexpected(error::NO_FILE);
    }
    if(rand() % 10 > 5) {
        return unexpected(error::UNDEF);
    }
    return rand();
}

void test1() {
    auto v = get_num_from_file().or_else( [](const error & err) -> expected<uint32_t, error> {return 100;} );

    // auto w = get_num_from_file().or_else( 
    //         [](const error & err) { 
    //             return expected<uint32_t, error> { 100 };
    //         }
    // );

    // cout << v.value() << endl;

    // auto x = get_num_from_file().transform_error( [](const error & err) -> error {return error{error::UNDEF};} );
    auto x = get_num_from_file().transform_error( [](const error & err) -> uint64_t {return 1;} );  // tranform error type

    auto y = get_num_from_file().transform([](uint32_t v) -> uint32_t { return v + 1; });   // transform value, lambda may not fail

    // auto z = get_num_from_file().and_then([](uint32_t v) -> expected<uint32_t, error> { return v * 2; });
    auto z = get_num_from_file().and_then([](uint32_t v) -> expected<double, error> { return v * 2.0; });   // lambda may fail with different error

}

[[nodiscard]]
optional<uint32_t> parseNumber (std::string_view sv) {
    uint32_t tmp = 0;
    for(char v: sv) {
        if(!std::isdigit(v)) {
            return nullopt;
        }
        tmp *= 10;
        tmp += v - '0';
    }
    return tmp;
}

// [[nodiscard]]
void test2() {

    optional<double> od1;
    optional<double> od2 {};
    optional<double> od3 = nullopt;
    std::println("{}", typeid(od1).name());
    std::println("{}", typeid(od2).name());
    std::println("{}", typeid(od3).name());

    optional<optional<double>> ood;
    std::println("{}", typeid(ood).name());

    // value -> unwrap value, throw if empty
    auto v = parseNumber("1234");
    std::println("{}", v.value());
    std::println("{}", typeid(v).name());

    // value_or -> unwrap value, provide default if empty
    v = parseNumber("a1234");   // will throw, when accessing with value()
    std::println("{}", v.value_or(0));
    std::println("{}", typeid(v).name());

    std::string inp;
    std::cin >> inp;
    v = parseNumber(inp);
    // transform -> apply f, wrapped the result in optional
    // auto w = v.transform([](uint32_t v) -> optional<double> { return 2.0*v; });  // w is of type optional<optional<double>>
    // auto w = v.transform([](uint32_t v) { return 2.0*v; });
    auto w = v.transform([](uint32_t v) -> double { return 2.0*v; });   // w is of type optional<double>
    std::println("{}", w.value_or(0.0));
    std::println("{}", typeid(w).name());

    std::cin >> inp;
    v = parseNumber(inp);
    // and_then -> return type as specified
    w = v.and_then([](uint32_t v) -> optional<double> { return 2.0*v; });
    std::println("{}", w.value_or(0.0));
    std::println("{}", typeid(w).name());

    std::cin >> inp;
    v = parseNumber(inp);   // return optional<uint32_t>
    // or_else -> takes f of type void -> optional<uint32_t>
    // or_else .. use to provide default, but stay in wrapped
    // w = v.or_else([]() -> optional<double> {return 0.0;});
    w = v.or_else([]() -> optional<uint32_t> {return 0;});  // must return the same type as v = optional<uint32_t>
    std::println("{}", w.value_or(0.0));
    std::println("{}", typeid(w).name());
}

int main() {

    std::cout << "in main" << std::endl;

    // error err;
    // error err1 {};
    // error err2 {error::UNDEF};
    // auto res = get_num_from_file();

    test1();
    test2();

    return 0;
}


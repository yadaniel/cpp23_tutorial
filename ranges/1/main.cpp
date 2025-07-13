#include <iostream>
#include <cstdint>
#include <vector>
#include <array>
#include <tuple>
#include <map>
#include <string>
#include <ranges>
#include <print>

//export LD_LIBRARY_PATH=/home/daniel/x-tools/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu/lib64/

using std::cout, std::endl;

void test1() {
    std::array<uint32_t,4> a = {1,2,3,4};
    std::vector<uint32_t> v = {1,2,3,4};
    std::map<uint32_t,std::string> m = {{1,"foo"}, {2,"bar"}};

    cout << "array" << endl;
    for(const auto& i: a) {
    // for(const auto i: a) {
    // for(auto i: a) {
        cout << i << endl;
    }

    cout << "vector" << endl;
    for(const auto& i: v) {
    // for(const auto i: v) {
    // for(auto i: v) {
        cout << i << endl;
    }

    cout << "map" << endl;
    for(const auto& i: m) {
    // for(const auto i: m) {
    // for(auto i: m) {
        cout << i.first << "->" << i.second << endl;
    }

    cout << "map" << endl;
    for(const auto& [k, v]: m) {
        cout << k << "->" << v << endl;
    }
    
}

// unpacking
void test2() {
    uint32_t arr[] = {1,2,3,4};
    // const uint32_t [a,b,c,d] = arr;
    // auto [a,b,c,d] = arr;
    // const auto [a,b,c,d] = arr;
    // const auto& [a,b,c,d] = arr;
    auto& [a,b,c,d] = arr;
    a = 10;
    cout << arr[0] << endl;
}

int main() {
    cout << "in main" << endl;
    test1();
    test2();
    return 0;
}


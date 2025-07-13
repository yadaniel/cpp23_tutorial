#include <iostream>
// #include <fmt/core.h>    // mingw only
#include <print>
#include <format>
#include <cstdint>
#include <string>
#include <array>
#include <map>
#include <vector>

// gcc15.1.0 -> /mingw64/bin/g++
// mingw command line
// g++ -std=c++23 -o main main.cpp -lfmt -lstdc++exp

// gcc15.1.0 -> /home/daniel/x-tools/x86_64-unknown-linux-gnu/bin/x86_64-unknown-linux-gnu-g++
// wsl2 command line
// export LD_LIBRARY_PATH=/home/daniel/x-tools/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu/lib64/

using std::vector, std::array, std::map,
      std::string;
using std::print, std::println;

void test1() {
    string txt;
    vector<uint32_t> v {1,2,3,4,5};
    for(uint32_t i: v) {
        print("{},", i);
        string s = std::format("{},", i);
        txt += s;
    }
    println();
    // fmt::print("");
    // fmt::println("");
    // fmt::println();
    std::cout << txt << std::endl;
}

void test2() {
    array<uint32_t, 5> v {1,2,3,4,5};
    for(uint32_t i: v) {
        print("{},", i);
    }
    println();
}

void test3() {
    map<string, string> v {{"",""}, {"book","buch"}};
    for(std::pair<string,string> i: v) {
        print("{} -> {}\n", i.first, i.second);
    }
    println();
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}


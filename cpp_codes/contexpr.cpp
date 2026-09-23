/*
#include <iostream>
#include <string_view>

int main()
{
    constexpr std::string_view s{ "Hello, world!" }; // s is a string symbolic constant
    std::cout << s << '\n'; // s will be replaced with "Hello, world!" at compile-time

    return 0;
}


const
↓
cannot modify this object

constexpr
↓
cannot modify it
+
its value can be determined at compile time

const int a = 10;          // constant
constexpr int b = 10;      // compile-time constant



const       = "don't change it"
constexpr   = "don't change it, and make it usable at compile time"
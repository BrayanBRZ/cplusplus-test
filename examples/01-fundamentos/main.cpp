#include <cstdint>
#include <iostream>
#include <string>

int main()
{
    int count{3};
    double price{19.90};
    bool active{true};
    std::string name{"C++"};
    std::int32_t fixedWidthId{42};

    constexpr int maxAttempts{5};
    const auto language = std::string{"moderno"};

    std::cout << "count = " << count << '\n';
    std::cout << "price = " << price << '\n';
    std::cout << "active = " << active << '\n';
    std::cout << "name = " << name << '\n';
    std::cout << "fixedWidthId = " << fixedWidthId << '\n';
    std::cout << "maxAttempts = " << maxAttempts << '\n';
    std::cout << "language = " << language << '\n';
}


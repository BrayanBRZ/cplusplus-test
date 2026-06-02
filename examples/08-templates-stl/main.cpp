#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
T maxValue(T a, T b)
{
    return a < b ? b : a;
}

template <typename T>
class Box
{
public:
    explicit Box(T value)
        : value_{std::move(value)}
    {
    }

    const T& value() const
    {
        return value_;
    }

private:
    T value_;
};

int main()
{
    std::cout << "maxValue(3, 7) = " << maxValue(3, 7) << '\n';
    std::cout << "maxValue(2.5, 1.5) = " << maxValue(2.5, 1.5) << '\n';

    Box<std::string> label{"template com string"};
    std::cout << label.value() << '\n';

    std::vector<int> values{5, 1, 9, 2, 7};

    std::sort(values.begin(), values.end());

    auto greaterThanFour = [](int value) {
        return value > 4;
    };

    const auto count = std::count_if(values.begin(), values.end(), greaterThanFour);

    std::cout << "ordenado:";
    for (int value : values) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';

    std::cout << "maiores que 4 = " << count << '\n';
}


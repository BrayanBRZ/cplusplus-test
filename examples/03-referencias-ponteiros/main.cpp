#include <iostream>
#include <string>

void incrementByValue(int value)
{
    ++value;
}

void incrementByReference(int& value)
{
    ++value;
}

void printText(const std::string& text)
{
    std::cout << text << '\n';
}

void printOptionalNumber(const int* number)
{
    if (number == nullptr) {
        std::cout << "sem valor\n";
        return;
    }

    std::cout << "valor = " << *number << '\n';
}

int main()
{
    int value{10};

    incrementByValue(value);
    std::cout << "apos valor: " << value << '\n';

    incrementByReference(value);
    std::cout << "apos referencia: " << value << '\n';

    printText("referencia constante aceita temporarios");

    int* pointer{&value};
    *pointer = 99;

    printOptionalNumber(pointer);
    printOptionalNumber(nullptr);
}


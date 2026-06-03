#include <cstdint>
#include <cstddef>
#include <iostream>
#include <string>

constexpr int square(int value)
{
    return value * value;
}

int main()
{
    // Inicializacao com chaves: forma recomendada neste material para valores simples.
    int count{3};
    double price{19.90};
    bool active{true};
    std::string name{"C++"};

    // Inicializacao com '=': comum e legivel, mas pode permitir conversoes implicitas.
    int copyStyle = 10;

    // Inicializacao com parenteses: aparece muito em codigo C++ existente.
    int directStyle(20);

    // Tipos com tamanho fixo: use quando a quantidade de bits faz parte da regra.
    std::int32_t signedId{-42};
    std::uint64_t largeCounter{9'000'000'000ULL};

    // unsigned nao aceita negativos e usa aritmetica modular.
    unsigned int lives{3};

    // std::size_t e o tipo usual para tamanhos e indices.
    std::size_t nameLength{name.size()};

    // const: valor calculado em runtime, mas protegido contra alteracao depois.
    const std::size_t immutableLength{name.size()};

    // constexpr: valor disponivel em tempo de compilacao.
    constexpr int maxAttempts{5};
    constexpr int squaredMaxAttempts{square(maxAttempts)};

    // auto: o compilador deduz o tipo pelo lado direito.
    const auto language = std::string{"moderno"};
    auto inferredUnsigned = 10u;

    std::cout << "count = " << count << '\n';
    std::cout << "copyStyle = " << copyStyle << '\n';
    std::cout << "directStyle = " << directStyle << '\n';
    std::cout << "price = " << price << '\n';
    std::cout << "active = " << active << '\n';
    std::cout << "name = " << name << '\n';
    std::cout << "signedId = " << signedId << '\n';
    std::cout << "largeCounter = " << largeCounter << '\n';
    std::cout << "lives = " << lives << '\n';
    std::cout << "nameLength = " << nameLength << '\n';
    std::cout << "immutableLength = " << immutableLength << '\n';
    std::cout << "maxAttempts = " << maxAttempts << '\n';
    std::cout << "squaredMaxAttempts = " << squaredMaxAttempts << '\n';
    std::cout << "language = " << language << '\n';
    std::cout << "inferredUnsigned = " << inferredUnsigned << '\n';
}

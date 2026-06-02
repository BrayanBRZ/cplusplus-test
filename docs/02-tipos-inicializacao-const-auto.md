# 02 - Tipos, inicialização, `const` e `auto`

Esta etapa não existe para ensinar o que é um inteiro ou um booleano. O objetivo é observar as escolhas específicas de C++.

## Tipos primitivos

Tipos comuns:

```cpp
int count = 10;
double price = 19.90;
float speed = 3.5f;
char letter = 'A';
bool active = true;
```

Em C++, o tamanho exato de alguns tipos pode depender da plataforma. Quando tamanho fixo importa, use `<cstdint>`:

```cpp
#include <cstdint>

std::int32_t id = 42;
std::uint64_t flags = 0;
```

## Inicialização

C++ possui várias formas de inicialização:

```cpp
int a = 10;
int b(10);
int c{10};
```

A forma com `{}` é muito usada em C++ moderno porque evita algumas conversões perigosas:

```cpp
int value{3.14}; // erro: perda de informação
```

## `const`

`const` significa que o objeto não deve ser modificado por aquele nome.

```cpp
const int maxUsers = 100;
```

Em parâmetros, `const` é especialmente importante:

```cpp
void printName(const std::string& name);
```

Esse parâmetro evita cópia e promete não alterar a string.

## `constexpr`

`constexpr` indica que um valor ou função pode ser avaliado em tempo de compilação.

```cpp
constexpr int screenWidth = 1280;
constexpr int square(int x)
{
    return x * x;
}
```

Use `constexpr` para constantes conhecidas em compilação. Prefira isso a macros:

```cpp
#define SCREEN_WIDTH 1280 // evite
constexpr int screenWidth = 1280; // prefira
```

## `auto`

`auto` pede ao compilador para deduzir o tipo.

```cpp
auto age = 30;          // int
auto price = 19.90;    // double
auto name = std::string{"Ana"};
```

Use `auto` quando o tipo estiver claro pelo lado direito ou quando escrever o tipo explicitamente piorar a leitura.

Bom uso:

```cpp
auto it = names.begin();
```

Uso discutível:

```cpp
auto result = calculate();
```

Se `calculate()` não deixa claro o tipo pelo nome ou contexto, escrever o tipo pode ser melhor.


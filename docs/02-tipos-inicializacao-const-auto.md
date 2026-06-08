# 02 - Tipos, inicializacao, `const`, `constexpr` e `auto`

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

O ponto importante: em C++, alguns tipos primitivos não têm exatamente o mesmo tamanho em todas as plataformas.

Por exemplo, `int` costuma ter 32 bits em computadores atuais, mas o padrão da linguagem não exige que seja sempre assim. Ele exige apenas algumas relações mínimas entre tamanhos.

Isso normalmente não importa para contadores simples, mas importa quando você está lidando com:

- formatos binários;
- protocolos de rede;
- arquivos gravados em disco;
- interoperabilidade com C;
- serialização;
- código que precisa se comportar igual em plataformas diferentes.

## Tipos com tamanho fixo: `<cstdint>`

Quando o tamanho em bits importa, use os tipos de `<cstdint>`:

```cpp
#include <cstdint>

std::int32_t id = 42;
std::uint64_t flags = 0;
```

O nome informa o significado:

- `std::int32_t`: inteiro com sinal de exatamente 32 bits;
- `std::uint64_t`: inteiro sem sinal de exatamente 64 bits;
- `std::int8_t`, `std::int16_t`, `std::int32_t`, `std::int64_t`;
- `std::uint8_t`, `std::uint16_t`, `std::uint32_t`, `std::uint64_t`.

O prefixo `u` em `uint` vem de `unsigned`, ou seja, sem sinal.

```cpp
std::int32_t signedValue = -10;
std::uint32_t unsignedValue = 10;
```

Use esses tipos quando o tamanho faz parte da regra do programa. Para contadores comuns, `int` continua aceitável.

## `signed` e `unsigned`

Um inteiro `signed` pode representar valores negativos, zero e positivos.

```cpp
int temperature = -5;
signed int score = -10;
```

Um inteiro `unsigned` representa apenas zero e valores positivos.

```cpp
unsigned int lives = 3;
```

Isso não significa apenas "não vou usar negativos". O tipo realmente muda a aritmética. Um erro comum:

```cpp
unsigned int value = 0;
--value; // o valor "volta" para um número muito grande
```

Esse comportamento acontece porque inteiros sem sinal usam aritmética modular.

Regra prática:

- use `int` para números comuns;
- use `unsigned` quando a aritmética modular for desejada ou quando uma API exigir;
- use `std::size_t` para tamanhos, índices e resultados de `.size()`;
- evite misturar `int` e `unsigned` sem pensar, porque comparações podem ficar traiçoeiras.

## `std::size_t`

É um tipo definido pela biblioteca padrão, disponível em headers como `<cstddef>`, `<string>`, `<vector>` e outros.

`std::size_t` é um tipo inteiro sem sinal usado para representar tamanhos de objetos e containers.

```cpp
#include <cstddef>

std::size_t length = 10;
```

Você o encontra com frequência:

```cpp
std::string name = "C++";
std::size_t length = name.size();
```

Por que não usar simplesmente `int`?

Porque um tamanho não deveria ser negativo e porque `std::size_t` é grande o suficiente para representar o tamanho máximo de objetos na plataforma.

Mas há uma consequência: como `std::size_t` é sem sinal, misturá-lo com `int` pode gerar warnings ou bugs.

```cpp
std::string text = "abc";

for (std::size_t i = 0; i < text.size(); ++i) {
    // i tem o mesmo tipo conceitual retornado por text.size()
}
```

## Inicialização

C++ possui várias formas de inicialização:

```cpp
int a = 10;
int b(10);
int c{10};
```

Essas formas parecem equivalentes em casos simples, mas têm diferenças importantes.

## Inicialização com `=`

```cpp
int a = 10;
```

Essa forma é chamada de copy initialization.

Para tipos primitivos, o compilador não está criando uma cópia custosa. O nome histórico é mais importante que o custo real nesse caso.

Ela é familiar e legível, mas permite algumas conversões implícitas:

```cpp
int value = 3.14; // compila, mas perde a parte decimal
```

Dependendo das flags do compilador, isso pode gerar warning.

## Inicialização com parênteses

```cpp
int b(10);
```

Essa forma é chamada de direct initialization.

Ela aparece bastante em código C++ antigo e também em construção de objetos:

```cpp
std::string name("Ada");
```

Para tipos simples, `int b(10)` funciona, mas não é a forma preferida hoje para ensinar inicialização geral, porque pode se confundir com declaração de função em alguns contextos mais avançados.

Esse problema é conhecido como "most vexing parse":

```cpp
std::string name(); // declara uma funcao chamada name; nao cria uma string
```

## Inicialização com chaves

```cpp
int c{10};
```

Essa forma é chamada de list initialization ou brace initialization.

Ela é muito usada em C++ moderno porque rejeita conversões com perda de informação:

```cpp
int value{3.14}; // erro: perda de informação
```

Esse erro é bom. Ele impede um bug silencioso.

Regra prática para este material:

- prefira `{}` para inicializar valores e objetos;
- aceite `=` quando deixar o código mais natural, especialmente com `auto`;
- reconheça `()` porque aparece muito em código C++ existente e em chamadas de construtores.

## `const`

`const` significa que o objeto não deve ser modificado por aquele nome.

```cpp
const int maxUsers = 100;
```

Isso melhora o código por três motivos:

1. comunica intenção;
2. impede alterações acidentais;
3. permite que o compilador rejeite usos incorretos.

Em parâmetros, `const` é especialmente importante:

```cpp
void printName(const std::string& name);
```

Esse parâmetro evita cópia e promete não alterar a string.

Use `const` quando o valor é calculado em tempo de execução, mas não deve mudar depois.

```cpp
std::string readUserName();

const std::string userName = readUserName();
```

`userName` não é conhecido em tempo de compilação. Mesmo assim, depois de inicializado, ele não deve mudar.

## Vantagens de `const`

- protege contra modificação acidental;
- documenta intenção no próprio tipo;
- funciona com qualquer tipo;
- é essencial para APIs que recebem referências sem modificar objetos.

## Limitações de `const`

`const` não significa necessariamente "constante de compilação".

```cpp
int readPortFromConfig();
const int port = readPortFromConfig();
```

`port` é imutável depois de inicializado, mas seu valor só é conhecido quando o programa roda.

## `constexpr`

`constexpr` indica que um valor ou função pode ser avaliado em tempo de compilação.

```cpp
constexpr int screenWidth = 1280;
constexpr int square(int x)
{
    return x * x;
}
```

Use `constexpr` quando o valor deve poder ser conhecido em tempo de compilação.

```cpp
constexpr int bufferSize = 1024;
```

Isso permite usar o valor em contextos que exigem constante de compilação:

```cpp
int buffer[bufferSize];
```

Em C++ moderno, uma função `constexpr` pode ser usada tanto em tempo de compilação quanto em tempo de execução:

```cpp
constexpr int square(int x)
{
    return x * x;
}

constexpr int compileTimeValue = square(4);
int runtimeValue = square(readValue());
```

## `const` vs `constexpr`

Use `const` quando:

- o valor não deve mudar depois de inicializado;
- o valor pode depender de entrada, arquivo, rede, horário ou cálculo em runtime;
- você quer proteger um objeto contra alteração.

Use `constexpr` quando:

- o valor é conhecido em compilação;
- o valor precisa ser usado como constante de compilação;
- você quer expressar que uma função ou valor pode ser avaliado pelo compilador.

Resumo curto:

```cpp
const int runtimeConstant = readValue(); // imutavel, mas runtime
constexpr int compileTimeConstant = 42;  // imutavel e compile-time
```

## Macros vs `constexpr`

Antes de C++ moderno, era comum escrever:

```cpp
#define SCREEN_WIDTH 1280
```

Prefira:

```cpp
constexpr int screenWidth = 1280;
```

Macros são processadas pelo pré-processador antes da compilação. Elas não respeitam tipos, escopos ou namespaces da mesma forma que objetos C++.

Problemas comuns com macros:

```cpp
#define SQUARE(x) x * x

int result = SQUARE(1 + 2); // vira 1 + 2 * 1 + 2
```

Também não há tipo associado:

```cpp
#define MAX_USERS 100
```

O compilador não sabe que isso deveria ser um `int`, `std::size_t` ou outro tipo específico. Ele só vê substituição textual.

Vantagens de `constexpr`:

- tem tipo;
- respeita escopo;
- pode ficar dentro de namespace ou classe;
- aparece melhor em mensagens de erro;
- evita armadilhas de substituição textual.

Macros ainda existem e são úteis para diretivas condicionais de compilação:

```cpp
#ifdef DEBUG
// codigo apenas em debug
#endif
```

Mas para constantes e funções simples, prefira `constexpr`.

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

## Cuidado com `auto`

`auto` deduz exatamente a partir da expressão de inicialização, e isso pode surpreender:

```cpp
auto value = 10;   // int
auto other = 10u;  // unsigned int
auto price = 10.0; // double
```

Com referências e `const`, o assunto fica mais sutil:

```cpp
const int original = 10;
auto copy = original;        // int, const foi descartado na copia
const auto fixed = original; // const int
```

Regra prática:

- use `auto` quando a dedução ajuda a leitura;
- escreva o tipo quando ele for parte importante da explicação;
- use `const auto` quando quer dedução sem permitir alteração.

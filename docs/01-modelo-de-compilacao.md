# 01 - Modelo de compilação

C++ não funciona como linguagens executadas diretamente por uma VM ou interpretador. Um programa C++ normalmente passa por estas fases:

1. Pré-processamento.
2. Compilação.
3. Montagem.
4. Linkedição.

Na prática diária, você verá principalmente dois conceitos:

- unidade de tradução;
- linker.

## Unidade de tradução

Uma unidade de tradução é, de forma simplificada, um arquivo `.cpp` depois que o pré-processador expande os `#include`.

Quando você escreve:

```cpp
#include <iostream>
#include "math_tools.hpp"
```

o pré-processador copia o conteúdo desses headers para dentro do `.cpp` antes da compilação.

Isso explica por que headers mal organizados podem aumentar muito o tempo de compilação.

## Declaração e definição

Declaração diz que algo existe.

```cpp
int sum(int a, int b);
```

Definição fornece a implementação ou reserva armazenamento.

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

Em C++, essa distinção é essencial. Várias linguagens escondem esse detalhe; C++ não.

## Compilação separada

Cada `.cpp` pode ser compilado separadamente para um arquivo objeto `.o`.
Depois, o linker junta esses objetos e resolve chamadas entre arquivos.

Exemplo conceitual:

```bash
g++ -c main.cpp -o main.o
g++ -c math_tools.cpp -o math_tools.o
g++ main.o math_tools.o -o app
```

O Makefile deste repositório esconde parte dessa mecânica, mas os conceitos continuam os mesmos.

## Erros típicos

Erro de compilação:

- sintaxe inválida;
- tipo incorreto;
- função chamada com argumentos errados;
- header inexistente.

Erro de linkedição:

- função declarada, mas não definida;
- `.cpp` necessário não foi passado ao compilador;
- biblioteca externa não foi linkada.

Exemplo clássico:

```cpp
int sum(int a, int b);

int main()
{
    return sum(1, 2);
}
```

Esse código compila, porque `sum` foi declarada. Mas não linka se nenhuma definição de `sum` for fornecida.


# 07 - Lvalue, rvalue, cópia e movimento

Este é um dos assuntos que mais diferenciam C++ moderno de linguagens com gerenciamento automático uniforme.

## Lvalue

Um lvalue tem identidade e pode ser localizado depois.

```cpp
int x = 10;
```

`x` é lvalue.

## Rvalue

Um rvalue é geralmente um valor temporário.

```cpp
int x = 10 + 5;
```

`10 + 5` produz um rvalue.

## Referência para lvalue

```cpp
int x = 10;
int& ref = x;
```

## Referência para rvalue

```cpp
int&& ref = 10;
```

Esse recurso é a base da semântica de movimento.

## Cópia

Copiar cria outro objeto com o mesmo valor lógico.

```cpp
std::string a = "texto";
std::string b = a;
```

Depois disso, `a` e `b` são strings independentes.

## Movimento

Mover transfere recursos internos de um objeto para outro quando isso é permitido.

```cpp
std::string a = "texto grande";
std::string b = std::move(a);
```

Depois do movimento, `a` continua válida, mas seu conteúdo específico não deve ser assumido.

## `std::move`

`std::move` não move nada sozinho.
Ele converte uma expressão para rvalue, permitindo que construtores ou atribuições de movimento sejam escolhidos.

## Rule of Zero

Se possível, escreva classes que não precisem declarar destrutor, copy constructor, move constructor ou operadores de atribuição.

Use membros que já gerenciam recursos corretamente:

- `std::string`;
- `std::vector`;
- `std::unique_ptr`;
- outros tipos RAII.

Essa é a regra mais segura em C++ moderno.


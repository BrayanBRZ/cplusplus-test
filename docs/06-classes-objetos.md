# 06 - Classes e objetos

C++ suporta orientação a objetos, mas com controle mais explícito que Java e C#.

## `class` vs `struct`

A diferença técnica principal é a visibilidade padrão.

Em `class`, membros são `private` por padrão.

```cpp
class User {
    std::string name; // private
};
```

Em `struct`, membros são `public` por padrão.

```cpp
struct Point {
    double x;
    double y;
};
```

Uso idiomático:

- `struct` para agregados simples;
- `class` para tipos com invariantes e comportamento.

## Construtor

Construtor inicializa o objeto.

```cpp
class User {
public:
    User(std::string name);
};
```

## Lista de inicialização

Prefira inicializar membros na lista de inicialização:

```cpp
User::User(std::string name)
    : name_{std::move(name)}
{
}
```

Isso evita inicializar primeiro e atribuir depois.

## Métodos `const`

Um método `const` promete não alterar o estado observável do objeto.

```cpp
double balance() const;
```

Isso permite chamar o método em objetos constantes:

```cpp
const BankAccount account{"Ana", 100.0};
account.balance();
```

## Invariantes

Uma invariante é uma regra que deve permanecer verdadeira durante a vida do objeto.

Exemplo:

- saldo de uma conta não pode ficar negativo;
- nome do titular não pode ser vazio.

Em C++, uma classe bem desenhada protege suas invariantes deixando dados privados e expondo operações válidas.


# 09 - Templates e STL

Templates são um mecanismo de programação em tempo de compilação.
Eles parecem "generics", mas são mais poderosos e também mais expostos.

## Função template

```cpp
template <typename T>
T maxValue(T a, T b)
{
    return a < b ? b : a;
}
```

O compilador instancia versões concretas conforme o uso:

```cpp
maxValue(1, 2);       // T = int
maxValue(1.5, 2.5);   // T = double
```

## Classe template

```cpp
template <typename T>
class Box {
public:
    explicit Box(T value);
    const T& value() const;
};
```

## Templates ficam em headers

Como templates precisam estar visíveis no ponto de instanciação, normalmente a implementação fica no header.

Isso é diferente de funções comuns, que podem ser declaradas no header e definidas no `.cpp`.

## STL

STL é o conjunto clássico de containers, iteradores e algoritmos da biblioteca padrão.

Containers importantes:

- `std::vector`;
- `std::array`;
- `std::map`;
- `std::unordered_map`;
- `std::string`.

Algoritmos importantes:

- `std::sort`;
- `std::find`;
- `std::count_if`;
- `std::remove_if`;
- `std::transform`.

## Lambdas

Lambdas são funções anônimas.

```cpp
auto isEven = [](int value) {
    return value % 2 == 0;
};
```

Elas combinam muito bem com algoritmos:

```cpp
auto count = std::count_if(values.begin(), values.end(), [](int value) {
    return value > 10;
});
```

## Estilo C++ moderno

Prefira:

```cpp
std::sort(values.begin(), values.end());
```

a loops manuais quando o algoritmo expressa melhor a intenção.

C++ moderno fica mais claro quando você usa a biblioteca padrão em vez de reimplementar estruturas e algoritmos comuns.


# 08 - Herança e polimorfismo

Herança em C++ deve ser usada com mais cuidado do que em linguagens onde tudo é referência gerenciada.

## Interface abstrata

Uma classe com método virtual puro não pode ser instanciada.

```cpp
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};
```

## Destrutor virtual

Se uma classe será usada polimorficamente, seu destrutor deve ser virtual.

```cpp
virtual ~Shape() = default;
```

Sem isso, destruir um objeto derivado através de ponteiro para base pode causar comportamento incorreto.

## `override`

Sempre use `override` ao sobrescrever método virtual.

```cpp
double area() const override;
```

Isso permite que o compilador detecte erro de assinatura.

## Polimorfismo por referência ou ponteiro

Para comportamento virtual funcionar, use referência ou ponteiro:

```cpp
void printArea(const Shape& shape);
```

Se você passa por valor, pode ocorrer object slicing.

## Object slicing

Object slicing acontece quando a parte derivada de um objeto é descartada ao copiá-lo para um objeto base por valor.

```cpp
Circle circle{2.0};
Shape shape = circle; // em geral, errado; e nem compila se Shape for abstrata
```

Regra prática:

- polimorfismo: use referência, ponteiro ou smart pointer;
- valor direto: use quando não há hierarquia polimórfica.


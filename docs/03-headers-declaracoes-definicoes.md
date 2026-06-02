# 03 - Headers, declarações e definições

Este é um dos primeiros assuntos realmente específicos de C++.

## `.cpp`

Arquivos `.cpp` normalmente contêm implementações.

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

Eles são compilados como unidades de tradução.

## `.h` e `.hpp`

Headers normalmente contêm declarações, tipos, constantes e templates.

```cpp
int sum(int a, int b);
```

Não existe diferença técnica obrigatória entre `.h` e `.hpp`. A extensão `.hpp` costuma indicar "header de C++", enquanto `.h` também é comum em C e C++.

Neste repositório, exemplos novos usam `.hpp` para deixar explícito que são headers C++.

## Include guard

Um header pode ser incluído mais de uma vez indiretamente. Para evitar redefinições:

```cpp
#ifndef MATH_TOOLS_HPP
#define MATH_TOOLS_HPP

int sum(int a, int b);

#endif
```

Outra opção comum:

```cpp
#pragma once
```

`#pragma once` é amplamente suportado, mas include guards são padrão e explícitos.

## Regra prática

Coloque no header:

- declarações de funções;
- declarações de classes;
- templates;
- constantes `inline constexpr`;
- aliases de tipos públicos.

Coloque no `.cpp`:

- implementação de funções comuns;
- implementação de métodos não-template;
- detalhes privados do módulo.

## Erro comum: definir função comum no header

Se você colocar isto em um header:

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

e incluir esse header em vários `.cpp`, cada unidade de tradução terá uma definição de `sum`.
Isso pode gerar erro de múltipla definição no linker.

Para funções pequenas em header, use `inline` quando fizer sentido:

```cpp
inline int sum(int a, int b)
{
    return a + b;
}
```

Mas a regra inicial é simples: declare no header, implemente no `.cpp`.


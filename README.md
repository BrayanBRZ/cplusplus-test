# C++ organizado: trilha de estudo

Este repositório é uma fonte de estudo progressiva da linguagem C++.
O foco não é ensinar lógica de programação genérica, mas sim os pontos que tornam C++ diferente de linguagens como Java, C# e JavaScript: compilação, linkedição, headers, referências, ponteiros, tempo de vida, RAII, cópia, movimento, templates, STL e organização real de projeto.

O diretório `SDLtemplate/` foi mantido fora da trilha. Ele não deve ser usado nem modificado durante estes estudos.

## Como usar

Liste os exemplos:

```bash
make list
```

Compile todos:

```bash
make
```

Execute um exemplo específico:

```bash
make run EXAMPLE=01-fundamentos
```

Remova os artefatos gerados:

```bash
make clean
```

## Ordem recomendada

1. `docs/01-modelo-de-compilacao.md`
2. `docs/02-tipos-inicializacao-const-auto.md`
3. `docs/03-headers-declaracoes-definicoes.md`
4. `docs/04-referencias-ponteiros-tempo-de-vida.md`
5. `docs/05-raii-smart-pointers.md`
6. `docs/06-classes-objetos.md`
7. `docs/07-lvalue-rvalue-copy-move.md`
8. `docs/08-heranca-polimorfismo.md`
9. `docs/09-templates-stl.md`
10. `docs/10-makefile-gitignore.md`

## Exemplos disponíveis

- `00-raiz`: programa mínimo da raiz do repositório.
- `01-fundamentos`: sintaxe essencial, inicialização, `auto`, `const`, `constexpr`.
- `02-headers`: separação entre `.hpp` e `.cpp`, declaração e definição.
- `03-referencias-ponteiros`: passagem por valor, referência, ponteiro e `nullptr`.
- `04-raii-smart-pointers`: tempo de vida, destrutor, `std::unique_ptr`.
- `05-classes`: classe com invariantes, construtor, métodos `const` e implementação separada.
- `06-copy-move`: lvalue, rvalue, cópia, movimento e `std::move`.
- `07-polimorfismo`: interface abstrata, `virtual`, `override`, destrutor virtual.
- `08-templates-stl`: função template, classe template, `std::vector`, algoritmos e lambdas.

## Filosofia do material

Cada módulo deve ter:

- um documento explicativo em `docs/`;
- um exemplo compilável em `examples/`;
- pouco comentário inline;
- nomes explícitos;
- código pequeno o suficiente para leitura atenta.

O objetivo é que você consiga estudar C++ de forma cumulativa, sem misturar a linguagem com uma biblioteca gráfica, framework ou engine.


# 10 - Makefile e `.gitignore`

Mesmo estudando linguagem, é importante saber compilar projetos com mais de um arquivo.

## Makefile

Um Makefile descreve alvos.

```make
all:
	g++ main.cpp -o app
```

O nome antes dos dois-pontos é o alvo.
As linhas abaixo são comandos e precisam começar com tab.

## Variáveis

```make
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic
```

Isso evita repetir flags em todos os comandos.

## Flags úteis

- `-std=c++23`: escolhe o padrão da linguagem.
- `-Wall`: liga muitos avisos.
- `-Wextra`: liga avisos adicionais.
- `-Wpedantic`: cobra conformidade com o padrão.
- `-O0`: sem otimização, melhor para estudo e debug.
- `-g`: inclui símbolos de debug.

## Include path

Quando headers estão em uma pasta própria:

```bash
g++ -Iexamples/02-headers/include main.cpp math_tools.cpp -o app
```

O `-I` adiciona uma pasta à busca de includes.

## `.gitignore`

Arquivos gerados não devem ser versionados.

Exemplos:

```gitignore
build/
*.o
*.exe
```

Código-fonte, headers, documentos e Makefile devem ser versionados.

## Estrutura deste repositório

```text
docs/
examples/
Makefile
.gitignore
README.md
```

Os exemplos geram executáveis em `build/`.
O diretório `build/` é descartável.


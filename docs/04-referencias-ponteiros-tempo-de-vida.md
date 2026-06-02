# 04 - Referências, ponteiros e tempo de vida

Referências e ponteiros são centrais em C++ porque a linguagem permite trabalhar diretamente com identidade, endereço e tempo de vida dos objetos.

## Referência

Uma referência é um alias para um objeto existente.

```cpp
int value = 10;
int& ref = value;

ref = 20; // altera value
```

Uma referência comum:

- precisa ser inicializada;
- não pode ser nula;
- não pode ser "redirecionada" para outro objeto.

## Parâmetro por referência

```cpp
void increment(int& value)
{
    ++value;
}
```

Use quando a função deve modificar o argumento original.

## Referência constante

```cpp
void print(const std::string& text);
```

Use quando:

- o objeto pode ser grande para copiar;
- a função não deve modificá-lo;
- você quer aceitar lvalues e temporários.

## Ponteiro

Um ponteiro guarda um endereço.

```cpp
int value = 10;
int* pointer = &value;

*pointer = 20;
```

Ponteiros podem ser nulos:

```cpp
int* pointer = nullptr;
```

Por isso, ponteiros costumam expressar "talvez exista".

## Quando usar referência ou ponteiro

Use referência quando:

- o objeto deve existir;
- a função não assume propriedade;
- você não precisa representar ausência.

Use ponteiro quando:

- `nullptr` é um estado válido;
- você precisa lidar com arrays C;
- interoperabilidade com APIs C;
- há semântica explícita de endereço.

## Tempo de vida

Um dos maiores riscos em C++ é guardar referência ou ponteiro para algo que já morreu.

Exemplo perigoso:

```cpp
int* makePointer()
{
    int value = 10;
    return &value; // errado: value morre ao sair da função
}
```

Esse ponteiro fica pendurado. Acessá-lo causa comportamento indefinido.


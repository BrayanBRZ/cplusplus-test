# 05 - RAII e smart pointers

RAII significa "Resource Acquisition Is Initialization".

Em C++, o jeito idiomático de gerenciar recursos é associar o recurso ao tempo de vida de um objeto.

## O problema

Este código é frágil:

```cpp
Resource* resource = new Resource{};
doWork();
delete resource;
```

Se `doWork()` lançar exceção ou retornar antes da hora, `delete` pode não executar.

## A ideia do RAII

O construtor adquire o recurso.
O destrutor libera o recurso.

```cpp
class ResourceHandle {
public:
    ResourceHandle();
    ~ResourceHandle();
};
```

Quando o objeto sai de escopo, o destrutor é chamado automaticamente.

## Evite `new` e `delete` manuais

C++ moderno prefere:

```cpp
auto value = std::make_unique<MyType>();
```

em vez de:

```cpp
MyType* value = new MyType{};
delete value;
```

## `std::unique_ptr`

Representa posse exclusiva.

```cpp
std::unique_ptr<User> user = std::make_unique<User>("Ana");
```

Quando o `unique_ptr` morre, o objeto apontado também é destruído.

Ele não pode ser copiado, apenas movido.

## `std::shared_ptr`

Representa posse compartilhada.

Use somente quando vários donos realmente precisam prolongar o tempo de vida do mesmo objeto.

## Regra prática

1. Prefira objeto direto:

```cpp
User user{"Ana"};
```

2. Se precisa de alocação dinâmica e dono único:

```cpp
auto user = std::make_unique<User>("Ana");
```

3. Use `std::shared_ptr` apenas com posse compartilhada real.

4. Use ponteiro cru sem dono para observar:

```cpp
User* selectedUser = nullptr;
```

Nesse caso, o ponteiro não deve destruir o objeto.


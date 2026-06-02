#include "BankAccount.hpp"

#include <stdexcept>
#include <utility>

BankAccount::BankAccount(std::string owner, double initialBalance)
    : owner_{std::move(owner)}
    , balance_{initialBalance}
{
    if (owner_.empty()) {
        throw std::invalid_argument{"owner nao pode ser vazio"};
    }

    if (balance_ < 0.0) {
        throw std::invalid_argument{"saldo inicial nao pode ser negativo"};
    }
}

const std::string& BankAccount::owner() const
{
    return owner_;
}

double BankAccount::balance() const
{
    return balance_;
}

void BankAccount::deposit(double amount)
{
    if (amount <= 0.0) {
        throw std::invalid_argument{"deposito deve ser positivo"};
    }

    balance_ += amount;
}

bool BankAccount::withdraw(double amount)
{
    if (amount <= 0.0 || amount > balance_) {
        return false;
    }

    balance_ -= amount;
    return true;
}


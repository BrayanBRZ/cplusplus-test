#include "BankAccount.hpp"

#include <iostream>

int main()
{
    BankAccount account{"Ada", 100.0};

    account.deposit(50.0);

    if (account.withdraw(30.0)) {
        std::cout << "saque aprovado\n";
    }

    std::cout << account.owner() << " tem saldo " << account.balance() << '\n';
}


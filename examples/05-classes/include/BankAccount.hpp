#ifndef EXAMPLES_05_CLASSES_BANK_ACCOUNT_HPP
#define EXAMPLES_05_CLASSES_BANK_ACCOUNT_HPP

#include <string>

class BankAccount
{
public:
    BankAccount(std::string owner, double initialBalance);

    const std::string& owner() const;
    double balance() const;

    void deposit(double amount);
    bool withdraw(double amount);

private:
    std::string owner_;
    double balance_;
};

#endif


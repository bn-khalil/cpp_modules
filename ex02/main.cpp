#include "Account.hpp"
#include <iostream>

int main() {
    Account a(12);
    Account b(42);
    Account c(1337);
    Account d(1337);
    Account k(1337);
    Account l(1337);
    Account::displayAccountsInfos();
    a.makeDeposit(12);
    return (0);
}
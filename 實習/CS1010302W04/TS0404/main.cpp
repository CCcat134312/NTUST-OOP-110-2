// Name: 林信佑
// Date: 2022/3/10 下午 01:23:26
// Last Update: 2022/3/10 下午 01:23:26
// Problem statement: Bank Account
#include <iostream>
#include "BankAccount.h"

using namespace std;

int main() {
	BankAccount bankAccount1(200), bankAccount2, bankAccount3(-100);
	cout << BankAccount::getAllMoneyInBank() << endl;
	bankAccount1.withdraw(100);
	cout << bankAccount1.getBalance() << endl;
	cout << BankAccount::getAllMoneyInBank() << endl;
	bankAccount2.save(50);
	cout << bankAccount2.getBalance() << endl;
	cout << BankAccount::getAllMoneyInBank() << endl;
	return 0;
}

// Name: �L�H��
// Date: 2022/3/22 �U�� 04:15:13
// Last Update: 2022/3/22 �U�� 04:15:13
// Problem statement: Prime Number

class PrimeNumber {
public:
	static int table[201];	// addition
	int value;
	int get();
	PrimeNumber();
	PrimeNumber(int _value);
	PrimeNumber & operator++();
	PrimeNumber operator++(int);
	PrimeNumber & operator--();
	PrimeNumber operator--(int);

};
// Name: 林信佑
// Date: 2022/4/7 下午 01:31:07
// Last Update: 2022/4/7 下午 01:31:07
// Problem statement: Memory Simulator
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 
bool notInRange(int memSize, int postion, int length)
{
	return postion + length >= memSize;
}

int main()
{
	int memSize, commandNum;
	cin >> memSize;
	vector<unsigned char> memory(memSize, 0);
	for (cin >> commandNum; commandNum; commandNum--)
	{
		string command, type;
		int position;
		cin >> command >> position >> type;
		if (command == "Set")
		{
			if (type == "char")
			{
				unsigned int data;
				cin >> data;
				data = data > 255 ? 255 : data;
				if (notInRange(memSize, position, 0))
					cout << "Violation Access.\n";

				if (position < memSize)
					memory[position] = (char)data;
			}
			else if (type == "short")
			{
				unsigned short data;
				cin >> data;
				if (notInRange(memSize, position, 1))
					cout << "Violation Access.\n";

				for (int i = position; data; data >>= 8, i++)
				{
					if (i < memSize)
						memory[i] = (char)(data & 0xff);
				}
			}
			else if (type == "int")
			{
				unsigned int data;
				cin >> data;
				if (notInRange(memSize, position, 3))
					cout << "Violation Access.\n";

				for (int i = position; data; data >>= 8, i++)
				{
					if (i < memSize)
						memory[i] = (char)(data & 0xff);
				}
			}
			else if (type == "String")
			{
				string data;
				cin.get();	// space between type and data
				getline(cin, data);
				if (notInRange(memSize, position, data.size()))
					cout << "Violation Access.\n";

				for (int i = 0; i < data.size(); i++)
				{
					if (i + position < memSize)
						memory[i + position] = data[i];
				}
			}
		}
		else if (command == "Get")
		{
			if (type == "char")
			{
				if (notInRange(memSize, position, 0))
				{
					cout << "Violation Access.\n";
					continue;
				}

				cout << (int)memory[position] << '\n';
			}
			else if (type == "short")
			{
				if (notInRange(memSize, position, 1))
				{
					cout << "Violation Access.\n";
					continue;
				}

				unsigned short data(0);
				for (int i = 0, base = 1; i < 2; i++, base <<= 8)
					data += (unsigned short)memory[i + position] * base;

				cout << data << '\n';
			}
			else if (type == "int")
			{
				if (notInRange(memSize, position, 3))
				{
					cout << "Violation Access.\n";
					continue;
				}

				unsigned int data(0);
				for (int i = 0, base = 1; i < 4; i++, base <<= 8)
					data += (unsigned int)memory[i + position] * base;

				cout << data << '\n';
			}
			else if (type == "String")
			{
				if (notInRange(memSize, position, 0))
					cout << "Violation Access.\n";

				for (int i = position; memory[i] && i < memory.size(); i++)
					cout << memory[i];

				cout << '\n';
			}
		}
	}
	return 0;
}
// Name: 林信佑
// Date: 2022/3/15 下午 03:41:29
// Last Update: 2022/3/15 下午 03:41:29
// Problem statement: Hot dog stand
#include "HotDogStand.h"
#include <string.h>
#include <iostream>

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
	standId = nullptr;
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char* id)
{
	int idSize = strlen(id);	// get size
	standId = new char[idSize + 1]();	// allocate memory
	for (int i = 0; id[i]; i++)	// copy data
		standId[i] = id[i];

	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char* id, int amount)
{
	int idSize = strlen(id);	// get size
	standId = new char[idSize + 1]();	// allocate memory
	for (int i = 0; id[i]; i++)	// copy data
		standId[i] = id[i];

	hotDogSellAmount = amount;
	totalSellAmount += amount;
}

HotDogStand::~HotDogStand()
{
	delete[] standId;
}

void HotDogStand::justSold()
{
	hotDogSellAmount++;
	totalSellAmount++;
}

void HotDogStand::print()
{
	std::cout << standId << ' ' << hotDogSellAmount << '\n';
}

int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}

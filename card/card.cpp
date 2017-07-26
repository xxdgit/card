#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "card.h"

Card::Card() : mAllCard(52)
{
	toPlayerCard = new vector<string>[4];
	initCard();
}

Card::~Card()
{
	delete [] toPlayerCard;
}

void Card::initCard()
{
	mAllCard = {
		"D_1", "D_2", "D_3", "D_4", "D_5", "D_6", "D_7", "D_8", "D_9", "D_10", "D_J", "D_Q", "D_K",
		"C_1", "C_2", "C_3", "C_4", "C_5", "C_6", "C_7", "C_8", "C_9", "C_10", "C_J", "C_Q", "C_K",
		"H_1", "H_2", "H_3", "H_4", "H_5", "H_6", "H_7", "H_8", "H_9", "H_10", "H_J", "H_Q", "H_K",
		"S_1", "S_2", "S_3", "S_4", "S_5", "S_6", "S_7", "S_8", "S_9", "S_10", "S_J", "S_Q", "S_K"
	};
}

void Card::shuffler()
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(mAllCard.begin(), mAllCard.end(), default_random_engine(seed));
}

void Card::deal()
{
	int i = 0;
	vector<string>::iterator it = mAllCard.begin();
	while (it < mAllCard.begin() + 13)
	{
		if (i == 0)
		{
			toPlayerCard[0].push_back(*it);

			if (toPlayerCard[0].size() == 13)
			{
				i = 1;
				mAllCard.erase(mAllCard.begin(), mAllCard.begin() + 13);
				it = mAllCard.begin();
			} else {
				it += 1;
			}
		}
		if (i == 1)
		{
			toPlayerCard[1].push_back(*it);

			if (toPlayerCard[1].size() == 13)
			{
				i = 2;
				mAllCard.erase(mAllCard.begin(), mAllCard.begin() + 13);
				it = mAllCard.begin();
			} else {
				it += 1;
			}
		}
		if (i == 2)
		{
			toPlayerCard[2].push_back(*it);

			if (toPlayerCard[2].size() == 13)
			{
				i = 3;
				mAllCard.erase(mAllCard.begin(), mAllCard.begin() + 13);
				it = mAllCard.begin();
			} else {
				it += 1;
			}
		}
		if (i == 3)
		{
			toPlayerCard[3].push_back(*it);
			it += 1;
		}

		
	}
}

void Card::print()
{
	shuffler();
	for (auto& it : mAllCard)
		cout << it << " ";
	cout << endl;
	cout << endl;

	deal();
	cout << "Player1: " << endl;
	for (auto& it : toPlayerCard[0])
		cout << "{" << it << "} ";
	cout << endl;
	cout << endl;

	cout << "Player2: " << endl;
	for (auto& it : toPlayerCard[1])
		cout << "{" << it << "} ";
	cout << endl;
	cout << endl;

	cout << "Player3: " << endl;
	for (auto& it : toPlayerCard[2])
		cout << "{" << it << "} ";
	cout << endl;
	cout << endl;

	cout << "Player4: " << endl;
	for (auto& it : toPlayerCard[3])
		cout << "{" << it << "} ";
	cout << endl;
}

//for test
int main()
{
	Card card;
	card.print();
	return 0;
}
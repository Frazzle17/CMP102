#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

bool bullseye()
{
	if (rand() % 100 < 70)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	float added_average = 0.0;
	float total_average = 0.0;
	int i;
	srand(time(NULL));

	int games;
	cout << "How many games would you like to play?" << endl;
	cin >> games;

	for (i = 0; i < games; i++)
	{
		int bull_hits = 0;
		float darts_thrown = 0;
		while (bull_hits < 10)
		{
			bool hit = bullseye();
			darts_thrown += 1;
			if (hit == true)
			{
				bull_hits += 1;
				cout << "Hit!" << endl;
			}
			else
			{
				cout << "Miss!" << endl;
			}
		}
		cout << "10 bullseye hits with " << darts_thrown << " darts thrown!" << endl;
		float game_average = (10 / darts_thrown) * 100;
		added_average += game_average;
		cout << "Accuracy: " << game_average << "%" << endl;
	}
	total_average = added_average / i;
	cout << "For a test run of " << i << " games, the total accuracy is: " << total_average << "%" << endl;
}
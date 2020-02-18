#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string>
using namespace std;

class Player
{
public:
	string name;
	float accuracy;
	float game_hits;
	float total_hits;
	float game_throws;
	float total_throws;

	float calculate_average(float hits, float throws)
	{
		float a = (hits / throws) * 100;
		return a;
	}

	bool bullseye()
	{
		if (rand() % 100 < accuracy)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void play_round(Player player, int round)
{
	cout << player.name << " - Round " << round << ":" << endl;
	for (int i = 0; i < 3; i++)
	{
		player.game_throws++;
		player.total_throws++;
		if (player.bullseye() == true)
		{
			cout << "Hit!" << endl;
			player.game_hits++;
			player.total_hits++;
		}
		else
		{
			cout << "Miss!" << endl;
		}
		if (player.game_hits == 10)
		{
			return;
		}
	}
}

int main()
{
	Player joe;
	joe.name = "Joe";
	joe.accuracy = 71;
	joe.total_hits = 0;
	joe.total_throws = 0;

	Player Sid;
	Sid.name = "Sid";
	Sid.accuracy = 73;
	Sid.total_hits = 0;
	Sid.total_throws = 0;

	srand(time(NULL));

	int games;
	cout << "How many games would you like to play?" << endl;
	cin >> games;

	for (int i = 0; i < games; i++)
	{
		int round = 0;
		joe.game_hits = 0;
		joe.game_throws = 0;
		Sid.game_hits = 0;
		Sid.game_throws = 0;
		while (joe.game_hits < 10 && Sid.game_hits < 10)
		{
			play_round(joe, round);
			cout << joe.game_hits << endl;
			round += 1;
			if (joe.game_hits != 10)
			{
				play_round(Sid, round);
				round += 1;
			}
			cout << Sid.game_hits << endl;
			Sleep(1000);
		}

		Player winner;
		if (joe.game_hits == 10)
		{
			winner = joe;
		}
		else
		{
			winner = Sid;
		}
		cout << winner.name << " wins!" << endl;
		cout << "10 bullseye hits with " << winner.game_throws << " darts thrown!" << endl;
		cout << "Joe's average was: " << joe.calculate_average(joe.game_hits, joe.game_throws) << "%" << endl;
		cout << "Sid's average was: " << Sid.calculate_average(Sid.game_hits, Sid.game_throws) << "%" << endl;
	}
	cout << "Joe's total average from " << games << " games, is: " << joe.calculate_average(joe.total_hits, joe.total_throws) << "%" << endl;
	cout << "Sid's total average from " << games << " games, is: " << Sid.calculate_average(Sid.total_hits, Sid.total_throws) << "%" << endl;
}
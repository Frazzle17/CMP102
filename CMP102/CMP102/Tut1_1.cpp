#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	int i = 0;
	while (i != -1)
	{
		srand(time(NULL));
		int num = (rand() % 100) + 1;
		cout << num << endl;
		cin >> i;
	}
}
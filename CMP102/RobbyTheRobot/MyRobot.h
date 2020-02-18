#pragma once
#include <Robot.h>
class MyRobot:
public Robot
{
public:
	void move(int);
	void back();
	void goTo(int, int);
};


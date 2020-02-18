#include "MyRobot.h"
#include "Robot.h"

void MyRobot::move(int n)
{
	for (int i = 0; i < n; i++)
	{
		Robot::move();
	}
}

void MyRobot::back()
{
	Robot::left();
	Robot::left();
	Robot::move();
	Robot::left();
	Robot::left();
}

void MyRobot::goTo(int newX, int newY)
{
	//current coords of robby
	int x = Robot::get_xpos();
	int y = Robot::get_ypos();
	//difference to move
	int xDiff = newX - x;
	int yDiff = newY - y;
	//if newX>x EAST, 1
	//if x>newX WEST, 3
	//if newY>y SOUTH, 2
	//if y>newY NORTH, 0

	int oldDir = Robot::get_dir();
	int newDir;
	if (xDiff > 0)
	{
		newDir = 1;
	}
	else
	{
		newDir = 3;
		xDiff *= -1;
	}
	while (Robot::get_dir() != newDir)
	{
		Robot::left();
	}
	MyRobot::move(xDiff);

	if (yDiff > 0)
	{
		newDir = 2;
	}
	else
	{
		newDir = 0;
		yDiff *= -1;
	}
	while (Robot::get_dir() != newDir)
	{
		Robot::left();
	}
	MyRobot::move(yDiff);
	Robot::setDirection(oldDir);
}
#include "GraphicsManager.h"
#include "MyRobot.h"
#include <iostream>

Room* room;
MyRobot* robby;
GraphicsManager* picture;

int main()
{
	room = new Room(0);
	robby = new MyRobot();
	picture = new GraphicsManager(room, robby);

	picture->draw();
	robby->left();
	picture->draw();
	robby->goTo(4, 13);
	picture->draw();
	robby->back();
	picture->draw();
	robby->move(4);
	picture->draw();
	system("Pause");
}
#include"Controller.h"
using namespace std;
int main(){
	int flag;
	MenuReady();
	srand(time(NULL));
	myWindow.setFramerateLimit(10);
	while (myWindow.isOpen())
	{
		while (myWindow.pollEvent(eve))
		{
			switch (eve.type)
			{
			case sf::Event::Closed:
				myWindow.close();
				break;
			}
		}
		    myWindow.clear();
			startGame();
			myWindow.display();

	}
}


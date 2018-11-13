#include"UserInterface.h"
#include<stdlib.h>
int flag,scoreflag,gamestateTemp;
char scor[20];
void Load()
{
	GenerateMaze();
	DrawInitialize();
	GetSolution();
	totalTime = haveTime;
	flag = 0;
}
void startGame()
{
	switch (GameState)
	{

	case 0://0: menu.
	{
			   SelectOptions();
			   LevelInitiate();
			   flag = 1;
			   break;
	}
	case 1://arcade
	{
			   if (flag)
				   Load();
			   PLAY();
			   SideMenu();
			   if (sideMenuState != 2 && sideMenuState)
				   DrawMaze();
			   gamestateTemp = 1;
			   scoreflag = 1;
			   break;
	}
	case 2://time trial
	{
			   if (flag)
			   {
				   Load();
			   }
			  PLAY();
			  SideMenu();
			  if (sideMenuState != 2 && sideMenuState)
			  {
				  DrawMaze();
				  gamestateTemp = 2;
				  scoreflag = 1;
			  }
			  break;
	}
	case 3://if success
	{
			   SideMenu();
			   myWindow.draw(solvedButton);
			   sf::Vector2i mousePos = sf::Mouse::getPosition(myWindow);
			   if (scoreflag){
				   totalScore += score;
				   scoreflag = 0;
			   }
			   itoa(totalScore, scor, 10);
			   _score.setString(scor);
			   myWindow.draw(_score);
			   if (mousePos.x >= 531 && mousePos.x <= 586 && mousePos.y >= 390 && mousePos.y <= 436 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			   {
				   if (gamestateTemp == 1)
				   {
					   clearMaze();
					   flag = 1;
					   GameState = 1;
					   LevelInitiate();
				   }
				   else if (gamestateTemp == 2)
				   {
					   clearMaze();
					   flag = 1;
					   GameState = 2;
					   LevelInitiate();

				   }

			   }
			   break;
	}
	case 4:
	{
			  SideMenu();
			  DrawMaze();
			  DrawSolution();
			  break;

	}

	}
	}

	
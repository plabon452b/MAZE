#include"player.h"
#include"Timer.h"
#include"Files.h"

using namespace std;
int totalScore;
sf::Event eve;
int menuState = 0;
int sideMenuState = 0;
sf::Text _score;
sf::Font score_font;
sf:: Text nameInputText;
sf::Font nameInputFont;
string input;//user name;
char inp;
sf::RectangleShape solvedButton(sf::Vector2f(400.0f, 220.0f));
sf::RectangleShape nameInput(sf::Vector2f(400.0f, 200.0f));
sf::RectangleShape giveup(sf::Vector2f(120.0f, 50.0f));
//textures:
sf::Texture menuTexture;
sf::Texture option_1;
sf::Texture option_2;
sf::Texture option_3;
sf::Texture option_4;
sf::Texture option_5;
sf::Texture option_6;
sf::Texture gamemodes;
sf::Texture gamemodes1;
sf::Texture gamemodes2;
sf::Texture levelselect;
sf::Texture level1;
sf::Texture level2;
sf::Texture level3;
sf::Texture level4;
sf::Texture sidemenu;
sf::Texture infoTexture;
sf::Texture sidemenuMuted;
sf::Texture sidemenuPaused;
sf::Texture solveButtonTexture;
sf::Texture nameInputTexture;
sf::Texture GiveupTexture;
sf::Texture highScoreTexture;
//sprites:
sf::Sprite menu;
sf::Sprite op_1;
sf::Sprite op_2;
sf::Sprite op_3;
sf::Sprite op_4;
sf::Sprite op_5;
sf::Sprite op_6;
sf::Sprite stropt;
sf::Sprite mode_1;
sf::Sprite mode_2;
sf::Sprite level;
sf::Sprite level_1;
sf::Sprite level_2;
sf::Sprite level_3;
sf::Sprite level_4;
sf::Sprite side_menu;
sf::Sprite Muted;
sf::Sprite paused;
sf::Sprite info;
sf::Sprite highScoreSprite;


//sf::SoundBuffer buffer;
//sf::Sound sound;
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::MENU:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void MenuReady()
{ //load texture:
	menuTexture.loadFromFile("MENU/STR.png");
	option_1.loadFromFile("MENU/start.png");
	option_2.loadFromFile("MENU/difficulty_level.png");
	option_3.loadFromFile("MENU/high_scores.png");
	option_4.loadFromFile("MENU/options.png");
	option_5.loadFromFile("MENU/about.png");
	option_6.loadFromFile("MENU/quit.png");
	gamemodes.loadFromFile("MENU/strtopt.png");
	gamemodes1.loadFromFile("MENU/arcade.png");
	gamemodes2.loadFromFile("MENU/time_trial.png");
	levelselect.loadFromFile("MENU/levelselect.png");
	level1.loadFromFile("MENU/daydream.png");
	level2.loadFromFile("MENU/luciddream.png");
	level3.loadFromFile("MENU/baddream.png");
	level4.loadFromFile("MENU/nightmare.png");
	sidemenu.loadFromFile("MENU/sidemenu.png");
	sidemenuMuted.loadFromFile("Menu/muted.png");
	sidemenuPaused.loadFromFile("Menu/paused.png");
	solveButtonTexture.loadFromFile("Textures/solvedButtonTexture.png");
	nameInputTexture.loadFromFile("Textures/name.png");
	infoTexture.loadFromFile("Menu/info.png");
	GiveupTexture.loadFromFile("Textures/giveup.png");
	highScoreTexture.loadFromFile("Menu/high_score.png");
	solvedButton.setPosition(355, 260);
	nameInput.setPosition(355, 260);
	//load sprite:
	menu.setTexture(menuTexture);
	op_1.setTexture(option_1);
	op_2.setTexture(option_2);
	op_3.setTexture(option_3);
	op_4.setTexture(option_4);
	op_5.setTexture(option_5);
	op_6.setTexture(option_6);
	stropt.setTexture(gamemodes);
	mode_1.setTexture(gamemodes1);
	mode_2.setTexture(gamemodes2);
	level.setTexture(levelselect);
	level_1.setTexture(level1);
	level_2.setTexture(level2);
	level_3.setTexture(level3);
	level_4.setTexture(level4);
	side_menu.setTexture(sidemenu);
	highScoreSprite.setTexture(highScoreTexture);
	Muted.setTexture(sidemenuMuted);
	paused.setTexture(sidemenuPaused);
	solvedButton.setTexture(&solveButtonTexture);
	nameInput.setTexture(&nameInputTexture);
	info.setTexture(infoTexture);
	giveup.setTexture(&GiveupTexture);
	score_font.loadFromFile("arial.ttf");
	_score.setFont(score_font);
	_score.setPosition(590, 335);
	nameInputFont.loadFromFile("arial.ttf");
	nameInputText.setFont(nameInputFont);
	nameInputText.setPosition(430, 370);
	giveup.setPosition(1132, 606);
	//sound:
	//buffer.loadFromFile("MENU/gta.wav");
	//sound.setBuffer(buffer);
	loadTimer();

}

//::::::::::::::::::::::::::::::::::::::::::::::menu:::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void SelectOptions()
{
	sf::Vector2i MousePos = sf::Mouse::getPosition(myWindow);
	printf("%d %d\n", MousePos.x, MousePos.y);
	switch (menuState)
	{

	case 0: 
	{        
	          myWindow.draw(menu);
			  if (MousePos.x >= 124 && MousePos.x <= 298 && MousePos.y >= 222 && MousePos.y <= 249)
			  {
				  myWindow.draw(op_1);//start
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  {
					  menuState = 1;
				  }

			  }
			  else if (MousePos.x >= 124 && MousePos.x <= 298 && MousePos.y >= 280 && MousePos.y <= 302)
			  {
				  myWindow.draw(op_2);//level
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					  menuState = 2;

			  }
			  else if (MousePos.x >= 124 && MousePos.x <= 298 && MousePos.y >= 327 && MousePos.y <= 351)
			  {
				  myWindow.draw(op_3);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					  menuState = 3;//high score
			  }
			  else if (MousePos.x >= 124 && MousePos.x <= 298 && MousePos.y >= 380 && MousePos.y <= 403)
			  {
				  myWindow.draw(op_4);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					  menuState = 4;//options
			  }
			  else if (MousePos.x >= 124 && MousePos.x <= 298 && MousePos.y >= 431 && MousePos.y <= 454)
			  {
				  myWindow.draw(op_5);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					  menuState = 5;//about
			  }
			  else if (MousePos.x >= 124 && MousePos.x <= 298 && MousePos.y >= 482 && MousePos.y <= 507)
			  {
				  myWindow.draw(op_6);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					  menuState = 6;//exit
			  }
			  break;
	}
	case 1:

	{
			  if (MousePos.x >= 320 && MousePos.x <= 460 && MousePos.y >= 280 && MousePos.y <= 301)
			  {
				  myWindow.draw(mode_1);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  {
					  GameState = 1;//arcade
				  }

			  }
			  else if (MousePos.x >= 320 && MousePos.x <= 460 && MousePos.y >= 328 && MousePos.y <= 352)
			  {
				  myWindow.draw(mode_2);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  {
					  GameState = 2;//timeTrial
				  }
			  }
			  else
				  myWindow.draw(stropt);
			  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  menuState = 0;
			  break;
	}

	case 2:

	{

			  if (MousePos.x >= 410 && MousePos.x <= 586 && MousePos.y >= 291 && MousePos.y <= 313)
			  {
				  myWindow.draw(level_1);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  {
					  GameLevel = 1;
				  }

			  }
			  else if (MousePos.x >= 410 && MousePos.x <= 586 && MousePos.y >= 321 && MousePos.y <= 342)
			  {
				  myWindow.draw(level_2);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  {
					  GameLevel = 2;
				  }

			  }
			  else if (MousePos.x >= 410 && MousePos.x <= 586 && MousePos.y >= 350 && MousePos.y <= 370)
			  {
				  myWindow.draw(level_3);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  {
					  GameLevel = 3;
				  }
			  }
			  else if (MousePos.x >= 410 && MousePos.x <= 586 && MousePos.y >= 380 && MousePos.y <= 402)
			  {
				  myWindow.draw(level_4);
				  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  {
					  GameLevel = 4;
				  }

			  }
			  else
				  myWindow.draw(level);
			  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  menuState = 0;
			  break;
	}
	case 3:
	{
			  myWindow.draw(highScoreSprite);
			 if( MousePos.x >= 74 && MousePos.x <= 125 && MousePos.y >= 662 && MousePos.y <= 702 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  menuState = 0;
			  break;

	}
	case 5:
	{
			  myWindow.draw(info);
			  if (MousePos.x >= 42 && MousePos.x <= 86 && MousePos.y <= 681 && MousePos.y >= 640 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  menuState = 0;
			  break;
	}
	case 6:
	{
			  myWindow.close();
			  break;
	}

		
	}
}
void SideMenu()
{
	sf::Vector2i MousePosn = sf::Mouse::getPosition(myWindow);
	switch (sideMenuState)
	{
	case 0:
	{
			  myWindow.draw(side_menu);
			  myWindow.draw(nameInput);
			  if (eve.TextEntered)
				 if( eve.text.unicode > 64 && eve.text.unicode < 91 || eve.text.unicode>96 && eve.text.unicode < 123)
			        input += eve.text.unicode;
			  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace))
				 {
					 if (input.size() > 0)  input.resize(input.size() - 1);
				 }
			  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
			  {
				  sideMenuState = 1;
				  startTimer();
			  }
			  nameInputText.setString(input);
			  myWindow.draw(nameInputText);
			  
			  break;
	}

	case 1:
	{

			  myWindow.draw(side_menu);
			  myWindow.draw(giveup);
			  if (MousePosn.x >= 1141 && MousePosn.x <= 1235 && MousePosn.y >= 622 && MousePosn.y <= 654 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			  {
				  GameState = 4;
			  }
			  if (GameState == 2)showTimer();
			  if (MousePosn.x >= 1157 && MousePosn.x <= 1203 && MousePosn.y >= 252 && MousePosn.y <= 300 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			  {
				  sideMenuState = 2;//pause
				  if(GameState==2) pauseTimer();

			  }
			  if (MousePosn.x >= 1157 && MousePosn.x <= 1203 && MousePosn.y >= 315 && MousePosn.y <= 362 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			  {
				  sideMenuState = 3;
				  myWindow.draw(Muted);
			  }
			  if (MousePosn.x >= 1157 && MousePosn.x <= 1203 && MousePosn.y >= 377 && MousePosn.y <= 425 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			  {
				  sideMenuState = 4;//goto main menu
				  file_io(totalScore,input);
			  }
				  
			  break;
	}
	case 2:
	{
			  myWindow.draw(paused);
			  myWindow.draw(giveup);
			  if (MousePosn.x >= 1141 && MousePosn.x <= 1235 && MousePosn.y >= 622 && MousePosn.y <= 654 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			  {
				  GameState = 4;
			  }
			  if (GameState == 2)showTimer();
			  if (MousePosn.x >= 546 && MousePosn.x <= 596 && MousePosn.y >= 345 && MousePosn.y <= 405 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			  {
				  sideMenuState = 1;
				  startTimer();
			  }
			  break;
	}
	case 3:
	{
			  myWindow.draw(Muted);
			  myWindow.draw(giveup);
			  if (MousePosn.x >= 1141 && MousePosn.x <= 1235 && MousePosn.y >= 622 && MousePosn.y <= 654 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			  {
				  GameState = 4;
			  }
			  if (GameState == 2)showTimer();
			  if (MousePosn.x >= 1157 && MousePosn.x <= 1203 && MousePosn.y >= 315 && MousePosn.y <= 362 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				  sideMenuState = 1;
				  
			  break;
	}
	case 4:
	{
			  GameState = 0;//menu
			  clearMaze();
			  sideMenuState = 0;
				  
			  break;
	}


	}
}
void DrawInitialize()
{
	int a, b, i, j;
	wallTexture.loadFromFile("Textures/wall.png");
	pathTexture.loadFromFile("Textures/path.png");
	solve.loadFromFile("Textures/solvepath.png");
	player.setSize(sf::Vector2f(10, 10));
	player.setFillColor(sf::Color::Green);
	player.setPosition(initialPos.x, initialPos.y);
	for (i = initialPos.x, a = 0; i < finalPos.x; i += 10, a++)
	{
		for (j = initialPos.y, b = 0; j < finalPos.y; j += 10, b++)
		{
			rect[a][b].setSize(sf::Vector2f(10, 10));
			rect[a][b].setPosition(sf::Vector2f(i, j));
			if (cell[a][b].isWall)
				rect[a][b].setTexture(&wallTexture);
			else
				rect[a][b].setTexture(&pathTexture);

		}

	}
}
void DrawMaze()
{
	for (int i = 0; i < nCells; i++)
	{
		for (int j = 0; j < mCells; j++)
		{
			if (i == (playerPosition.x - initialPos.x) / 10 && j == (playerPosition.y - initialPos.y) / 10)
			{
				myWindow.draw(player);
			}
			else
			{
				myWindow.draw(rect[i][j]);
				if (cell[i][j].visitedByPlayer)
					rect[i][j].setFillColor(sf::Color::Cyan);
				if (i ==endX && j == endY)
					rect[i][j].setFillColor(sf::Color::Blue);
			}
		}
	}
	myWindow.draw(border[0]);
	myWindow.draw(border[1]);
	myWindow.draw(border[2]);
	myWindow.draw(border[3]);
}

void DrawSolution()
{
	for (int i = 0; i < nCells; i++)
	{
		for (int j = 0; j < mCells; j++)
		{

			if (correctPath[i][j])
			{
				rect[i][j].setFillColor(sf::Color::Red);
				myWindow.draw(rect[i][j]);
			}

		}
	}
}

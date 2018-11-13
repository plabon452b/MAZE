#include"backtracker.h"
sf::RectangleShape player;
sf::Vector2u playerPosition;
int GameState = 0;
int GameLevel = 1;
int score;
int X, Y;
int haveTime;
void move_east()
{
	playerPosition.x += 10;
	player.setPosition(sf::Vector2f(playerPosition.x, playerPosition.y));
}
void move_west()
{
	playerPosition.x -= 10;
	player.setPosition(sf::Vector2f(playerPosition.x, playerPosition.y));
}

void move_north()
{
	playerPosition.y -= 10;
	player.setPosition(sf::Vector2f(playerPosition.x, playerPosition.y));
}

void move_south()
{
	playerPosition.y += 10;
	player.setPosition(sf::Vector2f(playerPosition.x, playerPosition.y));
}

void LevelInitiate()
{
	int diffX, diffY;
	if (GameLevel == 1)
	{
		nCells = 40;
		mCells = 40;
		haveTime = 45;
		score = 10;

	}
	else if (GameLevel == 2)
	{
		nCells = 50;
		mCells = 50;
		haveTime = 60;
		score = 20;
	}
	else if (GameLevel == 3)
	{
		nCells = 80;
		mCells = 60;
		haveTime = 90;
		score = 40;
	}
	else if (GameLevel == 4)
	{
		nCells = 100;
		mCells = 60;
		haveTime = 120;
		score = 50;
	}
	endX = nCells - 2;
	endY = mCells - 2;
	initialPos.x = ((1100 - (nCells * 10)) / 2) + 10;
	initialPos.y = ((720 - (mCells * 10)) / 2) + 10;
	finalPos.x = (initialPos.x + nCells * 10) + 10;
	finalPos.y = (initialPos.y + mCells * 10) + 10;
	playerPosition.x = initialPos.x;
	playerPosition.y = initialPos.y;
	X = 0;
	Y = 0;
	diffX = finalPos.x - initialPos.x;
	diffY = finalPos.y - initialPos.y;
	int r = 0, g = 0, b = 0;

	border[0].setPosition(initialPos.x - 10, initialPos.y - 10);
	border[0].setSize(sf::Vector2f((float)(diffX), 10.0f));
	border[0].setFillColor(sf::Color::Color(r, g, b));
	border[1].setPosition(finalPos.x - 20, initialPos.y);
	border[1].setSize(sf::Vector2f(10.0f, (float)diffY - 10));
	border[1].setFillColor(sf::Color::Color(r, g, b));
	border[2].setPosition(initialPos.x - 10, initialPos.y);
	border[2].setSize(sf::Vector2f(10.0f, (float)(diffY - 10)));
	border[2].setFillColor(sf::Color::Color(r, g, b));
	border[3].setPosition(initialPos.x - 10, initialPos.y + diffY - 20);
	border[3].setSize(sf::Vector2f((float)(diffX), 10.0f));
	border[3].setFillColor(sf::Color::Color(r, g, b));
}

int WaysFound(int x, int y)
{
	int ways = 0;
	if (y && !cell[x][y - 1].isWall)
		ways++;
	if (x &&!cell[x - 1][y].isWall)
		ways++;
	if (!cell[x][y + 1].isWall)
		ways++;
	if (y >= 0 && !cell[x + 1][y].isWall)
		ways++;
	return ways;
}
void PLAY()
{
	int a = endX, b = endY;
	if (cell[a][b].visitedByPlayer)
	{
		GameState = 3;
		clearMaze();
	}
	cell[X][Y].visitedByPlayer = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		while (Y && !cell[X][Y - 1].isWall)
		{
			move_north();
			Y--;
			cell[X][Y].visitedByPlayer = true;
			if (WaysFound(X, Y) > 2)
				break;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{

		while (!cell[X][Y + 1].isWall)
		{
			move_south();
			Y++;
			cell[X][Y].visitedByPlayer = true;
			if (WaysFound(X, Y) > 2)
				break;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		while (!cell[X + 1][Y].isWall)
		{
			move_east();
			X++;
			cell[X][Y].visitedByPlayer = true;
			if (WaysFound(X, Y) > 2)
				break;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		while (X && !cell[X - 1][Y].isWall)
		{
			move_west();
			X--;
			cell[X][Y].visitedByPlayer = true;
			if (WaysFound(X, Y) > 2)
				break;
		}
	}
}
#include"SFML/graphics.hpp"
#include<stack>
#include <ctime>
#include<iostream>
using namespace std;

stack <pair <int , int >> CellStack;
sf::Texture wallTexture;
sf::Texture pathTexture;
sf::Texture solve;
sf::Vector2u CurrentCell;
struct cellstruct {
	bool visited = false;
	bool isWall = true;
	bool visitedByPlayer = false;
};

int nCells; //row
int mCells;//col
int endX;
int endY;
sf::Vector2u initialPos;
sf::Vector2u finalPos;

cellstruct cell[110][72];//Cell[ncells][mCells]
sf::RectangleShape rect[110][72];
sf::RectangleShape border[4];



int GetNeighbour(int X,int Y)
{
	int east, west, north, south,dice;
	Y + 2 <mCells && !cell[X][Y+2].visited ? east = 1 : east = 10;
	Y - 2 >=0 && !cell[X][Y-2].visited ? west = 2 : west = 10;
	X - 2 >=0 && !cell[X - 2][Y].visited ? north = 3 : north = 10;
	X + 2 < nCells && !cell[X + 2][Y].visited ? south = 4 : south = 10;
	if (east == 10 && west == 10 && north == 10 && south == 10)
		return 0;
	while (1){
		dice = (rand() % 4) + 1;
		if (dice == east)
			return 1;
		else if (dice == west)
			return 2;
		else if (dice == north)
			return 3;
		else if (dice == south)
			return 4;
	}


}
//::::::::::::::::::::::::::::::::AlGORITHM:::::::::::::::::::::::::::::::::
void initialize()
{
	
	CurrentCell.x = 0;
	CurrentCell.y = 0;
	cell[CurrentCell.x][CurrentCell.y].visited = true;
	cell[CurrentCell.x][CurrentCell.y].isWall = false;
	CellStack.push(make_pair(CurrentCell.x, CurrentCell.y));

}
void GenerateMaze(){
	initialize();
	while (1)
	{
		int neighbour = GetNeighbour(CurrentCell.x,CurrentCell.y);

		   if (neighbour == 1)
	     	{
			   cell[CurrentCell.x][CurrentCell.y + 1].isWall = false;
			   cell[CurrentCell.x][CurrentCell.y + 2].isWall = false;
			   cell[CurrentCell.x][CurrentCell.y + 2].visited = true;
			   CellStack.push(make_pair(CurrentCell.x, CurrentCell.y+2));
			   CurrentCell.y += 2;
   			}
		   else if (neighbour == 2)
		   {
			   cell[CurrentCell.x][CurrentCell.y - 1].isWall = false;
			   cell[CurrentCell.x][CurrentCell.y - 2].isWall = false;
			   cell[CurrentCell.x][CurrentCell.y - 2].visited = true;
			   CellStack.push(make_pair(CurrentCell.x, CurrentCell.y - 2));
			   CurrentCell.y -= 2;
		   }
		   else if (neighbour == 3)
		   {
			   cell[CurrentCell.x-1][CurrentCell.y].isWall = false;
			   cell[CurrentCell.x-2][CurrentCell.y].isWall = false;
			   cell[CurrentCell.x-2][CurrentCell.y].visited = true;
			   CellStack.push(make_pair(CurrentCell.x-2, CurrentCell.y));
			   CurrentCell.x -= 2;
		   }
		   else if (neighbour == 4)
		   {
			   cell[CurrentCell.x + 1][CurrentCell.y].isWall = false;
			   cell[CurrentCell.x + 2][CurrentCell.y].isWall = false;
			   cell[CurrentCell.x + 2][CurrentCell.y].visited = true;
			   CellStack.push(make_pair(CurrentCell.x + 2, CurrentCell.y));
			   CurrentCell.x += 2;
		   }

		   else if (CurrentCell.x == 0 && CurrentCell.y == 0)
		   {
			   break;
		   }
		  else
		  {
			 CellStack.pop();
			 CurrentCell.x = CellStack.top().first;
			 CurrentCell.y = CellStack.top().second;
		
		 }
		  
	}
}
//::::::::::::::::::::::::::::::::::::::solution:::::::::::::::::::::::::::::::::::::::::::::::::::
int maze[128][72];
bool wasHere[128][72];
bool correctPath[128][72];
int startX = 0, startY = 0;

void IniSolution()
{
	for (int i = 0; i < nCells; i++)
	{
		for (int j = 0; j < mCells; j++)
		{
			wasHere[i][j] = false;
			correctPath[i][j] = false;
			cell[i][j].isWall ? maze[i][j] = 2 : maze[i][j] = 1;
		}
	}

}

bool recursiveSolve(int x, int y)
{
	if (x == endX&&y == endY)
		return true;
	if (maze[x][y] == 2 || wasHere[x][y])
		return false;
	wasHere[x][y] = true;
	if (x != 0)
	if (recursiveSolve(x - 1, y)) { 
		correctPath[x][y] = true; 
		return true;
	}
	if (x != nCells - 1) 
	if (recursiveSolve(x + 1, y)) { 
		correctPath[x][y] = true;
		return true;
	}
	if (y != 0)  
	if (recursiveSolve(x, y - 1)) { 
		correctPath[x][y] = true;
		return true;
	}
	if (y != mCells - 1) 
	if (recursiveSolve(x, y + 1)) { 
		correctPath[x][y] = true;
		return true;
	}
	return false;
}
void GetSolution()
{
	IniSolution();
	recursiveSolve(startX, startY);
}

void clearMaze()
{
	for (int i = 0; i < nCells; i++)
	for (int j = 0; j < mCells; j++)
	{
		cell[i][j].visitedByPlayer = false;
		cell[i][j].isWall = true;
		cell[i][j].visited = false;
		maze[i][j]=0;
		rect[i][j].setFillColor(sf::Color::White);
		correctPath[i][j] = false;
		startX = 0;
		startY = 0;
		endX = 0;
		endY = 0;
	}
}
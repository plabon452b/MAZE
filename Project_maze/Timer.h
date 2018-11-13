#include"SFML\graphics.hpp"
#include<math.h>
#define PI acos(-1)
using namespace std;
sf::RenderWindow myWindow(sf::VideoMode(1280, 720), "Maze");
char str[8];
int timerState = 0;
int timee = 0;
int previousTime = 0;
int totalTime;
int minutes;
int seconds;
int timerFlag = 1;
sf::Clock clk;
sf::Text timestr;
sf::Font timefont;
void sringconvert(int minitue, int second)
          {
	           str[0] = minitue + '0';
	           str[1] = ' ';
	           str[2] = ':';
	           str[3] = ' ';
	           str[4] = '0' + (second / 10);
	           str[5] = '0' + (second % 10);
         }

void loadTimer()
         {
             	timefont.loadFromFile("font.ttf");
	            timestr.setFont(timefont);
	            timestr.setPosition(sf::Vector2f(1150.0f, 100.0f));
         }
void pauseTimer()

        {
			    timerState = 0;
			    timerFlag = 1;
		}
		
void startTimer()
		{
	            clk.restart();
			    if (timerFlag)
			    {
				previousTime = 0;
				timerFlag = 0;

			    }
				timerState = 1;
		}
	
void showTimer(){
	if (timerState == 1)
	{
		timee = clk.getElapsedTime().asSeconds();
		if (previousTime + 1 == timee && totalTime>-1)
		{
			minutes = totalTime / 60;
			seconds = totalTime % 60;
			sringconvert(minutes, seconds);
			timestr.setString(str);
			myWindow.draw(timestr);
			totalTime--;
			previousTime++;
		}
		else
			myWindow.draw(timestr);
	}
}
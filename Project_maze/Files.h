#include<stdlib.h>
#include<stdio.h>
using namespace std;
sf::Text aboutText;
sf::Font aboutFont;
FILE  *Myfile;
FILE *about;
char ab[1000];
void file_io(int score, string name){
    Myfile=fopen("score_file.txt", "w");
	fprintf(Myfile,"%d  %s\n",score, name);
	fclose(Myfile);
 
}


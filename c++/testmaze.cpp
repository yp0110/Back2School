#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

//bool userVictory(char maze[][7]);
//bool compVictory(char maze[][7]);

enum Tile {CROSS = '+', HORIZONTAL = '-', VERTICAL = '|', LOCKED = 'X', EMPTY = ' '};
enum Color {RED, BLUE, BLACK};
/*string fileName;
        ofstream gameBoard;

        cout << "Enter the file name with the initial game board: " << flush;
        while (true)
        {
        getline(cin, fileName);
        gameBoard.open(fileName.c_str() );
        if (gameBoard) break;
        cout << "The file name you have entered does not exist" << flush;
        }

        if (gameBoard.is_open())
        {
                char maze[7][7];
                for (int i=1; i<8; i++)
                {
			for (int j=0; j<8; j++)
			{
                        	gameBoard >> array[i][j];
			}
                }
        }
*/
struct GamePieces
{
        char tile;
        char color;
        int laneIndex;
};

GamePieces** userGame(GamePieces** game);
GamePieces** compGame(GamePieces** game)

bool userVictory(GamePieces** game);
bool compVictory(GamePieces** game);

int main (void) {
GamePieces** game;
game=new GamePieces*[7];
//int line;
//char userChar;
//int currRowPos[rows] = {rows-1,rows-1,rows-1,rows-1,rows-1,rows-1,rows-1};
//int currColPos[cols] = {0,0,0,0,0,0,0};
bool victoryAchieved = false;


//reading file to intialize maze
//char fileName[256] = "input1.txt";
std::ifstream gameFile("input1.txt");

//char maze[7][7] = {{'X',' ','X',' ','X',' ','X'},{' ',' ',' ',' ',' ',' ',' '},{'X',' ','X',' ','X',' ','X'},{' ',' ',' ',' ',' ',' ',' '},{'X',' ','X',' ','X',' ','X'},{' ',' ',' ',' ',' ',' ',' '},{'X',' ','X',' ','X',' ','X'}};
//for(int i=0;i<rows;i++){
//for(int j=0;j<cols;j++){
//if(

printf("Initial maze\n");
for(int i=0;i<rows;i++) {
for(int j=0;j<cols;j++) {
printf("%c",maze[i][j]);
}
printf("\n");
}
while(!isWon){
printf("Enter the line: ");
scanf("%d",&line);
printf("\nEnter the character: ");
scanf(" %c",&userChar);
printf("currrowpos %d\n",currRowPos[line-1]);
printf("maze char %c\n",maze[currRowPos[line-1]][line-1]);
if(maze[currRowPos[line-1]][line-1] == 'X'){
printf("Locked\n");
}
else{
int temp;
for(int i=currRowPos[line-1];i<=6;i++) {
temp = maze[i][line-1];
//if(maze[i-1][line-1] == ' '){
maze[i-1][line-1] = temp;
//}
}
maze[rows-1][line-1] = userChar;
currRowPos[line-1] = currRowPos[line-1] - 1;
}

for(int i=0;i<rows;i++) {
for(int j=0;j<cols;j++) {
printf("%c",maze[i][j]);
}
printf("\n");
}
if(isUserWin(maze)) {
printf("Congrats, you WON!\n");
isWon = true;
break;
}


//Computer part
int compLine,compCharInt;
compLine = rand() % 7 + 1;
char compChar;
compCharInt = rand() % 3 + 1;
switch(compCharInt) {
case 1: compChar = '+';
break;
case 2: compChar = '-';
break;
case 3: compChar = '|';
break;
default:
break;
}
printf("currcolpos %d\n",currColPos[compLine-1]);
printf("maze char %c\n",maze[compLine-1][currColPos[compLine-1]]);
printf("comp line %d\n",compLine);
printf("comp char %c\n",compChar);
if(maze[compLine-1][currColPos[compLine-1]] == 'X'){
printf("Locked\n");
}
else{
int temp;
for(int i=currColPos[compLine-1];i>0;i--) {
temp = maze[compLine-1][i-1];
maze[compLine-1][i] = temp;
}
maze[compLine-1][0] = compChar;
currColPos[compLine-1] = currColPos[compLine-1] + 1;
}
for(int i=0;i<rows;i++) {
for(int j=0;j<cols;j++) {
printf("%c",maze[i][j]);
}
printf("\n");
}
if(isCompWin(maze)) {
printf("Ohoh! You lost!\n");
isWon = true;
break;
}
}
}

bool isUserWin(char maze[][7]) {
if(maze[0][1] != ' ' || maze[0][3] != ' ' || maze[0][5] != ' ') {
return true;
}
else
return false;
}

bool isCompWin(char maze[][7]) {
if(maze[1][6] != ' ' || maze[3][6] != ' ' || maze[5][6] != ' ') {
return true;
}
else
return false;
}


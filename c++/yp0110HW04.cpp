#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct TileStruct
        {
                char tileType;
                char color;
                int laneNum;
        };

TileStruct** userTurn(TileStruct** maze);

TileStruct** compTurn(TileStruct** maze);

bool isUserWin(TileStruct** maze);

bool isCompWin(TileStruct** maze);

enum TileType {CROSS = '+', HORIZONTAL = '-', VERTICAL = '|', LOCKED = 'X', EMPTY = ' '};
enum Color {RED, BLUE, BLACK};

int main (void){

cout << "**********************************************************" <<endl;
cout << "        Computer Science and Engineering                  " << endl;
cout << "        CSCE 1030 - Computer Science I                    " << endl;
cout << "   YashasviPalawat yp0110 yashasvipalawat@my.unt.edu      " << endl;
cout << "**********************************************************" << endl;

	int rows = 7;

	int cols = 7;

	bool isWon = false;

	TileStruct** maze;

	maze = new TileStruct*[7];


	char str[256] = "input1.txt";

	std::ifstream is(str);

	bool isRead = true;

	char ch;

	for(int i =0;i<7;i++){

		maze[i] = new TileStruct[7];
	}


	int i,j;

	i = 0;

	j = 0;

	while(is.get(ch)){

	if(ch == ','){

		continue;
	}

	else if(ch == '\n') {

		i++;

		j = 0;
	}

	else {

	//TileType enumTileType = LOCKED;

		maze[i][j].tileType = ch;

		maze[i][j].color = BLACK;

		j++;

		}
	}


	is.close();

printf("The Initial Maze structure\n");

	for(int i=0;i<rows;i++) {

		for(int j=0;j<cols;j++) {

		printf("%c",maze[i][j].tileType);
		}

		printf("\n");
	}

	while(!isWon){


	char** mazeUser;

	maze = userTurn(maze);


	if(isUserWin(maze)) {

	printf("Congratulations! You WON!\n");

	isWon = true;

	break;
	}


//Computer part

	char** mazeComp;

	maze = compTurn(maze);


	if(isCompWin(maze)) {

		printf("Uh! Bad Luck! You lost!\n");

		isWon = true;

		break;
	}
	}
	}


TileStruct** userTurn(TileStruct** maze) {

	int rows = 7;

	int cols = 7;

	int line;

	char userChar;

	int rowPos = -1;

		printf("Please choose a lane: 1-7 or type -1 to quit: ");

		scanf("%d",&line);

		printf("\nPlease choose a tile to add: -, |, or +: ");

		scanf(" %c",&userChar);


		for(int i=6;i>=0;i--) {

			if(maze[i][line - 1].tileType == ' ' || maze[i][line - 1].tileType == 'X') {

				rowPos = i;

			break;
		}
	}

	if(maze[rowPos][line-1].tileType == 'X'){

		printf("A locked tile is preventing the computer's tile from being added. Silly computer.\n");

	}

	else{

	//int temp;

		TileStruct temp;

			for(int i=rowPos+1;i<=6;i++) {

				temp = maze[i][line-1];

				maze[i-1][line-1] = temp;

			}

		maze[rows-1][line-1].tileType = userChar;

		Color col = RED;

		maze[rows-1][line-1].color = col;

	}


	return maze;
}



TileStruct** compTurn(TileStruct** maze) {

	int rows = 7;

	int cols = 7;

	int line;

	char userChar;

	int colPos = -1;

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

	for(int i=0;i<=6;i++) {

	        if(maze[compLine-1][i].tileType == ' ' || maze[compLine - 1][i].tileType == 'X') {
	                colPos = i;
                break;
        }
}

	if(maze[compLine-1][colPos].tileType == 'X'){

		printf("A locked tile is preventing the computer's tile from being added. Silly computer.\n");
	}

	else{

		TileStruct temp;

			for(int i=colPos-1;i>=0;i--) {

				temp = maze[compLine-1][i];

				maze[compLine-1][i+1] = temp;
			}

			maze[compLine-1][0].tileType = compChar;

			Color col = BLUE;

			maze[compLine-1][0].color = col;
		}

	for(int i=0;i<rows;i++) {

		for(int j=0;j<cols;j++) {

			if(maze[i][j].color == RED){

				printf("\033[1;31m%c\033[0m",maze[i][j].tileType);
		}

			else if(maze[i][j].color == BLUE) {

				printf("\033[1;34m%c\033[0m",maze[i][j].tileType);
		}

			else{

				printf("%c",maze[i][j].tileType);
			}
		}

				printf("\n");
		}

		return maze;
	}



bool isUserWin(TileStruct** maze) {

	if(maze[0][1].tileType != ' ' || maze[0][3].tileType != ' ' || maze[0][5].tileType != ' ') {

	return true;
}

	else

	return false;
}



bool isCompWin(TileStruct** maze) {

	if(maze[1][6].tileType != ' ' || maze[3][6].tileType != ' ' || maze[5][6].tileType != ' ') {

	return true;
}

	else

	return false;
}


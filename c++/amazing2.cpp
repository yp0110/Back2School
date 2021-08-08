#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

enum Tile {
	CROSS = '+', HORIZONTAL = '-', VERTICAL = '|', LOCKED = 'X', EMPTY = ' '
};

enum Color {
	RED, BLUE, BLACK
};

struct GamePieces {
	char tile;
	char color;
//int laneIndex;
};

//GamePieces** userGame(GamePieces** game);
//GamePieces** compGame(GamePieces** game);

//bool userVictory(GamePieces** game);
//bool compVictory(GamePieces** game);

int main(void) {
	GamePieces** game;
	game = new GamePieces*[7];
	bool victoryAchieved = false;

//reading file to intialize maze
	std::ifstream gameFile("input1.txt");
	for (int i = 0; i < 7; i++) {

		game[i] = new GamePieces[7];
	}
	char charac;
	int i = 0;
	int j = 0;

	while (gameFile.get(charac)) {
		if (charac == ',') {
			continue;
		} else if (charac == '\n') {
			i++;
			j = 0;
		} else {
//TileType enumTileType = LOCKED;
			game[i][j].tile = charac;
			game[i][j].color = BLACK;
			j++;
		}
	}

	gameFile.close();

	printf("Starting Maze\n");
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
		//	if (i == 0 || i == 8 || j == 0 || j == 8)
		//		printf("*");
		//	else
				printf("%c", game[i][j].tile);
		}
		printf("\n");
	}
//int line = 0;
//char userChar = 0;
	while (true) {

		//char** mazeUser;
		//game = userGame(game);
		int rows = 7;
		//int cols = 7;
		int line;
		char userChar;
		int rowPos = -1;

		printf("Enter the line: ");
		scanf("%d", &line);
		printf("\nEnter the character: ");
		scanf(" %c", &userChar);
		for (int i = 6; i >= 0; i--) {
			if (game[i][line - 1].tile == ' '
					|| game[i][line - 1].tile == 'X') {
				rowPos = i;
				break;
			}
		}

		if (game[rowPos][line - 1].tile == 'X') {
			printf("Locked\n");
		} else {
			GamePieces temp;
			for (int i = rowPos + 1; i <= 6; i++) {
				temp = game[i][line - 1];
				game[i - 1][line - 1] = temp;
			}
			game[rows - 1][line - 1].tile = userChar;
			Color col = RED;
			game[rows - 1][line - 1].color = col;
		}

		if (game[0][1].tile != ' ' || game[0][3].tile != ' '
				|| game[0][5].tile != ' ') {
			printf("User victory\n");
			//victoryAchieved = true;
			break;
		}

//Computer part
		//char** mazeComp;
		//game = compGame(game);
//		int rows = 7;
		//int cols = 7;
		//int line;
		//char userChar;
		int colPos = -1;

		int compLine, compCharInt;
		compLine = rand() % 7 + 1;
		char compChar;
		compCharInt = rand() % 3 + 1;
		switch (compCharInt) {
		case 1:
			compChar = '+';
			break;
		case 2:
			compChar = '-';
			break;
		case 3:
			compChar = '|';
			break;
		default:
			break;
		}

		for (int i = 0; i <= 6; i++) {
			if (game[compLine - 1][i].tile == ' '
					|| game[compLine - 1][i].tile == 'X') {
				colPos = i;
				break;
			}
		}

		if (game[compLine - 1][colPos].tile == 'X') {
			printf("Locked\n");
		} else {
			GamePieces temp;
			for (int i = colPos - 1; i >= 0; i--) {
				temp = game[compLine - 1][i];
				game[compLine - 1][i + 1] = temp;
			}
			game[compLine - 1][0].tile = compChar;
			Color col = BLUE;
			game[compLine - 1][0].color = col;
		}
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (game[i][j].color == RED) {
					printf("\033[1;31m%c\033[0m", game[i][j].tile);
				} else if (game[i][j].color == BLUE) {
					printf("\033[1;34m%c\033[0m", game[i][j].tile);
				} else {
					printf("%c", game[i][j].tile);
				}
			}
			printf("\n");
		}

		if (game[1][6].tile != ' ' || game[3][6].tile != ' '
				|| game[5][6].tile != ' ') {
			printf("Computer Victory\n");
			//victoryAchieved = true;
			break;
		}
	}
}

/*Computer part
 int compLine, compCharInt;
 compLine = rand() % 7 + 1;
 char compChar;
 compCharInt = rand() % 3 + 1;
 switch (compCharInt) {
 case 1:
 compChar = '+';
 break;
 case 2:
 compChar = '-';
 break;
 case 3:
 compChar = '|';
 break;
 default:
 break;
 }
 printf("currcolpos %d\n", currColPos[compLine - 1]);
 printf("maze char %c\n", maze[compLine - 1][currColPos[compLine - 1]]);
 printf("comp line %d\n", compLine);
 printf("comp char %c\n", compChar);
 if (maze[compLine - 1][currColPos[compLine - 1]] == 'X') {
 printf("Locked\n");
 } else {
 int temp;
 for (int i = currColPos[compLine - 1]; i > 0; i--) {
 temp = maze[compLine - 1][i - 1];
 maze[compLine - 1][i] = temp;
 }
 maze[compLine - 1][0] = compChar;
 currColPos[compLine - 1] = currColPos[compLine - 1] + 1;
 }
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
 printf("%c", maze[i][j]);
 }
 printf("\n");
 }
 if (isCompWin (maze)) {
 printf("Ohoh! You lost!\n");
 isWon = true;
 break;
 }
 }
 }

 bool isUserWin(char maze[][7]) {
 if (maze[0][1] != ' ' || maze[0][3] != ' ' || maze[0][5] != ' ') {
 return true;
 } else
 return false;
 }

 bool isCompWin(char maze[][7]) {
 if (maze[1][6] != ' ' || maze[3][6] != ' ' || maze[5][6] != ' ') {
 return true;
 } else
 return false;
 }
 */

/*
 * GamePieces** userGame(GamePieces** game) {
 int rows = 7;
 //int cols = 7;
 int line;
 char userChar;
 int rowPos = -1;

 printf("Enter the line: ");
 scanf("%d", &line);
 printf("\nEnter the character: ");
 scanf(" %c", &userChar);
 for (int i = 6; i >= 0; i--) {
 if (game[i][line - 1].tile == ' '
 || game[i][line - 1].tile == 'X') {
 rowPos = i;
 break;
 }
 }

 if (game[rowPos][line - 1].tile == 'X') {
 printf("Locked\n");
 } else {
 GamePieces temp;
 for (int i = rowPos + 1; i <= 6; i++) {
 temp = game[i][line - 1];
 game[i - 1][line - 1] = temp;
 }
 game[rows - 1][line - 1].tile = userChar;
 Color col = RED;
 game[rows - 1][line - 1].color = col;
 }
 return game;
 }

 GamePieces** compGame(GamePieces** game) {
 int rows = 7;
 int cols = 7;
 //int line;
 //char userChar;
 int colPos = -1;

 int compLine, compCharInt;
 compLine = rand() % 7 + 1;
 char compChar;
 compCharInt = rand() % 3 + 1;
 switch (compCharInt) {
 case 1:
 compChar = '+';
 break;
 case 2:
 compChar = '-';
 break;
 case 3:
 compChar = '|';
 break;
 default:
 break;
 }

 for (int i = 0; i <= 6; i++) {
 if (game[compLine - 1][i].tile == ' '
 || game[compLine - 1][i].tile == 'X') {
 colPos = i;
 break;
 }
 }

 if (game[compLine - 1][colPos].tile == 'X') {
 printf("Locked\n");
 } else {
 GamePieces temp;
 for (int i = colPos - 1; i >= 0; i--) {
 temp = game[compLine - 1][i];
 game[compLine - 1][i + 1] = temp;
 }
 game[compLine - 1][0].tile = compChar;
 Color col = BLUE;
 game[compLine - 1][0].color = col;
 }
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
 if (game[i][j].color == RED) {
 printf("\033[1;31m%c\033[0m", game[i][j].tile);
 } else if (game[i][j].color == BLUE) {
 printf("\033[1;34m%c\033[0m", game[i][j].tile);
 } else {
 printf("%c", game[i][j].tile);
 }
 }
 printf("\n");
 }
 return game;
 }

 bool userVictory(GamePieces** game) {
 if (game[0][1].tile != ' ' || game[0][3].tile != ' '
 || game[0][5].tile != ' ') {
 return true;
 } else
 return false;
 }

 bool compVictory(GamePieces** game) {
 if (game[1][6].tile != ' ' || game[3][6].tile != ' '
 || game[5][6].tile != ' ') {
 return true;
 } else
 return false;
 }*/

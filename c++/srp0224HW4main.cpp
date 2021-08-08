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
};
GamePieces** printMaze(GamePieces** game);

GamePieces** readFile(GamePieces** game);
GamePieces** playRound(GamePieces** game);
bool gameDecided(GamePieces** game);

int main(void) {
	GamePieces** game;
	game = new GamePieces*[7];

	//reading file to initialize maze
	game = readFile(game);

	printf("Starting Maze\n");
	game = printMaze(game);

	while (true) {

		game = playRound(game);

		//print current maze
		game = printMaze(game);
		if (gameDecided(game)) {
			break;
		}

	}
}


GamePieces** readFile(GamePieces** game) {
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
			game[i][j].tile = charac;
			game[i][j].color = BLACK;
			j++;
		}
	}

	gameFile.close();

	return game;
}

GamePieces** printMaze(GamePieces** game) {
	printf("*********\n");
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (j == 0)
				printf("*");

			if (game[i][j].color == RED)
				printf("\033[1;31m%c\033[0m", game[i][j].tile);
			else if (game[i][j].color == BLUE)
				printf("\033[1;34m%c\033[0m", game[i][j].tile);
			else
				printf("%c", game[i][j].tile);

			if (j == 6)
				printf("*");
		}

		printf("\n");
	}
	printf("*********\n");
	return game;
}

GamePieces** playRound(GamePieces** game) {

	int userLine;
	char userShape;
	int userRowPos = -1;
	int compColPos = -1;
	char compShape;
	int compLine, compCharInt;

//Reading user play
	printf("Enter the line or enter -1 to quit: ");
	scanf("%d", &userLine);
	if (userLine == -1) {
		printf("The game is over. The user has quit.\n");
		exit(0);
	}

	printf("\nEnter the shape: ");
	scanf(" %c", &userShape);

	//Generating computer play
	compLine = rand() % 7 + 1;
	compCharInt = rand() % 3 + 1;
	switch (compCharInt) {
	case 1:
		compShape = '+';
		break;
	case 2:
		compShape = '-';
		break;
	case 3:
		compShape = '|';
		break;
	default:
		break;
	}
	int i=6;
	while(i>=0) {
			if (game[i][userLine - 1].tile == ' ' || game[i][userLine - 1].tile == 'X') {
				userRowPos = i;
				break;
			}
			i--;
		}
	int j=0;
	while(j<=6) {
		if (game[compLine - 1][j].tile == ' '
				|| game[compLine - 1][j].tile == 'X') {
			compColPos = j;
			break;
		}
		j++;
	}

	if (game[userRowPos][userLine - 1].tile == 'X') {
			printf("Locked\n");
		} else {
			GamePieces temp;
			for (int i = userRowPos + 1; i <= 6; i++) {
				temp = game[i][userLine - 1];
				game[i - 1][userLine - 1] = temp;
			}
			game[7 - 1][userLine - 1].tile = userShape;
			Color col = RED;
			game[7 - 1][userLine - 1].color = col;
		}


	if (game[compLine - 1][compColPos].tile == 'X') {
		printf("Locked\n");
	} else {
		GamePieces temp;
		for (int i = compColPos - 1; i >= 0; i--) {
			temp = game[compLine - 1][i];
			game[compLine - 1][i + 1] = temp;
		}
		game[compLine - 1][0].tile = compShape;
		Color col = BLUE;
		game[compLine - 1][0].color = col;
	}

	return game;
}


bool gameDecided(GamePieces** game) {

	if (game[0][1].tile != ' ' || game[0][3].tile != ' '
			|| game[0][5].tile != ' ') {
		printf("User victory\n");
		return true;
	}
	if (game[1][6].tile != ' ' || game[3][6].tile != ' '
			|| game[5][6].tile != ' ') {
		printf("Computer Victory\n");
		return true;
	}

	return false;
}

	
 
 

  

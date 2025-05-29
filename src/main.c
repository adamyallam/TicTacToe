#include "../include/utils.h"
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
const char player = 'X';
const char computer = 'O';

void initializeBoard()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      board[i][j] = ' ';
    }
  }
}

void printBoard()
{
  printf("\n");
  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}

int checkFreeSpaces()
{
  int spaces = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == ' ')
      {
        spaces++;
      }
    }
  };
  return spaces;
}

void playerMove()
{
  int x;
  int y;

  while (1)
  {
    printf("make your move! (row #):\n");
    scanf("%d", &x);
    printf("(col #): \n");
    scanf("%d", &y);

    x--;
    y--;

    if (x < 3 && y < 3 && x >= 0 && y >= 0 && board[x][y] == ' ')
    {
      printf("Your move:\n");
      board[x][y] = 'X';
      break;
    }
    else
    {
      printf("Sorry, that space is already taken!\n");
    }
  }
}

void computerMove()
{
  int rowNumber;
  int colNumber;

  while (1)
  {
    rowNumber = (rand() % 3);
    colNumber = (rand() % 3);

    if (board[rowNumber][colNumber] == ' ')
    {
      printf("Computer just moved!\n");
      board[rowNumber][colNumber] = 'O';
      break;
    }
  }
}

char checkWinner()
{
  int spaces = checkFreeSpaces();

  if (spaces == 0)
  {
    return 'T';
  }

  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
    {
      return board[i][0];
    }
    else if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
    {
      return board[0][i];
    }
  }

  if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
  {
    return board[0][0];
  }
  else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
  {
    return board[0][2];
  }

  return 'N';
}

void printWinner()
{
  char winner = checkWinner();
  if (winner == 'X' || winner == 'O')
  {
    printf("player: %c won!", winner);
  }
  else if (winner == 'T')
  {
    printf("It's a tie!\n");
  }
}

int main()
{
  char winner;
  char playAgain;
  srand(time(NULL));

  do
  {
    initializeBoard();
    printBoard();

    do
    {
      playerMove();
      printBoard();

      winner = checkWinner();
      if (winner != 'N') break;

      computerMove();
      printBoard();
      winner = checkWinner();
    } while (winner == 'N');

    printf("game over!\n");

    if (winner == 'T')
    {
      printf("The game was a Tie!\n");
    }
    else
    {
      printf("The winner is, %c\n", winner);
    }

    do
    {
      printf("would you like to play again? (Y/N):\n");
      scanf(" %c", &playAgain);

      playAgain = toupper(playAgain);

      if (playAgain != 'Y' && playAgain != 'N')
      {
        printf("Sorry, please type either Y or N\n");
      }
    } while (playAgain != 'Y' && playAgain != 'N');

  } while (playAgain == 'Y');

  printf("Aw! sorry to see you go :(\n");

  return 0;
}
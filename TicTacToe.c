#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char ToFill[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
int turn = 0;
void welcome(char p1[20], char p2[20]);
void TicTacToe(void);
int Add_X_O(char choice);
int Finish(void);
int main(void) {
  int i, result;
  char choice, temp, p1[20], p2[20];
  welcome(p1, p2);
  do {
    TicTacToe();
    if(turn % 2 == 0)
      printf("\n\n\t\t%s, choose a letter: ", p1);
    else
      printf("\n\n\t\t%s, choose a letter: ", p2);
    scanf("%c", &choice);
    result = Add_X_O(choice);
    if(result == 0)
      printf("\n\t\tChoice Unavailable... Please try again!\n");
  } while(turn < 9 && Finish());
  system("clear");
  if(Finish())
    printf("\n\t\tThat's a draw!\n");
  else {
    if(turn % 2 == 0)
      printf("\n\t\t%s: You Won!\n", p2);
    else
      printf("\n\t\t%s: You Won!\n", p1);
  }
  return 0;
}
void welcome(char p1[20], char p2[20]) {
  system("clear");
  printf("\n\t\tWelcome to Harouak's TicTacToe. The best one out there ;)\n");
  printf("\n\t\tPlayer 1, Please enter your name: ");
  scanf("%s", p1);
  printf("\n\t\tPlayer 2, Please enter your name: ");
  scanf("%s", p2);
  printf("\n\t\tThank You and Good Luck!");
}
void TicTacToe(void) {
  system("clear");
  printf("\n\t\t%c\t|\t%c\t|\t%c", ToFill[0], ToFill[1], ToFill[2]);
  printf("\n\t\t------------------");
  printf("\n\t\t%c\t|\t%c\t|\t%c", ToFill[3], ToFill[4], ToFill[5]);
  printf("\n\t\t------------------");
  printf("\n\t\t%c\t|\t%c\t|\t%c", ToFill[6], ToFill[7], ToFill[8]);
}
int Add_X_O(char choice) {
  int i;
  for(i = 0; i < sizeof(ToFill) / sizeof(ToFill[0]); i++) {
    if(toupper(choice) == ToFill[i]) {
      if(turn % 2 == 0)
        ToFill[i] = 'X';
      else
        ToFill[i] = 'O';
      turn++;
      return 1;
    }
  }
  return 0;
}
int Finish(void) {
  if((ToFill[0] == ToFill[1] && ToFill[1] == ToFill[2]) || (ToFill[3] == ToFill[4] && ToFill[4] == ToFill[5]) || (ToFill[6] == ToFill[7] && ToFill[7] == ToFill[8]) || (ToFill[0] == ToFill[3] && ToFill[3] == ToFill[6]) || (ToFill[1] == ToFill[4] && ToFill[4] == ToFill[7]) || (ToFill[2] == ToFill[5] && ToFill[5] == ToFill[8]) || (ToFill[0] == ToFill[4] && ToFill[4] == ToFill[8]) || (ToFill[2] == ToFill[4] && ToFill[4] == ToFill[6]))
    return 0;
  return 1;
}

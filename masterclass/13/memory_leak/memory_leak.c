#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play(int bet);

int cash = 100;

int main() {
  // vazamento de memória é quando memória é alocada na heap, mas não é liberada quando terminada, ou seja, fica por ex: uma variável alocada, mas sem referência, perdida na heap
  // portanto a aplicação tá com uma memória não referenciada alocada 
  
  // Simple Betting Game
  // Jack Queen King - computer shuffles these cards
  // player has to guess  the position of queen
  // if he wins, he takes 3 * bet
  // if he looses, he looses the bet amount
  // player has $100 initially, and can play until runs out of cash
  int bet;
  printf("Welcome to the Virtual Casino\n");
  printf("Total cash = %d\n", cash);
  while(cash > 0) {
    printf("What's your bet? $");
    scanf("%d", &bet);
    if(bet == 0 || bet > cash) break;
    play(bet);
  }
  
  return 0;
}

void play(int bet) {
  // char c[3] = {'J', 'Q', 'K'};
  // o vazamento aqui aconteece porque, quando a função play() é chamada ela aloca uma variável *c e um bloco de memória na heap, porém como ela não desaloca o bloco de memória,
  // a variável *c desaloca pela stack, perde a referência, mas por falta do free() o bloco de memória da heap fica armazenado mesmo quando a função play termina
  // ou seja, se rodar o play() várias vezes, vai encher de bloco de memória na heap e vai aumentar o tamanho da memória que tá consumindo, e isso só porque o free() não foi usado
  // na stack dava certo, porque assim que a função play() acabava, a vida da variável c[] acabava também, desalocando automaticamente
  // char *c = (char *)malloc(10000 * sizeof(char)); // isso daqui faria MUITO vazamento de memória, mas com free, fica de boa
  char *c = (char *)malloc(3 * sizeof(char));
  c[0] = 'J';
  c[1] = 'Q';
  c[2] = 'K';
  printf("Shuffling...");
  srand(time(NULL)); // seeding
  for (int i = 0; i < 5; i++) {
    int x = rand() % 3;
    int y = rand() % 3;
    int temp = c[x];
    c[x] = c[y];
    c[y] = temp;
  }

  int players_guess;
  printf("What's the position of queen - 1, 2 or 3?");
  scanf("%d", &players_guess);

  if(c[players_guess - 1] == 'Q') {
    cash += 3 * bet;
    printf("You win! Result = %c%c%c Total cash = %d\n", c[0], c[1], c[2], cash);
  } else {
    cash -= bet;
    printf("You loose! Result = %c%c%c Total cash = %d\n", c[0], c[1], c[2], cash);
  }

  // free(c); // desalocar com free() resolveria o problema de vazamento de memória
}
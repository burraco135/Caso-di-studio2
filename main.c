#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void menu_iniziale(int opzione);

//prototipi funzioni
//int accedi(char nome[], int password);

int main(void) {
	unsigned int indice = 0;	
	menu_iniziale(indice);
	puts("> Programma chiuso correttamente! <");
  return 0;
}
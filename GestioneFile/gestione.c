#include "gestione.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum {
	matematica, italiano, storia, geografia, arte, inglese
} disciplina;

typedef enum {
	principiante, intermedio, avanzato
} livello;

typedef struct {
	char nome[15];
	char cognome[20];
	int disciplina;
	int livello;
} utente_t;

void CreaFileUtente(FILE *creaFileUtente) {

	if ((creaFileUtente = fopen("FileUtente.txt", "r")) == NULL) {
		puts("File corrotto o inesistente");
	} else {
		puts("File aperto.");
	}

	if (!fclose(creaFileUtente)) {
		puts("File chiuso.");
	}
}
	



//void AggiornaFile(FILE *aggiornaFile);
//void ModificaFile(FILE *modificaFile);
//void CancellaRecord(FILE *cancellaFile);
//void CreaRecord(FILE *recordFile);
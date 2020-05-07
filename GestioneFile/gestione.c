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
	int result = 0;
	FILE *creaFileU; // Puntatore al file Utente

	if ((creaFileU = fopen("FileUtente.txt", "w")) == NULL) {
		puts("!! File corrotto o non esistente.");
	  rewind(creaFileUtente); // Puntatore al primo elemento
		fprintf(creaFileU, "%-16s%-21s%-11s%-13s%\n", 
		"Nome", "Cognome", "Disciplina", "Livello");

		while (!feof(creaFileUtente)) {
			utente_t utente = {"", "", 0, 0};
			result = fread(&utente, sizeof(utente_t), 1, creaFileUtente);

			if (result != 0 && utente.disciplina != 0 && utente.livello != 0) {
				fprintf(creaFileU, "%-16s%-21s%-11s%-13s%\n", utente.nome, utente.cognome, utente.disciplina, utente.livello);
			} // Fine if
		} // Fine while
		fclose(creaFileU);
	} // Fine if
}







//void AggiornaFile(FILE *aggiornaFile);
//void ModificaFile(FILE *modificaFile);
//void CancellaRecord(FILE *cancellaFile);
//void CreaRecord(FILE *recordFile);
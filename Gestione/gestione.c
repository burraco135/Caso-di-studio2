#include <stdlib.h>
#include <stdio.h>
#include "gestione.h"
#define MAX_CH 10

typedef struct {
	int codice;
  char nome[MAX_CH];
  char cognome[MAX_CH];
  int disciplina;
  int livello;
} utente_t;

typedef struct {
  char titolo[MAX_CH];
	int livello;
	int disciplina;
	char autore[MAX_CH];
  char parola_chiave[MAX_CH];  
  int valutazione;
  int tipologia;
} risorsa_t;

void CreaUtente(FILE *fileUtente){
  utente_t utente = {0, "", "", 0, 0}; // Struct temporanea per l'input
	
  if ((fileUtente = fopen("FileUtente.csv","rb+")) == NULL) {
    puts("File corrotto o inesistente.");  
  } else {        
		puts("\nInserisci: Codice, Nome, Cognome, Disciplina e Livello");
    puts("Premi CTRL-Z per terminare.");
		printf("%s", ">> ");
		scanf("%d %19s %19s %d %d", &utente.codice, utente.nome, utente.cognome, &utente.disciplina, &utente.livello);
      
		while(!feof(stdin)){
			fseek(fileUtente, (utente.codice - 1) * sizeof(utente_t), SEEK_SET);
			fwrite(&utente, sizeof(utente_t), 1, fileUtente);
			printf("%s", ">> ");
			scanf("%d %19s %19s %d %d", &utente.codice, utente.nome, utente.cognome, &utente.disciplina, &utente.livello);
    } 
		puts("\n");
		fclose(fileUtente);
  }

	// Stampa
	if ((fileUtente = fopen("FileUtente.csv", "rb")) == NULL) {
		puts("File corrotto o inesistente");
	} else {
		rewind(fileUtente);
		printf("\n---------------------------------------------------------------------");
    printf("\n| %-8s | %-12s | %-12s | %-12s | %-9s |", "Codice", "Nome", "Cognome", "Disciplina", "Livello");
	
    
		while (!feof(fileUtente)) {
			fread(&utente, sizeof(utente_t), 1, fileUtente);
			if (!feof(fileUtente)) {
				printf("\n|-------------------------------------------------------------------|");
				printf("\n| %-8d | %-12s | %-12s | %-12d | %-9d |", utente.codice, utente.nome, utente.cognome, utente.disciplina, 
        utente.livello);
					
			}
		}
		printf("\n---------------------------------------------------------------------");
	fclose(fileUtente);
	}
}

void CreaRisorse(FILE *fileRisorse){
  risorsa_t risorsa = {"", 0, 0, "", "", 0, 0};
  if ((fileRisorse = fopen("FileRisorse.dat", "rb+")) == NULL) {
    puts("File corrotto o inesistente.");  
  } else {
    puts("Inserisci: Titolo, livello educativo, disciplina,\nautore, tipologia.");
    puts("Premi CTRL-Z per terminare.");
		printf("%s", "? ");
    scanf("%s %d %d %s %d", risorsa.titolo, &risorsa.livello, &risorsa.disciplina, risorsa.autore, &risorsa.tipologia);
    
		while (!feof(stdin)){   
      fprintf(fileRisorse,"%s %d %d %s %d\n", risorsa.titolo, risorsa.livello, risorsa.disciplina, risorsa.autore, risorsa.tipologia);
      printf("%s", "? ");
      scanf("%s %d %d %s %d", risorsa.titolo, &risorsa.livello, &risorsa.disciplina, risorsa.autore, &risorsa.tipologia);
    } // Fine while
  fclose(fileRisorse);
  } // Fine if
}

void EliminaUtente(FILE *fileUtente) {
	utente_t utente;
  utente_t utenteVuoto = {0, "", "", 0, 0};
	int codice = 0; //indica il codice dell'utente da eliminare

	if ((fileUtente = fopen("FileUtente.csv", "rb+")) == NULL) {
		puts("File corrotto o inesistente");
	} else {
		do {
			printf("Inserisci il codice da cancellare: ");
			scanf("%d", &utente.codice);

			if (!feof(stdin)) {
				fseek(fileUtente, (utente.codice - 1) * sizeof(utente_t), SEEK_SET);
				fread(&utente, sizeof(utente_t), 1, fileUtente);
        
				if (!feof(fileUtente) && utente.codice != 0) {								
					fseek(fileUtente, (utente.codice - 1) * sizeof(utente_t), SEEK_SET);
					fwrite(&utenteVuoto, sizeof(utente), 1, fileUtente);
					puts("Utente cancellato");
          
				} else {
					puts("Codice non trovato");
				}
			} 
		} while (!feof(stdin));
    //puts("\nPremi [1] per eliminare un utente\nPremi [2] per modificare un utente\nPremi [3] per creare un utente\nPremi [4] per disconnetterti");

		fclose(fileUtente);  
  } // Fine if
}

void ModificaUtente(FILE *fileUtente) {
	utente_t utente;
  if ((fileUtente = fopen("FileUtente.csv", "rb+")) == NULL) {
		puts("File corrotto o inesistente");
	} else {
    puts("\nCodice\tNome\tCognome\tDisciplina\tLivello");
      
    while (!feof(fileUtente)) {
      utente_t utente = {0, "", "", 0, 0};
      int result = fread(&utente, sizeof(utente_t), 1, fileUtente);

      if (result != 0 && utente.codice != 0) {
        printf("%d\t%s\t%s\t%d\t%d\n", utente.codice, utente.nome, utente.cognome, utente.disciplina, utente.livello);
      } // Stampa il file
    }	// Fine while	

    puts("Inserisci il codice dell'utente da modificare: ");
    unsigned int codice = 0;
    //utente_t utente = {0, "", "", 0, 0};

    scanf("%d", &codice);

    fseek(fileUtente, (codice - 1) * sizeof(utente_t), SEEK_SET);  
    fread(&utente, sizeof(utente_t), 1, fileUtente);

    if(utente.codice == 0) { //esiste il codice ricercato?
      printf("Codice utente n.%d non trovato.", codice);
    } else { //modifica altrimenti
      printf("%-d%-s%-s%-d%-d\n\n", utente.codice, utente.nome, utente.cognome, utente.disciplina, utente.livello);

      puts("Ora inserisci i nuovi valori dell'utente scelto.");
      printf("Nome --> " );
      scanf("%s", utente.nome);
      printf("Cognome --> " );
      scanf("%s", utente.cognome);
      printf("Disciplina --> " );
      scanf("%d", &utente.disciplina);
      printf("Livello Educativo --> " );
      scanf("%d", &utente.livello);

      //printf("%-d%-s%-s%-d%-d\n\n",utente.codice, utente.nome, utente.cognome, utente.disciplina, utente.livello);

      fseek(fileUtente, (codice - 1) * sizeof(utente_t), SEEK_SET);
      fwrite(&utente, sizeof(utente_t), 1, fileUtente);
    }
		fclose(fileUtente);
  }
}
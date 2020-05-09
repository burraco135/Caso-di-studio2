#include "menu.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_CH 20

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

void CreaUtente(FILE *fileUtente);
void EliminaUtente(FILE *fileUtente);
void ModificaUtente(FILE *fileUtente);
void CreaRisorse(FILE *fileRisorse);
void ModificaRisorse(FILE *fileRisorse);


void menu_iniziale(int opzione) { 
	int status = 0; // Controlla l'input

	puts("\n\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("\t+                                                      +");
	puts("\t+ Benvenuto nel programma 'Risorse Didattiche Online'! +");
	puts("\t+                                                      +");
	puts("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  puts("\nPremi [1] se se sei un utilizzatore\nPremi [2] se sei un Creatore\nPremi [3] se sei un amministratore\nPremi [4] per uscire dal programma\n");
	
	while(status != 1) { 	// Aspetta che status diventi 1
	printf("--> ");
		scanf("%d", &opzione);	// Acquisisce l'input

		switch(opzione) {	// Scelte menù iniziale
		case 1:
			puts("\n> Caricamento menù utilizzatore...");
			menu_utilizzatore(opzione);
			puts("\nPremi [1] se se sei un utilizzatore\nPremi [2] se sei un Creatore\nPremi [3] se sei un amministratore\nPremi [4] per uscire dal programma\n");
			break;
		case 2:
			puts("\n> Caricamento menù creatore...");
			menu_creatore(opzione);
			puts("\nPremi [1] se se sei un utilizzatore\nPremi [2] se sei un Creatore\nPremi [3] se sei un amministratore\nPremi [4] per uscire dal programma\n");
			break;
		case 3:
		 	puts("\n> Caricamento menù amministratore...");
			menu_amministratore(opzione);
			puts("\nPremi [1] se se sei un utilizzatore\nPremi [2] se sei un Creatore\nPremi [3] se sei un amministratore\nPremi [4] per uscire dal programma\n");
			break;
		case 4:
			puts("\n> Uscita in corso...");
			status = 1; // return 0; -> FINE
			break;
    default:
      puts("Valore inserito non valido! Inserisci di nuovo l'opzione: ");
			getchar();
		} // Fine switch
	} // Fine while
} // Fine menu_iniziale

void menu_utilizzatore(int opzione) {
	int status = 0, accesso = 0;
	char nome_utente[MAX_CH] = "";
	int password = 0;

	puts("Inserisci nome utente e password.");
	puts("Nome utente: ");
	scanf("%9s", nome_utente);
	puts("Password: ");
	scanf("%d", &password);
	//accesso = accedi(nome_utente, password); // Controlla i dati di accesso

	puts("\nPremi [1] per cercare risorse didattiche\nPremi [2] per leggere le statistiche\nPremi [3] per ordinare le risorse\nPremi [4] per disconnetterti\n");
	if (accesso == 0) {	//FIXME 
		while (status != 1) {
			printf("--> ");
			scanf("%d", &opzione);
			switch(opzione) {
				case 1:
					puts("> Ricerca risorse didattiche...");
					break;
				case 2:
					puts("> Lettura statistiche...");
					break;
				case 3:
					puts("> Ordinamento risorse...");
					break;
				case 4:
					puts("> Disconnessione account in corso...");
					status = 1;
					break;
				default:
					puts(" !-> Valore inserito non valido! Inserisci di nuovo l'opzione: ");
					getchar();			
			}	// Fine switch
		} // Fine while
	} // Fine if
} // Fine menu_utilizzatore

void menu_creatore(int opzione) {
  FILE *ptrRisorse;
	int status = 0, accesso = 0;
	char nome_utente[10] = "";
	int password = 0;

	puts("\nPremi [1] per gestire le risorse\nPremi [2] per leggere le statistiche\nPremi [3] per ordinare le risorse\nPremi [4] per disconnetterti");
	if (accesso == 0) {	// FIXME
		while (status != 1) {
			printf("--> ");
			scanf("%d", &opzione);
			switch (opzione) {
				case 1:
					puts("> Gestione risorse...");
					CreaRisorse(ptrRisorse);
					puts("\nPremi [1] per gestire le risorse\nPremi [2] per leggere le statistiche\nPremi [3] per ordinare le risorse\nPremi [4] per disconnetterti");
					break;
				case 2:
					puts("> Lettura statistiche...");
					// Funzione statistiche
					puts("\nPremi [1] per gestire le risorse\nPremi [2] per leggere le statistiche\nPremi [3] per ordinare le risorse\nPremi [4] per disconnetterti");
					break;
				case 3:
					puts("> Ordinamento risorse...");
					// Funzione Ordinamento
					puts("\nPremi [1] per gestire le risorse\nPremi [2] per leggere le statistiche\nPremi [3] per ordinare le risorse\nPremi [4] per disconnetterti");
					break;
				case 4:
					puts("> Disconnessione in corso...");
					status = 1;
					break;
				default:
					puts(" !-> Valore inserito non valido! Inserisci di nuovo l'opzione: ");
					getchar();		
			} // Fine switch
		} // Fine while
	} // Fine if
} // Fine menu_creatore

void menu_amministratore(int opzione) {
	FILE *ptrUtente;
	int status = 0, accesso = 0;
	char nome_utente[10] = "";
	int password = 0;

	puts("\nPremi [1] per eliminare un utente\nPremi [2] per modificare un utente\nPremi [3] per creare un utente\nPremi [4] per disconnetterti\n");
	if (accesso == 0) {
		while (status != 1) {
			printf("--> ");
			scanf("%d", &opzione);
			switch(opzione) {
				case 1:
					puts("\n> Elimina utente...");
					EliminaUtente(ptrUtente);
					puts("\nPremi [1] per eliminare un utente\nPremi [2] per modificare un utente\nPremi [3] per creare un utente\nPremi [4] per disconnetterti\n");    
					// TODO
					break;
				case 2:
					puts("\n> Modifica utente...");
					ModificaUtente(ptrUtente);
					puts("\nPremi [1] per eliminare un utente\nPremi [2] per modificare un utente\nPremi [3] per creare un utente\nPremi [4] per disconnetterti\n");    
					break;
				case 3:
					puts("\n> Crea utente...");
					CreaUtente(ptrUtente);    
          puts("\n\nPremi [1] per eliminare un utente\nPremi [2] per modificare un utente\nPremi [3] per creare un utente\nPremi [4] per disconnetterti\n");       				
					break;
				case 4:
				 	puts("\n> Disconnessione in corso...");
					 status = 1;
					 break;
				default:
					puts("\n!-> Valore inserito non valido! Inserisci di nuovo l'opzione: ");
					getchar();		
			}// Fine switch
		} // Fine while
	} // Fine if
} // Fine menu_amministratore
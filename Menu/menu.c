#include "menu.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_CH 20

typedef struct {
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
void CreaRisorse(FILE *fileRisorse);
void EliminaUtente(FILE *fileUtente);

void menu_iniziale(int opzione) { 
	int status = 0; // Controlla l'input

	puts("\n\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	puts("\t|                                                      |");
	puts("\t| Benvenuto nel programma 'Risorse Didattiche Online'! |");
	puts("\t|                                                      |");
	puts("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  puts("\nPremi [1] se se sei un utilizzatore\nPremi [2] se sei un Creatore\nPremi [3] se sei un amministratore\nPremi [4] per uscire dal programma");
	
	while(status != 1) { 	// Aspetta che status diventi 1
		scanf("%d", &opzione);	// Acquisisce l'input

		switch(opzione) {	// Scelte menù iniziale
		case 1:
			puts("> Caricamento menù utilizzatore...");
			menu_utilizzatore(opzione);
			puts("\nPremi [1] se se sei un utilizzatore\nPremi [2] se sei un Creatore\nPremi [3] se sei un amministratore\nPremi [4] per uscire dal programma");
			break;
		case 2:
			puts("> Caricamento menù creatore...");
			menu_creatore(opzione);
			puts("\nPremi [1] se se sei un utilizzatore\nPremi [2] se sei un Creatore\nPremi [3] se sei un amministratore\nPremi [4] per uscire dal programma");
			break;
		case 3:
		 	puts("> Caricamento menù amministratore...");
			menu_amministratore(opzione);
			puts("\nPremi [1] se se sei un utilizzatore\nPremi [2] se sei un Creatore\nPremi [3] se sei un amministratore\nPremi [4] per uscire dal programma");
			break;
		case 4:
			puts("> Uscita in corso...");
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

	puts("Premi [1] per cercare risorse didattiche\nPremi [2] per leggere le statistiche\nPremi [3] per ordinare le risorse\nPremi [4] per disconnetterti");
	if (accesso == 0) {	//FIXME 
		while (status != 1) {
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
  FILE *fRisorse;
	int status = 0, accesso = 0;
	char nome_utente[10] = "";
	int password = 0;

	puts("Premi [1] per gestire le risorse\nPremi [2] per leggere le statistiche\nPremi [3] per ordinare le risorse\nPremi [4] per disconnetterti");
	if (accesso == 0) {	// FIXME
		while (status != 1) {
			scanf("%d", &opzione);
			switch (opzione) {
				case 1:
					puts("> Gestione risorse...");
					CreaRisorse(fRisorse);
					break;
				case 2:
					puts("> Lettura statistiche...");
					break;
				case 3:
					puts("> Ordinamento risorse...");
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
	FILE *fUtente;
	int status = 0, accesso = 0;
	char nome_utente[10] = "";
	int password = 0;

	puts("Premi [1] per eliminare un utente\nPremi [2] per modificare un utente\nPremi [3] per creare un utente\nPremi [4] per disconnetterti");
	if (accesso == 0) {
		while (status != 1) {
			scanf("%d", &opzione);
			switch(opzione) {
				case 1:
					puts("> Elimina utente...");
					EliminaUtente(fUtente);
					// TODO
					break;
				case 2:
					puts("> Modifica utente...");
					break;
				case 3:
					puts("> Crea utente...");
					CreaUtente(fUtente);    
          puts("\nPremi [1] per eliminare un utente\nPremi [2] per modificare un utente\nPremi [3] per creare un utente\nPremi [4] per disconnetterti");       				
					break;
				case 4:
				 	puts("> Disconnessione in corso...");
					 status = 1;
					 break;
				default:
					puts(" !-> Valore inserito non valido! Inserisci di nuovo l'opzione: ");
					getchar();		
			}// Fine switch
		} // Fine while
	} // Fine if
} // Fine menu_amministratore

void CreaUtente(FILE *fileUtente){
  utente_t utente = {"","",0,0};
  if((fileUtente = fopen("FileUtente.txt","a+"))==NULL) {
    puts("File corrotto o inesistente.");  
  } else {
    puts("Inserisci: Nome, Cognome, Disciplina e Livello");
    puts("Premi CTRL-Z per terminare.");
		printf("%s", "? ");
    scanf("%s %s %d %d", utente.nome, utente.cognome, &utente.disciplina, &utente.livello);

		while(!feof(stdin)){   
			
      fprintf(fileUtente,"%s %s %d %d\n", utente.nome, utente.cognome, utente.disciplina, utente.livello);
      printf("%s", "? ");
      scanf("%s %s %d %d", utente.nome, utente.cognome, &utente.disciplina, &utente.livello);      
    } 
  fclose(fileUtente);
  }
}

void CreaRisorse(FILE *fileRisorse){
  risorsa_t risorsa = {"", 0, 0, "", "", 0, 0};
  if((fileRisorse = fopen("FileRisorse.txt","a+"))==NULL) {
    puts("File corrotto o inesistente.");  
  } else {
    puts("Inserisci : Titolo, livello educativo, disciplina,\nautore, tipologia ");
    puts("Premi CTRL-Z per terminare.");
		printf("%s", "? ");
    scanf("%20s %d %d %s %d", risorsa.titolo, &risorsa.livello, &risorsa.disciplina, risorsa.autore, &risorsa.tipologia);

		while(!feof(stdin)){   
			
      fprintf(fileRisorse,"%s %d %d %s %d\n", risorsa.titolo, risorsa.livello, risorsa.disciplina, risorsa.autore, risorsa.tipologia);
      printf("%s", "? ");
      scanf("%s %d %d %s %d", risorsa.titolo, &risorsa.livello, &risorsa.disciplina, risorsa.autore, &risorsa.tipologia);
    } 
  fclose(fileRisorse);
  }
}

void EliminaUtente(FILE *fileUtente) {

}
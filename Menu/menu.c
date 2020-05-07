#include "menu.h"
#include <stdlib.h>
#include <stdio.h>

void menu_iniziale(int opzione) { 
	int status = 0; // Controlla l'input

	puts("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
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
			status = 1;
			break;
		case 2:
			puts("> Caricamento menù creatore...");
			menu_creatore(opzione);
			status = 1;
			break;
		case 3:
		 	puts("> Caricamento menù amministratore...");
			menu_amministratore(opzione);
		 	status = 1;
			break;
		case 4:
			puts("> Uscita in corso...");
			status = 1;
			break;
    default:
      puts("Valore inserito non valido! Inserisci di nuovo l'opzione: ");
			getchar();	
		} // Fine switch
	} // Fine while
} // Fine menu_iniziale

void menu_utilizzatore(int opzione) {
	int status = 0, accesso = 0;
	char nome_utente[10] = "";
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
					status = 1;
					break;
				case 2:
					puts("> Lettura statistiche...");
					status = 1;
					break;
				case 3:
					puts("> Ordinamento risorse...");
					status = 1;
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
					status = 1;
					break;
				case 2:
					puts("> Lettura statistiche...");
					status = 1;
					break;
				case 3:
					puts("> Ordinamento risorse...");
					status = 1;
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
					status = 1;
					break;
				case 2:
					puts("> Modifica utente...");
					status = 1;
					break;
				case 3:
					puts("> Crea utente...");
					status = 1;
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

/*
			Libreria menu.h
		Questa libreria contiene procedure con menù predefiniti.
		Contenuto:
		(1) Menù generico di accesso per 3 tipologie di utenti
		(2) Menù generico per utenti
		(3) Menù generico per creatori
		(4) Menù generico per amministratori
		(5) Sottomenù generico per ulteriori opzioni
*/

#ifndef MENU_H_SEEN
#define MENU_H_SEEN

void menu_iniziale(int opzione);
void menu_utilizzatore(int opzione);
void menu_creatore(int opzione);
void menu_amministratore(int opzione);

#endif
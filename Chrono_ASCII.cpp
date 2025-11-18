#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

// Tableau global output de 11x11 caractères
char output[11][11];

// Structure pour stocker l'état du chrono
struct Chrono {
	float time; // Temps écoulé en secondes
};

// Fonction pour initialiser le tableau output
void InitializeOutput() {
	// Remplir le tableau de caractères '-'
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			output[i][j] = '-';
		}
	}
	
	// Écrire 'X' en position centrale (5,5)
	output[5][5] = 'X';
	
	// Écrire '|' en positions (1,5) à (4,5)
	// (colonnes 5, lignes 1 à 4)
	for (int i = 1; i <= 4; i++) {
		output[i][5] = '|';
	}
}

// Fonction pour afficher le tableau output
void DisplayOutput() {
	// Déclarer et remplir une chaîne de caractères correspondant au texte à afficher
	std::string displayText = "";
	
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			displayText += output[i][j];
		}
		displayText += "\n"; // Ajouter un retour à la ligne après chaque ligne du tableau
	}
	
	// Un seul appel à std::cout pour afficher la chaîne complète
	std::cout << displayText;
}

void ResetDisplay() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {0, 0};
	SetConsoleCursorPosition(hConsole, pos);
	// Réinitialiser également le contenu du tableau
	InitializeOutput();
}

// Fonction pour écrire '0' en fonction de l'avancement de la seconde
void WriteSecond(Chrono& chrono) {
	// Calculer la position X basée sur l'avancement de la seconde
	int posX = ((int)(chrono.time * 11)) % 11;
	
	// Écrire '0' à la position {posX, 0}
	output[0][posX] = '0';
}

int main() {

	// Récupérer la durée du timer (en secondes)
	float duration = 0.0f;
	std::cout << "Entrez la duree du timer (en secondes) : ";
	std::cin >> duration;

	if (duration < 1) {
		std::cout << "Comment veux-tu qu'un chrono commence avec un temps inferieur à 1 seconde. Recommence" << std::endl;
		return 1;
	}

	// Déclarer le temps de départ
	float startTime = (float)clock() / (float)CLOCKS_PER_SEC;

	std::cout << "\nTimer lance! Le timer va s'arreter apres " << duration << " secondes." << std::endl;
	std::cout << "\n";

	// Créer une structure Chrono
	Chrono chrono;
	chrono.time = 0.0f;

	// Boucle du timer
	bool running = true;
	system("cls");
	while (running) {
		// Calculer le temps écoulé
		float currentTime = (float)clock() / (float)CLOCKS_PER_SEC;
		float elapsedTime = currentTime - startTime;
		
		// Mettre à jour le temps dans la structure Chrono
		chrono.time = elapsedTime;
		
		// réinitialise la position du curseur en positon 0,0
		ResetDisplay();
		
		// Écrire le '0' qui avance selon les secondes
		WriteSecond(chrono);

		// Afficher le tableau
		DisplayOutput();
		
		// Calculer le temps restant
		float remainingTime = duration - elapsedTime;

		// Vérifier si le timer est terminé
		if (remainingTime <= 0) {
			std::cout << "\nFin du chrono ! [^_^]" << std::endl;
			running = false;
			continue;
		}

		// Convertir en minutes, secondes, centièmes
		int minutes = (int)remainingTime / 60;
		int seconds = (int)remainingTime % 60;
		int centiseconds = (int)((remainingTime - (int)remainingTime) * 100);


		// Vérifier si une touche est enfoncée (pour arrêt manuel)
		if (_kbhit()) {
			_getch(); // Consommer la touche
			std::cout << "\n\nTimer arrete manuellement." << std::endl;
			running = false;
		}

		// Petit délai pour éviter une utilisation CPU excessive
		Sleep(10);
	}
	return 0;
}
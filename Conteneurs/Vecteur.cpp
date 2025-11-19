#include <vector>
#include <iostream>

// Demande un nombre de joueurs pour un jeu

int main() {
	int numPlayers;

	std::cout << "Entrez le nombre de joueurs : ";
	std::cin >> numPlayers;

	std::vector<int> myVector(numPlayers, 0); // Initialisation du vecteur avec des zéros

	//  Calculer la taille du plateau : 10 + 2*nombre de joueurs
	int boardSize = 10 + 2 * numPlayers;

	// Créer un vecteur 2D pour le plateau de jeu
	// Chaque élément contient une valeur bool initialisée à false
	std::vector<std::vector<bool>> gameBoard(boardSize, std::vector<bool>(boardSize, false));

	//ajout d'un joueur
	numPlayers++;
	myVector.push_back(0); // Ajoute un joueur avec un score initial de 0

	// Redimensionner le plateau de jeu en fonction du nouveau nombre de joueurs
	int newSize = 10 + 2 * numPlayers;
	gameBoard.resize(newSize);
	for (auto& row : gameBoard) {
		row.resize(newSize, false);
	}

	return 0;
}
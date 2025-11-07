#include <iostream>

// Programme très simple montrant une boucle de tours entre deux joueurs.
// Trois fonctions A, B et C s'appellent en chaîne pour simuler un tour :
// - A : début du tour pour un joueur donné
// - B : action du joueur et changement d'identifiant du joueur
// - C : fin du tour, décrémente le nombre de tours restants et relance A si
//       des tours restent

// Déclarations de fonctions (prototypes)
void StartTurn(int remainingTurn, int playerId);
void playAndSwitch(int &playerId);
void endTurn(int &remainingTurn);

int main(){
	// Nombre initial de tours à jouer
	int remainingTurn = 5;
	// Identifiant du joueur courant (0 ou 1)
	int playerId = 0;	

	//boucle 	
	while(remainingTurn > 0) {
		StartTurn(remainingTurn, playerId);
		playAndSwitch(playerId);
		endTurn(remainingTurn);
	}
	
	return 0;
}

// A : affiche le début du tour pour le joueur courant puis appelle B
void StartTurn(int remainingTurn, int playerId) {
	// Affiche quel joueur commence son tour
	std::cout << "Starting turn for player : " << playerId << "." <<
	std::endl;
	// Passe au traitement de l'action du joueur
}

// B : simule le fait que le joueur a joué, change le joueur courant, appelle C
void playAndSwitch(int &playerId) {
	std::cout << "Player " << playerId << " has played. Switching player."
	<< std::endl;
	// Alterne l'identifiant du joueur entre 0 et 1
	playerId = (playerId+1)%2;
	// Appel de fin de tour
}

// C : décrémente le compteur de tours, affiche le nombre de tours restants
// et relance la séquence si des tours restent
void endTurn(int &remainingTurn) {
	--remainingTurn; // un tour vient de se terminer
	std::cout << "End of turn. " << remainingTurn << " turns left." <<
	std::endl;
}
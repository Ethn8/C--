#include <iostream>
#include <windows.h>  // Pour SetConsoleOutputCP

struct Coordinate
{
	int i;
	int j;
};

// Fonction qui trouve la direction de la case adjacente avec la plus grande valeur
Coordinate FindHighestAdjacent(int tab[][5], int size, int i, int j);
// Fonction qui modifie la valeur d'une case du tableau en vérifiant les limites
bool SetValue(int tab[][5], int size, int i, int j, int newValue);
// Fonction qui affiche l'état actuel du tableau
void PrintGrid(int tab[][5], int size);
// Fonction récursive qui trouve un chemin en suivant les plus grandes valeurs adjacentes
void FindPath(int tab[][5], int size, Coordinate pos, int remainingMoves);

int main()
{
    // Configuration de la console pour afficher les caractères UTF-8
    SetConsoleOutputCP(CP_UTF8);
    
    Coordinate start = {2, 2};
    int tab[5][5] = {
        {0, 8, 7, 1, 5},
        {3, 5, 2, 8, 9},
        {0, 4, 0, 1, 0},
        {2, 4, 3, 6, 1},
        {1, 4, 3, 1, 0}
    };

    std::cout << "État initial du tableau :" << std::endl;
    PrintGrid(tab, 5);

    std::cout << "Début de la recherche de chemin depuis (" << start.i << "," << start.j 
              << ") avec un maximum de 10 déplacements." << std::endl;
    
    FindPath(tab, 5, start, 10);

    std::cout << "État final du tableau (les 0 représentent le chemin parcouru) :" << std::endl;
    PrintGrid(tab, 5);

    return 0;
}

Coordinate FindHighestAdjacent(int tab[][5], int size, int i, int j)
{
    // Directions possibles : haut, droite, bas, gauche
    const Coordinate directions[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    Coordinate bestDirection = {0, 0};
    int maxValue = -1; // Valeur minimale pour initialisation

    // Parcourir les 4 directions
    for (int dir = 0; dir < 4; dir++)
    {
        int newI = i + directions[dir].i;
        int newJ = j + directions[dir].j;

        // Vérifier si la nouvelle position est dans les limites du tableau
        if (newI >= 0 && newI < size && newJ >= 0 && newJ < size)
        {
            // Si la valeur trouvée est plus grande que la précédente
            if (tab[newI][newJ] > maxValue)
            {
                maxValue = tab[newI][newJ];
                bestDirection = directions[dir];
            }
        }
    }

    return bestDirection;
}

// Implémentation de SetValue : retourne true si la modification a réussi
bool SetValue(int tab[][5], int size, int i, int j, int newValue)
{
    if (i < 0 || i >= size || j < 0 || j >= size) {
        return false; // indices hors limites
    }
    tab[i][j] = newValue;
    return true;
}

// Affiche le tableau de manière formatée
void PrintGrid(int tab[][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << tab[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Implémentation de FindPath
void FindPath(int tab[][5], int size, Coordinate pos, int remainingMoves) {
    // Afficher la position courante
    std::cout << "Position actuelle: (" << pos.i << "," << pos.j << ")" << std::endl;
    
    // Conditions d'arrêt
    if (remainingMoves <= 0) {
        std::cout << "Nombre maximal de déplacements atteint." << std::endl;
        return;
    }

    // Trouver la direction de la plus grande valeur adjacente
    Coordinate direction = FindHighestAdjacent(tab, size, pos.i, pos.j);
    int nextI = pos.i + direction.i;
    int nextJ = pos.j + direction.j;
    
    // Vérifier si une case adjacente non nulle existe
    if (nextI >= 0 && nextI < size && nextJ >= 0 && nextJ < size && 
        tab[nextI][nextJ] > 0) {
        
        // Marquer la case courante comme visitée
        SetValue(tab, size, pos.i, pos.j, 0);
        
        // Afficher l'état du tableau après le déplacement
        std::cout << "Tableau après déplacement :" << std::endl;
        PrintGrid(tab, size);
        
        // Créer la nouvelle position
        Coordinate nextPos = {nextI, nextJ};
        
        // Continuer le chemin récursivement
        FindPath(tab, size, nextPos, remainingMoves - 1);
    } else {
        std::cout << "Chemin terminé : toutes les cases adjacentes sont nulles." << std::endl;
        return;
    }
}
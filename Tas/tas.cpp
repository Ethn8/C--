#include <iostream>

void pointeur () {

	/*A partir du code ci - dessous :
	● Afficher les valeurs contenues dans les variables “a”, “b”, “pa” et “pb”.
	● Afficher les valeurs des variables pointées par les pointeurs “pa” et “pb”(“*pa” et “*pb”)
	● A l’aide de “pc”, échanger les adresses mémoires contenues dans les variables pointeurs “pa” et “pb”.
	● Afficher de nouveau les valeurs contenues dans les variables “a”, “b”, “pa” et “pb”.
	● Afficher de nouveau les valeurs des variables pointées par les pointeurs “pa” et “pb”*/

	int a = 5;
	int *pa = &a;
	int b = 10;
	int *pb = &b;
	int *pc = nullptr;

	//afficher les valeurs contenues dans "a", "b", "pa", "pb".
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "pa = " << pa << std::endl;
	std::cout << "pb = " << pb << std::endl;

	// Afficher les valeurs pointées par "pas" et "pb".
	std::cout << "*pa = " << *pa << std::endl;
	std::cout << "*pb = " << *pb << std::endl;

	// Échanger les adresses contenues dans pa et pb en utilisant pc
	pc = pa; // pc pointe vers ce que pa pointe (adresse de a)
	pa = pb; // pa pointe maintenant vers b
	pb = pc; // pb pointe maintenant vers a

	std::cout << "\nApres echange des pointeurs :" << std::endl;
	// Afficher de nouveau les adresses stockées dans pa et pb
	std::cout << "pa = " << pa << std::endl;
	std::cout << "pb = " << pb << std::endl;

	// Afficher de nouveau les valeurs pointées
	std::cout << "*pa = " << *pa << std::endl;
	std::cout << "*pb = " << *pb << std::endl;

}

/*Écrire une fonction “AllocateSquare” qui alloue une variable de type “float” dynamiquement
	et l'initialise avec une valeur égale au carré de la valeur passée en paramètre. La fonction
	renvoie en valeur de retour l’adresse mémoire de la variable allouée dynamiquement.
	● Paramètre : Valeur de type “float”.
	● Valeur de retour : Adresse mémoire de la variable allouée dynamiquement.
	Dans la fonction “main” :
	● Appeler la fonction “AllocateSquare” avec comme valeur en paramètre “5.0f”.
	● Récupérer la valeur de retour de la fonction dans une variable “pointeur de float”.
	● Afficher l’adresse mémoire de la variable allouée dynamiquement.
	● Multiplier la valeur contenue dans la variable allouée dynamiquement par “2.0f”.
	● Afficher en console la valeur contenue dans la variable allouée dynamiquement.
	● Désallouer la variable allouée dynamiquement.*/

// Alloue dynamiquement une variable float, l'initialise au carré du paramètre
float* AllocateSquare(float value) {
    // Allouer dynamiquement un float
    float* result = new float;
    
    // Initialiser avec le carré de la valeur
    *result = value * value;
    
    // Renvoyer l'adresse mémoire
    return result;
}

int main() {
    // Appeler pointeur() pour exécuter la première partie
    pointeur();

    std::cout << "\n--- Test d'allocation dynamique ---\n" << std::endl;

    // Appeler AllocateSquare avec 5.0f
    float* dynamicValue = AllocateSquare(5.0f);
    
    // Afficher l'adresse mémoire
    std::cout << "Adresse memoire allouee : " << dynamicValue << std::endl;
    
    // Afficher la valeur initiale (devrait être 25.0)
    std::cout << "Valeur initiale : " << *dynamicValue << std::endl;
    
    // Multiplier par 2.0f
    *dynamicValue *= 2.0f;
    
    // Afficher la nouvelle valeur
    std::cout << "Valeur apres multiplication : " << *dynamicValue << std::endl;
    
    // Désallouer la mémoire
    delete dynamicValue;
    dynamicValue = nullptr; // Bonne pratique : évite les pointeurs dangling

	// Boucle demandée : pour i de 1 à 5, allouer un tableau d'entiers de taille i,
	// remplir chaque case avec son index, afficher puis désallouer.
	for (int i = 1; i <= 5; ++i) {
		// Allouer dynamiquement un tableau de int de taille i
		int* arr = new int[i];

		// Remplir chaque case avec son index
		for (int k = 0; k < i; ++k) {
			arr[k] = k;
		}

		// Afficher le contenu du tableau
		std::cout << "Table taille " << i << " : ";
		for (int k = 0; k < i; ++k) {
			std::cout << arr[k];
			if (k + 1 < i) std::cout << " ";
		}
		std::cout << std::endl;

		// Désallouer le tableau
		delete[] arr;
		arr = nullptr;
	}

	return 0;
}

/*Dans la fonction “main”, écrire une boucle “for”, pour “i” de 1 à 5, qui exécute à chaque
boucle l’algorithme suivant :
● Allouer dynamiquement un tableau de int de taille “i”.
● Assigner dans chaque case du tableau une valeur correspondant à son index.
● Afficher le contenu du tableau.
● Désallouer le tableau alloué dynamiquement.*/

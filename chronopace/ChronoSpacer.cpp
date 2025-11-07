#include <iostream>
#include <ctime> // On inclut la bibliothèque <ctime> pour utiliser la fonction clock()
#include <cstdlib> // remplace window.h
#include <conio.h> // for kbhit

// Get Input
bool isKeyPressed()
{
    if (_kbhit())
    {
        while (_kbhit()) // Flush input buffer
        {
            _getch();
        }
        return true; // Key Was Hit
    }
    return false; // No keys were pressed
}

int main()
{    

    for (int NumberGame = 0; NumberGame=10; NumberGame++)
    {
        return 0;
    }

    // Déclarer une variable contenant le temps à trouver
    float timeToFind = 5.0f;

    // Afficher les règles du jeu aux joueurs
    std::cout << "Le but du jeu est de compter " << timeToFind << " secondes dans votre tete." << std::endl;
    std::cout << "Appuyez sur une touche pour lancer le chronometre." << std::endl;

    // lancement du jeu
    system("pause");

    // Déclarer et initialiser le temps de début de jeu
    float startTime = (float)clock() / (float)CLOCKS_PER_SEC;

    std::cout << "C'est parti ! Comptez dans votre tete... Appuyez sur une touche quand vous pensez que c'est le bon moment." << std::endl;
    // Stopper le jeu
    system("pause");

    // Déclarer et initialiser le temps de fin de jeu
    float endTime = (float)clock() / (float)CLOCKS_PER_SEC;

    // Calculer la différence entre le temps de début et de fin
    float elapsedTime = endTime - startTime;

    // Afficher le temps écoulé
    std::cout << "Temps ecoule : " << elapsedTime << " secondes." << std::endl;
    // Calculer et afficher la différence avec le temps à trouver
    float difference = std::abs(elapsedTime - timeToFind);
    std::cout << "Votre ecart est de " << difference << " secondes." << std::endl;

    if (difference <= 1.0f) 
    {
        std::cout << "Bravos" << std::endl;
    }
    else if (difference > 1.0f)
    {
        std::cout <<"T'es mauvais Jack, t'es mauvais" << std::endl;
    }
    
    if (elapsedTime > 5.0f)
    {
        std::cout <<"T'es mauvais Jack, t'es mauvais" << std::endl;
    }
}
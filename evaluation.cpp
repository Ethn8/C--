/*Evaluation*/

#include <iostream>
#include <string>

/* I – Variables et opérations
Évaluer les variables suivantes. Préciser les « . » et « f » au besoin :

/*int a = 3.1415f;
a vaut : 3.1415f

float b = (int)4.2f;
b vaut : 4f;

char c = 256;
c vaut : error

int d = 100;
d += (50 + d);
d vaut : 250;

bool e = !(1 < 2);
e vaut :false;

bool f = false || (true && (true || false) ) && true;
f vaut : false;

bool g = ((5%3) == 1);
g vaut : true;

int h;
h = h * 2 - 5;
h vaut : 5;

int tab[5] = {1,2,3,4,5};
tab[2] vaut : 2;

std::string s = "a";
s = s + "b" + "c\nd" + "ef\0g";
std::cout << s; affiche :

II – Structures de contrôle

1 - Ecrire un code déclarant un tableau de 10 variables de type int et initialisant chaque sous-
variable du tableau à sa valeur d'index correspondante (utiliser un for ou un while) :*/

void tableau()
{
	int tab[10];

	for (int i = 0; i < 10; ++i)
	{
		tab[i] = i;
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "tab[" << i << "] = " << tab[i] << std::endl;
	}
}

/*2 – Déclarer deux variables, "somme" et "i", de type int initialisées à 0. Ecrire une structure de
contrôle "while" qui incrémente "i" à chaque boucle puis qui additionne "i" à "somme" :
0+1+2+3+4+... La boucle s'arrête quand "somme" est strictement supérieure à 100.*/

int somme  = 0;
int i = 0;

void calcule() {

	while (somme <= 100) {
		i += 1;
		somme += i;
	}
	return;
}


/*III – Fonctions

*1 - Ecrire une fonction "Abs" qui prend en paramètre une valeur de type int et qui a comme valeur
de retour la valeur positive de ce paramètre. Par exemple : Abs(7) renvoie 7, Abs(-3) renvoie 3.*/

int Abs(int value) {
	return (value < 0) ? -value : value;
}

/*2 - Utiliser cette fonction dans une ligne d'instructions et stocker son résultat dans une variable.*/

void UseAbs() {
	int v = -3;
	int result = Abs(v); 
	std::cout << "Abs(" << v << ") = " << result << std::endl;
}


/*IV – Exercice*/

/*Ecrire une fonction "Attack" qui calcule les dégâts d'une attaque d'un pokémon sur un autre.
• Paramètres en entrée : Type de l'attaquant (std::string), puissance de l'attaquant (int), type du
défenseur (std::string)
• Valeur de retour : nombre de dégâts (int)
Le calcul de dégâts respecte la règle ci-dessous. Dans tous les autres cas, le nombre de dégâts vaut
la puissance de l'attaquant. (Note : les std::string se comparent avec == )

Attaquant Défenseur Dégats
"electric" "water" power * 2
"water" "fire" power * 2
"fire" "water" power / 2 	*/

int Attack(const std::string& TypeAttaquant, int PuissanceAttaquant, const std::string& TypeDefense) {
	if (TypeAttaquant == "electric" && TypeDefense == "water") {
		return PuissanceAttaquant * 2;
	}
	if (TypeAttaquant == "water" && TypeDefense == "fire" || TypeDefense == "pierre") {
		return PuissanceAttaquant * 2;
	}
	if (TypeAttaquant == "fire" && TypeDefense == "water") {
		return PuissanceAttaquant / 2;
	}
	if (TypeAttaquant == "eletric" && TypeDefense == "pierre") {
		return PuissanceAttaquant / 2;
	}
	return PuissanceAttaquant;
}


/*Pour un index i, les tableaux ci-dessous donnent respectivement le nom, le type et la puissance d'un
pokemon.
• Utiliser la fonction ci-dessus pour calculer les dégâts de Pikachu sur Carapuce.
• Afficher le résultat en console
• Ajouter le pokémon de votre choix en dernière position des tableaux*/

std::string names[5] = { "Pikatchu", "Carapuce" , "Salameche" , "Evoli" , "Racaillou",};
std::string types[5] = { "electric", "water" , "fire" , "normal" , "pierre",};
int powers[5] = { 100 , 40 , 60 , 50 , 70};

// Exemple d'utilisation : calculer et afficher les dégâts de Pikatchu (index 0) sur Carapuce (index 1)
void ShowAttackExample() {
	int damagePikatchuOnCarapuce = Attack(types[0], powers[0], types[1]);
	std::cout << names[0] << " (" << types[0] << ") attaque " << names[1] << " (" << types[1]
			  << ") et inflige " << damagePikatchuOnCarapuce << " dégâts." << std::endl;
}


#include <iostream>
#include <list>
#include <string>
#include <windows.h>

//nains du hobbit

// Fonction pour afficher les éléments de la liste
void afficherListe(const std::list<std::string>& lst) {
	int count = 1;
	for (const std::string& element : lst) {
		std::cout << count << ". " << element << std::endl;
		count++;
	}
}

int main() {
	// Configuration pour afficher les accents correctement en UTF-8
	SetConsoleOutputCP(CP_UTF8);
	
	// Liste contenant les 13 nains du Hobbit
	std::list<std::string> myList = {
		"Balin", "Bifur", "Bofur", "Bombur", "Dori", "Dwalin", "Fíli",
		"Glóin", "Kíli", "Nori", "Óin", "Ori", "Thorin", "Bilbo"
	};

	std::cout << "Les 13 nains du Hobbit :" << std::endl;
	std::cout << "========================" << std::endl;
	
	// Afficher la liste des nains
	afficherListe(myList);
	
	std::cout << "\nNombre total de nains : " << myList.size() << std::endl;

	myList.pop_back();

	std::cout << "\nAprès suppression du dernier nain :" << std::endl;
	afficherListe(myList);
	std::cout << "\nNombre total de nains : " << myList.size() << std::endl;

	// affihe tous les noms finissant par "-in" avec for
	std::cout << "\nNoms des nains finissant par '-in' (avec for) :" << std::endl;
	for (const std::string& name : myList) {
		if (name.size() >= 2 && name.substr(name.size() - 2) == "in") {
			std::cout << name << std::endl;
		}
	}

	// affihe tous les noms finissant pas "-in" avec un iterator
	std::cout << "\nNoms des nains finissant par '-in' (avec itérateur) :" << std::endl;
	std::list<std::string>::iterator it = myList.begin();
	while (it != myList.end())
	{
		if (it->size() >= 2 && it->substr(it->size() - 2) == "in") {
			std::cout << *it << std::endl;
		}
		it++;
	}

	// le dernier nom e la liste avec le plus de lettres avec for
	std::cout << "\nLe nom le plus long (avec for) :" << std::endl;
	std::string longestName;
	for (const std::string& name : myList) {
		if (name.length() >= longestName.length()) {
			longestName = name;
		}
	}
	std::cout << "\nLe nom le plus long est : " << longestName << std	::endl;

	// le dernier nom avec le plus de lettres avec un iterator
	std::cout << "\nLe nom le plus long (avec itérateur) :" << std::endl;
	std::string longestNameIt;
	std::list<std::string>::iterator it2 = myList.begin();
	while (it2 != myList.end())
	{
		if (it2->length() >= longestNameIt.length()) {
			longestNameIt = *it2;
		}
		it2++;
	}
	std::cout << "\nLe nom le plus long est : " << longestNameIt << std::endl;

	return 0;
}
#include <map>
#include <string>
#include <iostream>

// animaux

int main() {

	std::map<std::string, int> myMap;
	myMap["chat"] = 4;
	myMap["humain"] = 2;
	myMap["araignée"] = 8;
	myMap["chien"] = 4;
	myMap["dodo"] = 2;
	myMap["mouton"] = 4;
	myMap["serpent"] = 0;

	//recherche dans la map
	std::map<std::string, int>::iterator found = myMap.find("humain");
	if (found != myMap.end())
	{
		std::cout << "Nom:" << (*found).first << std::endl;
		std::cout << "Nombre de pattes:" << (*found).second << std::endl;
	}
	
	std::map<std::string, int>::iterator found2 = myMap.find("licorne");
	if (found2 != myMap.end())
	{
		std::cout << "Nom:" << (*found2).first << std::endl;
		std::cout << "Nombre de pattes:" << (*found2).second << std::endl;
	}

	//supprimer le dodo
	myMap.erase("dodo");

	//ajouter une patte au mouton
	myMap["mouton"] += 1;

	//tous les animaux à 4 pattes
	std::cout << "\nAnimaux avec 4 pattes :" << std::endl;
	for (const auto& pair : myMap) {
		if (pair.second == 4) {
			std::cout << "Nom: " << pair.first << ", Nombre de pattes:	" << pair.second << std::endl;
		}
	}

	return 0;
}
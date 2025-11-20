#include <iostream>
#include <stdexcept>
// Pré-déclaration pour que `Element` puisse contenir des pointeurs vers lui-même
struct Element;

// Définition du type `Element`
struct Element {
	Element* previous; // adresse de l'élément précédent
	Element* next;     // adresse de l'élément suivant
	char value;        // valeur contenue dans l'élément
};

// Définition du type `List`
struct List {
    Element* first; // adresse du premier élément (tête de liste)
    int count;      // nombre d'éléments dans la liste
};

// Alloue dynamiquement une List, l'initialise (vide) et renvoie son adresse
List* CreateList() {
	List* lst = new List;
	lst->first = nullptr;
	lst->count = 0;
	return lst;
}

// Retourne l'adresse de l'élément à la position donnée (0-based), ou nullptr si invalide
Element *GetElementAt(List *list, int position) {
	// Vérifier que la position est valide
	if (position < 0 || position >= list->count)
	{
		return nullptr; // Position invalide
	}

	// Commencer au premier élément
	Element *current = list->first;

	// Avancer jusqu'à la position voulue
	for (int i = 0; i < position; i++)
	{
		current = current->next; // Passer à l'élément suivant
	}

	// Retourner l'élément trouvé
	return current;
}

// Ajout d'élément à la fin de la liste
void AddElement(List *list, char value) {
	// Allouer dynamiquement un nouvel élément
	Element* newElement = new Element;
	newElement->value = value;
	newElement->next = nullptr;     // Cet élément est le dernier

	if (list->first == nullptr)
	{
		// Si la liste est vide, cet élément devient le premier
		newElement->previous = nullptr;  // Premier élément
		list->first = newElement;
	}
	else
	{
		// Récupérer l'adresse du dernier élément de la liste
		Element* lastElement = GetElementAt(list, list->count - 1);
		// Affecter dans la sous-variable next du dernier élément l'adresse du nouvel élément
		lastElement->next = newElement;
		// Affecter dans la sous-variable previous du nouvel élément l'adresse du dernier élément
		newElement->previous = lastElement;
	}

	// Incrémenter le nombre d'éléments
	list->count++;
}

// Suppresion de la liste
void DestroyList(List *list) {
	// Parcourir tous les éléments et les supprimer
	Element* current = list->first;
	while (current != nullptr)
	{
		Element* nextElement = current->next; // Sauvegarder l'adresse du prochain élément
		delete current;                       // Supprimer l'élément courant
		current = nextElement;                // Passer au prochain élément
	}
	// Supprimer la structure de la liste elle-même
	delete list;
}

	// Supprime l'élément à la position donnée et renvoie une copie de cet élément
Element RemoveElementAt(List *list, int position) {
	// Vérifier que la position est valide
	if (position < 0 || position >= list->count)
	{
		throw std::out_of_range("Position invalide");
	}

	// Trouver l'élément à supprimer
	Element *toRemove = GetElementAt(list, position);

	// Mettre à jour les pointeurs des éléments voisins
	if (toRemove->previous != nullptr)
	{
		toRemove->previous->next = toRemove->next;
	}
	else
	{
		// Suppression du premier élément
		list->first = toRemove->next;
	}

	if (toRemove->next != nullptr)
	{
		toRemove->next->previous = toRemove->previous;
	}

	// Sauvegarder la valeur à retourner
	Element removedElement = *toRemove;

	// Libérer la mémoire de l'élément supprimé
	delete toRemove;

	// Décrémenter le compteur d'éléments
	list->count--;

	// Retourner l'élément supprimé
	return removedElement;
}

// Exemple d'utilisation
int main() {
	List* myList = CreateList();
	std::cout << "Liste cree dynamiquement." << std::endl;

	// Créer plusieurs éléments avec AddElement
	AddElement(myList, 'A');
	AddElement(myList, 'B');
	AddElement(myList, 'C');
	AddElement(myList, 'D');
	AddElement(myList, 'E');

	// Vérifier le bon fonctionnement : récupérer chaque élément avec GetElementAt et afficher sa valeur
	std::cout << "Verification via GetElementAt :" << std::endl;
	for (int i = 0; i < myList->count; ++i)
	{
		Element* elem = GetElementAt(myList, i);
		if (elem != nullptr)
		{
			std::cout << "Index " << i << ": '" << elem->value << "'" << std::endl;
		}
		else
		{
			std::cout << "Index " << i << ": <nullptr>" << std::endl;
		}
	}

	// Supprimer un élément à une position donnée avec RemoveElementAt et afficher la valeur supprimée
	int positionToRemove = 2; // Par exemple, supprimer l'élément à l'index 2
	Element removedElem = RemoveElementAt(myList, positionToRemove);
	std::cout << "Element supprime a l'index " << positionToRemove << ": '" << removedElem.value << "'" << std::endl;

	std::cout << "Verification via GetElementAt :" << std::endl;
	for (int i = 0; i < myList->count; ++i)
	{
		Element *elem = GetElementAt(myList, i);
		if (elem != nullptr)
		{
			std::cout << "Index " << i << ": '" << elem->value << "'" << std::endl;
		}
		else
		{
			std::cout << "Index " << i << ": <nullptr>" << std::endl;
		}
	}

	// Détruire la liste pour libérer la mémoire
	DestroyList(myList);

	return 0;
}
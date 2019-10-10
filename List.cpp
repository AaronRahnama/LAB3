#include "List.h"
#include <fstream>

List::List() {
	head = current = end = nullptr;
	size = 0;
}

List::~List() {
	head = current = end = nullptr;
	size = 0;
}

void List::InitializeList(int playerC) {
	string name = "\0";
	ifstream fin;
	fin.open("input.txt");
	nodePTR n = nullptr;
	for (int i = 0; i < playerC; i++) {
		fin >> name;
		try {
			n = new node;
			n->next = nullptr;
			n->name = name;
			n->number = ++size;
		}
		catch (bad_alloc) { cout << "couldn't allocate memory" << endl; }
		current = head;
		// if list is empty initialize it
		if (current == nullptr) {
			end = head = n;
			head->next = head;
		}
		// if list isnt empty add node to begining and make end of list point to begining
		else if (current != nullptr) {
			n->next = head;
			head = n;
			end->next = head;
		}
	}
	fin.close();
}


void List::delUsers(int delval) {
	nodePTR del;
	nodePTR before = nullptr;
	while (size != 1) {
		for (int i = 0; i < delval; i++) {
			before = current;
			current = current->next;
		}
		del = current;
		before->next = del->next;
		cout << "Removing " << del->name << " from the game. " << --size << " players left." << endl;
		current = current->next;
		delete del;
		del = nullptr;
	}
	cout << "Last player is " << current->name << '.' << endl;
	delete current;
	current = nullptr;
	size = 0;
}

//void List::printPlayers() {
//	current = head;
//	cout  << current->name << '\t' << current->number << endl;
//	current = current->next;
//	while (current != head) {
//		cout << current->name << '\t' << current->number << endl;
//		current = current->next;
//	}
//}
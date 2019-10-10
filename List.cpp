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
			head = n;
			head->next = head;
			end = head;
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
	current = head;
	while (size != 1) {
		for (int i = 0; i < delval -1; i++)
			current = current->next;
		nodePTR delnext = current->next;
		current->next = delnext->next;
		cout << "removing " << delnext->name << '\t' << delnext->number << endl;
		delete delnext;
		--size;
	}
	cout << "Last man standing is " << current->name << '\t' << current->number << endl;
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
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main()
{
	int num = 0;
	List list;
	char choice = '\0';
	do {
		cout << "How many players: ";
		cin >> num;
		list.InitializeList(num);
		cout << "How many passes: ";
		cin >> num;
		//list.printPlayers();
		list.delUsers(num);
		cout << "Would you like to play another hot potatoe game (y/n)?: ";
		cin >> choice;
		while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
			cout << "Your imput was invalid try again (y/n)?: ";
			cin >> choice;
		}
	} while (choice == 'y' || choice == 'Y');
}

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main()
{
	int num = 0;
	List list;
	cout << "How many players: ";
	cin >> num;
	list.InitializeList(num);
	cout << "How many passes: ";
	cin >> num;
	//list.printPlayers();
	list.delUsers(num);


}

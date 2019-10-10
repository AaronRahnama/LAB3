#include <iostream>
#include <string>
using namespace std;
class List
{
private:
	typedef struct node {
		string name;
		int number;
		node* next;
	}*nodePTR;
	nodePTR head;
	nodePTR end;
	nodePTR current;
	int size;
public:
	List();
	~List();
	void InitializeList(int);
	void delUsers(int);
	void printPlayers();

};


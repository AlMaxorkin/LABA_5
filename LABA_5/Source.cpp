#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List list;
/*int N,x,y;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		cin >> y;
		a.add(x, y);

	}*/
	
	
	list.add(1, 3);
	list.add(4, 8);
	list.add(7, 6);
	list.add(6, 10);
	list.add(20, 27);
	list.add(3, 13);
	list.add(5, 12);

	list.show();
	Node* head = list.getHead();

	list.merge_sort(&head);
	list.show();

	cout << endl << list.colored() << endl;
	system("pause");
	return 0;
}
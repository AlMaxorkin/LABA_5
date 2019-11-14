#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List a;

	int N,x,y;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		cin >> y;
		a.add(x, y);

	}


	a.sort();
	a.show();

	cout << endl << a.colored() << endl;


	system("pause");
	return 0;
}
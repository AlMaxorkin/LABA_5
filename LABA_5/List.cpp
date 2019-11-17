#include "List.h"

using namespace std;

List::~List()
{
	while (Head)
	{
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
		
}


void List::add(int x, int y)
{
	if (x > y)
	{
		cout << x << " > " << y << "!!!" << endl;
		return;
	}

	Node* temp = new Node;
	temp->Next = NULL;	
	temp->l = x;
	temp->r = y;
	if (Head != NULL)
	{
		Tail->Next = temp;
		Tail = temp;
	}
	else
		Head = Tail = temp;
}

void List::show()
{

	Node* temp = Head;
	while (temp != NULL)
	{
		cout << temp->l << " ";
		cout << temp->r << " " << endl;
		temp = temp->Next;
	}
	cout << endl;
}

int List::colored()
{
	int length = 0;
	Node* temp = Head;

	while (temp->Next)
	{
		if (temp->r > temp->Next->l)
		{
			temp->Next->l = temp->l;
			if (temp->r > temp->Next->r)
				temp->Next->r = temp->r;
		}
		else
			length += temp->r - temp->l;
		temp = temp->Next;
	}
	length += temp->r - temp->l;
	return length;
}



void List::split(Node *source, Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->Next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->Next;
		if (fast != NULL) {
			slow = slow->Next;
			fast = fast->Next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->Next;
	slow->Next = NULL;
}

Node* merge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->l <= b->l) {
		result = a;
		result->Next = merge(a->Next, b);
	}
	else {
		result = b;
		result->Next = merge(a, b->Next);
	}
	return (result);
}

void List::merge_sort(Node ** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->Next == NULL)) {
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	split(head,&a, &b);

	/* Recursively sort the sublists */
	merge_sort(&a);
	merge_sort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = merge(a, b);	
}
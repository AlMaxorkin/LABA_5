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
	Node* temp = new Node;
	temp->Next = NULL;	
	temp->l = x;
	temp->r = y;

	if (Head != NULL)
	{
		temp->Prev = Tail;
		Tail->Next = temp;
		Tail = temp;
	}
	else
	{
		temp->Prev = NULL;
		Head = Tail = temp;
	}
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
	cout << "\n";
}

void List::sort() 
{
	Node* left = Head;                
	Node* right = Head->Next;          
	Node* temp = new Node;              

	while (left->Next)
	{                 
		while (right)
		{              
			if (left->l > right->l) 
			{       
				temp->l = left->l;
				temp->r = left->r;

				left->l = right->l; 
				left->r = right->r;

				right->l = temp->l;  
				right->r = temp->r;

			}
			right = right->Next;                   
		}
		left = left->Next;                             
		right = left->Next;                            
	}
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
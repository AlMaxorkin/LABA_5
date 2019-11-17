#pragma once
#include <iostream>
struct Node                           
{
	int l,r;                            
	Node* Next;                 
};

class List									
{
	Node* Head, * Tail;  
	void split(Node* source, Node** frontRef, Node** backRef);
public:
	List() :Head(NULL), Tail(NULL) {}; 
	List(Node* H) : Head(H), Tail(NULL) {};
	~List();                    
	Node* getHead() { return Head; };
	void merge_sort(Node **headRef);
	void show();                       
	void add(int, int);     
	int colored();
};



#pragma once
#include <iostream>
struct Node                           
{
	int l,r;                            
	Node* Next, * Prev;                 
};

class List									
{
	Node* Head, * Tail;                
public:
	List() :Head(NULL), Tail(NULL) {};  
	~List();                          
	void show();                       
	void add(int, int);     
	void sort();
	int colored();
};



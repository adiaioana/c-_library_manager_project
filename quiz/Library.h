#pragma once
#include "Item.h"
class Library {
	int count;
	Item* items[110];
public:
	Library();
	~Library();
	Library& operator +=(Item* A);
	void print_all_borrowed();
	void print_all_not_borrowed();
	void print_all();
	bool Return(int item_id, int client_id);
	bool Borrow(int item_id,int client_id);
};
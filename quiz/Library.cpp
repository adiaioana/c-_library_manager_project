#pragma once
#include "Library.h"

Library::
Library() {
	count = 0;
}
Library::~Library() {
	for (int i = 0; i < count; ++i)
		delete items[i];
	count = 0;
}

Library& Library:: operator+=(Item* A)
{
	items[count++] = A;
	return (*this);
}

void Library::print_all_borrowed()
{
	for(int i=0; i<count; ++i)
		if (items[i]->isBorrowed()) {
			items[i]->printInfo();
		}

}
void Library::print_all_not_borrowed() {
	for (int i = 0; i < count; ++i)
		if (!items[i]->isBorrowed()) {
			items[i]->printInfo();
		}

}
void Library::print_all()
{
	for (int i = 0; i < count; ++i){
			items[i]->printInfo();
		}

}
bool Library::Borrow(int item_id, int client_id)
{
	for (int i = 0; i < count; ++i)
		if (items[i]->GetItemID() == item_id && !items[i]->isBorrowed()) {
			Date d;
			d.day = 11; d.month = 1; d.year = 2015;
			return items[i]->Borrow_Self(d, client_id);
		}
	return 0;
}


bool Library::Return(int item_id, int client_id)
{
	for (int i = 0; i < count; ++i)
		if (items[i]->isBorrowed() && items[i]->GetItemID() == item_id && items[i]->WhoBorrowed() == client_id) {
			return items[i]->Return_Self();
		}
	return 0;
}
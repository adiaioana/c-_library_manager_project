#pragma once
#include <string>
#include "Date.h"
class Item {
public:
	virtual void printInfo() = 0;
	virtual bool isBorrowed() = 0;
	virtual int WhoBorrowed() = 0;
	virtual int GetItemID() = 0;
	virtual int TypeofItem() = 0;
	virtual bool Borrow_Self(Date When, int client_id) =0;
	virtual bool Return_Self() =0;
};
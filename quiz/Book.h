#pragma once
#include "Item.h"

class Book : public Item {
	private:
	int id;
	std::string author_name;
	std::string title;

	bool borrowed;
	int Who_Borrowed;
	Date When_Borrowed;
	public:
		int TypeofItem() override{
			return 2;
		}
	int GetItemID() override {
		return id;
	}
	Book() {
		srand(time(NULL));
		id = rand() % 1000000;
		if (id % 2 == 0) id++;
		author_name = "_";
		title = "_";
		borrowed = 0;
	}
	~Book() {
		id = -1;
		borrowed = 0;
	}
	Book(std::string titleof, std::string author) {
		srand(time(NULL));
		borrowed = 0;
		id = rand() % 1000000;
		if (id % 2 == 0) id++;
		this->author_name = author;
		this->title = titleof;
	}
	bool Borrow_Self(Date When,int client_id) override {
		if (borrowed)
			return 0;
		When_Borrowed = When;
		Who_Borrowed = client_id;
		borrowed = 1;
		return 1;
	}
	void printInfo() override {
		std::cout << "This book has the ID: " << id << std::endl;
		std::cout << "Title: " << title << "; Author:" << author_name << std::endl;
	}
	bool isBorrowed() override {
		return borrowed;
	}
	int WhoBorrowed() override {
		return Who_Borrowed;
	}
	bool Return_Self() override {
		if (!borrowed)
			return 0;
		borrowed = 0;
		this->Who_Borrowed = 0;
		return 1;
	}
};
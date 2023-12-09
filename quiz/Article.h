#pragma once
#include "Item.h"
class Article : public Item {
private:
	int id;
	int no_authors;
	std::string authors_names[110];
	std::string title;

	bool borrowed;
	int Who_Borrowed;
	Date When_Borrowed;

public:
	Article() {
		srand(time(NULL));
		borrowed = 0;
		id = rand() % 1000000;
		if (id % 2 == 1) id++;
		this->no_authors = 0;
		this->title = "_";
		this->authors_names[0] = "_";
	}
	~Article() {
		id = -1;
		borrowed = 0;
	}
	Article(std::string titleof, int nr, std::string author[]) {
		srand(time(NULL));
		id = rand() % 1000000;
		if (id % 2 == 1) id++;
		borrowed = 0;
		this->no_authors = nr;
		this->title = titleof;
		for (int i = 0; i < no_authors; ++i)
			this->authors_names[i] = author[i];
	}


	int GetItemID() override {
		return id;
	}
	int TypeofItem() override {
		return 1;
	}

	bool Borrow_Self(Date When, int client_id) override {
		if (borrowed)
			return 0;
		When_Borrowed = When;
		Who_Borrowed = client_id;
		borrowed = 1;
	}
	void printInfo() override {
		std::cout << "This article has the ID: " << id << std::endl;
		std::cout << "Title: " << title << "; No of authors=" << no_authors <<"; Authors: " << std::endl;
		for (int i = 0; i < no_authors; ++i)
			std::cout << this->authors_names[i] << ' ';
		std::cout << '\n';
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
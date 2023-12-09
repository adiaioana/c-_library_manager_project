#pragma once
#include <string>
#include <cstdlib>
#include <time.h>

class Client {
private:
	int ID;
	
	std::string Name, Surname;
	std::string password;
public:
	Client() {
		srand(time(NULL));
		ID = rand() % 1000000;
		Name = "_!";
		Surname="_?";
	}
	Client(std::string A, std::string B) {
		srand(time(NULL));
		ID = rand() % 1000000;
		Name = A;
		Surname = B;
		password = "12345678";
	}
	Client(std::string A, std::string B, std:: string C) {
		srand(time(NULL));
		ID = rand() % 1000000;
		Name = A;
		Surname = B;
		password = C;
	}
	Client(char* p, char* q) {
		srand(time(NULL));
		ID = rand() % 1000000;
		std::string Test;
		char* pt=p;
		Test.clear();
		while (*pt != '\0') {
			Test.push_back(*pt); pt++;
		}
		Name = Test;

		Test.clear(); pt = q;
		while (*pt != '\0') {
			Test.push_back(*pt); pt++;
		}
		Surname = Test;
	}
	~Client() {
		ID = -1;
		Surname.clear();
		Name.clear();
	}
	void printData() {
		std::cout << "Name= " << Name << "; Surname= " << Surname <<"; ID= "<<ID<< std::endl;
	}
	void UpdatePass(std::string A) {
		this->password = A;
	}
	std::string GetPass() {
		return password;
	}
	int GetID() {
		return ID;
	}
	std::string GetName() {
		return Name;
	}
	std::string GetSurname() {
		return Surname;
	}
};
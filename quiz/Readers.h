#pragma once
#define separator "\n_____________________________________________\n"

#include <iostream>
#include "Client.h"
class Readers {
	int count;
	Client* clients[110];
public:
	Readers() {
		for (int i = 0; i <= 100; ++i)
			clients[i] = new Client();
		count = 0;
	}
	~Readers() {
		for (int i = 0; i < count; ++i)
			delete clients[i];
		count = 0;
	}
	void PrintDB() {
		if (count > 1)
			std::cout << "\nThere are " << count << " readers>\n";
		else if (count == 0)
			std::cout << "\nNo readers in DB\n";
		else std::cout << "\nThere is one reader>\n";

		for (int i = 0; i < count; ++i)
		{
			std::cout << "The "<<i+1 <<" client is: ";
			clients[i]->printData();
		}
		std::cout << separator;
	}
	Client WhoHasID(int IDC) {
		for (int i = 0; i < count; ++i)
			if(clients[i]->GetID() == IDC)
				return *clients[i];
		return Client("no","one");
	}

	void addClient(Client* A) {
		clients[count++] = A;
	}
	void addClient(std::string nume, std::string prenume) {
		for(int i=0; i<count; ++i)
			if (clients[i]->GetName() == nume && clients[i]->GetSurname() == prenume) {
				return;
			}
		Client A(nume, prenume);
	//	std::cout << separator << "Debug>>>> ";
	//	A.printData();
	//	std::cout << separator;
		*clients[count++]=A;
	}
	void addClient(std::string nume, std::string prenume, std::string passphrase) {
		for (int i = 0; i < count; ++i)
			if (clients[i]->GetName() == nume && clients[i]->GetSurname() == prenume) {
				clients[i]->UpdatePass(passphrase);
				return;
			}
		Client A(nume, prenume, passphrase);
		//	std::cout << separator << "Debug>>>> ";
		//	A.printData();
		//	std::cout << separator;
		*clients[count++] = A;
	}
	bool isThereAClient(std::string nume, std::string prenume) {
		for (int i = 0; i < count; ++i)
			if (clients[i]->GetName() == nume && clients[i]->GetSurname() == prenume)
				return 1;
		return 0;
	}
	bool isThereAClient(int id_aux) {
		for (int i = 0; i < count; ++i)
			if (clients[i]->GetID() == id_aux)
				return 1;
		return 0;
	}
	bool CheckPassword(std::string Pass, int id_aux) {
		for (int i = 0; i < count; ++i)
			if (clients[i]->GetID() == id_aux && Pass == clients[i]->GetPass())
				return 1;
		return 0;
	}
	void removeClient(std::string nume, std::string prenume) {
		for (int i = 0; i < count; ++i)
			if (clients[i]->GetName() == nume && clients[i]->GetSurname() == prenume) {
				for (int j = i + 1; j < count; ++j)
					clients[j - 1] = clients[j];
				count--;
				return;
			}
	}
};
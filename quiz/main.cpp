#pragma once
#include <iostream>
#include "Library.h"
#include <chrono>
#include <thread>
#include "Readers.h"
#include "Book.h"
#include "Article.h"
#include <cstring>
#define separator "\n_____________________________________________\n"

using namespace std;
using namespace std::this_thread; 
using namespace std::chrono;

int ID_OF_LOGGED_IN_ACCOUNT;
bool LOGGED_IN = 0;

Readers R_info;
Library Lib;

string to_string(char sir[]) {
	int lg = strlen(sir);
	string aux; aux.clear();
	for (int i = 0; i < lg; ++i)
		aux += sir[i];
	return aux;
}

inline void print_command_explained();
inline void register_client();
inline void register_art_or_book();
inline void login_as();

inline void borrow_item();
inline void return_item();

int main() {

	print_command_explained();
	while (1) {
		int number_of_command;
		cout << "Enter command> ";
		cin >> number_of_command;
		if (number_of_command == -1) {
			print_command_explained();
		}
		else if (number_of_command == 0) {
			cout << "Visit ended, time for reading... Goodbye!\n";
			return 0;
		}
		else while (number_of_command > 5 || number_of_command<-1) {
			cout << "\nUnknown command, please type a known command (1-5) or -1 for help> ";
			cin >> number_of_command;
			if (number_of_command == -1)
				print_command_explained();
			if (number_of_command == 0) {
				cout << "Visit ended, time for reading... Goodbye!\n";
				return 0;
			}
				
		}

		switch ( number_of_command)
		{
		case 1: register_client(); break;
		case 2: register_art_or_book(); break;
		case 3: login_as(); break;
		case 4: borrow_item(); break;
		case 5: return_item(); break;
		default: break;
		}
		//break;
	}

	return 0;
}
inline void print_command_explained()
{
	cout << "List of commands\n";
	cout << " 1. Register client as reader\n";
	cout << "2. Register Book/Article in the Library\n";
	cout << "3. Login as reader\n";
	cout << "4. Borrow Book/Article\n";
	cout << "5. Return Book/Article\n";
}
inline void register_client()
{
	string A1, A2;
	cout << separator;
	cout << " Beggining registration for a new client";
	cout << separator;
	cout << "Enter name: "; cin >> A1;
	cout << "Enter surname: "; cin >> A2;
	char ok;
	cout << "Do you want to set a password? (Y/N), if you do not, it will be automatically 12345678\n"; cin >> ok;
	if (ok == 'Y') {
		string A3;
		cout << "Enter password: "; cin >> A3;
		R_info.addClient(A1, A2,A3);
	}
	else {
		R_info.addClient(A1, A2);
	}
	R_info.PrintDB();
}

inline void register_art_or_book() {
	int nr;
	cout << separator;
	cout << " Beggining registration for a new item:\n";
	cout << " (1) Article\n";
	cout << " (2) Book\n";
	cout << "Choose an option by entering 1 or 2 or 0 for cancel\n";
	cin >> nr;
	if (nr == 0) {
		cout << "Cancelling operation...\n";
		return;
	}
	string A1, A2, A3[110]; int nr_a;
	char sir[220];
	if (nr == 2) {
		cout << "Enter the book's title:\n"; 
		cin >> A1;
		cout << "Enter the book's author:\n";
		cin >> A2;
		Lib += (new Book(A1,A2));
	}
	else {
		cout << "Enter the article's title: "; 
		cin >> A1;
		cout << endl;
		cout << "Enter the article's number of authors: "; cin >> nr_a;
		for (int i = 0; i < nr_a; ++i) {
			cout << "Enter the " << i+1 << " author of the article: ";
			cin >> A3[i];
			cout << endl;
		}
		Lib += (new Article(A1, nr_a, A3));
	}
	cout << separator;
	Lib.print_all();
}

inline void login_as() {

	cout << separator;
	cout << " For login, the following accounts are:\n";
	R_info.PrintDB();
	cout << separator;
	cout << "Type the ID for the account you'd like to login:\n";
	int NR;
	cin >> NR;
	string A3;
	cout << "Enter password: "; cin >> A3;
	if (R_info.CheckPassword(A3, NR))
	{
		LOGGED_IN = 1;
		ID_OF_LOGGED_IN_ACCOUNT = NR;
	}
	cout << separator;
	if (LOGGED_IN) {
		cout << "Currently, you are logged in as: " << ID_OF_LOGGED_IN_ACCOUNT << '\n';
		cout << "Would you like to logout? (Y/N) ";
		char ch;
		cin >> ch;
		if (ch == 'Y')
			LOGGED_IN = 0, ID_OF_LOGGED_IN_ACCOUNT = -1;
	}
	else {
		cout << "Login failed. Better luck next time!\n";
	}
}
void borrow_item()
{
	cout << separator;
	cout << "Your request of borrowing is being proccessed..." << '\n';
	sleep_for(nanoseconds(10));
	if (!LOGGED_IN) {
		cout << "Not logged in as any reader. Please log in in order to borrow an item.\n";
		return;
	}
	int idaux;
	cout << "Not borrowed items:\n";
	Lib.print_all_not_borrowed();
	cout << separator;
	cout << "Enter the item's ID: "; cin >> idaux;
	if (Lib.Borrow(idaux, ID_OF_LOGGED_IN_ACCOUNT))
		cout << " Succesfully borrowed " << idaux << '\n';
	else cout << "Can't borrow " << idaux << '\n';
	cout << separator;
}
void return_item()
{
	cout << separator;
	cout << "Your request of returning is being proccessed..." << '\n';
	sleep_for(nanoseconds(10));
	if (!LOGGED_IN) {
		cout << "Not logged in as any reader. Please log in in order to return an item.\n";
		return;
	}
	int idaux;
	cout << "Borrowed items:\n";
	Lib.print_all_borrowed();
	cout << separator;
	cout << "Enter the item's ID: "; cin >> idaux;
	if (Lib.Return(idaux, ID_OF_LOGGED_IN_ACCOUNT))
		cout << " Succesfully returned " << idaux << '\n';
	else cout << " Can't return " << idaux << '\n';
	cout << separator;
}
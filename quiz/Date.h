#pragma once
#include <iostream>

static char actual_months[15][20] = { "","January","February","March","April",
"May", "June", "July", "August", "September", "October", "November",
"December"};

struct Date {
	int day, month, year;
	void print_data_calendaristica() {
		std::cout << " on the "<<day;
		switch (day) {
		case 1: std::cout << "st"; break;
		case 2: std::cout << "nd"; break;
		case 3: std::cout << "rd"; break;
		default:std::cout << "th"; break;
		}
		std::cout << " of ";
		std::cout << actual_months[month] << " in "<<year<<std::endl;
	}

	Date() {
		day = 3; month = 9; year = 2003;
	}
	Date(int x, int y, int z) {
		day = x; month = y; year = z;
	}
	Date(char *data) {
		int ind = 0; char* pt = data; int nr = 0;
		

		while (pt != nullptr) {
			if (*pt == '/') {
				switch (ind) {
				case 0: day = nr; break;
				case 1: month = nr; break;
				case 2: year = nr; break;
				}
				nr = 0; ind++;
			}
			else {
				if (*pt >= '0' && *pt <= '9')
					nr = nr * 10 + (*pt) - '0';
			}
		}
		}
};
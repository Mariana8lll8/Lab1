#include <iostream>

struct Money {
	int grn;
	short int kop;
};

void additional(Money& price) {
	price.kop = price.grn * 100 + price.kop;
	price.grn = 0;
}

void multiplication(Money& price, unsigned int quantity) {
	price.kop = price.kop * quantity;
	price.grn = price.kop / 100;
	price.kop = price.kop % 100;
}

void roundTo10(Money& price) {
	if (price.kop % 10 < 5) {
		price.kop -= price.kop % 10;
	}
	else {
		int num = price.kop % 10;
		price.kop = price.kop + (10 - num);
	}
}

const void print(Money& price) {
	if (price.kop >= 100) {
		price.grn += price.kop / 100;
		price.kop = price.kop % 100;
	}

	std::cout << price.grn << "." << price.kop;
}
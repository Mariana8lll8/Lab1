#include <iostream>
#include "struct.hpp"

using namespace std;

int main()
{
    FILE* inputFile;
    
    int err = fopen_s(&inputFile, "prices.txt", "r");

    if (err != 0 || inputFile == nullptr) {
        cout << "Error!" << endl;
        return 1;
    }

    int grn, kop;
    unsigned int quantity;
    Money finalPrice = { 0,0 };
    char ch[100];
    int lineAndProductNumber = 1;

    cout << "Numbering of products and results of adding grn and kop and multiplying by quantity and total result:\n\n";

    while (fgets(ch, sizeof(ch), inputFile)) {
        sscanf_s(ch, "%d %d %d", &grn, &kop, &quantity);

        Money currentPrice = { grn,kop };

        additional(currentPrice);
        multiplication(currentPrice, quantity);

        finalPrice.grn += currentPrice.grn;
        finalPrice.kop += currentPrice.kop;

        string productWord = (lineAndProductNumber == 1) ? "product" : "products";

        cout << lineAndProductNumber << ". ";
        print(currentPrice);
        cout << " -- " << lineAndProductNumber << " " << productWord;
        cout << "\n\n";

        lineAndProductNumber++;
    }

    roundTo10(finalPrice);

    cout << "FINAL PRICE: ";
    print(finalPrice);
    cout << endl;

    fclose(inputFile);

    return 0;
}


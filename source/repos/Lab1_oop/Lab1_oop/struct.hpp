struct Money {
    int grn;
    short int kop;
};

void roundTo10(Money& price);
void additional(Money& price);
void multiplication(Money& price, unsigned int quantity);
const void print(Money& price);
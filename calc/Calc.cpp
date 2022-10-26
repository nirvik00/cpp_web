#include "Calc.h"

int Calc::sum(int a, int b){
    return a+b;
}

double Calc::exp(){
    const double PI = 3.14159;
    int x = sum(1, 3);
    std::cout << "sum is: " << x << "\n";
    
    double ar = PI * pow(x, 3);
    std::cout << "exp of sum is: " << ar << "\n";

    return ar;
}

void Calc::castFunc(){
    int books; int months;
    std::cout << "enter books: ";
    std::cin >> books;
    std::cout << "enter months: ";
    std::cin >> months;

    double perMonth= static_cast<double> (books) / months;

    std::cout << "books per month: " << perMonth << "\n";
}
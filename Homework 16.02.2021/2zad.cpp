#include <iostream>
#include <math.h>

int main(){

    int a, b, c;
    int x1, x2;

    std::cout << "VVedite chislo a = ";
    std::cin >> a;

    std::cout << "Vvedite chislo b = ";
    std::cin >> b;

    std::cout << "Vvedite chislo c = ";
    std::cin >> c;

    int D = 0;
    D = a*a - 4*b*c;
    
    if (D < 0){
        std::cout << "Discriminant < 0";
        exit(0);
    }

    else if (D == 0){
        x1 = (-b) / 2*a;
        std::cout << "Korenb = " << x1;
    }

    else{
        x1 = (-b + sqrt(D)) / 2*a;
        x2 = (-b -sqrt(D)) / 2*a;
        std::cout << "Korenb1 = " << x1;
        std::cout << " Korenb2 = " << x2;
    }
    return 0;
}

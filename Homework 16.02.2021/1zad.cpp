#include <iostream>

int main(){
    
    int n;
    int summ = 0;
    int chislo;

    std::cout << "Vvedite kolvo chisel = ";
    std::cin >> n;

    while(n != 0){

        std::cout << "Vvedite chislo = ";
        std::cin >> chislo;
        summ = summ + chislo;
        n = n - 1;
    }

    std::cout << "znachenie = " << summ << std::endl;
    return 0;
}
#include <iostream>

int power(int x, unsigned p){

    int res = 1;

    for(int i = 1; i <= p; i++){
        res = res * x;
    } 
    
    return res;
}

int main(){

    int res = 1;
    int x;
    unsigned p;

    std::cout << "Vvedite x = ";
    std::cin >> x;
    
    std::cout << "Vvedite p = ";
    std::cin >> p;

    res = power(x, p);

    std::cout << res;

    return 0;
}
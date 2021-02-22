#include <iostream>
#include <math.h>

int main(){

    int x, kv;
    int p = 0;
    
    std::cout << "Vvedite x = ";
    std::cin >> x;

    while (pow(2, p) < x){
        p++;
    }

    std::cout << "Max stepenb = " << p-1;
    return 0;
}
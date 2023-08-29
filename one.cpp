#include <iostream>
#include <cmath>

//Sieve of Eratosthenes
int main() {
    const int n = 100; //Number to find primes up to
    int numbers[n]; //Array of numbers to find primes up to

    //Initialize Array with numbers from 2 to N
    for(int i = 0; i < n - 2; i++) {
        numbers[i] = i + 2;
        //std::cout << numbers[i] << std::endl;
    }
 
    //Remove all even numbers greater than 2
    for(int i = 1; i < n; i++) {
        if (numbers[i] % 2 == 0 && numbers[i] != 0) {
            numbers[i] = 0;
        }
    }

    //Find primes and remove their multiples
    for(int i = 0; i <= std::sqrt(n); i++){
        if (numbers[i] != 0){
            for (int j = i + numbers[i]; j < n; j += numbers[i]){
                numbers[j] = 0;
            }
        }
    }

    //Print that shit
    for(int i = 0; i < n; i++) {
        if (numbers[i] != 0) {
            std::cout << numbers[i] << std::endl;
        }
    }
    return 0;
}
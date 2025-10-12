#include "PrimeNumbers.h"

long long int PrimeNumbers_naive(int n) {
    long long int count = 0;

    for (int i = 2; i < n; i++) {     
        int is_prime = 1;   // car 2 est premier        

        for (int j = 2; j < i; j++) { // on teste TOUS les diviseurs
            if (i % j == 0) {         // si divisible, pas premier
                is_prime = 0;
            }
        }
        if (is_prime){
            count++;
        }     
    }
    return count;
}


// 2eme O(n log log n) car on élimine en bloc les multiples des nombres premiers déjà trouvés jsuq'à √n.
long long int PrimeNumbers_dynamic(int n) {
    bool is_prime[n];
    long long int count = 0;

    for (int i = 0; i < n; i++) {
        is_prime[i] = true; // TRUE 
    }
    is_prime[0] = false;
    is_prime[1] = false;

    // on élimine en bloc les multiples des nombres premiers déjà trouvés. 
    // Après avoir éliminé tous les multiples des petits nombres, tout nombre restant non éliminé est premier.
    for (int p = 2; p * p < n; p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple < n; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (is_prime[i])
            count++;
    }

    return count;
}



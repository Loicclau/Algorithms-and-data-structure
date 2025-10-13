#include "utils.h"
#include <stdbool.h>

bool is_sorted_nondecreasing(int *arr, int n)
{
    // Vérifie si le tableau est trié dans l'ordre non décroissant
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false; // dès qu’un élément est plus grand que le suivant → pas trié
        }
    }
    return true; //le tableau est trié
}

// return smallest value between a and b
int min_int(int a, int b)
{
    if (a < b) {
        return a;
    }
    else return b;
}
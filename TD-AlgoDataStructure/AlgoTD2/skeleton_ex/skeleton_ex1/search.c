#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)  // que si cest PAS trier
{
    // linear search on array, return index
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Return index si trouvé
        }
    }
    return -1;
}

int jump_search(int *arr, int n, int target)
{
    // Vérifie si le tableau est trié
    if (!is_sorted_nondecreasing(arr, n))
        return -1;

    int step = sqrt(n);       // Taille du saut
    int prev = 0;

    // Trouver le bloc où la valeur peut être
    while (arr[min_int(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Recherche linéaire dans le bloc trouvé
    for (int i = prev; i < min_int(step, n); i++) {
        if (arr[i] == target)
            return i;
    }
    return -1; // Non trouvé
}



int binary_search(int *arr, int n, int target)
{
    // Vérifie si le tableau est trié
    if (!is_sorted_nondecreasing(arr, n))
        return -1;

    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Non trouvé
}

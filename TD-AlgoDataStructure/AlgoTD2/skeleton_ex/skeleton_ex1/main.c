#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int target = 69;
    int arr[] = {5, 8, 143, 138, 122, 109, 130, 107, 134, 127, 141, 136, 108, 117, 132, 
        123, 125, 116, 114, 140, 135, 78, 12, 118, 145, 12, 113, 147, 146, 128, 111, 
        112, 149, 153, 152, 151, 155, 154, 13, 456, 69, 36, 156, 157, 158, 159, 7}; // Non trié
    int arr_sorted[] = {2, 3, 4, 5, 7, 8, 12, 23, 45, 56, 69, 78, 82, 85, 89, 93, 99, 113, 146, 153, 456}; // Trié
    // sizeof(arr) → taille totale en octets
    // sizeof(arr[0]) → taille d’un élément
    int n1 = sizeof(arr) / sizeof(arr[0]); // 40 / 4 = 10, donc le tableau a 10 éléments
    int n2 = sizeof(arr_sorted) / sizeof(arr_sorted[0]);

    int index;
    // --- Premier tableau ---
    printf("Tableau 1 :\n");
    if (is_sorted_nondecreasing(arr, n1)) {
        index = jump_search(arr, n1, target);
        if (index != -1)
            printf("Jump search : valeur %d trouvee a l'indice %d.\n", target, index);
        else
            printf("Jump search : valeur %d non trouvee.\n", target);

        index = binary_search(arr, n1, target);
        if (index != -1)
            printf("Binary search : valeur %d trouvee a l'indice %d.\n", target, index);
        else
            printf("Binary search : valeur %d non trouvee.\n", target); // tableau trié
    } else {
        index = linear_search(arr, n1, target);
        if (index != -1)
            printf("Linear search : valeur %d trouvee a l'indice %d.\n", target, index);
        else
            printf("Linear search : valeur %d non trouvee.\n", target);
    } // tableau non trié
    


    // --- Deuxième tableau ---
    printf("\nTableau 2 :\n");
    if (is_sorted_nondecreasing(arr_sorted, n2)) {
        index = jump_search(arr_sorted, n2, target);
        if (index != -1)
            printf("Jump search : valeur %d trouvee a l'indice %d.\n", target, index);
        else
            printf("Jump search : valeur %d non trouvee.\n", target);

        index = binary_search(arr_sorted, n2, target);
        if (index != -1)
            printf("Binary search : valeur %d trouvee a l'indice %d.\n", target, index);
        else
            printf("Binary search : valeur %d non trouvee.\n", target);

    } else {
        index = linear_search(arr_sorted, n2, target);
        if (index != -1)
            printf("Linear search : valeur %d trouvee a l'indice %d.\n", target, index);
        else
            printf("Linear search : valeur %d non trouvee.\n", target);
    }
}

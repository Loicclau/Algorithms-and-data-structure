#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

#define N 210

int main(void)
{

        int tableau[N] = {
        12, 45, 3, 89, 7, 56, 102, 33, 78, 5,
        99, 11, 67, 42, 8, 19, 64, 23, 91, 2,
        10, 84, 29, 50, 6, 17, 80, 93, 1, 37,
        71, 15, 62, 41, 98, 27, 77, 9, 31, 59,
        14, 85, 35, 49, 4, 73, 26, 92, 18, 60,
        47, 79, 25, 100, 36, 13, 65, 90, 58, 40,
        97, 22, 87, 32, 70, 16, 38, 83, 95, 48,
        28, 75, 20, 44, 63, 86, 94, 21, 55, 30,
        68, 34, 74, 53, 81, 24, 57, 39, 66, 46,
        76, 43, 88, 54, 82, 61, 52, 96, 51, 72,
        120, 115, 133, 142, 129, 137, 124, 150, 119, 101,
        143, 138, 122, 109, 130, 107, 134, 127, 141, 136,
        108, 117, 132, 123, 125, 116, 114, 140, 135, 121,
        139, 118, 145, 113, 147, 146, 128, 111, 112, 149,
        153, 152, 151, 155, 154, 156, 157, 158, 159, 160,
        161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
        171, 172, 173, 174, 175, 176, 177, 178, 179, 180,
        181, 182, 183, 184, 185, 186, 187, 188, 189, 190,
        191, 192, 193, 194, 195, 196, 197, 198, 199, 200,
        58, 14, 99, 72, 6, 45, 91, 32, 77, 8
    };
    
    clock_t start, end;
    double time_taken;

    // Créer un tableau dynamique pour copier les données
    int *arr = (int *)malloc(N * sizeof(int));
    if (!arr) {
        printf("Erreur allocation mémoire !\n");
        return 1;
    }

    // Selection Sort
    copy_array(tableau, arr, N); // copie donne tab sur arr

        if (is_sorted_nondecreasing(arr, N)){
            printf("Tableau trier correctement\n");

        }else{
            printf("Tableau pas triee normal pas de tri fait encore\n");
        }
    start = clock();
    selection_sort(arr, N);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort terminer en %.6f secondes\n", time_taken);
    if (is_sorted_nondecreasing(arr, N))
        printf("Tableau trier correctement avec selection_sort\n\n");


    // Bubble Sort
    copy_array(tableau, arr, N);
    start = clock();
    bubble_sort(arr, N);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort terminer en %.6f secondes\n", time_taken);

    if (is_sorted_nondecreasing(arr, N))
        printf("Tableau triee correctement avec bubble_sort\n\n");


    
    // Insertion Sort
    copy_array(tableau, arr, N);
    start = clock();
    insertion_sort(arr, N);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion sort terminer en %.6f secondes\n", time_taken);

    if (is_sorted_nondecreasing(arr, N))
        printf("Tableau trier correctement avec insertion_sort\n\n");





    free(arr);
    return 0;
}

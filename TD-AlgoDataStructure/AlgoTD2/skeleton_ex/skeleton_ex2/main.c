#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

#define N 600

int main(void)
{

        int tableau[N] = {
        12, 45, 35, 89, 7, 564, 3102, 33, 78, 5,
        99, 11, 67, 42, 8, 19, 64345, 23, 91, 2,
        10, 84, 29, 50, 6234, 17, 80, 93, 1, 37,
        71, 15, 62, 4, 81, 275, 777, 91, 31, 59,
        14, 85, 35, 49, 4, 73, 262, 932, 18, 60,
        47, 79, 25, 100, 36, 13, 65, 90, 58, 40,
        97, 22, 87, 32, 700, 16, 38, 83, 95, 48,
        28, 75, 20, 44, 343, 86, 94, 21, 55, 30,
        68, 34, 74, 53, 81, 24, 57, 39, 626, 46,
        99, 11, 67, 42, 4558, 159, 564, 233, 91,
        10, 84, 29, 50, 6, 17, 80, 93, 1233, 37,
        71, 1225, 62, 41, 98, 27, 77, 9, 31, 59,
        14, 85, 35, 49, 566, 73, 26, 92, 18, 60,
        47, 79, 25, 100, 36, 13, 65, 90, 58, 40,
        97, 22, 87, 456, 70, 16, 33458, 823, 95,
        28, 75, 20, 44, 63, 86, 94, 221, 232355,
        123, 908, 47, 365, 2501, 674, 985, 210, 44, 3821,
        72, 156, 499, 863, 302, 709, 54, 391, 27, 642340,
        15, 88, 420, 335, 901, 278, 659, 743, 12282, 904,
        317, 58, 820, 44, 710, 634, 928, 122111, 59, 360,
        111, 222, 333, 444, 555, 666, 777, 888, 999, 900,
        1023, 567, 981, 431, 221, 842, 13, 75, 9221, 604,
        432, 987, 145, 789, 654, 321, 1111, 2020, 303040,
        5050, 6060, 7070, 8080, 9090, 12, 17, 83, 250, 7,
        421, 678, 809, 190, 340, 240, 415, 99, 255, 1224,
        561, 7824, 679, 321, 452, 876, 912, 645, 713, 58,
        973453, 654, 739, 81, 34343, 930, 241, 3277, 609,
        120, 420, 670, 930, 210, 87, 54, 901, 740, 30023,
        50, 150, 250, 350, 450, 550, 650, 750, 850, 9503,
        16, 27, 39, 41, 58, 64, 73, 85, 96, 108, 4650315,
        118, 132, 145, 159, 173, 184, 195, 207, 219, 230,
        9999, 12000, 8001, 4200, 1002, 710, 312, 415, 13,
        668, 534, 474, 533, 81, 254, 57, 34459, 917, 932,
        76, 43, 999, 7129, 88, 54, 852, 561, 552, 96, 51,
        120, 115, 133, 142, 129, 137, 124, 150, 119, 101,
        143, 138, 122, 109, 130, 107, 134, 127, 141, 136,
        108, 117, 132, 123, 125, 116, 114, 140, 135, 121,
        139, 118, 145, 113, 147, 146, 128, 111, 112, 149,
        153, 154532, 54155, 154, 156, 157, 158, 159, 160,
        161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
        171, 172, 173, 174, 175, 176, 177, 178, 179, 180,
        181, 182, 183, 184, 185, 186, 187, 188, 189, 190,
        234182, 344183, 1831, 134185, 14386, 1874, 41884,
        191, 192, 193, 194, 195, 196, 197, 198, 199, 200,
        153, 4567, 151, 155, 2456, 156, 157, 124558, 159,
        161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
        171, 1572, 34507, 174, 9748274, 176, 177, 144748,
        181, 182, 1483, 1844, 185, 186, 187, 1838, 48494, 
        1591, 192, 193, 194, 195, 196, 197, 1968, 194294,
        58, 14, 959, 72, 656, 45, 9156, 325, 7744583, 34,
        1139, 1128, 1435, 1143, 1475, 1466, 1728, 188531,
        1853, 1545732, 541655, 155434, 41561, 1357, 1258,
        1368, 2473, 1963, 345, 45, 136, 162, 2468, 12259,
        762, 343, 4999, 71529, 78868, 55674, 852, 561995, 
        447, 444, 568, 999, 7777, 8853, 124, 7647, 18819,
        143, 33354, 122, 109, 89076, 78899, 226644, 2235,
        11134, 24456, 3556, 356, 4442, 13368, 169, 93875,
        3507, 99989, 55039, 1734, 459767, 175556, 174467,
        33059, 344595, 183, 30587, 45039, 186, 187, 3086,
        236505, 23005, 224958, 348602, 5475, 767676, 989,
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
            printf("Tableau pas triee normal pas de tri encore fait\n");
        }

    start = clock();
    selection_sort(arr, N);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort terminer en %.9f secondes\n", time_taken);
    if (is_sorted_nondecreasing(arr, N))
        printf("Tableau trier correctement avec selection_sort\n\n");


    // Bubble Sort
    copy_array(tableau, arr, N);
    start = clock();
    bubble_sort(arr, N);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort terminer en %.9f secondes\n", time_taken);

    if (is_sorted_nondecreasing(arr, N))
        printf("Tableau triee correctement avec bubble_sort\n\n");


    
    // Insertion Sort
    copy_array(tableau, arr, N);
    start = clock();
    insertion_sort(arr, N);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion sort terminer en %.9f secondes\n", time_taken);

    if (is_sorted_nondecreasing(arr, N))
        printf("Tableau trier correctement avec insertion_sort\n\n");


    // merge sort
    copy_array(tableau, arr, N);
    start = clock();
    merge_sort(arr, N);
    end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("merge sort terminer en %.9f secondes\n", time_taken);

    if (is_sorted_nondecreasing(arr, N))
        printf("Tableau trier correctement avec merge_sort\n\n");

    // quick sort
    copy_array(tableau, arr, N);
    start = clock();
    quick_sort(arr, N);
    end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("quick sort terminer en %.9f secondes\n", time_taken);

    if (is_sorted_nondecreasing(arr, N))
        printf("Tableau trier correctement avec quick_sort\n\n");


    free(arr);
    return 0;
}

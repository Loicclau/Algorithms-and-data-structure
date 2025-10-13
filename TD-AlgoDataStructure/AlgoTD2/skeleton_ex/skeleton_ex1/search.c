#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)  // que si cest trier
{
    // linear search on array, return index
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;
}




int jump_search(int *arr, int n, int target)  //si pas trier
{
    // jump search on sorted array, return index
    // of target, return -1 if not found
    return -1;
}

int binary_search(int *arr, int n, int target)
{
    // binary search on sorted array, return index
    // of target, return -1 if not found
    return -1;
}
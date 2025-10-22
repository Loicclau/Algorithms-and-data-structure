#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n) //Temps : O(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i; 

        // cherche le plus petit
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // Pour échanger
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void insertion_sort(int *arr, int n) { //Temps : O(n^2)
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];       // élément a mettre
        int j = i - 1;

        // déplacer tous les éléments plus grands que key vers la droite
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // placer key à sa position correcte
        arr[j + 1] = key;
    }
}


// ont change la solution plusieur fois
void bubble_sort(int *arr, int n) { //Temps : O(n^2) horribleee  
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)  // -i pour pas refaire de calcul sur les triee
        {
            if (arr[j] > arr[j + 1])
            {
                swap_int(&arr[j], &arr[j + 1]); // swap si j plus grand
            }
        }
    }
}


// divise tout, trie et fusionne
//arr = [2, 5, 8 | 1, 3, 9]
//          i=l      j=m+1
void merge(int *arr, int *tmp, int l, int m, int r)
{
    int i = l;      // début du premier sous-tableau
    int j = m + 1;  // début du second sous-tableau
    int k = l;      // début pour tmp

    // fusionner les deux sous-tableaux
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    // copie les éléments restants du premier sous-tableau
    while (i <= m)
        tmp[k++] = arr[i++];

    // copie les éléments restants du second sous-tableau
    while (j <= r)
        tmp[k++] = arr[j++];

    // copie tmp(le résultat) dans arr
    for (i = l; i <= r; i++)
        arr[i] = tmp[i];
}

//tableau temporaire recursif
void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    if (l >= r) // arr deja triee
        return;

    int m = l + (r - l) / 2;

    // trier récursivement la moitié gauche et droite
    mergesort_rec(arr, tmp, l, m);
    mergesort_rec(arr, tmp, m + 1, r);

    // fusionne les deux moitiés
    merge(arr, tmp, l, m, r);
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return; //on trie pas
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}



int partition(int *arr, int l, int r)
{
    int pivot = arr[r]; // Dernier en Pivot
    int i = l - 1;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // swap arr[i] and arr[j] si plus petit que le pivot
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    // place bien le pivot 
    int tmp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = tmp;
    return i + 1;
}

// en recursive
void quick_sort_rec(int *arr, int l, int r)
{
    if (l < r) { // si il y a 2 elements
        int p = partition(arr, l, r);  // position du pivot
        quick_sort_rec(arr, l, p-1);     // tri de gauche
        quick_sort_rec(arr, p+1, r);     // tri de droite
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}
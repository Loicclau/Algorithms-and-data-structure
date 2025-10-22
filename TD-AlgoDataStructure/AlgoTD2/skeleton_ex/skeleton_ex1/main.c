#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int target = 199988;
    int arr[] = {421, 15, 398, 72, 493, 120, 351, 260, 44, 311, 278, 442, 137, 84, 35, 491, 199, 463, 86, 234,
    470, 18, 189, 436, 94, 268, 305, 392, 347, 362, 59, 297, 382, 279, 431, 176, 105, 418, 286, 70,
    403, 413, 364, 275, 64, 201, 153, 214, 280, 269, 295, 312, 388, 244, 116, 491, 174, 140, 440, 256,
    318, 250, 446, 300, 382, 336, 208, 414, 275, 49, 360, 333, 482, 161, 437, 190, 40, 163, 471, 141,
    339, 247, 195, 365, 478, 331, 203, 142, 219, 399, 390, 298, 426, 170, 282, 260, 467, 204, 343, 328,
    299, 400, 457, 134, 200, 329, 327, 169, 376, 221, 420, 317, 165, 493, 248, 181, 475, 487, 186, 273,
    356, 411, 285, 380, 143, 290, 359, 490, 427, 475, 464, 418, 495, 394, 372, 355, 83, 389, 372, 305,
    362, 343, 332, 220, 452, 284, 402, 276, 303, 253, 488, 199, 464, 167, 478, 282, 470, 380, 436, 342,
    154, 208, 322, 341, 405, 314, 455, 304, 498, 160, 431, 478, 384, 426, 389, 355, 308, 340, 346, 272,
    309, 285, 487, 253, 361, 370, 388, 450, 294, 123456, 152, 149, 192, 299, 457, 485, 123, 249, 316, 489,
    411, 245, 368, 329, 172, 309, 272, 301, 341, 280, 219, 268, 285, 297, 344, 223, 252, 261, 273, 254,
    122, 232, 310, 277, 293, 306, 325, 319, 307, 326, 327, 330, 335, 337, 338, 342, 345, 349, 350, 352,
    354, 357, 358, 361, 363, 366, 367, 369, 371, 373, 374, 375, 377, 378, 379, 381, 383, 385, 386, 387,
    391, 393, 395, 396, 397, 401, 404, 406, 407, 408, 409, 410, 412, 415, 416, 417, 419, 422, 423, 424,
    425, 428, 429, 430, 432, 433, 434, 435, 438, 439, 441, 443, 444, 445, 447, 448, 449, 451, 453, 454,
    456, 458, 459, 460, 461, 467, 465, 466, 468, 469, 472, 473, 474, 476, 477, 479, 480, 481, 483, 484,
    486, 492, 494, 496, 497, 3567, 500, 1, 42, 475, 4, 5, 78, 7, 8, 9, 10, 8, 143, 138, 122, 109, 1, 7, 54, 
    11, 12, 13, 14, 16, 17, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 579, 127, 141, 136, 108, 117, 132, 
    31, 32, 33, 34, 36, 37, 38, 39, 40, 41, 42, 43, 46, 47, 48, 50, 51, 52, 864, 54,
    55, 56, 57, 58, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 73, 74, 75, 76,
    77, 78, 79, 8056, 81, 82, 85, 86, 87, 88, 89, 90, 91, 92, 93, 3, 96, 78, 683, 468,
    100, 101, 102, 103, 104, 106, 107, 108, 109, 110, 111, 876, 113, 114, 115, 117, 118, 119, 121, 124,
    125, 126, 127, 128, 129, 130, 131, 132, 133, 135, 136, 138, 139, 144, 145, 146, 147, 148, 150, 151,
    195, 156, 77, 89, 159, 162, 14, 166, 168, 71, 1773, 175, 177, 17856, 179, 180, 182, 183, 184, 185,
    187, 188, 191, 193, 194, 196, 197, 198, 202, 205, 206, 207, 209, 210, 211, 212, 213, 215, 216, 217,
    218, 222, 224, 225, 226, 227, 228, 229, 230, 231, 233, 235, 236, 237, 238, 239, 240, 241, 242, 246,
    251, 255, 257, 258, 259, 262, 263, 264, 265, 266, 267, 270, 271, 274, 281, 283, 287, 288, 289, 291,
    29234, 294, 296, 302, 30445, 306, 307, 308, 39906, 313, 3, 50, 5674, 321, 323, 24, 325, 326, 327, 330, 334,
    335, 336, 337, 338, 339, 340, 341, 344, 3453, 346, 199988, 349, 350, 351, 352, 353, 354, 355, 356, 3575,
    123, 125, 116, 114, 140, 135, 78, 12, 118, 145, 12, 113, 147, 146, 128, 111, 23, 679, 43, 79, 457, 68,
    112, 149, 153, 152, 151, 155, 154, 13, 456, 69, 36, 156, 157, 158, 159, 7}; // Non trié

    int arr_sorted[199999];
    for (int i = 0; i < 199999; i++) {
        arr_sorted[i] = i + 1; 
    }

    // sizeof(arr) → taille totale en octets
    // sizeof(arr[0]) → taille d’un élément
    int n1 = sizeof(arr) / sizeof(arr[0]); // 40 / 4 = 10, donc le tableau a 10 éléments
    int n2 = sizeof(arr_sorted) / sizeof(arr_sorted[0]);
    clock_t start, end;
    double cpu_time_used;

    int index;
    // --- Premier tableau non sort donc linear---
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
        start = clock();
        index = linear_search(arr, n1, target);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("linear_search a pris %.9f secondes.\n\n", cpu_time_used);
        if (index != -1)
            printf("Linear search : valeur %d trouvee a l'indice %d.\n", target, index);
        else
            printf("Linear search : valeur %d non trouvee.\n", target);
    } // tableau non trié
    


    // --- Deuxième tableau sort ont fait les autres ---
    printf("\nTableau 2 :\n");
    if (is_sorted_nondecreasing(arr_sorted, n2)) {
        start = clock();
        index = jump_search(arr_sorted, n2, target);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("jump_search a pris %.9f secondes.\n", cpu_time_used);

        if (index != -1)
            printf("Jump search : valeur %d trouvee a l'indice %d.\n", target, index);
        else
            printf("Jump search : valeur %d non trouvee.\n", target);
        start = clock();
        index = binary_search(arr_sorted, n2, target);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("binary_search a pris %.9f secondes.\n", cpu_time_used);

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

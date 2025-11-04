#include <stdio.h>
#include <stdlib.h>

/* ---------- Fonction de comparaison pour qsort ---------- */
int comparer(const void *a, const void *b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return -1;   // ordre croissant
    if (x > y) return 1;
    return 0;
}

/* ---------- Recherche binaire dans arr1 trié ---------- */
int contient(long long *arr, int taille, long long valeur) {
    int gauche = 0;
    int droite = taille - 1;
    while (gauche <= droite) {
        int milieu = (gauche + droite) / 2;
        if (arr[milieu] == valeur)
            return 1;  // trouvé
        else if (arr[milieu] < valeur)
            gauche = milieu + 1;
        else
            droite = milieu - 1;
    }
    return 0; // pas trouvé
}

/* ---------- Comparer deux fichiers ---------- */
int comparerFichiers(const char *fichier1, const char *fichier2) {
    FILE *f1 = fopen(fichier1, "r");
    FILE *f2 = fopen(fichier2, "r");

    if (f1 == NULL || f2 == NULL) {
        perror("Erreur d'ouverture d'un fichier");
        return -1; // erreur d’ouverture
    }

    int c1, c2;
    int position = 0;

    while (1) {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        position++;

        if (c1 != c2) {
            fclose(f1);
            fclose(f2);
            return position; // retourne la position du premier caractère différent
        }

        if (c1 == EOF || c2 == EOF)
            break;
    }

    fclose(f1);
    fclose(f2);

    if (c1 == EOF && c2 == EOF)
        return 0; // fichiers identiques
    else
        return position; // différences de longueur
}

/* ---------- Programme principal ---------- */
int main(void) {
    FILE *fichier = fopen("test06.txt", "r");

    int n1, n2;
    long long *arr1 = NULL;
    long long *arr2 = NULL;

    /* Lire n1 et le tableau arr1 */
    if (fscanf(fichier, "%d", &n1) != 1 || n1 <= 0) {
        fprintf(stderr, "Erreur: lecture n1 invalide.\n");
        fclose(fichier);
        return 2;
    }
    arr1 = malloc(n1 * sizeof(long long));
    for (int i = 0; i < n1; i++) {
        if (fscanf(fichier, "%lld", &arr1[i]) != 1) {
            fprintf(stderr, "Erreur lecture arr1[%d]\n", i);
            free(arr1);
            fclose(fichier);
            return 3;
        }
    }

    /* Lire n2 et le tableau arr2 */
    if (fscanf(fichier, "%d", &n2) != 1 || n2 < 0) {
        free(arr1);
        fclose(fichier);
        return 4;
    }
    arr2 = malloc(n2 * sizeof(long long));
    for (int i = 0; i < n2; i++) {
        if (fscanf(fichier, "%lld", &arr2[i]) != 1) {
            free(arr1);
            free(arr2);
            fclose(fichier);
            return 5;
        }
    }

    fclose(fichier);

    /* Tri du premier tableau */
    qsort(arr1, n1, sizeof(long long), comparer);

    /* Ouvrir le fichier de sortie */
    FILE *sortie = fopen("resultats.txt", "w");
    if (!sortie) {
        free(arr1);
        free(arr2);
        return 6;
    }

    printf("\n--- Verification des ID du 2e tableau --- ");
    for (int i = 0; i < n2; i++) {
        if (contient(arr1, n1, arr2[i])) {
            fprintf(sortie, "YES\n");
            //  printf("YES\n", arr2[i]);
        } else {
            fprintf(sortie, "NO\n");
            //  printf("NO\n", arr2[i]);
        }
    }

    fclose(sortie);

    /* Comparaison du fichier généré avec un fichier attendu */
    int diff = comparerFichiers("resultats.txt", "test06-output.txt");

    if (diff == 0)
        printf("\n Les fichiers sont identiques.\n\n");
    else if (diff > 0)
        printf("\n  Différence détectée à la position %d.\n", diff);
    else
        printf("\n Erreur lors de la comparaison.\n");

    /* Nettoyage mémoire */
    free(arr1);
    free(arr2);

    return 0;
}

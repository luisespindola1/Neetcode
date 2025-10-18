#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra {
    char word[200];
    int idx_original;
} Palavra;

// função de comparação usada pelo qsort
int cmpPalavra(const void *a, const void *b) {
    const Palavra *pa = (const Palavra *)a;
    const Palavra *pb = (const Palavra *)b;
    return strcmp(pa->word, pb->word); // ordem alfabética
}

int cmpChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
    Palavra *sorted_strs = malloc(strsSize * sizeof(Palavra));

    for (int i = 0; i < strsSize; i++) {
        strcpy(sorted_strs[i].word, strs[i]);
        qsort(sorted_strs[i].word, strlen(sorted_strs[i].word), sizeof(char), cmpChar);
        sorted_strs[i].idx_original = i;
    }

    qsort(sorted_strs, strsSize, sizeof(Palavra), cmpPalavra);

    *returnSize = 0;
    int count_column = 1;

    *returnColumnSizes = malloc(strsSize * sizeof(int));

    for (int i = 0; i < strsSize - 1; i++) {
        if (strcmp(sorted_strs[i + 1].word, sorted_strs[i].word) == 0) {
            count_column++;
        } else {
            (*returnColumnSizes)[*returnSize] = count_column;
            (*returnSize)++;
            count_column = 1;
        }
    }

    (*returnColumnSizes)[*returnSize] = count_column;
    (*returnSize)++;

    char ***anagrams = malloc((*returnSize) * sizeof(char **));

    for (int i = 0; i < *returnSize; i++) {
        anagrams[i] = malloc((*returnColumnSizes)[i] * sizeof(char *));
    }

    int idx1 = 0;
    int idx2 = 0;


    anagrams[idx1][idx2++] = strs[sorted_strs[0].idx_original];

    for (int i = 1; i < strsSize; i++) {
        if (strcmp(sorted_strs[i].word, sorted_strs[i - 1].word) == 0) {
            anagrams[idx1][idx2++] = strs[sorted_strs[i].idx_original];
        } else {
            idx1++;
            idx2 = 0;
            anagrams[idx1][idx2++] = strs[sorted_strs[i].idx_original];
        }
    }

    free(sorted_strs);

    return anagrams;
}
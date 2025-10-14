#include <stdio.h>
#include <stdlib.h>

int* sum(int *array, int n, int target, int *returnsize){

    int *result = malloc(2 * sizeof(int));
    int found = 0;
    for(int d = 0; d < n - 1 && !found; d++){
         for(int i = d + 1; i < n; i++){
            if(array[d] + array[i] == target){
                result[0] = d;
                result[1] = i;
                *returnsize = 2;
                return result;
            }
         }
     }
     
     *returnsize = 0;
     return NULL;

}

int main(){
    int n, target;

    scanf("%d", &n);

    int array[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    scanf("%d", &target);

    int returnsize;

    int *result = sum(array, n, target, &returnsize);

    if (returnsize == 2) {
        printf("[%d %d]\n", result[0], result[1]);
        free(result);  // Libere a memória alocada
    } else {
        printf("No valid pair found.\n");
    }

    return 0;
}
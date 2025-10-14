/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


 typedef struct numero{
    int valor; //valor
    int count; //aparicoes
}Numero;

int sort(const void* a, const void* b){
    return *(int*) a - *(int*)b;
}

int sort_struct(const void* a, const void* b){
    Numero* a1 = (Numero*)a;
    Numero* a2 = (Numero*)b;

    return a2->count - a1->count; //ordem decrescente de count
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    *returnSize = k; 
    int* array_return = (int*) malloc(k * sizeof(int)); //aloca vetor de retorno

    qsort(nums, numsSize, sizeof(int), sort);
    
    Numero* unique_nums;
    unique_nums = (Numero*) malloc(numsSize * sizeof(Numero)); //aloca espaco do tamanho do array
    int numero_atual;
    int idx = 0;
    for(int i = 0; i < numsSize; i++){ 
        if(i == 0 || numero_atual != nums[i]){ //novo numero
            numero_atual = nums[i]; 
            unique_nums[idx].valor = numero_atual; 
            unique_nums[idx].count = 0; 
            idx++;
        }

        unique_nums[idx - 1].count++; //incrementa

    }

    qsort(unique_nums, idx, sizeof(Numero), sort_struct); //sort structs

    for(int i = 0; i < k; i++){
        *(array_return + i) = unique_nums[i].valor;
    }

    return array_return;

}
int comp(const void* a, const void* b){

    return *(int*)a - *(int*)b; //crescente
}


bool containsDuplicate(int* nums, int numsSize) {

    int local_array[numsSize];

    for(int i = 0; i < numsSize; i++){
        local_array[i] = *(nums + i);
    }

    qsort(local_array, numsSize, sizeof(int), comp);
    
    for(int i = 0; i < numsSize - 1; i++){
        if(local_array[i] == local_array[i + 1]) return true;
    }

    return false;
}
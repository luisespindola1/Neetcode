/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int sum;

    int i = 0;
    int j = numbersSize - 1;

    sum =  numbers[i] + numbers[j]; //soma dos extremos
    while(sum != target && i != j){
        if(sum < target){
            i++;
        }
        else{
            j--;
        }
        sum = numbers[i] + numbers[j];
    }

    int* return_array = (int*) malloc(2 * sizeof(int));
    return_array[0] = i + 1;
    return_array[1] = j + 1;

    *returnSize = 2;

    return return_array;
}
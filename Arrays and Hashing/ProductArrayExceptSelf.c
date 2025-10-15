/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*) malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int left = 1;
    for(int i = 0; i < numsSize; i++){ //guarda o produto dos numeros a esquerda
        answer[i] = left;
        left *= nums[i];
    }

    int right = 1;
    for(int i = numsSize - 1; i >= 0; i--){ //multiplica pelo produto dos numeros da direita
        answer[i] *= right;
        right *= nums[i];
    }

    return answer;
}
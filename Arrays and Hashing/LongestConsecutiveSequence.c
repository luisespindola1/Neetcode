int sort(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}


int longestConsecutive(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), sort);

    int curr_length = 1;
    int max_length = 0;
    for(int i = 0; i < numsSize; i++){
        if(i != numsSize - 1 && (nums[i] == nums[i + 1] - 1)){
            curr_length++;
        }
        else if(i != numsSize - 1 && (nums[i] == nums[i + 1])){
            continue;
        }
        else{
            if(curr_length > max_length){
                max_length = curr_length;
            }

            curr_length = 1;
        }
    }

    return max_length;
}
int maxArea(int* height, int heightSize) {

    int max_area;
    int curr_area;
    if(height[0] > height[heightSize - 1]){
        max_area = height[heightSize - 1] * (heightSize - 1);
    }
    else{
        max_area = height[0] * (heightSize - 1);
    }

    int i = 0;
    int j = heightSize - 1;
    while(i < j){
        if(height[i] >= height[j]){
            int new_j = j;
            while(height[new_j] <= height[j] && new_j != i){
                new_j--;
            }
            if(new_j == i){
                break;
            }
            if(height[i] >= height[new_j]){
                curr_area = height[new_j] * (new_j - i);
            }
            else{
                curr_area = height[i] * (new_j - i);
            }   

            j = new_j;
        }
         else{
            int new_i = i;
            while(height[new_i] <= height[i] && new_i != j){
                new_i++;
            }
            if(new_i == j){
                break;
            }
            if(height[j] >= height[new_i]){
                curr_area = height[new_i] * (j - new_i);
            }
            else{
                curr_area = height[j] * (j - new_i);
            }   

            i = new_i;
        }

        if(curr_area > max_area){
                max_area = curr_area;
        }
        
    }

    return max_area;
}
#include <stdio.h>
#include <string.h>

bool IsPalindrome(int n){

    char number_original[50];

    sprintf(number_original, "%d", n); // int pra string

    int end = strcspn(number_original, "\0");

    int temp = end;

    for(int i = 0; i < end; i++){
        if(number_original[i] != number_original[temp - 1]){
            return false;
        }

        temp--;
    }

    return true;
    

}

int main(){
    int n;

    scanf("%d", &n);

    bool answer = IsPalindrome(n);

    if(answer == false){
        printf("False\n");
    }

    else{
        printf("True\n");
    }

    return 0;
}
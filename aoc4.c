#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LEN 200
#define X_LEN 200
#define Y_LEN 200

int main(){
    

    // part 1
    // open file
    FILE * file =  fopen("./data/4_data.txt", "r");
    if(file == NULL){
        printf("file not found\n");
    }
    
    // buffer in
    char str[LEN];
    // initialize result of part 1
    int count1 = 0;
    int count2 = 0;
    int matrix[X_LEN][Y_LEN] = {0};
    // find coun1
    int y_max = 0;
    int x_max = 0;
    while(fgets(str, LEN*sizeof(char), file) != NULL){
        int len = strlen(str);
        x_max = len;
        for(int i = 0; i<len; i++){
            if(str[i] == 64)
            matrix[y_max][i] = 1;
            else
            matrix[y_max][i] = 0;
        }
        y_max++;
    }
    fclose(file);
    
    // part 1
    for(int j = 0; j<y_max; j++){
        for(int i = 0; i<x_max; i++){
            if(matrix[j][i]  == 1){
                int at = 0;
                // eight cases
                if(i > 0) at += matrix[j][i-1];
                if(j > 0) at += matrix[j-1][i];
                if(i < x_max) at += matrix[j][i+1];
                if(j < y_max) at += matrix[j+1][i];
                if(i < x_max && j < y_max) at += matrix[j+1][i+1];
                if(i > 0 && j < y_max) at += matrix[j+1][i-1];
                if(i > 0 && j > 0) at += matrix[j-1][i-1];
                if(i < x_max && j > 0) at += matrix[j-1][i+1];
                if(at<4){
                    count1++;
                }
            }
        }
    }
    
    // part 2
    int check = 1;
    while(check){
        check = 0;
        for(int j = 0; j<y_max; j++){
            for(int i = 0; i<x_max; i++){
                if(matrix[j][i]  == 1){
                    int at = 0;
                    // eight cases
                    if(i > 0) at += matrix[j][i-1];
                    if(j > 0) at += matrix[j-1][i];
                    if(i < x_max) at += matrix[j][i+1];
                    if(j < y_max) at += matrix[j+1][i];
                    if(i < x_max && j < y_max) at += matrix[j+1][i+1];
                    if(i > 0 && j < y_max) at += matrix[j+1][i-1];
                    if(i > 0 && j > 0) at += matrix[j-1][i-1];
                    if(i < x_max && j > 0) at += matrix[j-1][i+1];
                    if(at<4){
                        count2++;
                        check++;
                        matrix[j][i] = 0;
                    }
                }
            }
        }
    }
    
    // result part 1
    printf("%d\n", count1);
    // result part 2
    printf("%d\n", count2);
}

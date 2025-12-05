#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define LEN 500

int main(){
    

    // part 1
    // open file
    FILE * file =  fopen("./data/3_data.txt", "r");
    if(file == NULL){
        printf("file not found\n");
    }
    
    // buffer in
    char str[LEN];
    // initialize result of part 1
    int count1 = 0;
    long long count2 = 0;
    // find coun1
    while(fgets(str, LEN*sizeof(char), file) != NULL){
        
        // part 1
        int len_str = strlen(str)-1;
        int buf = 0;
        int max_j = 0;
        int max_i = 0;
        for(int i = 0; i<len_str; i++){
            for(int j = i+1; j<len_str; j++){
                buf = (str[i]-48)*10+(str[j]-48);
                if(buf > max_j){
                    max_j = buf;
                }
            }
            if (max_j > max_i) max_i = max_j;
        }
        count1 += max_j;
        
        // part 2
        len_str++;
        int k = 0;
        for(int j=13; j>1; j--){
            int max = 0;
            for(int i = k; i<=len_str-j; i++){
                if(max < str[i]- '0') {
                    max = str[i]- '0';
                    k = i+1;
                }
            }
            count2 += (long long)max* (long long)pow(10,j-2);
        }
    }
    fclose(file);
    
    // result part 1
    printf("%d\n", count1);
    // result part 2
    printf("%lld\n", count2);
}

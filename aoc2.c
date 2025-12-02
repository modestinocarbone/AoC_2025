#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define LEN 2000

// String to long int
long int atoli(char *cnum){
    long int inum = 0 ;
    int len = strlen(cnum);
    for(int i = 0; i<len; i++){
        inum += (long int)(cnum[i]-48)*(long int)pow(10,len-1-i);
    }
    return inum;
}

// Check if number is valid or not
int is_valid_1(char *num){
    int len = strlen(num);
    if(len%2 == 0){
        for(int i = 0; i<len; i++){
            if(num[i] != num[i+len/2]) break;
            if(i == len/2 - 1) return 1;
        }
    }
    return 0;
}

int is_valid_2(char *num){
    int len = strlen(num);
    for(int i = 2; i<=len; i++){
        if(len%i == 0){
            for(int j = 0; j< len - len/i; j++){
                if(num[j] != num[j+len/i]) break;
                if(j == len - len/i -1) return 1;
            }
        }
    }
    return 0;
}

int main(){
    
    // open file
    FILE * file =  fopen("./data/2_data.txt", "r");
    if(file == NULL){
        printf("file not found\n");
    }
    
    // buffer in
    char str[LEN];
    
    // capture input
    if(fgets(str, LEN*sizeof(char) ,file) != NULL){
        //printf("%s\n", str);
    }

    int len_str = strlen(str);
    char num[20];
    int len = 1;
    long int from = 0;
    long int to = 0;
    long int count1 = 0;
    long int count2 = 0;
    for(int i = 0; i<len_str; i++){
        if(str[i] == ',' || str[i] == '\n'){
            to  = atoli(num);
            for(long int k = from; k <= to; k++){
                char buff[20];
                sprintf(buff, "%ld", k);
                if(is_valid_1(buff)){
                    count1 += k;
                }
                if(is_valid_2(buff)){
                    count2 += k;
                }
            }
            num[0] = '\0';
            len = 1;
        } else if(str[i] == '-'){
            from  = atoli(num);
            num[0] = '\0';
            len = 1;
        } else {
            // here only when a number is detected
            num[len-1] = str[i];
            num[len] = '\0';
            len++;
        }
    }
    
    // result part 1
    printf("%ld\n", count1);
    // result part 2
    printf("%ld\n", count2);

}

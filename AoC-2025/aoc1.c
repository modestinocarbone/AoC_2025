#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int abs(int x){
    if (x<0){
        return -x;
    }
    return x;
}
int main(){
    
    // open file
    FILE * file =  fopen("./data/1_data.txt", "r");
    if(file == NULL){
        printf("file not found\n");
    }
    
    //dial start
    int dial = 50;
    int count1 = 0;
    int count2 = 0;
    // buffer in
    char str[6];
    
    // elaboration loop
    for(int i=0; fgets(str, 6*sizeof(char) ,file) != NULL; i++){
        
        int len = strlen(str)-3;
        int num = 0;
        for(int j=1; str[j] != '\n'; j++){
            num += ((int)str[j]-48)*pow(10,len);
            len--;
        }
        
        int old_dial = dial;
        int mul;

        if(str[0] == 'R'){
            dial += num;
            mul = dial/100;
        } else {
            dial -= num;
            mul = abs(dial/100);
        }
     
        if(mul > 0){
            count2 += mul;
            if(old_dial*dial<0) count2++;
            if(dial%100 == 0) count2--;
        }
        
        if(old_dial*dial<0 && mul == 0) count2++;
        
        dial = dial%100;
        
        if(dial == 0) count1++;
        
    }
    
    // let's sum again 0 cases
    count2 += count1;
    // result part 1
    printf("%d\n", count1);
    // result part 2
    printf("%d\n", count2);
    
}

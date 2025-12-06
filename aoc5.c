#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LEN 200
#define NUMBER_ROW 2000
#define NUMBERS 1000

// String to long int
long long atoli(char *cnum){
    long long inum = 0 ;
    int len = strlen(cnum);
    for(int i = 0; i<len; i++){
        inum += (long long)(cnum[i]-48)*(long long)pow(10,len-1-i);
    }
    return inum;
}

int main(){

    FILE * file =  fopen("./data/5_data.txt", "r");
    if(file == NULL){
        printf("file not found\n");
    }
    
    int row = 0;
    int number = 0;
    // initialize result
    int count1 = 0;
    long long count2 = 0;
    // buffer in
    char str[NUMBER_ROW][LEN];
    while(fgets(str[row], LEN*sizeof(char), file) != NULL){
        int slen = strlen(str[row]);
        str[row][slen-1] = '\0';
        if(strcmp(str[row], "") == 0){
            number = row;
        }
        row++;
    }
    fclose(file);
    
    // part 1
    for(int i = number; i < row; i++){
        for(int j = 0; j < number; j++){
            long long min, max;
            sscanf(str[j],"%lld-%lld", &min, &max);
            long long n = atoli(str[i]);
            if (n <= max && n >= min){
                count1++;
                break;
            }
        }
        long long n = atoli(str[i]);
    }
    
    // part 2
    long long mat[NUMBERS][2];
    for(int i = 0; i < number; i++){
        long long min, max;
        sscanf(str[i],"%lld-%lld", &min, &max);
        mat[i][0] = min;
        mat[i][1] = max;
    }
    
    
    for(int k = 0; k < number; k++){
        for( int i = 0; i < number; i++ ){
            if( mat[i][1] > mat[i][0] -1){
                long long diff = mat[i][1] - mat[i][0]+1;
                
                for(int j = i+1; j < number; j++){
                    
                    if( mat[j][1] > mat[j][0] -1){
                        long long diff1 = mat[j][0] - mat[i][0];
                        long long diff2 = mat[j][1] - mat[i][1];
                        if( diff1>=0 &&  diff2>0 && diff1<diff ){
                            mat[i][1] = mat[j][1];
                            mat[j][1] = mat[j][0]-1;
                            break;
                        }
                        if( diff1<0 && diff2<=0 && -diff2<diff ){
                            mat[i][0] = mat[j][0];
                            mat[j][1] = mat[j][0]-1;
                            break;
                        }
                        if( diff1<0 && diff2>0 ){
                            mat[i][1] = mat[j][1];
                            mat[i][0] = mat[j][0];
                            mat[j][1] = mat[j][0]-1;
                            break;
                        }
                        if( diff1>=0 && diff2<=0 ){
                            mat[j][1] = mat[j][0]-1;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < number; i++){
        count2 += mat[i][1] - mat[i][0] + 1;
        if(mat[i][1] - mat[i][0] +1< 0){
           printf("%d,%lld-%lld: %lld\n",i, mat[i][0] , mat[i][1], count2);
        }
    }
    
    //result 1
    printf("%d\n", count1);
    //result 1
    printf("%lld\n", count2);
    
}

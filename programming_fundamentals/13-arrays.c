
/*
  Simple arrays and pointers
  Cristofer
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    int data[5] = {4,3,2,1,0};
    
    printf("Working with array of numbers:\n");
    
    for(int i = 0; i < 5; i++){
        printf("The number is %d.\n", data[i]);
    }

    char str[] = {'C','r','i','s'};
    char str2[] = "Cristofer";
    int n;

    n = sizeof(str)/sizeof(str[0]);

    printf("Working with array of characteres.\n");
    printf(" Number of elements is %d.\n", n);
    
    /* print each char */
    for(int i=0; i < n; i++){
        printf("%c",str[i]);
    }

    puts("");

    for(int i=0; i < 9; i++){
        printf("%c",str2[i]);
    }

    /* print the whole array of char */
    printf("\n%s\n",str);

    return 0;
}


/*
  Open and read a file of integers into an 
  array that is created with the first integer telling you how many to read
  
  coded by Cristofer
*/

#include <stdio.h>
#include <stdlib.h>     //exit()

#define MAX 50

void read_data(FILE *ptr, int d[], int how_many)
{
    int i = 0;
    while(fscanf(ptr, "%d", &d[i]) == 1)
        i++;
}

void print_data(int d[], int size)
{
  	int i;
  	for(i = 0; i < size; i++){
    	printf("%d\t", d[i]);
    	if((i + 1) % 5 == 0) printf("\n");
  	}
    printf("\n");
}

void to_file(FILE *ptr, int d[], int how_many)
{
  	int i;
  	for(i = 0; i < how_many; i++){
    	putc(d[i], ptr);
    	if((i + 1) % 10 == 0) putc('\n', ptr);
  	}
}

double average(int d[], int size)
{
	int i;
	double avg = 0;
	for(i = 0; i < size; i++)
		avg += d[i];
	return(avg/size);
}

int main(int argc, char const *argv[])
{
    if(argc != 3){
        printf("Need: how_many_to_read input_file\n");
        exit(1);
    }

    // Reading how many int should be read
    int how_many = atoi(argv[1]);

    // Reading and print input from the file
    int data[MAX] = {0};
    FILE *ifp, *ofp;
    ifp = fopen(argv[2], "r+");
    read_data(ifp, data, how_many);
    print_data(data, how_many);

    // Averaging and printing
    printf("The average is: %.2f\n", average(data, how_many));

    ofp = fopen("answer-hw3", "w+");

    fclose(ifp);
    fclose(ofp);

    return 0;
}

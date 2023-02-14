/*
 * Compute the average weight for a population of elephant
 * seals read into an array.
 * 
 * c 4 every one course
 *
 * Cristofer Costa - 2023.02.09
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE* ptr;

	// Opening file in reading mode
	ptr = fopen("course_files\\08_elephant_seal_data.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

    int numbers[5000];
    int i = 0;              // Array index / sample counter

    // Populating the array with the raw data
    while (fscanf(ptr, "%d", &numbers[i]) != EOF)
    {
      i++;
    }

    printf("Number of samples from raw data: %d.\n", i);

    // Computing the average weight
    float sum = 0;

    for (int j = 0; j < i; j++)
       sum += numbers[j];

    printf("The average  the average weight of the northern\n" \
           "elephant seal (Mirounga angustirostris) is: %0.2f.\n", sum / i);

	fclose(ptr);
	return 0;
}

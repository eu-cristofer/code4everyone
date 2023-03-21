
/*
  Double spacing file i/o
  Command line arguments
  Cristofer
*/

#include <stdio.h>
#include <stdlib.h>     //exit()

void print_file(FILE *fptr)
{
    int c;
    rewind(fptr);
    while((c = getc(fptr)) != EOF)
        putc(c, stdout);
}

void double_spacing(FILE *ifp, FILE *ofp)
{
    int c;
    rewind(ifp);
    while((c = getc(ifp)) != EOF){
        putc(c, ofp);
        //putchar(c);
        if(c == '\n')
            putc('\n', ofp);
    }
}

int main(int argc, char *argv[])
{
    FILE *ifp, *ofp;

    if(argc != 3){
        printf("Need executable inputfile outputfile\n");
        exit(1);
    }

    ifp = fopen(argv[1], "r+");
    ofp = fopen(argv[2], "w+");
    printf("File %s is read:\n", argv[1]);
    print_file(ifp);
    printf("\n\n");
    double_spacing(ifp, ofp);
    printf("File %s is double spaced:\n", argv[2]);
    print_file(ofp);
    printf("\n\n");
    fclose(ifp);
    return 0;
}

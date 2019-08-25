#include<stdio.h>
#include<sys/time.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
/* demo script version 2.0 */

void readfile(char*,char*,int);
void writefile(char*,char*,int,int);

int main(int argc, char* argv[])
{
    // Get user input
    // 
    char block_size[64]; 
    strcpy(block_size, argv[1]);
    int iblock_size;

    iblock_size = atoi(block_size);

    // creating a pointer and allocating it with 25 KB of memory
    /************************** TODO **************************/
    // for testing purpose,there is only one memory pointer created, however
    // in phase 3, there should be at least 50 memory pointers each assigned with
    // a random amount of memory
    // suggestion: change mp into an array, use for loop to malloc each pointer
    /**********************************************************/
    char* mp = (char*)malloc(iblock_size);
    
    // clock current time as start time
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    
    // write memory block to 10 files
    /************************* TODO *****************************/
    // the following for loop should be a function, the number of files
    // should be a parameter instead of a fixed value, for each memory block
    // n files should be written. Also this is where threadding should come in.
    // suggestion: package it into a thread function
    /************************************************************/
    int i=0;
    for(i=0;i<10;i++)
    {
        //create a temp file
        char name[22];
        snprintf(name, 100, "temp%d.dat", i); // puts string into buffer
        //write to temp files
        writefile(mp,name,iblock_size,1);
        
    }
    
    //clock current time as end time
    gettimeofday(&stop, NULL);
    
    // get time difference and output result
    /************************ TODO ****************************/
    // currently, this program only displays the total duration for 10 files written using one memory block
    // this needs to be changed into displaying each memory block's writing time and a total output in the end
    // suggestion: reformat the display message and add clocking time in each loop for each memory block
    /**********************************************************/
    printf("Duration MS %'.9f\n", (double) (stop.tv_sec - start.tv_sec) * 1000 + (double) (stop.tv_usec - start.tv_usec) / 1000);
    
    return 0;
}

/************* read file into memory *************/
// currently, this function is deemed optional, but it's good to keep it in the code for future usage
void readfile(char* filename, char* memorypointer, int iblock_size)
{
    FILE* input;
    input = fopen(filename,"r");
    while (!feof(input))
    {
        fread(memorypointer,iblock_size, 1, input);
    }
    
}

/*********** write from memory to file ************/
void writefile(char* memorypointer, char* filename, int size_of_element, int num_of_element)
{
    FILE* output;
    output = fopen(filename,"wb+");
    //write to temp file
    fwrite(memorypointer,size_of_element,num_of_element,output);
}


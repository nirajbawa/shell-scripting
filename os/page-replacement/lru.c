#include <stdio.h>
#include <stdlib.h>

int findLRU(int time[], int n)
{
    int min = time[0], pos = 0;
    for (int i = 0; i < n; i++)
    {
        if(time[i]<min)
        {
            min = time[i];
            pos = i;
        }
    }
    return pos;   
}

int main()
{
    int noOfPages, noOfFrames;
   
    
    printf("\nenter the number of pages : ");
    scanf("%d", &noOfPages);
    
    int *pages = (int *) calloc(noOfPages, sizeof(int)); 

    printf("\nenter the number of frames : ");
    scanf("%d", &noOfFrames);

    int *frames = (int *) calloc(noOfFrames, sizeof(int)); 
    int *time = (int *) calloc(noOfFrames, sizeof(int)); 


    printf("\nEnter the page reference sequence :\n");
    for (int i = 0; i < noOfPages; i++)
    {
        scanf("%d", &pages[i]);
    }

    int counter = 0, faults = 0;

    for (int i = 0; i < noOfFrames; i++)
    {
        frames[i] = -1;
        time[i] = -1;
    }

    printf("\nPage Reference\tFrames\n");

    for (int i = 0; i < noOfPages; i++)
    {
        int page = pages[i], found = 0;

        for (int j = 0; j < noOfFrames; j++)
        {
            if(frames[j] == page)
            {
                found = 1;
                time[j] = counter++;
                break;
            }
        }
        

        if(!found)
        {
            int pos = findLRU(time, noOfFrames);
            frames[pos] = page;
            time[pos] = counter++;
            faults++;
        }

        printf("%d\t\t", page);

        for (int i = 0; i < noOfFrames; i++)
        {
            if(frames[i] == -1)
            {
                printf("- ");
            }
            else{
                printf("%d ", frames[i]);
            }
        }

        printf("\n");
        
    }
    
    
    printf("\nTotal page faults : %d\n", faults);

    return 0;
}
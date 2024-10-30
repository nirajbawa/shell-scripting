#include <stdio.h>
#include <stdlib.h>




int main()
{
    int numOfPage, framesSize;
    printf("\nenter number of pages : ");
    scanf("%d", &numOfPage);
    printf("\nenter number of frames : ");
    scanf("%d", &framesSize);
    int *pages = (int *) calloc(numOfPage, sizeof(int));
    int *frames = (int *) calloc(framesSize, sizeof(int));

    printf("\nenter page reference sequence : \n");
    for (int i = 0; i < numOfPage; i++)
    {
        scanf("%d", &pages[i]);
    }


    int front = 0, faults = 0;

    for (int i = 0; i < framesSize; i++)
    {
        frames[i] = -1;
    }

    printf("\nPage Reference\tFrames\n");

    for (int i = 0; i < numOfPage; i++)
    {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < framesSize; j++)
        {
            if(frames[j]==page)
            {
                found = 1;
                break;
            }
        }
        
        if(!found)
        {
            frames[front] = page;
            front = (front+1) % framesSize;
            faults++;
        }

        printf("%d\t\t", page);

        for (int j = 0; j < framesSize; j++)
        {
            if(frames[j]==-1)
            {
                printf("- ");
            }
            else{
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("\nTotal page faults : %d\n", faults);
    
    
    return 0;
}
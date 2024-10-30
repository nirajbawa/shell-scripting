#include <stdio.h>
#include <stdlib.h>


int findOptimal(int pages[], int frames[], int noOfPages, int noOfFrames, int currentIndex)
{
    int pos = -1, f=currentIndex;

    for (int i = 0; i < noOfFrames; i++)
    {
        int j;
        for (j = currentIndex; i < noOfPages; j++)
        {
            if(frames[i] == pages[j])
            {
                if(j>f)
                {
                    f = j;
                    pos = i;
                }
                break;
            }
        }
        if(j==noOfPages) return i;
    }

    return pos == -1 ? 0 : pos;
}


int main()
{

    int noOfpages;
    int noOfFrames;


    printf("\nenter number of pages : ");
    scanf("%d", &noOfpages);

    int *pages = (int *) calloc(noOfpages, sizeof(int));

    printf("\nenter the number of frames : ");
    scanf("%d", &noOfFrames);

    int *frames = (int *) calloc(noOfFrames, sizeof(int));

    printf("\nenter the page reference sequence : \n");
    for (int i = 0; i < noOfpages; i++)
    {
        scanf("%d", &pages[i]);
    }


    int faults = 0;


    for (int i = 0; i < noOfFrames; i++)
    {
        frames[i] = -1;
    }

    printf("\nPage Reference\tFrames\n");
    for (int i = 0; i < noOfpages; i++)
    {
        int page = pages[i], found = 0;
        for (int j = 0; j < noOfFrames; j++)
        {
            if(frames[j]==page)
            {
                found = 1;
                break;
            }
        }
        

        if(!found)
        {
            int replacemntIndex = -1;

            for (int j = 0; j < noOfFrames; j++)
            {
                if(frames[j]==-1)
                {
                    replacemntIndex = j;
                    break;
                }
            }

            if(replacemntIndex==-1)
            {
                replacemntIndex = findOptimal(pages, frames, noOfpages, noOfFrames, i+1); 
            }

            frames[replacemntIndex] = page;
            faults++;
        }


        printf("%d\t\t", page);

        for (int j = 0; j < noOfFrames; j++)
        {
            if(frames[j] == -1)
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
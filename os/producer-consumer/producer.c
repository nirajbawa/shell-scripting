#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10, data = 0;


void producer()
{
    -- mutex;
    ++full;
    --empty;
    data++;
    printf("\nProducer produces item number : %d\n", data);

    ++mutex;
}


void consumer()
{
    -- mutex;
    --full;
    ++empty;
   
    printf("\nConsumer consumes item number : %d\n", data);
    data--;
    ++mutex;
}




int main()
{
    int n, i;
    printf("\n1. Enter 1 for producer ");
    printf("\n2. Enter 2 for consumer ");
    printf("\n3. Enter 3 to exit");

    for (int i = 1; i > 0; i++)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            if((mutex == 1) && (empty !=0 ))
            {
                producer();
            }
            else{
                printf("The buffer is full. New data cannot be produced!");
            }
            break;
        case 2:
            if((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else{
                printf("The buffer is empty! New data cannot be consummd!");
            }
            break;
        case 3:
            exit(0);
            break; 
        default:
            exit(0);
            break;
        }
    }
    

    return 0;
}
#include<stdio.h>

void first();
void best();
void worst();

int blocks,process,bl[30],pr[30],i,j;

void main()
{
    printf("enter the number of the available blocks: ");
    scanf("%d",&blocks);
    printf("enter the number of the process: ");
    scanf("%d",&process);
    printf("enter the size of the blocks: \n");
    for(i=0;i<blocks;i++)
    {
        printf("\nblock b%d : ",i+1);
        scanf("%d",&bl[i]);
    }
    printf("enter the reqesting processes: \n");
    for(i=0;i<process;i++)
    {
        printf("\nprocess p%d : ",i+1);
        scanf("%d",&pr[i]);
    }
    first();
    best();
    worst();

}
void best()
{
    int block[30],proc[30],temp,k,flag_block[30]={0},
    flag_proc[30]={0};

    //copying 
    for(i=0;i<blocks;i++)
    {
        block[i]=bl[i];
    }
    for(i=0;i<process;i++)
    {
        proc[i]=pr[i];
    }

    //sorting using bubblesort i=1;j=0
    for(i=1;i<blocks;i++)
    {
        for(j=0;j<blocks-i;j++)
        {
            if(block[j]>block[j+1])
            {
                temp=block[j];
                block[j]=block[j+1];
                block[j+1]=temp;
            }
        }
    }

    //arragnments
    printf("\nBestfit allocation\n");
    printf("____________________\n");


    for(i=0;i<process;i++)
    {
        for(j=0;j<blocks;j++)
        {
            if(block[j]>=proc[i] && flag_block[j]==0)
            {
                for(k=0;k<blocks;k++)
                {
                    if(bl[k]==block[j])
                    {
                        break;
                    }
                }
                printf("\nprocess p%d is allocated to the block b%d of size->%d \n",i+1,k+1,block[j]);
                flag_block[j]=1;
                flag_proc[i]=1;
                break;
            }

        }
        if(flag_proc[i]==0)
        {
            printf("\nprocess p%d cannot be allocated", i + 1);
            break;
        }
    }
}


void worst()
{
    int block[30],proc[30],temp,k,flag_block[30]={0},
    flag_proc[30]={0};

    //copying 
    for(i=0;i<blocks;i++)
    {
        block[i]=bl[i];
    }
    for(i=0;i<process;i++)
    {
        proc[i]=pr[i];
    }

    //sorting using bubblesort i=1;j=0
    for(i=1;i<blocks;i++)
    {
        for(j=0;j<blocks-i;j++)
        {
            if(block[j]<block[j+1])
            {
                temp=block[j];
                block[j]=block[j+1];
                block[j+1]=temp;
            }
        }
    }

    //arragnments
    printf("\nWorstit Allocation\n");
    printf("_____________________\n");
    for(i=0;i<process;i++)
    {
        for(j=0;j<blocks;j++)
        {
            if(block[j]>=proc[i] && flag_block[j]==0)
            {
                for(k=0;k<blocks;k++)
                {
                    if(bl[k]==block[j])
                    {
                        break;
                    }
                }
                printf("\nprocess p%d is allocated to the block b%d of size->%d \n",i+1,k+1,block[j]);
                flag_block[j]=1;
                flag_proc[i]=1;
                break;
            }

        }
        if(flag_proc[i]==0)
        {
            printf("\nprocess p%d cannot be allocated", i + 1);
            break;
        }
    }
}
void first()
{
    int block[30],proc[30],temp,k,flag_block[30]={0},
    flag_proc[30]={0};

    //copying 
    for(i=0;i<blocks;i++)
    {
        block[i]=bl[i];
    }
    for(i=0;i<process;i++)
    {
        proc[i]=pr[i];
    }
     //arragnments
    printf("\nFirstfit allocation\n");
    printf("____________________\n");


    for(i=0;i<process;i++)
    {
        for(j=0;j<blocks;j++)
        {
            if(block[j]>=proc[i] && flag_block[j]==0)
            {
                printf("\nprocess p%d is allocated to the block b%d of size->%d \n",i+1,j+1,block[j]);
                flag_block[j]=1;
                flag_proc[i]=1;
                break;
            }

        }
        if(flag_proc[i]==0)
        {
            printf("\nprocess p%d cannot be allocated", i + 1);
            break;
        }
    }

}
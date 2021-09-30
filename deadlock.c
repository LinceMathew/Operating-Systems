#include<stdio.h>

void main(){
    int n,m,i,j,k;
    printf("enter the number of process\n");
    scanf("%d",&n);
    printf("enter the number of resources \n");
    scanf("%d",&m);
    int max[n][m],alloc[n][m];
    printf("enter the maximum matrix\n");
    

    for(i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter the allocation matrix\n");
    for(i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    int avail[3]={3,3,2};
    int need[n][3];
    int work[n];
    int finish[n];
    int count=0;
    int flag;
    int safe_seq[n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        work[k]=avail[k];
        finish[k]=0;
    }
    while(count<n)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                        break;
                    
                }
                if(j==m)
                {
                    for(k=0;k<m;k++)
                    {
                        work[k]+=alloc[i][j];
                    }
                    finish[i]=1;
                    safe_seq[count++]=i;
                    flag=1;
                }    

            }
        }
    
    if(flag==0)
    {
        printf("not in safe sequence\n");

    }
    }
    printf("safe sequence\n");
    for(i=0;i<n;i++)
    {
        printf("p%d->",safe_seq[i]);
    }



    }
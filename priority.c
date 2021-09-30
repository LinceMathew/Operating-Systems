#include<stdio.h>
void main()
{
    int i,j,pid[10],bt[10],p[10],wt[10],tat[10],n,t,total_wt=0,total_tat=0;
    float avg_wt,avg_tat;
    printf("Enter the total num of processes:");
    scanf("%d",&n);
    printf("Enter the PID , Bt and priority:");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&pid[i],&bt[i],&p[i]);
    }
    //sorting the processes based on priority
    for(i=0;i<n;i++)
    {
        //j=i;
        for(j=i+1;j<n;j++)
        {
            //int flag=0;
                if(p[i]>p[j])
                {
                    t=p[i];
                    p[i]=p[j];
                    p[j]=t;


                    t=pid[i];
                    pid[i]=pid[j];
                    pid[j]=t;

                    t=bt[i];
                    bt[i]=bt[j];
                    bt[j]=t;

                // j=j;
                }
           // int t;
            }


        }

        wt[0]=0;
        tat[0]=wt[0]+bt[0];
        for(i=1;i<n;i++)
        {
            wt[i]=wt[i-1]+bt[i-1];
            tat[i]=wt[i]+bt[i];

        }
        for(i=0;i<n;i++)
        {
            total_wt+=wt[i];
            total_tat+=tat[i];
        }
      // printf("%d",n);

        avg_wt = total_wt/n;
        avg_tat =total_tat/n;

       printf("PID\tBT\tp\tWT\tTAT");
        for(int i=0;i<n;i++)
        {
            printf("\n%d\t%d\t%d\t%d\t%d",pid[i],bt[i],p[i],wt[i],tat[i]);
        }
        //printf("\n%d\t%d",total_wt,total_tat);
        printf("\nAverage Wt: %f \nAverage tat: %f",avg_wt,avg_tat);

    }
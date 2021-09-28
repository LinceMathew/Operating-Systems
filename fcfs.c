#include<stdio.h>
int main(){
    int i,n,at[10],bt[10],ct[10],tat[10],wt[10],total_tat,total_wt;
    float tavg_tat,tot_wt;
    printf("enter the number of process \n");
    scanf("%d",&n);
    printf("enter the arrival time and burst time of each process according their order of arrival:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d%d",&at[i],&bt[i]);

    }
    ct[0]=at[0]+bt[0];
    for (i=1;i<n;i++)
    {
        if(at[i]<=ct[i-1])
        {
            ct[i]=ct[i-1]+bt[i];

        }
        else{
            ct[i]=at[i]+bt[i];
        }
    }
    for (i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        printf("%d",wt[i])   ;
         }
    printf("\nPID\tTAT\tBT\tCT\tAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d",i+1,tat[i],bt[i],ct[i],at[i],wt[i]);
    }
    total_tat=0;
    total_wt=0;
    for( i=0;i<n;i++)
    {
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("%d\n%d",total_tat,total_wt);


    return 0;
}
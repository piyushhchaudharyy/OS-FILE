// #include<bits/stdc++.h>
// using namespace std;

// // First come first serve (FCFS)
// int main(){
//     // each n represents process
//     // burst time represents the time allocated to each process by cpu
//     int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
//     cout<<"Enter total number of processes(maximum 20): ";
//     cin>>n;

//     cout<<"\nEnter Process Burst Time\n";
//     for(i=0;i<n;i++){
//         cout<<"P["<<i+1<<"]:";
//         cin>>bt[i];
//     }

//     wt[0]=0;    //waiting time for first process is 0

//     //calculating waiting time in the queue
//     for(i=1;i<n;i++){
//         wt[i]=0;
//         // we can use loop or maybe prefix sum
//         for(j=0;j<i;j++)
//             wt[i]+=bt[j];
//     }

//     cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

//     //calculating turnaround time
//     for(i=0;i<n;i++){
//         tat[i]=bt[i]+wt[i]; // total burst time + waiting time
//         avwt+=wt[i];
//         avtat+=tat[i];
//         cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
//     }

//     avwt/=i; // i will go till n
//     avtat/=i;
//     cout<<"\n\nAverage Waiting Time: "<<avwt;
//     cout<<"\nAverage Turnaround Time: "<<avtat;

//     return 0;
// }

#include<bits/stdc++.h>

struct PCB{
    int pid, arrival, burst, turnaround;
};

void pline(int);

int main(){
    int i, n, j;
    float avg = 0.0, sum = 0.0;
    struct PCB p[10], temp;
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    for( i = 0; i<n; i++){
        printf("Enter Arrival Time and Burst Time for process id %d :\n", i+1);
        scanf("%d %d",&p[i].arrival, &p[i].burst);
        p[i].pid = i+1;
    }
    for( i = 0; i<n-1; i++){
        for( j = 0; j<n-i-1; j++){
            if(p[j].arrival > p[j+1].arrival){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    for( i = 0; i<n; i++){
        sum = sum + p[i].burst;
        p[i].turnaround = sum;
    }
    sum = 0;
    pline(44);
    printf("PID\tArrival\tBurst\tTurnaround\n");
    pline(44);
    for( i = 0; i<n; i++){
        printf("%d\t%d\t%d\t%d\n",p[i].pid, p[i].arrival, p[i].burst, p[i].turnaround);
        sum+=p[i].turnaround;
    }
    pline(44);
    avg = sum/(float)(n);
    printf("Total Turnaround Time: %f", sum);
    printf("Average Turnaround Time : %.3f", avg);
    return 0;
}

void pline(int n){
    for(int i = 0; i<=n; i++){
        printf("-");
    }
    printf("\n");
}

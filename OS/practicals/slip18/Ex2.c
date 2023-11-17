/*
Q.2 Write a C program to simulate FCFS CPU-scheduling. The arrival time and  
   first CPU-burst of different jobs should be input to the system. Accept no. of  
   Processes, arrival time and burst time. The output should give Gantt chart,  
        turnaround time and waiting time for each process. Also find the average  
        waiting time and turnaround time.
*/
#include<stdio.h>
typedef struct Process 
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    
    int start_time;
    int completion_time;
    int rem_time;

}Process;

float getAverageWaitingTime(Process p[] , int n)
{
    float sum =0;
    for(int i=0;i<n;i++)
    {
        sum+=p[i].waiting_time;
    }
    return sum/n;
}
float getAverageTurnAroundTime(Process p[] , int n)
{
    float sum =0;
    for(int i=0;i<n;i++)
    {
        sum+=p[i].turn_around_time;
    }
    return sum/n;
}
void printTable(Process process[], int n)
{
    float avg_waiting_time = getAverageWaitingTime(process ,n);
    float avg_turn_around_time = getAverageTurnAroundTime(process ,n);

    printf("_____________[Priority Scheduling (NON PREEMPTIVE) ]_____________");
    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t\n", process[i].id,
                                             process[i].arrival_time,
                                             process[i].burst_time,
                                             process[i].completion_time, 
                                             process[i].waiting_time, 
                                             process[i].turn_around_time);
    }
    printf("\nAVERAGE WAITING TIME %.3f \nAVERAGE TURN AROUND TIME %.3f \n" ,avg_waiting_time , avg_turn_around_time );
}
void printGanttChart(Process p[] , int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].start_time > p[j+1].start_time)
            {
                Process temp = p[j];
                p[j]  = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    printf("\nGantt Chart :\n");

    int start =0;
    int end =0;
    for(int i=0;i<n;i++)
    {
        printf("p%d => [%d  %d]\n" ,  p[i].id,p[i].start_time ,p[i].completion_time);

    }
    printf("\n");
}
void sortOnArrivalTime(Process p[] , int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j =0 ; j<n-i-1;j++)
        {
            if(p[j].arrival_time > p[j+1].arrival_time)
            {
                Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}
int getProcessIndex(Process p[] , int n , int current_index)
{
    for(int i=0;i<n;i++)
    {
        if(p[i].arrival_time <=current_index && p[i].rem_time!=0)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter number of process :");
    scanf("%d" , &n);

    Process p[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter arrival time & burst time :");
        scanf("%d%d" ,  &p[i].arrival_time , &p[i].burst_time);

        p[i].rem_time = p[i].burst_time;
        p[i].id = (i+1);
    }

    sortOnArrivalTime(p , n);

    int current_time=0;
    int total_process = 0;
    int i;
    while(total_process <n)
    {
        i = getProcessIndex(p , n , current_time);
        if(i==-1)
        {
            current_time++;
        }
        else{
            p[i].start_time = current_time;
            current_time+=p[i].rem_time;
            p[i].completion_time  = current_time;
            p[i].rem_time = 0;

            p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
            p[i].waiting_time =  p[i].turn_around_time - p[i].burst_time;

            total_process++;
        }
    }

    printGanttChart(p,n);
    printTable(p,n);
}
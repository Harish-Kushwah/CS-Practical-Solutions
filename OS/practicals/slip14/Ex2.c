/*
Q.2 Write a C program to simulate Non-preemptive Shortest Job First (SJF) – 
     scheduling. The arrival time and first CPU-burst of different jobs should be    
     input to the system. Accept no. of Processes, arrival time and burst time. The  
     output should give Gantt chart, turnaround time and waiting time for each  
     process. Also find the average waiting time and turnaround time
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_BURST_TIME 1000

typedef struct  Process
{
   int id;
   int arrival_time;
   int burst_time;
   int waiting_time;
   int completion_time;
   int turn_around_time;
   int rem_burst_time;
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

    printf("_____________[SJF (NON PREEMPTIVE) ]_____________");
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

//return the which process needs to schedule on the basis of arrival time and burst time
int getProcessID(Process p[] , int n , int current_time)
{
    int min_burst_time = MAX_BURST_TIME;
    int process_needs_to_schedule =-1;
    //get all the process which are ready for execution came before the current time
    for(int i=0;i<n;i++)
    {
        if(p[i].arrival_time <= current_time && p[i].rem_burst_time!=0)
        {     
            //select that process which has minium burst time
            if(p[i].burst_time < min_burst_time)
            {
                min_burst_time = p[i].burst_time;
                process_needs_to_schedule = i;
            }
        }
    }
    return process_needs_to_schedule;  
   
}

int main()
{
    int n = 5;
    printf("Enter total number of process :");
    scanf("%d" , &n);

    Process p[n];
    
    for(int i=0;i<n;i++)
    {
        p[i].id = i+1;
        printf("Enter arrival time and burst time :");
        scanf("%d%d" , &p[i].arrival_time,&p[i].burst_time);
        p[i].rem_burst_time = p[i].burst_time;
    }

    int current_time =0;
    int temp_total_process =0;
    int i =0; 
    while(temp_total_process<n)
    { 
        i = getProcessID(p , n , current_time);
        if(i==-1)
        {
          current_time++;
        }
        else{
            current_time += p[i].rem_burst_time;
            p[i].rem_burst_time = 0;
            p[i].completion_time = current_time;
            temp_total_process++;
        }
      
    }
   for (int i = 0; i < n; i++)
    {
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    }
    printTable(p,n);
    return 0;
}
/*
Q.2 Write the program to simulate Non-preemptive Shortest Job First (SJF) – 
     scheduling. The arrival time and first CPU-burst of different jobs should be    
     input to the system. Accept no. of Processes, arrival time and burst time. The  
     output should give Gantt chart, turnaround time and waiting time for each  
     process. Also find the average waiting time and turnaround time
*/
#include<stdio.h>

typedef struct Process 
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int completion_time;
    int turn_around_time;
    int rem_time;
}Process;

typedef struct GanttChart 
{
    int id;
    int start_time;
    int completion_time;
}GanttChart;

void sortOnArrivalTime(Process p[] , int n)
{
    for(int i =0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
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

    printf("\n_____________[SJF(Non Preemptive)]_____________");
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
void printGanttChart(GanttChart g[] , int n)
{
    printf("\nGantt Chart :\n");
    for(int i=0;i<n;i++)
    {
        int dif = g[i].completion_time - g[i].start_time;
        if(dif!=0  && g[i].id !=-1)
        printf("p%d => [%d  %d]\n" ,  g[i].id,g[i].start_time ,g[i].completion_time,dif);

    }
    printf("\n");
}
int getArrivedProcessId(Process p[] , int n , int current_time)
{
    int min = 1000;
    int index = -1;
    for(int i=0;i<n;i++)
    {
        if(p[i].arrival_time <= current_time && p[i].rem_time !=0)
        {
            if(p[i].burst_time < min)
            {
                min  = p[i].burst_time;
                index = i;
            }
        }
    }
    return index;
}
int main()
{
    int n;
    printf("Enter total number of process :");
    scanf("%d" , &n);

    Process p[n];
    GanttChart g[100];

    for(int i=0;i<n;i++)
    {
        printf("Enter arrival time and burst time :");
        scanf("%d%d", &p[i].arrival_time , &p[i].burst_time);

        p[i].rem_time = p[i].burst_time;
        p[i].id = (i+1);
    }

    int current_time = 0;
    int total_process = 0;
    int i = 0;
    int k = 0;
    while(total_process < n)
    {
        i = getArrivedProcessId(p, n , current_time);
        if(i==-1)
        {
            current_time++;
        }
        else{
            g[k].id = p[i].id;
            g[k].start_time = current_time;

            //SJF logic
            current_time+=p[i].rem_time ; 
            p[i].rem_time = 0;
            p[i].completion_time = current_time;

            p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
            p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;


            g[k++].completion_time = current_time;
            total_process++;
        }
    }
    printTable(p,n);
    printGanttChart(g,n);

}
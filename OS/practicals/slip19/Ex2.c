/*
Q.2 Write the simulation program for Round Robin scheduling for given time  
       quantum. The arrival time and first CPU-burst of different jobs should be input  
       to the system. Accept no. of Processes, arrival time and burst time.  The output  
       should give the Gantt chart, turnaround time and waiting time for each  
       process.  Also  display  the  average  turnaround  time  and  average  waiting  time
*/
#include<stdio.h>
typedef struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    int rem_time;
    int completion_time;
    int start_time;

}Process;

typedef struct GanttChart
{
    int id;
    int completion_time;
    int start_time;
    int rem_time;

}GanttChart;

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

    printf("\n_____________[Round Robin]_____________");
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
        printf("p%d => [%d  %d]\ttime : %d\trem_time : %d\n" ,  g[i].id,g[i].start_time ,g[i].completion_time,dif , g[i].rem_time);

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
int getArrivedProcessIndex(Process p[] , int n , int current_time)
{
    for(int i=0;i<n;i++)
    {
        if(p[i].arrival_time <= current_time && p[i].rem_time !=0)
        return i;
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter number of process :");
    scanf("%d" , &n);

    Process p[n];
    GanttChart g[100];

    for(int i = 0 ; i < n; i++ )
    {
        printf("Enter arrival time & burst time :");
        scanf("%d%d", &p[i].arrival_time , &p[i].burst_time);

        p[i].rem_time = p[i].burst_time;
        p[i].id  = (i+1);
        p[i].start_time =-1;
    }
    sortOnArrivalTime(p,n);
   

    int time_quanta;
    printf("Enter time quanta :");
    scanf("%d" , &time_quanta);

    int current_time = 0;
    int total_process = 0 ;
    int i = 0;

    int k = 0;
    while(total_process < n)
    {

        i  = getArrivedProcessIndex(p,n,current_time);
        if(i==-1)
        {
            current_time++;
        }
        else
        {
            //set the start time of process in gantt chart
            g[k].id = p[i].id;
            g[k].start_time = current_time;
        
            //logic of Round Robin 
            if(p[i].rem_time <= time_quanta && p[i].rem_time!=0)
            {
                current_time+=p[i].rem_time;
                
                p[i].completion_time = current_time;
                p[i].rem_time =0;

                p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
                p[i].waiting_time  = p[i].turn_around_time  - p[i].burst_time;

                total_process++;
            }
            else if(p[i].rem_time > 0){
                current_time+=time_quanta;
                p[i].rem_time-=time_quanta;
            }

            g[k].rem_time = p[i].rem_time;
            g[k++].completion_time = current_time;
            //set the completion time of process in gantt chart
        }
    }
    printTable(p,n);
    printGanttChart(g,k);
}
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
    int completion_time;
    int waiting_time;
    int turn_around_time;
    int rem_burst;
} Process;
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

    printf("_____________[Round Robin]_____________");
    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t\n", process[i].id, process[i].arrival_time, process[i].burst_time, process[i].completion_time, process[i].waiting_time, process[i].turn_around_time);
    }
    printf("\nAVERAGE WAITING TIME %f \nAVERAGE TURN AROUND TIME %f \n" ,avg_waiting_time , avg_turn_around_time );
}

int main()
{
    int n;
    printf("Enter total number of process :");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++)
    {   
        printf("Enter Arrival time :");
        scanf("%d" , &p[i].arrival_time);
        printf("Enter  burst time :");
        scanf("%d", &p[i].burst_time);

        p[i].id = (i+1);
        p[i].rem_burst = p[i].burst_time;
    }

    int time_quantum;
    printf("Enter time quantum :");
    scanf("%d", &time_quantum);

    int process_running = 0;
    int current_time = 0;
    int temp_total_process = 0;
    //all precess not finished 
    while(temp_total_process<n)
    {
        //when burst time is less than or equal time quanta then it will execute for the amount of burst time
        if ( p[process_running].rem_burst <= time_quantum &&  p[process_running].rem_burst > 0) // define the conditions
        {
            current_time = current_time +  p[process_running].rem_burst;
            p[process_running].rem_burst = 0;
            
            p[process_running].completion_time = current_time;  //process finished hence completion time will be current time
           
            temp_total_process++;
 
        }
        //when burst time is greater than time quanta then it will execute of time_quanta time 
        else if ( p[process_running].rem_burst> 0)
        {
            p[process_running].rem_burst =  p[process_running].rem_burst - time_quantum;
            current_time = current_time + time_quantum;
        }

        //check whether next proccess is arrived 
        int next_process = process_running + 1;
        if (p[next_process].arrival_time <= current_time)
        {
            process_running++; //if arrived then execute it
        }
        else{
            process_running = 0;  //not arrived then execute first process
        }   
    }
     for (int i = 0; i < n; i++)
    {
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    }
    printTable(p, n);
}
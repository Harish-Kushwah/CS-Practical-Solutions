/*
Q.2 Write the simulation program for Round Robin scheduling for given time  
       quantum. The arrival time and first CPU-burst of different jobs should be input  
       to the system. Accept no. of Processes, arrival time and burst time.  The output  
       should give the Gantt chart, turnaround time and waiting time for each  
       process.  Also  display  the  average  turnaround  time  and  average  waiting  time
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    int rem_time;
    int completion_time;
    int allot;

}Process;
typedef struct GanttChart
{
    int id;
    int completion_time;
    int start_time;
    int rem_time;

}GanttChart;

//------------------------ CIRCULAR QUEUE USING LINKED LIST --------------------------
typedef struct Node 
{
    Process *data;
    struct Node *next;
    
}Node;
Node *add(Node *head , Process *p)
{
    Node *temp=NULL,*newnode = NULL;    
    newnode =  (Node *)malloc(sizeof(Node));
    newnode->data = p;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else{
          for(temp = head; temp->next !=NULL ; temp = temp->next);
          temp->next = newnode;
    }
    return head;
}
int isEmpty(Node * qu)
{
    if(qu==NULL) 
     return 1;
    return 0;
}
Node *removeProcess(Node *head)
{
    Node *t = head;
    head = head->next;
    free(t);
    return head;
}
Process* getPeek(Node *head)
{
    if(head!=NULL)
    return head->data;
    return NULL;
}
Node *qu = NULL;

//------------------------------------------------------------------------------------------
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
void printGanttChart(GanttChart g[] , int n )
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

void insertAllArrivedProcess(Process *p , int  n ,int current_time)
{
     for(int i=0;i<n;i++)
    {
        if(p[i].arrival_time <= current_time && p[i].rem_time !=0){
         if(p[i].allot!=1){
            p[i].allot =1;
            qu = add(qu,&p[i]);
         }
        }  
    }
}
int main()
{
    int n ;
    printf("Enter number of process :");
    scanf("%d" , &n);

    GanttChart g[100];   
    Process p[n];
    for(int i = 0 ; i < n; i++ )
    {
        printf("Enter arrival time & burst time :");
        scanf("%d%d", &p[i].arrival_time , &p[i].burst_time);
        p[i].rem_time = p[i].burst_time;
        p[i].id  = (i+1);
        p[i].allot =0;
    }    
    int time_quanta ;
    printf("Enter time quanta :");
    scanf("%d" , &time_quanta);

    int current_time = 0;
    int total_process = 0 ;
    Process *p1 = NULL;

    int k = 0;
    while(total_process < n)
    {
        insertAllArrivedProcess(p,n,current_time);
        p1  = getPeek(qu);
        if(p1==NULL)
        {
            current_time++;
        }
        else
        {
            //set the start time of process in gantt chart
            g[k].id = p1->id;
            g[k].start_time = current_time;
        
            //logic of Round Robin 
            if(p1->rem_time <= time_quanta && p1->rem_time!=0)
            {
                current_time+=p1->rem_time;
                
                p1->completion_time = current_time;
                p1->rem_time =0;

                p1->turn_around_time = p1->completion_time - p1->arrival_time;
                p1->waiting_time  = p1->turn_around_time  - p1->burst_time;
                
                qu = removeProcess(qu);

                total_process++;
            }
            else if(p1->rem_time > 0){
                current_time+=time_quanta;
                p1->rem_time-=time_quanta;
            }
             if(p1->rem_time != 0)
            {
                insertAllArrivedProcess(p,n,current_time);
                qu = removeProcess(qu);
                qu = add(qu ,p1); 
               
            }

            g[k].rem_time = p1->rem_time;
            g[k++].completion_time = current_time;
            //set the completion time of process in gantt chart
        }    
    }
    printTable(p,n);
    printGanttChart(g,k);


}
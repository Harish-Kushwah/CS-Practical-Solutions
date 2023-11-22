/*
Q.2 Write the simulation program for Round Robin scheduling for given time         
quantum. The arrival time and first CPU-burst of different jobs should be input         
to the system. Accept no. of Processes, arrival time and burst time.  The output         
should  give  the  Gantt  chart,  turnaround  time  and  waiting  time  for  each         
process. Also display the average turnaround time and average waiting time.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Process
{
    int id, arrival_time, burst_time, waiting_time, turn_around_time, rem_time, completion_time, allot;

} Process;
//------------------------ CIRCULAR QUEUE USING LINKED LIST --------------------------
typedef struct Node
{
    Process *data;
    struct Node *next;
} Node;

Node *add(Node *head, Process *p)
{
    Node *temp = NULL, *newnode = NULL;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = p;
    newnode->next = NULL;
    if (head != NULL)
    {
        for (temp = head; temp->next != NULL; temp = temp->next);
        temp->next = newnode;
    }
    else
        head = newnode;
    return head;
}
int isEmpty(Node *qu)
{
    return qu == NULL;
}
Node *removeProcess(Node *head)
{
    Node *t = head;
    head = head->next;
    free(t);
    return head;
}
Process *getPeek(Node *head)
{
    return (head != NULL) ? head->data : NULL;
}
Node *qu = NULL;

void printTable(Process process[], int n)
{
    printf("\n_____________[Round Robin]_____________");
    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t\n", process[i].id, process[i].arrival_time, process[i].burst_time, process[i].completion_time, process[i].waiting_time, process[i].turn_around_time);
    }
}
void insertAllArrivedProcess(Process *p, int n, int current_time)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].arrival_time <= current_time &&  p[i].rem_time !=0 &&  p[i].allot!=1)
        {
            p[i].allot = 1;
            qu = add(qu, &p[i]);
        }
    }
}
int main()
{
    int n;
    printf("Enter number of process :");
    scanf("%d", &n);

    int g[100];
    Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time & burst time :");
        scanf("%d%d", &p[i].arrival_time, &p[i].burst_time);
        p[i].rem_time = p[i].burst_time;
        p[i].id = (i + 1);
        p[i].allot = 0;
    }

    int time_quanta;
    printf("Enter time quanta :");
    scanf("%d", &time_quanta);

    int current_time = 0;
    int total_process = 0;
    Process *p1 = NULL;
    int k = 0;
    float total_waiting_time = 0.0, total_turn_around_time = 0.0;
    while (total_process < n)
    {
        insertAllArrivedProcess(p, n, current_time);
        p1 = getPeek(qu);
        if (p1 == NULL)
        {
            current_time++;
        }
        else
        {
            // set the start time of process in gantt chart
            g[k++] = p1->id;
            // logic of Round Robin
            if (p1->rem_time <= time_quanta && p1->rem_time != 0)
            {
                current_time += p1->rem_time;

                p1->completion_time = current_time;
                p1->rem_time = 0;

                p1->turn_around_time = p1->completion_time - p1->arrival_time;
                p1->waiting_time = p1->turn_around_time - p1->burst_time;

                total_waiting_time += p1->waiting_time;
                total_turn_around_time += p1->turn_around_time;

                qu = removeProcess(qu);
                total_process++;
            }
            else if (p1->rem_time > 0)
            {
                current_time += time_quanta;
                p1->rem_time -= time_quanta;
            }

            if (p1->rem_time != 0)
            {
                insertAllArrivedProcess(p, n, current_time);
                qu = removeProcess(qu);
                qu = add(qu, p1);
            }
        }
    }
    printTable(p, n);
    printf("\nAverage waiting time : %f\nAverage Turn Around Time : %f\n", total_waiting_time / n, total_turn_around_time / n);
    printf("Gantt Chart :\n");
    for (int i = 0; i < k; i++)
    {
        printf(" p%d |", g[i]);
    }
    printf("\n");
}
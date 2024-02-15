#include <stdio.h>

int main()
{
	int time, burst_time[10], arrival_time[10], sum_burst_time = 0, smallest, n, i;
	int total_turn_around_time = 0, total_waiting_time = 0;
	printf("enter the no of processes : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("the arrival time for process P%d : ", i + 1);
		scanf("%d", &arrival_time[i]);
		printf("the burst time for process P%d : ", i + 1);
		scanf("%d", &burst_time[i]);
		sum_burst_time += burst_time[i];
	}


	burst_time[9] = 9999;
	for (time = 0; time < sum_burst_time;)
	{
		smallest = 9;
		for (i = 0; i < n; i++)
		{
			if (arrival_time[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[smallest])
				smallest = i;
		}


		printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time + burst_time[smallest] - arrival_time[smallest], time - arrival_time[smallest]);
		
        total_turn_around_time += time + burst_time[smallest] - arrival_time[smallest];
		total_waiting_time += time - arrival_time[smallest];
		
        time += burst_time[smallest];
		burst_time[smallest] = 0;
	}
	printf("\n\n average waiting time = %f", total_waiting_time * 1.0 / n);
	printf("\n\n average turnaround time = %f", total_turn_around_time * 1.0 / n);
	return 0;
}
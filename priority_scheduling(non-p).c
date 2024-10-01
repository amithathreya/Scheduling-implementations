/* program implementing Priority Scheduling Algorithm { non preemptive}
  How it works =>
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_PROCESSES 10
struct Processes {
    int id;
    int priority;
    int burst_time;
    int comp_time;
    int turnaround_time;
    int waiting_time;
};


void swap(struct Processes *xp , struct Processes *yp) {
    struct Processes temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_priority(struct Processes process[] , int n) {
    for(int i = 0; i <n-1;i++) {
        for(int j = 0;j<n-i-1;j++) {
            if(process[j].priority < process[j+1].priority) {
                swap(&process[j] , &process[j+1]);
            }
        }
    }
}

void calculate_completion_time(struct Processes process[] , int n) {
    int start = 0;
    for(int i=0;i<n;i++) {
        process[i].comp_time = start + process[i].burst_time;
        start = process[i].comp_time;
    }
}

void calculate_turnaround_time(struct Processes process[] , int n) {
    calculate_completion_time(process , n);
    for(int i = 0; i < n;i++) {
        process[i].turnaround_time = process[i].comp_time - 0;
    }
}

void calculate_waiting_time(struct Processes process[] , int n) {
    for(int i = 0;i < n; i++) {
        process[i].waiting_time = process[i].turnaround_time - process[i].burst_time;
    }
}

void print(struct Processes process[] , int n) {
    printf("PID\tTurnAroundtime\tWaitingTime\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%d\t\t%d\n",process[i].id , process[i].turnaround_time , process[i].waiting_time);
    }
}


int calculate_tt_avg(struct Processes process[] , int n) {
    float avg = 0;
    for(int i=0;i<n;i++) {
        avg+=process[i].turnaround_time;
    }
    avg/=n;
    return avg;
}

int calculate_w_avg(struct Processes process[] , int n) {
    float avg = 0;
    for(int i=0;i<n;i++) {
        avg+=process[i].waiting_time;
    }
    avg/=n;
    return avg;
}
int main() {
    struct Processes process[MAX_PROCESSES];
    int n;
    printf(" enter the number of processes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        process[i].id = i+1;
        printf("enter the burst_time of process %d\n",i+1);
        scanf("%d" , &process[i].burst_time);
        printf(" enter the priority of process %d\n",i+1);
        scanf("%d" , &process[i].priority);
    }
    sort_by_priority(process, n);
    calculate_turnaround_time(process , n);
    calculate_waiting_time(process , n);
    print(process , n);
    float res = calculate_tt_avg(process , n);
    printf("average turnaround time: %.2f\n",res);
    res = calculate_w_avg(process , n);
    printf(" average waiting time: %.2f\n",res);
    return 0;
}
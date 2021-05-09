#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Max-Min Scheduler Algorithm
struct Assignment
{ int task, machine; };

int main()
{
    int T,VM;
    cout<<"Enter number of tasks to be scheduled: ";  cin>>T;
    cout<<"Enter number of virtual machines: ";  cin>>VM;
    int C[T][VM]={0}, E[T][VM]={0}, R[VM]={0};
    cout<<"Enter task execution time matrix:\n";
    cout<<"\n VM:\t"; for(int j=0;j<VM;j++) cout<<j<<" "; cout<<endl;
    cout<<"    \t"; for(int j=0;j<VM;j++) cout<<"_ "; cout<<endl;
    for(int i=0;i<T;i++)
    {
     cout<<"Task-"<<i<<"| ";
     for(int j=0;j<VM;j++)
      cin>>E[i][j];
    }

    for(int i=0;i<T;i++)
     for(int j=0;j<VM;j++)
       C[i][j] = E[i][j]+R[j];

    int task_count=0;
    Assignment A[T];
    do
    {
     int max=INT_MIN/2, task_id, machine_id;
     for(int i=0;i<T;i++)
       for(int j=0;j<VM;j++)
         if(C[i][j] > max)
           max=C[i][j], task_id=i, machine_id=j;

     A[task_count].task=task_id, A[task_count].machine=machine_id;
     R[machine_id] += C[task_id][machine_id];

     for(int i=0; i<T; i++)
      C[i][machine_id]+=R[machine_id];

     for(int j=0; j<VM; j++)
      C[task_id][j]=INT_MIN/2;

    }while(++task_count < T);

    cout<<"\nThe assigned tasks as per Max-Min scheduling are:\n";
    for(int i=0;i<T;i++)
      cout<< "Task[" << A[i].task << "] --> Machine[" << A[i].machine << "]" <<endl;

    return 0;
}
/*
3 1 2
5 4 6
7 9 8
9 7 5
8 6 4
*/

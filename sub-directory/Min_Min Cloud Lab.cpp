#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Min-Min Scheduler Algorithm
struct Assignment
{ int task, machine; };

int main()
{
    int T,VM;
    cout<<"Enter number of tasks to be scheduled: ";  cin>>T;
    cout<<"Enter number of virtual machines: ";  cin>>VM;
    int C[T][VM]={0}, E[T][VM]={0}, R[VM]={0};
    cout<<"Enter task execution time matrix:\n";
    cout<<"\n VT:\t"; for(int j=0;j<VM;j++) cout<<j<<" "; cout<<endl;
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
     int min=INT_MAX/2, task_id, machine_id;
     for(int i=0;i<T;i++)
      for(int j=0;j<VM;j++)
       if(C[i][j] < min)
         min=C[i][j], task_id=i, machine_id=j;

     A[task_count].task=task_id, A[task_count].machine=machine_id;
     R[machine_id] += C[task_id][machine_id];

     for(int i=0; i<T; i++)
      C[i][machine_id]+=R[machine_id];

     for(int j=0; j<VM; j++)
      C[task_id][j]=INT_MAX/2;

    }while(++task_count <= T);

    cout<<"\nThe assigned tasks as per Min-Min scheduling are:\n";
    for(int i=0;i<T;i++)
      cout<< "Task[" << A[i].task << "] --> Machine[" << A[i].machine << "]" <<endl;

    return 0;
}
/*
1 2 3
4 5 6
7 8 9
9 7 5
8 6 4
*/

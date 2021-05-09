#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Activitiy
{ int start, finish; };

bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}

int MaxActivities(Activitiy arr[], int n)
{
    /// Sort jobs according to finish time using C++ standard Template library sort in O( n.log(n) )
    sort(arr, arr+n, activityCompare);
    cout<<"\nSorted list: ";
    for(int i=0;i<n;i++)
        cout << "(" << arr[i].start << ", "<< arr[i].finish << "), ";

    cout <<endl<< "\nFollowing activities are selected :";

    // The first activity always gets selected
    int i = 0;    int count=1;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
     for (int j = 1; j < n; j++)
      if (arr[j].start >= arr[i].finish)
      {
          cout << "(" << arr[j].start << ", "<< arr[j].finish << "), ";
          i = j; count++;
      }
      cout<<endl;
      return count;

}

int main()
{
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Number of activities selected out of "<<n<<" activities = "<<MaxActivities(arr, n);
    cout<<endl<<endl;
    return 0;
}

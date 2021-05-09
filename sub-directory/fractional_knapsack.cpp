#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Item
{
  int value;
  float weight;
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp); // std template library function predefine in C++ with O(n.log(n))
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].value << " -:- " << arr[i].weight << " := "
             << ((double)arr[i].value / arr[i].weight) << endl;
    }


    int curWeight = 0;  // Current weight in knapsack
    double finalvalue = 0.0; // Result (value in Knapsack)
    cout<<endl;
    // Looping through all Items
    for (int i = 0; i < n; i++)
    {
        // If adding Item won't overflow, add it complet`ely
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
            cout<<"("<<arr[i].value<<" X "<< 1<<") + ";
        }
        else
        {
            int remain = W - curWeight;
            cout<<"("<<arr[i].value<<" X "<< remain <<"/"<< arr[i].weight<<")";
            finalvalue += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }

    cout<<endl;
    return finalvalue;
}

// driver program to test above function
int main()
{
    int W = 40;   //    Weight of knapsack
    cin>>W;
    cout<<endl<<"Weight of Knapsack = "<<W<<endl;
    Item arr[] = { {28, 4}, {75, 15}, {27, 3}, {32,8}, {120,20}, {70,7}, {44,11}, {6,2}, {136,17}, {26,13} };

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum profit we can obtain = "<< fractionalKnapsack(W, arr, n)<<endl;
    return 0;
}

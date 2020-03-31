#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int cases;
    cout<<"Enter number of test cases: ";
    cin >> cases;
    int kase;
    for(kase = 1; kase <= cases; kase++) {
        int  N;
        cout<<"Enter number:";
        cin >> N;
        vector<int> result;
        result.push_back(1);
        int temp, carry = 0;
        for(int i = 2; i <= N; i++) {
            for(int j = 0; j < result.size(); j++) {
                temp = carry + result[j] * i;
                carry = temp / 10;
                result[j] = temp % 10;
            }
            while(carry)
            {
                result.push_back(carry % 10);
                carry /= 10;
            }
        }
        for(int i = result.size() - 1; i >= 0; i--){
            cout << result[i];
        }
        cout << endl <<"______________________________________________________________"<<endl;
    }
    return 0;
}

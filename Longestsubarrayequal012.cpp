//length of Longest Subarray With Equal Number Of 0s 1s And 2s

#include<bits/stdc++.h>
using namespace std;

int equalength(vector<int> arr)
{
    unordered_map<string,int> um;  // unique pattern string, count
    int length=0;
    um["0|0"]=-1;
    int n0=0;
    int n1=0;
    int n2=0;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0)
        n0++;
        else if(arr[i]==1)
        n1++;
        else
        n2++;

        string key=to_string(n1-n0)+"|"+to_string(n2-n1);
        //same c1-c0|c2-c1

        if(um.find(key)!=um.end())
        length=max(length,i-um[key]);

        if(um.find(key)==um.end())
        um[key]=i;
    }

    return length;
}


/*

.......................(N0,N1,N2)
.....(x0,x1,x2)

*/

int main()
{
    int n;
    cin>>n;

    vector<int> arr;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        arr.push_back(x);
    }

    cout<<equalength(arr);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,elem,k;
    cin>>n;

    vector<int> arr;

    for(int i=0;i<n;i++)
    {
        cin>>elem;
        arr.push_back(elem);
    }
    cin>>k;


    // int count=0;
    // int i=0;
    // int len=0;

    // for(int j=0;j<n;j++)
    // {
    //     if(arr[j]==0)
    //     count++;

    //     while(count>k)             //invalid
    //     {
    //         if(arr[i]==0)
    //         count--;

    //         i++;
    //     }

    //     len=max(len,j-i+1);
    // }
    // cout<<len;


    unordered_map<int,int> um;
    int i=0;
    int j=0;
    int len=0;

    while(true)
    {
        bool f1=false;
        bool f2=false;

        while(j<n)
        {
            f1=true;
            um[arr[j]]++;
            j++;

            if(um.find(0)!=um.end() && um[0]>k)  //k zero allowed only
            {
                len=max(len,j-i-1);
                break;
            }
            len=max(len,j-i);

        }

        while(i<j)
        {
            f2=true;
            if(um[arr[i]]==1)
            um.erase(arr[i]);
            else
            um[arr[i]]--;

            i++;

            if(um.find(0)==um.end() || (um.find(0)!=um.end() && um[0]==k)) //back to valid 1 zero
            {
                len=max(len,j-i);
              break;
            }

        }

        if(f1==false && f2==false)
        break;

    }

    if(i==n && j==n && len==0)
    cout<<n;
    else
    cout<<len;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,elem,nn;
    cin>>n;
    nn=n;
    unordered_set<int> s;
    vector<int> arr;
    int cnt=0;

    while(n--)
    {
        cin>>elem;
        arr.push_back(elem);
    }

    for(int i=0;i<nn;i++)
    {
        s.insert(arr[i]);
    }

    int k=s.size();

    int i=0;int j=0;
    unordered_map<int,int> um;

    while(true)
    {
        bool f1=false;
        bool f2=false;

        while(j<nn)                 //first valid subarray with all unique characters
        {
            f1=true;
           um[arr[j]]++;
           j++;

           if(um.size()==k)
           {
               cnt+=nn-j+1;
               break;
           }

        }

        while(i<j)  //moving starting point forward/optimizing towards shorter length
        {
            f2=true;
            if(um[arr[i]]==1)
             um.erase(arr[i]);
            else
            um[arr[i]]--;
            i++;

            if(um.size()<k)
            break;
            else if(um.size()==k)
            {
                cnt+=nn-j+1;
            }

        }

        if(f1==false && f2==false)
        break;

    }

    cout<<cnt;

    return 0;
}

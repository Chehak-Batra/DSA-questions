#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    unordered_map<char,int> um;
    int i=0; int j=0; int cnt=0;

    while(true)
    {
        bool f1=false;
        bool f2=false;

        while(j<s.size())
        {
            f1=true;
            um[s[j]]++;
            j++;

            if(um[s[j-1]]==2)
            break;
            else
            cnt+=j-i;
        }

        while(i<j)
        {
            f2=true;
            um[s[i]]--;
            i++;

            if(um[s[i-1]]==1)
            {
                cnt+=j-i;       //collect ans after making it valid
                break;
            }

        }

        if(f1==false && f2==false)
        break;
    }

    cout<<cnt;

    return 0;
}

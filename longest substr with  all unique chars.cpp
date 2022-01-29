#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    unordered_map<char,int> um;
    int i=0;
    int j=0;
    int len=0;

    while(true)
    {
        bool flag1=false;
        bool flag2=false;

        //acquire till all unique
        while(j<s.size())
        {
            flag1=true;
            um[s[j]]++;
            j++;

            if(um[s[j-1]]>1)
            break;

            len=max(len,j-i);

        }

        while(i<j)
        {
            um[s[i]]--;
            flag2=true;
            i++;

            if(um[s[i-1]]==1)
                break;

        }

        if(flag1==false && flag2==false)
        break;

    }

    cout<<len;

    return 0;
}

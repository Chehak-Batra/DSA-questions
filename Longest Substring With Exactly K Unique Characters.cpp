#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;

    unordered_map<char,int> um;
    int i=0;
    int j=0;
    int len=-1;

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

            // if(um[s[j-1]]>1)
            // break;
            if(um.size()>k)
            break;

            else if(um.size()==k)
                len=max(len,j-i);

        }

        while(i<j)
        {
            flag2=true;

            if(um[s[i]]==1)
            um.erase(s[i]);
            else
            um[s[i]]--;

            i++;

            if(um.size()==k){
                len=max(len,j-i);
                break;
            }

        }

        if(flag1==false && flag2==false)
        break;

    }

    if(len)
    cout<<len;

    return 0;
}

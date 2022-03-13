#include<bits/stdc++.h>
using namespace std;

//isomorphic strings : a uniquely mapped to b and b uniquely mapped to a
//soln1: check for both mappings

/*
 bool ismapping(string a,string b){

        unordered_map<char,char> um;

        for(int i=0;i<a.size();i++)
        {
            if(um.find(a[i])!=um.end())
            {
                if(um[a[i]]!=b[i])
                    return false;
            }

            else
            um[a[i]]=b[i];
        }

        return true;

    }

    bool isIsomorphic(string s, string t) {

        if(ismapping(s,t) && ismapping(t,s))
            return true;

        return false;

    }
*/

//soln2: mapping a-> b check used chars of b

bool func(string s1,string s2)
{
    if(s1.size()!=s2.size())
     return false;

    unordered_map<char,char> um;         //string1 char to string2 char
    unordered_map<char,bool> mp;         //string2 char already mapped or not

    for(int i=0;i<s1.size();i++)
    {
        if(um.find(s1[i])!=um.end())         //string1 char already mapped
        {
            if(s2[i]!=um[s1[i]])          //present str2 char and prev mapping not same
            return false;
        }

        else{
            if(mp.find(s2[i])!=mp.end())         // str2 char already mapped
             return false;

            um[s1[i]]=s2[i];                //done mapping and marked str2 char
            mp[s2[i]]=true;

        }

    }

    return true;

}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    bool x=func(s1,s2);
    if(x) cout<<"true";
    else
    cout<<"false";
    return 0;
}

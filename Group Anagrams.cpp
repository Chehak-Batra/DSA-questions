#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupanagram(vector<string> strings)
{
   map<map<char,int>,vector<string>> um;                // freq map, vector of strings with this freq map

    for(auto str:strings)
    {
        map<char,int> mp;                             //freq map of each string

        for(int j=0;j<str.size();j++)
        {
            mp[str[j]]++;
        }

       um[mp].push_back(str);                        //pushing string in front of its freq map

    }

    vector<vector<string>> ret;

    for(auto i:um)
    {
      ret.push_back(i.second);                     //vector of (all groups of string with same freq map/anagrams)
    }

    return ret;

}


int main()
{
int n;
cin>>n;

vector<string> arr;

for(int i=0;i<n;i++)
{
   string s;
   cin>>s;
   arr.push_back(s);
}

vector<vector<string>> ret=groupanagram(arr);

for(int i=0;i<ret.size();i++)
{
  for(int j=0;j<ret[i].size();j++)
  {
     cout<<ret[i][j]<<" ";
  }

  cout<<"\n";
}

return 0;
}


#include<bits/stdc++.h>
using namespace std;

bool isValidAnagram(string s,string t){           //two string are anagram or not (Same freq map)

   unordered_map<char,int> um;

   for(int i=0;i<s.size();i++)
   {
       um[s[i]]++;                            //adding chars from one string
   }

   for(int j=0;j<t.size();j++)
   {
       if(um[t[j]]==1)
          um.erase(t[j]);
       else
       um[t[j]]--;                           //removing chars from second string
   }

   if(um.empty())
   return true;
   else
   return false;
}

int main(){
    string s,t;
    cin >> s >> t;
    if(isValidAnagram(s,t)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}

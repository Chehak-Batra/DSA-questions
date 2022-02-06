#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
int solution(string s, int k) {

 int i=0;
 int j=0;
 int len=0;

unordered_map<char,int> um;

 while(true)
 {
   bool f1=false;
   bool f2=false;

   while(j<s.size())
   {
      f1=true;
      um[s[j]]++;
      j++;

      if(um.size()<=k)
        len=max(len,j-i);
      else
        break;

   }

   while(i<j)
   {
     f2=true;

     if(um[s[i]]==1)
        um.erase(s[i]);
     else
       um[s[i]]--;

     i++;

     if(um.size()<=k)
     {
       len=max(len,j-i);
       break;
     }
   }

   if(f1==false && f2==false)
     break;
 }

return len;
}


int main() {
  string str;
  cin>>str;
  int k;
  cin >> k;
  cout << solution(str, k);

}


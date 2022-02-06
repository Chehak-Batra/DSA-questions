#include<bits/stdc++.h>
using namespace std;

int solution(string s, int k) {

 int i=0;
 int j=0;
 int cnt=0;

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
        cnt+=j-i;
      else
        break;

   }

   if(j==s.size() && um.size()<=k)        //last valid substring leli
     break;

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
       cnt+=j-i;
       break;
     }
   }

   if(f1==false && f2==false)
     break;
 }

return cnt;
}

int main() {
    string str;
    int k;
    cin >> str >> k;
	cout << solution(str,k);
}

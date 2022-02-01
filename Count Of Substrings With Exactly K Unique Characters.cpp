#include<bits/stdc++.h>
using namespace std;

int codefork1(string s){

   unordered_map<char,int> um;
    int cnt=0;
    int i=0;
    int j=0;

   while(true)
   {
      bool f1=false;
      bool f2=false;

      while(j<s.size())           //j stays on pos
      {
        f1=true;
        um[s[j]]++;
        j++;

        if(um.size()>1)
        {
            j--;

            if(um[s[j]]==1)
                um.erase(s[j]);
            else
                um[s[j]]--;

            break;
        }
      }

      while(i<j)               //i stays ahead
      {
        f2=true;
                               //aaa
                               //i  j    size is j-i

        if(um.size()==1)
         cnt+=j-i;

          if(um[s[i]]==1)
            um.erase(s[i]);
          else
            um[s[i]]--;

        i++;
        if(um.size()==0)
        break;
      }

    if(f1==false && f2==false)
      break;
   }

   return cnt;

}


int main()
{
    string s;
    int k;
    cin>>s>>k;

    if(k==1)
    {
        cout<<codefork1(s);
        return 0;
    }

    int i=0;
    int j=0;
    int z=0;

    unordered_map<char,int> big;
    unordered_map<char,int> small;
    int cnt=0;

    while(true)
    {
        bool f1=false;
        bool f2=false;
        bool f3=false;

        while(j<s.size())             //big k map
        {
            f1=true;
            big[s[j]]++;
            j++;

            if(big.size()>k)              //(condn just got invalid) undo action
            {
                j--;
                if(big[s[j]]==1)
                big.erase(s[j]);
                else
                big[s[j]]--;

                break;
            }

        }

        while(z<j)           //small k-1 map
        {
            f2=true;
            small[s[z]]++;
            z++;

            if(small.size()>k-1)        //(condn just got invalid) undo action
            {
                z--;
                if(small[s[z]]==1)
                small.erase(s[z]);
                else
                small[s[z]]--;

                break;
            }

            // if(small.size()==k-1)
            // break;
        }

        while(i<z)
        {
            f3=true;

            if(big.size()==k && small.size()==k-1)
            cnt+=j-z;

            if(big[s[i]]==1)
            big.erase(s[i]);
            else if(big[s[i]]>1)
            big[s[i]]--;

            if(small[s[i]]==1)
            small.erase(s[i]);
            else if(small[s[i]]>1)
            small[s[i]]--;

            i++;

           if(big.size()<k || small.size()<k-1)
            break;

        }

        if(f1==false && f2==false && f3==false)
         break;
    }

    cout<<cnt;

    return 0;
}

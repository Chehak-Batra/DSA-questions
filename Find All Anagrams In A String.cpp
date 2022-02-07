#include <bits/stdc++.h>
using namespace std;


void findAnagrams(string s, string p) {

	unordered_map<char,int> um;

    int n=p.size();

	for(auto i:p)
	{
		um[i]++;
	}

    unordered_map<char,int> mp;

	int i=0;int j=0;
	int cnt=0;                   //count of anagrams
	string show="";              //start indexes of matched anagram

	while(j<n)                 //first n size window in mp map
	{
      mp[s[j]]++;
	  j++;
	}

    while(j<s.size())
	{
       if(um==mp)                 //compare both maps
	   {
		   cnt++;
		   show+=to_string(i);
		   show+=" ";
	   }

       mp[s[j]]++;                //moving whole window forward: adding jth element removing ith element

	    if(mp[s[i]]==1)
	      mp.erase(s[i]);
		else
	      mp[s[i]]--;

	   i++;
	   j++;

	}

	if(um==mp)                   //last window check
	   {
		   cnt++;
		   show+=to_string(i);
		   show+=" ";
	   }

cout<<cnt<<endl;
cout<<show;

}

int main() {
	string s;
	string p;
	cin >> s >> p;
	findAnagrams(s, p);
}

#include<bits/stdc++.h>
using namespace std;

// K Anagrams
//replacing upto k chars in str1 will make same frequency map of both strings (extra chars in str1<=k which can be replaced)


bool areKAnagrams(string str1, string str2, int k) {

if(str1.size()!=str2.size())             //diff size strings can never be anagrams
   return false;

unordered_map<char,int> um;              //char freq of str1

for(int i=0;i<str1.size();i++)
{
	um[str1[i]]++;
}

for(int i=0;i<str2.size();i++)
{
	if(um[str2[i]]>0)                     // consuming characters of str2 if present in str1
	   um[str2[i]]--;                      //extra characters of str1 left in map
}

int cnt=0;

for(auto j:um)
{
	cnt+=j.second;                         //extra elements in str1 which can be replaced
}

if(cnt>k)
 return false;
else
return true;

}

int main(){

	string str1;
	string str2;
	int k;
	cin >> str1 >> str2 >> k;
	if(areKAnagrams(str1, str2, k))
	    cout<<"true";
	else
	    cout<<"false";

}

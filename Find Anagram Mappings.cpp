#include<bits/stdc++.h>
using namespace std;

//vector of indexes of elements of a1 in a2
vector<int> findMapping(int a1[],int a2[],int n){

    //find element of a1 in a2 and tell index occurence wise

    unordered_map<int,pair<int,vector<int>>> um;      //int: (pos,indexes)

    for(int i=0;i<n;i++)
    {
        um[a2[i]].first=0;
        um[a2[i]].second.push_back(i);
    }

    vector<int> ret;

    for(int i=0;i<n;i++)
    {
        int pos=um[a1[i]].first;
        vector<int> arr=um[a1[i]].second;

         ret.push_back(arr[pos++]);                   //moving pos forward
         um[a1[i]].first=pos;
    }

return ret;

}

int main(){
    int n;
    cin >> n;
    int a1[n],a2[n];
    for(int i=0;i<n;i++){
        cin >> a1[i];
    }
    for(int i=0;i<n;i++){
        cin >> a2[i];
    }

    vector<int> ans = findMapping(a1,a2,n);
    for(auto a:ans){
        cout << a << " ";
    }
}

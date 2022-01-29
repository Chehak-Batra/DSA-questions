// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     cin>>s;

//     unordered_set<int> um;

//     for(auto i:s)
//     {
//         um.insert(i);
//     }

//     int i=0;int j=0;

//     unordered_map<char,int> mp;
//     int len=s.size();
//     string k="";

//     while(true)
//     {
//         bool flag2=false;
//         bool flag1=false;

//         while(mp.size()<um.size() && j<s.size())    //acquire
//         {
//             mp[s[j]]++;
//             j++;
//             flag1=true;
//         }

//         while(mp.size()==um.size() && i<j)
//         {
//             len=min(len,j-i);
//             if(k.size()==0 || j-i<k.size())
//             k=s.substr(i,j-i);

//             if(mp[s[i]]==1)
//             mp.erase(s[i]);

//             else mp[s[i]]--;

//             i++;
//             flag2=true;
//         }

//         if(flag1==false && flag2==false)
//             break;
//     }

//     // cout<<k;
//     cout<<len;

//     return 0;
// }


#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long int
#define MOD 1000000007
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll power(ll x, ll y) {if (y < 0) return 1; ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}


int helper(string s, string ans) {
    int m= ans.length();
    unordered_map<char, int> um;
    for(int i=0; i< m; i++) um[ans[i]]++;
    int count= um.size();
    int len= INT_MAX;

    int i(0), j(0), n(s.length());
    while(j< n) {
        if(um.find(s[j])!= um.end()) {
            um[s[j]]--;
            if(um[s[j]]==0) count--;
        }
            while(count==0) {
                len= min(len, j-i+1);
                if(um.find(s[i])!= um.end()) {
                      um[s[i]]++;
                      if(um[s[i]]==1) count++;
                }
                i++;
        }
        j++;
    }

    return len==INT_MAX ? 0 : len;
}

void solve() {
    string s;
    cin>>s;

    /*
    create string with
    one unique character only
    */
    int n= s.length();
    unordered_set<char> s1;
    for(int i=0; i< n; i++) s1.insert(s[i]);

    string ans= "";
    for(auto i: s1) {
        ans+= i;
    }
    cout<<helper(s, ans);
}


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    t=1;
  //cin>>t;
    while(t--){
        solve();
    }


return 0;
}



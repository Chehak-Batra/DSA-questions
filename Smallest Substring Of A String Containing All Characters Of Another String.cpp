
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


void helper(string s, string ans) {
    int m= ans.length();
    unordered_map<char, int> um;
    for(int i=0; i< m; i++) um[ans[i]]++;
    int count= um.size();
    int len= INT_MAX;
    int start=0;

    int i(0), j(0), n(s.length());
    while(j< n) {
        if(um.find(s[j])!= um.end()) {
            um[s[j]]--;
            if(um[s[j]]==0) count--;
        }
            while(count==0) {
                if(len>j-i+1)
                {
                    len=j-i+1;
                    start=i;
                }
                if(um.find(s[i])!= um.end()) {
                      um[s[i]]++;
                      if(um[s[i]]==1) count++;
                }
                i++;
            }
        j++;
    }

    if(len!=INT_MAX)
        cout<<s.substr(start,len);
    else
        cout<<" ";

}

void solve() {
    string s,ans;
    cin>>s>>ans;

    helper(s, ans);
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


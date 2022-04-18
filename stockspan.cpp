#include<bits/stdc++.h>
using namespace std;

// right to left iterate
// popping out smaller elements

vector<int> greatertoleft(vector<int> arr)
{
   int n=arr.size();
   stack<int> s;
   s.push(n-1);
   vector<int> ans(n);

   for(int i=n-2;i>=0;i--)
   {
            while(!s.empty() && arr[i]>arr[s.top()])          // present element is greater than stack/right elements
             {

                ans[s.top()]=s.top()-i;                     //present element is ans for popped element
                  s.pop();
             }

          s.push(i);
    }

   while(!s.empty())                                        //no greater element on left,  ans=index+1
        {
         //cout<<"left smaller for "<<arr[s.top()]<<" is -1 \n";
         ans[s.top()]=s.top()+1;
         s.pop();
        }

   return ans;

}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int> ans;
    ans=greatertoleft(arr);

    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}

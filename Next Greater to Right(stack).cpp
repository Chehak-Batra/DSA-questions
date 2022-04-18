#include<bits/stdc++.h>
using namespace std;

class Solution
{
     /*
    pop smaller elements than u on the right they will never be used
    top element will be ans
    push present element

    move from right to left

    2 5 9  3  1  12 6  8  7
    5 9 12 12 12 -1 8 -1 -1

    */

    public:
    //Function to find the next greater element for each element of the array

    vector<long long> nextLargerElement(vector<long long> arr, int n){

        vector<long long> ans(n,-1);
        stack<long long> s;

        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<=arr[i])
            {
                s.pop();                            //popping out all smaller elements
            }

            if(!s.empty())                     //topmost element greater than present element
            ans[i]=s.top();

            s.push(arr[i]);                       //push present element
        }

        return ans;
    }

    /*
     alternate approach
     move from left to right
     pop smaller elements and present element will be ans for popped elements
     push present element

    push indexes in stack instead of elements
    */

    vector<long long> nextLargerElement(vector<long long> arr, int n){

        vector<long long> ans(n,-1);
        stack<long long> s;


        for(int i=0;i<arr.size();i++)
        {
            while(!s.empty() && arr[s.top()]<arr[i])      //top element smaller than present element
            {
                ans[s.top()]=arr[i];                     //ans for popped element is present element
                s.pop();
            }

            s.push(i);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends

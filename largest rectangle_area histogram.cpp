class Solution {
public:
    vector<int> smallerleft(vector<int> arr)
    {
        vector<int> ans(arr.size(),-1);
        stack<int> s;

        for(int i=arr.size()-1;i>=0;i--)               // right to left
        {
            while(!s.empty() && arr[i]<arr[s.top()])     // present element < stack elements
            {
                ans[s.top()]=i;
                s.pop();
            }

            s.push(i);
        }

        return ans;

    }

    vector<int> smallerright(vector<int> arr)
    {
         vector<int> ans(arr.size(),arr.size());
        stack<int> s;

        for(int i=0;i<arr.size();i++)               // left to right
        {
            while(!s.empty() && arr[i]<arr[s.top()])     // present element < stack elements
            {
                ans[s.top()]=i;
                s.pop();
            }

            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> left=smallerleft(heights);
        vector<int> right=smallerright(heights);

        int area=0;

        for(int i=0;i<heights.size();i++)
        {
            int height=heights[i];
            int width=right[i]-left[i]-1;             //max width possible for current height

            area=max(area,height*width);
        }

        return area;

    }
};

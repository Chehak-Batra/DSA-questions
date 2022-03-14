//maximum length of a contiguous subarray with an equal number of 0 and 1.
//length of longest subarray with sum k

class Solution {
public:
    int longestsubarraysumequalk(vector<int>& nums, int k)
    {
        int length=0;
        unordered_map<int,int> um;
        um[0]=-1;
        int sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

            int key=sum-k;

            if(um.find(key)!=um.end())
                length=max(length,i-um[key]);

            if(um.find(sum)==um.end())
                um[sum]=i;
        }

        return length;
    }

    //length me um[0]=-1  and no updating step

    int findMaxLength(vector<int>& nums) {

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                nums[i]=-1;
        }

        return longestsubarraysumequalk(nums,0);
    }
};

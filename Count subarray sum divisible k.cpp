//count of subarray with sum divisible by k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int count=0;
        unordered_map<int,int> um;
        um[0]=1;
        int sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int key=sum%k;

            if(key<0)
                key+=k;

            if(um.find(key)!=um.end())
                count+=um[key];

            if(um.find(key)==um.end())
                um[key]=1;

            else
                um[key]++;

        }

        return count;
    }
};

/*

................(sum)
.....(x)(sum-x)

(sum-x)%k==0
(sum%k-x%k)%k==0
sum%k==x%k            //left store right find

*/

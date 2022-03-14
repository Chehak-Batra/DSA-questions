//count of subarray with sum k


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> um;         //sum count
        um[0]=1;                           //sum0 always count1
        int sum=0;
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

            int key=sum-k;       //find sum-k in map

            if(um.find(key)!=um.end())        //found key
            {
                count+=um[key];
            }

            if(um.find(sum)==um.end())         //first time sum coming
                um[sum]=1;
            else
                um[sum]++;
        }


        return count;
    }

    /*

    ...............(sum)
    .....(sum-k)(k)
    */
};

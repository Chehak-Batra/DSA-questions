//Count of subarray with equal 0 and 1
//Count of subarray with sum k(0)

long long int subarraySum(int k,int nums[], int n) {

        unordered_map<int,int> um;         //sum count
        um[0]=1;                           //sum0 always count1
        long long int sum=0;
        long long int count=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            long long int key=sum-k;       //find sum-k in map

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

    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            arr[i]=-1;
        }

        return subarraySum(0,arr,n);

    }

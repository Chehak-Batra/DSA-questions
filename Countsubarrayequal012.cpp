//Count of subarray with equal 0,1,2   c1-c0|c2-c1 same


class Solution {
  public:
    long long getSubstringWithEqual012(string arr) {

    unordered_map<string,long long int> um;  // unique pattern string, count
    long long int count=0;
    um["0|0"]=1;
    long long int n0=0;
    long long int n1=0;
    long long int n2=0;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]=='0')
        n0++;
        else if(arr[i]=='1')
        n1++;
        else
        n2++;

        string key=to_string(n1-n0)+"|"+to_string(n2-n1);
        //same c1-c0|c2-c1

        if(um.find(key)!=um.end())
        count+=um[key];

        if(um.find(key)==um.end())
        um[key]=1;
        else
        um[key]++;
    }

    return count;
}

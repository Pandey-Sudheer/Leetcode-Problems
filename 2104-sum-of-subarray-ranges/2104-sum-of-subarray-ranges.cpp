class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return maxsum(nums) - minsum(nums);
    }
    //for maxsum 
    long long maxsum(vector<int>& nums)
    {
        int n = nums.size();
        stack<int> stk;
        long long res = 0;
        for(int i=0; i<=n; i++)
        {
            while(!stk.empty() && (i == n || nums[stk.top()] < nums[i]))
            {
                int mid = stk.top();
                stk.pop();
                long long left = stk.empty() ? -1 : stk.top();
                int right = i;
                res += (long long)nums[mid]*(mid - left)*(right - mid);
            }
            stk.push(i);
        }
        return res;
    }
    //for min sum
    long long minsum(vector<int>& nums)
    {
        int n = nums.size();
        stack<int> stk;
        long long res = 0;
        for(int i=0; i<=n; i++)
        {
            while(!stk.empty() && (i == n || nums[stk.top()] > nums[i]))
            {
                int mid = stk.top();
                stk.pop();
                long long left = stk.empty() ? -1 : stk.top();
                int right = i;
                res += (long long)(nums[mid])*(mid - left)*(right - mid);
            }
            stk.push(i);
        }
        return res;
    }
};
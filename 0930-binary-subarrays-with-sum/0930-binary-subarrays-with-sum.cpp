class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        unordered_map<int, int>cnt;
        cnt[0] = 1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(cnt.count(sum-goal))
            {
                ans += cnt[(sum-goal)];
            }
            cnt[sum]++;
        }
        return ans;
    }
};
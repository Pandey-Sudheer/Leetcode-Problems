class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>cnt( n+1, 0);
        // base case: before array starts, odd count = 0 occurred once
        cnt[0] = 1;
        int t =0;
        int ans = 0;
        for(int v : nums)
        {
            // v & 1 → 1 if v is odd
            t += v & 1;
            if( t-k >= 0)
            {
                ans += cnt[t-k];
            }
            cnt[t]++;
        }
        return ans;
    }
};

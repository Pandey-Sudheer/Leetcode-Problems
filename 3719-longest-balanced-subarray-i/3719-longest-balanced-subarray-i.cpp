class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            unordered_set<int> vis;
            int cnt[2] = {0, 0};

            for(int j = i; j<n; j++)
            {
                if(!vis.count(nums[j]))
                {
                    vis.insert(nums[j]);
                    ++cnt[nums[j] % 2];
                }

                // check odd and even are equal numbers or not
                if( cnt[0] == cnt[1] )
                {
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
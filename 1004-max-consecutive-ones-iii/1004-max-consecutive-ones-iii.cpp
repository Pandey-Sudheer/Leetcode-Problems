class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, maxlen=0, zerocnt = 0;
        for(int right=0; right<n; right++)
        {
            if(nums[right] == 0)
            {
                zerocnt++;
            }
            while(zerocnt > k)
            {
                if(nums[left] == 0)
                {
                    zerocnt--;
                }
                left++;
            }
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
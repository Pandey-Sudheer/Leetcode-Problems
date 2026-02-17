class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int ans = 0;  // total valid subarrays
        
        unordered_map<int,int> cnt;
        cnt[0] = 1;   // 0 odd seen once (base case)
        
        int odd = 0;  // prefix count of odd numbers
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] % 2 == 1) 
                odd++;  // increase odd count
            
            ans += cnt[odd - k];  
            // if previous prefix had (odd-k) odds → subarray has k odds
            
            cnt[odd]++;  // store current prefix
        }
        
        return ans;
    }
};

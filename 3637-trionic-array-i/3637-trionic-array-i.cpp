class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        //increasing order (must have at least one step)
        while( i < n-1 && nums[i] < nums[i+1]) i++;
        if(i==0) return false; //no increasing part

        //decreasing order (must have at least one step)
        int p = i;
        while(i<n-1 && nums[i] > nums[i+1]) i++;
        if(i==p || i == n-1) return false; //no decreasing or no room for third part

        //increasing order till the end
        while(i < n-1 && nums[i] < nums[i+1]) i++;
        
        return i==n-1;
    }
};
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] ans = new int[nums.length];
        int p =0;
        int neg = 1;
        for( int num : nums )
        {
            if( num > 0)
            {
                ans[p] = num;
                p +=2;
            }else{
                ans[neg] = num;
                neg += 2;
            }
            
        }
        return ans;
    }
}
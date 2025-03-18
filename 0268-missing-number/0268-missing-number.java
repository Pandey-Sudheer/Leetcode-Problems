class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        // int count = 0;
        Arrays.sort(nums);
        for( int i= 0; i<nums.length; i++)
        {
          
            if( nums[i] != i)
            {
             return i;
                // count++;
            }
        }
        return n;
    }
}
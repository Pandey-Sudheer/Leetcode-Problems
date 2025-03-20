class Solution {
    public void sortColors(int[] nums) {
        int temp = 0;
        int start = 0, mid = 0, end = nums.length-1;
        while( mid <= end)
        {
            if( nums[mid] == 0)
            {
                temp = nums[start];
                nums[start] = nums[mid];
                nums[mid] = temp;
                start++;
                mid++;
            }else if( nums[mid] == 1)
            {
                mid++;
            }else
            {
                temp = nums[mid];
                nums[mid] = nums[end];
                nums[end] = temp;
                end--;
            }
        }
    }
}
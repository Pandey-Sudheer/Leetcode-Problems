class Solution {
    public int search(int[] nums, int target) {
        int strt = 0;
        int end = nums.length-1;
        int mid;
        while( strt <= end )
        {
            mid = (strt + end) / 2;
            if( nums[mid] == target )
            {
                return mid;
            }

            if( nums[strt] <= nums[mid] )
            {
                if (nums[strt] <= target && nums[mid] >= target)
                {
                    end = mid - 1;
                } else 
                {
                    strt = mid + 1;
                }
            } else 
            {
                if ( nums[end] >= target && nums[mid] <= target)
                {
                    strt = mid + 1;
                } else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
}
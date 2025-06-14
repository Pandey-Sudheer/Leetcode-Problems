class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1,-1};
        ans[0] = binarySearch(nums, target, true);
        ans[1] = binarySearch(nums, target, false);

        return ans;
    }

    static int binarySearch(int[] nums, int target, boolean findFirst)
    {
        int strt = 0; 
        int end = nums.length-1;
        int ans = -1;
        while( strt <= end )
        {
            int mid = strt+ (end - strt)/2;
            if( target > nums[mid] )
            {
                strt = mid + 1;
            }else if(target < nums[mid] )
            {
                end = mid - 1;
            }else
            {
                ans = mid;

                if(findFirst)
                {
                    end = mid - 1;
                }else
                {
                    strt = mid + 1;
                }
            }
        }
        return ans;
    }
}
class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int maxNum = 0;
        for( int i=0; i<nums.length; i++)
        {
            if( nums[i] > maxNum )
                maxNum = nums[i];
        }

        int low = 1;
        int high = maxNum;
        while( low <= high )
        {
            int mid = ( low + high ) / 2;
            int sum = 0;
            for(int i=0; i<nums.length; i++)
            {
            sum += ( nums[i] + (mid - 1)) / mid;
            if( sum > threshold){
            break;
            }
            }

        if( sum <= threshold )
        {
            high = mid - 1;
        }else {
            low = mid + 1;
        }
        }
        return low;
    }
}
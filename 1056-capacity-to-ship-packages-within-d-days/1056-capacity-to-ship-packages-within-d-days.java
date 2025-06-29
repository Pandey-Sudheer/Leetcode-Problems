class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int minCap = 0;
        int maxCap = 0;

        for( int weight : weights )
        {
            minCap = Math.max( minCap, weight);
            maxCap += weight;
        }

        // Apply Binary Search 
        while( minCap < maxCap)
        {
            int mid = ( minCap + maxCap ) / 2;
            int D = 1;
            int sum = 0;
            for(int weight : weights)
            {
                if( weight + sum > mid)
                {
                    D++;
                    sum=0;
                }
                sum += weight;
            }
            // if more days required, then increase capacity
            if( days < D)
            {
                minCap = mid + 1;
            }else{
                maxCap = mid;
            }
        }
        return minCap;
    }
}
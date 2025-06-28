class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int s = 0; int e = (int)1e9;
        int ans = -1;

        while( s <= e )
        {
            int mid = s + (e - s) / 2;
            int count = 0; int buk = 0;

            for( int i=0; i<bloomDay.length; i++)
            {
                if( bloomDay[i] <= mid)
                {
                    count++;
                    if( count >= k)
                    {
                        buk++;
                        count = 0;
                    }
                }else {
                    count = 0;
                }
            }

            if( m <= buk)
            {
                ans = mid;
                e = mid - 1;
            }else {
                s = mid + 1;
            }
        }
        return ans;
    }
}
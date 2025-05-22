class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        if(n == 0)
        {
            return 0;
        }
        int longest = 1;
        Set<Integer> set = new HashSet<>();

        // put all the array element in to the set 
        for( int i=0; i<n; i++)
        {
            set.add(nums[i]);
        }

        // find the longest sequences
        int maxcnt =1;
        for(int it:set)
        {
            // if it is starting number
            if(!set.contains(it-1))
            {
                // find consequetive numbers
                int cnt = 1;
                // int x = it;
                while(set.contains(it+1))
                {
                    // x = x+1;
                    it++;
                    cnt++;
                    // cnt = cnt+1;
                }
                if(cnt>maxcnt)
                {
                    maxcnt = cnt;
                }
                // longest = Math.max(longest,cnt);
            }
        }
         return maxcnt;
    }
}
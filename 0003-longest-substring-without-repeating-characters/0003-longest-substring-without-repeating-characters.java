class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxlen = 0;
        Set<Character> charset = new HashSet<>();
        int left = 0;
        for(int right=0; right<n; right++)
        {
            if(!charset.contains(s.charAt(right)))
            {
                charset.add(s.charAt(right));
                maxlen = Math.max(maxlen, right-left+1);
            }else{
                while(charset.contains(s.charAt(right)))
                {
                    charset.remove(s.charAt(left));
                    left++;
                }
                charset.add(s.charAt(right));
            }
        }
        return maxlen;
    }
}
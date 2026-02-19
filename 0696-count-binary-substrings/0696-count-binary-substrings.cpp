class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, crnt = 1, ans = 0;
        for(int i=1; i<s.length(); i++)
        {
            if(s[i] == s[i-1])
            {
                crnt++;
            }else{
                ans += min(prev, crnt);
                prev = crnt;
                crnt = 1;
            }
        }
        return ans + min(prev, crnt);
    }
};
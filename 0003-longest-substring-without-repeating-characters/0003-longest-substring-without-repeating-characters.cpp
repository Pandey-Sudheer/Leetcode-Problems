class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < s.size())
        {
        // check whether element is found up to the end or not 
        // if not found then if condition runs anotherwise else because of element is found
            if(st.find(s[right]) == st.end() )
            {
                st.insert(s[right]);
                ans = max(ans, right-left+1);
                right++;
            }else
            {
            st.erase(s[left]);
            left++;
            }
        }
        return ans;
    }
};
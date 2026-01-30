class Solution {
public:
    int firstUniqChar(string s) {
        // 1. Create a frequency array for 26 lowercase English letters
        vector<int> count(26,0);

        // 2. First pass: Populate the frequency array
        for( char c : s)
        {
            count[c-'a']++;
        }
         // 3. Second pass: Find the first char with count == 1
        for( int i=0; i<s.length(); i++){
            if( count[s[i] - 'a'] == 1)
            {
                return i; // Return index of first non-repeated char
            }
        }
        return -1; // If no unique character exists
    }
};
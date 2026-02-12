class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int uniquecnt = 0;
            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';

                if (freq[idx] == 0)
                    uniquecnt++;

                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);

                int len = j - i + 1;

                // Balanced condition
                if (len == uniquecnt * maxFreq) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};

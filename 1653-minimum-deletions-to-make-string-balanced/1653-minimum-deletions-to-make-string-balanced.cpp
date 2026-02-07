class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int cnta = 0;

        for(int i=n-1; i>=0; i--)
        {
            if( s[i] == 'a')
            {
                cnta++;
            }
        }
        int count = INT_MAX;
        int cntb = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a')
            {
                cnta--;
            }
            count = min(count, cnta + cntb);
            if(s[i] == 'b')
            {
                cntb++;
            }
        }
        return count;
    }
};
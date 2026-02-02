class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        stack<int> stk;
        long minsum = 0;
        for( int i=0; i<=arr.size(); i++)
        {
            while(!stk.empty() && (i==arr.size() || arr[stk.top()] >= arr[i]))
            {
                int mid = stk.top();
                stk.pop();
               int leftBoundary = stk.empty() ? -1 : stk.top();
               int rightBoundary = i;

               long count = (mid-leftBoundary)*(rightBoundary - mid)% MOD;

               minsum += ( count * arr[mid]) % MOD;
               minsum %= MOD;
            }
            stk.push(i);
        }
        return static_cast<int>(minsum);
    }
};
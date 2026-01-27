class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool isPositive = !((dividend < 0) ^ (divisor < 0));

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long ans = 0;

        while (a >= b) {
            int low = 0, high = 31, best = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if ((b << mid) <= a) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans += (1LL << best);
            a -= (b << best);
        }

        return isPositive ? ans : -ans;
    }
};

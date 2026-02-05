class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>res(n, 0);
        // Case 1: k == 0 → all values become 0
        if( k == 0) return res;

        int sum = 0;
        // Case 2: k > 0 (sum NEXT k elements)
        if( k > 0)
        {
            // Step 1: compute sum for index 0
            // window = code[1] to code[k]
            for(int i=1; i<=k; i++)
            sum += code[i%n];  // %n handles circular array

            // Step 2: sliding window
            for(int i=0; i<n; i++)
            {
                res[i] = sum; // store current window sum
                // remove the element leaving the window
                sum -= code[(i+1)%n];
                // add the new element entering the window
                sum += code[(i+k+1) % n];
            }
        }
        // Case 3: k < 0 (sum PREVIOUS |k| elements)
        else{
            k = -k;  // convert k to positive count (direction handled by indices)

            // Step 1: compute sum for index 0
            // window = code[n-1] to code[n-k]
            for(int i=1; i<=k; i++)
              sum += code[(n-i) % n];

              // Step 2: sliding window
            for(int i=0; i<n; i++)
            {
                res[i] = sum; // store current window sum

                // remove element leaving the window
                sum -= code[(n + i -k) % n];
                // add new element entering the window
                sum += code[i % n];
            }
        }
        return res;
    }
};
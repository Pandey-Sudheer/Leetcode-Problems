class Solution {
public:
    int helper(string& s , char a , char b){
        int n = s.size();
        int countA = 0 , countB = 0 ;
        unordered_map<int , int> diffMap;
        int maxL = 1;

        for(int i = 0 ; i < n ; i++){
            if(s[i] != a && s[i] != b){
                diffMap.clear();
                countA = 0 ;
                countB = 0 ;
                continue;
            }

            if(s[i] == a) countA++;
            if(s[i] == b) countB++;

            if(countA == countB)
                maxL = max(maxL , countA + countB);

            int diff = countA - countB;

            if(diffMap.count(diff)){
                maxL = max(maxL , i - diffMap[diff]);
            }else{
                diffMap[diff] = i;
            }
        }
        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxL = 1;

        // Case 1: Single character
        int count = 1;
        for(int i = 1 ; i < n ; i++){
            if(s[i] == s[i - 1]){
                count++;
            }else{
                maxL = max(maxL , count);
                count = 1;
            }
        }
        maxL = max(maxL, count);

        // Case 2: Two characters
        maxL = max(maxL , helper(s , 'a' , 'b')); 
        maxL = max(maxL , helper(s , 'a' , 'c')); 
        maxL = max(maxL , helper(s , 'b' , 'c')); 

        // Case 3: Three characters
        int countA = 0, countB = 0, countC = 0;
        unordered_map<string , int> mpp;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a') countA++;
            if(s[i] == 'b') countB++;
            if(s[i] == 'c') countC++;

            if(countA == countB && countA == countC)
                maxL = max(maxL , countA + countB + countC);

            int diffAB = countA - countB;
            int diffAC = countA - countC;
            string key = to_string(diffAB) + '_' + to_string(diffAC);

            if(mpp.count(key)){
                maxL = max(maxL , i - mpp[key]);
            }else{
                mpp[key] = i;
            }
        }

        return maxL;
    }
};
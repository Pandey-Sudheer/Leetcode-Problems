class Solution {
public:
    int minimumDeletions(string s) {

        int b_before_a = 0;
        int cntdeletion = 0;
        for(auto ch : s)
        {
            if(ch == 'b') 
            {
                b_before_a++;
            }else if(b_before_a > 0)
            {
                b_before_a--;
                cntdeletion++;
            }

        }
        return cntdeletion;
       
    }
};
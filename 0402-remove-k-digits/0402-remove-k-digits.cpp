class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for( char c : num )
        { //check current value is minimal than top of stack
            while( !s.empty() && s.top() > c && k > 0)
            {
                s.pop();
                k--;
            }
            s.push(c);
        }
        
        while( k > 0 && !s.empty() )
        {
            s.pop();
            k--;
        }
        string res = "";
        while( !s.empty())
        {
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        //remove leading zeros
        size_t first_nonzero = res.find_first_not_of('0');
        if(first_nonzero == string::npos) return "0";
        return res.substr(first_nonzero);
    }
};
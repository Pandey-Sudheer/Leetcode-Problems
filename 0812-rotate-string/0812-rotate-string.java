class Solution {
    public boolean rotateString(String s, String goal) {
        // if the length of one string is not equal to another then there is never happens rotation 
        if( s.length() != goal.length())
        {
            return false;
        }
        return ( s + s ).contains( goal );
    }
}
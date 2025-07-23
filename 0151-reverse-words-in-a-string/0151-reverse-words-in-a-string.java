class Solution {
    public String reverseWords(String s) {
        String[] arr = s.split("\\s+");

        StringBuilder sb = new StringBuilder("");

        for(int i = arr.length -1; i>=0; i-- )
        {
        // Using sb.append(...) to join each word
            sb.append( arr[i] + " " );
        }
        
        // Convert StringBuilder to String
        String ans = sb.toString();
        ans = ans.trim();
        return ans;
    }
}
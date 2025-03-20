class Solution {
    public int majorityElement(int[] nums) {
        int candidate = nums[0];  // Start with the first element as the candidate
        int count = 1;  // Count starts at 1 since we already have one occurrence of the candidate

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == candidate) {
                count++;  // Increase count if the element is the same as the candidate
            } else {
                count--;  // Decrease count if the element is different
                if (count == 0) {
                    candidate = nums[i];  // Reset candidate if count drops to 0
                    count = 1;  // Reset count to 1 for the new candidate
                }
            }
        }
        
        return candidate;  // The majority element will be the candidate
    }
}
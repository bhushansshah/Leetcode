/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.   
*/
import java.util.HashMap;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            if(!hashMap.containsKey(target - nums[i])){
                hashMap.put(nums[i], i);
            } 
            else {
                int[] result = {i, hashMap.get(target - nums[i])};
                return result;
            }
        }
    return null;
    }
}   
   

class Solution {
    public int maxProduct(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        int max=nums[0];
        int min=nums[0];
        int result=max;

        for(int i=1;i<nums.length;i++){
            int curr=nums[i];
            int tempmax=Math.max(curr,Math.max(curr*max,curr*min));
             min=Math.min(curr,Math.min(curr*max,curr*min));
             max=tempmax;

             result= Math.max(result,max);
        }
        return result;
    }
}
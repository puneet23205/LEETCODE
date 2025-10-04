class Solution {
    public int findMin(int[] nums) {
                 int low=0;
         int high= nums.length-1;
         int ans=nums[0];
         while(low<=high){
            if(nums[low]<nums[high]){
                ans=nums[low];
                break;
            }
            int mid=(low+high)/2;

             ans=Math.min(ans,nums[mid]);
             if(nums[low]<=nums[mid]){
                low=mid+1;
             }
             else{
                high=mid;
             }
         }
         return ans;
    
    }
}
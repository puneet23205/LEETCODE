class Solution {
    public int trap(int[] height) {
        int left = 0, right = height.length - 1;
        int leftMax = 0, rightMax = 0;
        int trappedWater = 0;

        while (left < right) {
            // operate on the side with the smaller height
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left]; // update boundary
                } else {
                    trappedWater += leftMax - height[left]; // water trapped
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right]; // update boundary
                } else {
                    trappedWater += rightMax - height[right]; // water trapped
                }
                right--;
            }
        }
        return trappedWater;
    }
}


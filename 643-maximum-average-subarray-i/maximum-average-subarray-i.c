double findMaxAverage(int* nums, int numsSize, int k){        
        if (k > numsSize) {
            return -1;
        }
        
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        double maxSum = sum;
        for (int i = k; i < numsSize; i++) {
            sum = sum - nums[i - k] + nums[i];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        
        return maxSum/k;
    }

class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        l_sum, r_sum =0, sum(nums)

        for i in range(len(nums)):
            if l_sum==r_sum-nums[i]:
                return i
            

            l_sum+=nums[i]
            r_sum-=nums[i]

        return -1
class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        cur=-1
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[j]-nums[i]>cur and nums[j]!=nums[i]:
                    cur=nums[j]-nums[i]
        return cur
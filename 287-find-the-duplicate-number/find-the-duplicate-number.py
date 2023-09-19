class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        l = sorted(nums)
        for i in range(len(l)-1):
            if l[i]==l[i+1]:
                return l[i]
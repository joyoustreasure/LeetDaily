class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        nums = [int(ch) for ch in s.split() if ch.isdigit()]
        for i in range(1,len(nums)):
            if nums[i-1]>=nums[i]:
                return False
        return True
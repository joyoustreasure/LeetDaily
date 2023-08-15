class Solution:
    def rotate(self, nums: List[int], k: int) -> None:

        k = k % len(nums) 
        p1= nums[-k:]
        p2 = nums[:-k]
        nums[:] =p1+p2

        
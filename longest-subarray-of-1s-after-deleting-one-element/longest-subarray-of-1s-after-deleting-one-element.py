class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        s,e=0,0
        cnt,res=0,0
        while e<len(nums):
            if nums[e]==0:
                cnt+=1
            e+=1
            while cnt>1:
                if nums[s]==0:
                    cnt-=1
                s+=1
            res=max(res,e-s-1)
            
        return res
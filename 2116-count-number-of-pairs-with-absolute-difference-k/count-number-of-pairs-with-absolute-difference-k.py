class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        seen={}
        cnt=0

        for i in nums:
            if i in seen:
                seen[i] += 1
            else:
                seen[i] = 1

        for i in seen:
            if (i+k) in seen:
                cnt+=seen[i]*seen[i+k]
        
        return cnt
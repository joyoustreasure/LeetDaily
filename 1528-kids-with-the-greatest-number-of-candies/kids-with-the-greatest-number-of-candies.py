class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        M = max(candies)
        lst = [x-M+extraCandies for x in candies]
        result=[0]*len(candies)
        for i in range(len(lst)):
            if lst[i]>=0:
                result[i]=True
            else:
                result[i]=False
        return result
            
              
class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        dct={}

        for i in nums1:
            if i in dct:
                dct[i][0]+=1
            else:
                dct[i]=[1,0,0]
        
        for i in nums2:
            if i in dct:
                dct[i][1] +=1
            else:
                dct[i] = [0,1,0]
        for i in nums3:
            if i in dct:
                dct[i][2]+=1
            else:
                dct[i] = [0,0,1]
        ans=[]
        for i in dct:
            if sum(dct[i])>1 and sum(dct[i]) not in (dct[i][0], dct[i][1], dct[i][2]):
                ans.append(i)
        return ans

        
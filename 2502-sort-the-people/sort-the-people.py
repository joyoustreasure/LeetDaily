class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        dct = dict(zip(heights,names))
        names=[]
        for h in sorted(dct.keys(), reverse=True):
            names.append(dct[h])
        
        return names
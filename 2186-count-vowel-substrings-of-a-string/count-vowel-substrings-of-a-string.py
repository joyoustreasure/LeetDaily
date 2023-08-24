class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        def check(sub:str)->bool:
            return set(sub)=={'a', 'e', 'i', 'o', 'u'}
        cnt=0
        for s in range(len(word)):
            for e in range(s+4,len(word)):
                if check(word[s:e+1]):
                    cnt+=1
        return cnt
class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        res=''
        tot=sum(shifts)
        used=0

        for i in range(len(s)):
            char_n = ord(s[i])+tot-used
            used+=shifts[i]
#97~122
            res+=chr(97+(char_n-97)%26)
  
        return res
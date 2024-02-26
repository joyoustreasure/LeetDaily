class Solution:
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        result=[]
        for i in range(n):
            for j in range(i + 1, n + 1):
                substring = s[i:j]
                if substring==substring[::-1]:
                    result.append(substring)
        M,idx=0,0
        for i in range(len(result)):
           if len(result[i])>M:
               M,idx = len(result[i]),i
        return result[idx]       
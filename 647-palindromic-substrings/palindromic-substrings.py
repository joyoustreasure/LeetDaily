class Solution:
    def countSubstrings(self, s: str) -> int:
        def contiguous_all_cases(s:str):
            n=len(s)
            result=[]
            for i in range(n):
                for j in range(i + 1, n + 1):
                    substring = s[i:j]
                    if substring==substring[::-1]:
                        result.append(substring)
            return result
        result = contiguous_all_cases(s)
        return len(result)
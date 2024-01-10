class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n_len = len(needle)
        for i in range(len(haystack)-len(needle)+1):
            cur = haystack[i:i+n_len]
            if cur==needle:
                return i
        return -1
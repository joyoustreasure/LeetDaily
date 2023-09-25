class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s)<=1:
            return len(s)
        l,r = 0, 0
        chars=set()
        M = 0

        while r<len(s):
                if s[r] not in chars:
                    chars.add(s[r])
                    M = max(M, r- l + 1)
                    r += 1
                else:
                    chars.remove(s[l])
                    l+=1
        return M

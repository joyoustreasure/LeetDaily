class Solution:
    def reverseWords(self, s: str) -> str:
        ans = []
        words = s.split()
        for word in words:
            ans.append(word[::-1])
        return ' '.join(ans)

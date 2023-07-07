class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        maxConsecutive, maxLength = 0,0
        cntT, cntF = 0,0
        s, e = 0,0

        while e < len(answerKey):
            if answerKey[e] == 'T':
                cntT += 1
            else:
                cntF += 1

            if max(cntT, cntF) + k < (e-s+1):
                if answerKey[s] == 'T':
                    cntT -= 1
                else:
                    cntF -= 1
                s += 1

            maxLength = max(maxLength, e-s+1)
            e += 1

        return maxLength       
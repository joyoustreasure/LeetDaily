class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        for i in range(len(word)):
            if word[i]==ch:
                if i==0:
                    return word
                elif i == 1:
                    return word[1]+word[0]+word[2:]
                else:
                    new=word[:i]
                    return word[i]+new[::-1]+word[i+1:]
        return word
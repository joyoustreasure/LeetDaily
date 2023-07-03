class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s)!=len(goal):
            return False
        cand_s, cand_g=[],[]
        cnt=0
        for i in range(len(s)):
            if s[i]!=goal[i]:
                cand_s.append(s[i])
                cand_g.append(goal[i])
                cnt+=1
        if cnt==2 and cand_s[::-1]==cand_g:
            return True
        elif cnt==0 and len(s)>len(set(s)):
            return True
        return False
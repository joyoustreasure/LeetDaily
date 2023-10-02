class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        a, b= 0, 0
        for i in range(len(colors)-2):
            if colors[i:i+3]=="AAA":
                a+=1
            elif colors[i:i+3]=='BBB':
                b+=1
        if a==b:
            return False
        elif a>b:
            return True
        else:
            return False

class Solution:
    def isValid(self, s: str) -> bool:

        dct = {'(': ')', '{': '}', '[': ']'}
        stack = []
        for char in s:
            if char in dct:       # 여는 기호면 스택에 넣기
                stack.append(char)
            elif char in dct.values():                #닫는 기호면 stack이 비어있어도 false이고 stack 마지막에서 dct값이 char여도 false
                if not stack or dct[stack.pop()] != char:
                    return False
        return len(stack) == 0
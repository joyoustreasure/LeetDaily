class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack=[]
        for i in tokens:
            if i not in {'+', '-', '*', '/'}:
                stack.append(i)
            else:
                x,y= int(stack.pop()), int(stack.pop())

                if i =='*':
                    stack.append(x*y)
                elif i == '/':
                    stack.append(trunc(y/x))
                elif i == '+':
                    stack.append(x+y)
                else:
                    stack.append(y-x)

        return int(stack[0])
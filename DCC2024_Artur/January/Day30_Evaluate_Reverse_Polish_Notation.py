"""
 https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=daily-question&envId=2024-01-30
"""
from typing import Optional, List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        
        for val in tokens:
            if val in ['-', '+', '/', '*']:
                val2 = stack.pop()
                val1 = stack.pop()
                
                if val == '-':
                    stack.append(val1 - val2)
                elif val == '+':
                    stack.append(val1 + val2)
                elif val == '/':
                    stack.append(int(float(val1) / val2))
                else:
                    stack.append(val1 * val2)

            else:
                stack.append(int(val))
                    
        return stack[0]

    
if __name__ == "__main__":
    test1 = ["2","1","+","3","*"]
    test2 = ["4","13","5","/","+"]
    test3 = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    
    print(Solution().evalRPN(test1))
    print(Solution().evalRPN(test2))
    print(Solution().evalRPN(test3))

"""
https://leetcode.com/problems/determine-if-string-halves-are-alike/?envType=daily-question&envId=2024-01-12
"""

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        i = 0
        
        while i < len(s):
            if s[i] != ']':
                stack.append(s[i])
            else:
                temp = []
                while stack[-1] != '[':
                    temp.append(stack.pop())

                stack.pop()
                #int
                num = 0
                tens = 1
                while stack and stack[-1].isnumeric():
                    num += int(stack.pop()) * tens
                    tens *= 10
                
                for _ in range(num):
                    for j in range(len(temp) - 1, -1, -1):
                        stack.append(temp[j])
            i += 1

        res = str()
        for char in stack:
            res += char
        
        return res
        


if (__name__ == '__main__'):
    solution = Solution()
    
    test1 = "3[a]2[bc]"
    test2 = "3[a2[c]]"
    test3 = "2[abc]3[cd]ef"
    test4 = "100[leetcode]"
    
    print(solution.decodeString(test1))
    print(solution.decodeString(test2))
    print(solution.decodeString(test3))
    print(solution.decodeString(test4))

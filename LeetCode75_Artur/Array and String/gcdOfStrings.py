class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        str1_len, str2_len = len(str1), len(str2)
        if str1_len >= str2_len:
            gcd = Solution.gcd(str1_len, str2_len)
            if str2[:gcd] * int(str1_len / gcd) == str1:
                return str2[:gcd]
        return ""

    def gcd(num1, num2):
        if num1 < num2:
            return Solution.gcd(num2, num1)
        elif num1 % num2 == 0:
            return num2
        return Solution.gcd(num2, num1 % num2)

Solution.gcdOfStrings()
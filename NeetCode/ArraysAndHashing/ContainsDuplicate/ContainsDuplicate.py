class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        numberFreq = dict()
        for number in nums:
            if number in numberFreq:
                return True
            numberFreq[number] = 1

        return False

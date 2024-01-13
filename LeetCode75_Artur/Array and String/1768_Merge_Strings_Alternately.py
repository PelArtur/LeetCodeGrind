class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        len_wrd1, len_wrd2 = len(word1), len(word2)
        min_len = len_wrd1
        if len_wrd2 < len_wrd1:
            min_len = len_wrd2

        res = ''
        for i in range(min_len):
            res += word1[i] + word2[i]

        if len_wrd1 != len_wrd2 and min_len == len_wrd1:
            res += word2[i+1:]
        elif min_len == len_wrd2:
            res += word1[i+1:]
        return res
        
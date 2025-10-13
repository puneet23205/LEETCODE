class Solution:
    def removeAnagrams(self, words):
        result = []
        prev_sorted = ""

        for w in words:
            sorted_word = ''.join(sorted(w))
            if sorted_word != prev_sorted:
                result.append(w)
                prev_sorted = sorted_word
        return result
    
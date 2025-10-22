class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1

        # Step 1: Skip trailing spaces
        while i >= 0 and s[i] == ' ':
            i -= 1

        # Step 2: Count characters of the last word
        length = 0
        while i >= 0 and s[i] != ' ':
            length += 1
            i -= 1

        return length  # Step 3: Return the count

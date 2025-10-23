class Solution:
    def hasSameDigits(self, s: str) -> bool:
        while len(s) > 2:
            t = ""
            for i in range(len(s) - 1):
                x = (int(s[i]) + int(s[i + 1])) % 10
                t += str(x)
            s = t
        return s[0] == s[1]

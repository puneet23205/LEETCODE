class Solution:
    def totalMoney(self, n: int) -> int:
        weeks = n // 7
        days = n % 7

        total = weeks * 28 + (weeks * (weeks - 1) // 2) * 7
        for i in range(days):
            total += (weeks + 1) + i
        return total

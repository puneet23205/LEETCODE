from collections import Counter, defaultdict
import bisect

class Solution:
    def maxFrequency(self, nums: list[int], k: int, numOperations: int) -> int:
        freq = Counter(nums)
        events = defaultdict(int)
        for v in nums:
            L, R = v - k, v + k
            events[L] += 1
            events[R + 1] -= 1

        items = sorted(events.items())
        pos, pref = [], []
        cur = 0
        for p, d in items:
            pos.append(p)
            cur += d
            pref.append(cur)

        max_cover = max(pref)
        ans = min(max_cover, numOperations)

        for v, cntEq in freq.items():
            i = bisect.bisect_right(pos, v) - 1
            cover = pref[i] if i >= 0 else 0
            cand = min(cover, cntEq + numOperations)
            ans = max(ans, cand)
        return ans

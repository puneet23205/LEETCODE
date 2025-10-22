import java.util.*;

class Solution {
    public int maxFrequency(int[] nums, long k, long numOperations) {
        Map<Long,Integer> freq = new HashMap<>();
        for (int x: nums) freq.put((long)x, freq.getOrDefault((long)x,0)+1);

        TreeMap<Long, Long> events = new TreeMap<>();
        for (int x: nums) {
            long v = x;
            long L = v - k, R = v + k;
            events.put(L, events.getOrDefault(L, 0L) + 1L);
            events.put(R + 1, events.getOrDefault(R + 1, 0L) - 1L);
        }

        List<Long> pos = new ArrayList<>();
        List<Long> pref = new ArrayList<>();
        long cur = 0;
        for (Map.Entry<Long,Long> e: events.entrySet()) {
            pos.add(e.getKey());
            cur += e.getValue();
            pref.add(cur);
        }

        long maxCover = 0;
        for (long x: pref) maxCover = Math.max(maxCover, x);

        long ans = Math.min(maxCover, numOperations);

        for (Map.Entry<Long,Integer> e: freq.entrySet()) {
            long v = e.getKey();
            int cntEq = e.getValue();
            int idx = Collections.binarySearch(pos, v);
            long cover;
            if (idx >= 0) cover = pref.get(idx);
            else {
                int ins = -idx - 1;
                cover = (ins == 0) ? 0 : pref.get(ins - 1);
            }
            long cand = Math.min(cover, cntEq + numOperations);
            ans = Math.max(ans, cand);
        }

        return (int)ans;
    }
}

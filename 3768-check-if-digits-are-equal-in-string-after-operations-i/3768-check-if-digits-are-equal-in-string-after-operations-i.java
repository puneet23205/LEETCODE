class Solution {
    public boolean hasSameDigits(String s) {
        while (s.length() > 2) {
            StringBuilder t = new StringBuilder();
            for (int i = 0; i < s.length() - 1; i++) {
                int x = ((s.charAt(i) - '0') + (s.charAt(i + 1) - '0')) % 10;
                t.append((char)(x + '0'));
            }
            s = t.toString();
        }
        return s.charAt(0) == s.charAt(1);
    }
}

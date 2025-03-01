int firstUniqChar(char* s) {
      int count[26];
    for (int i = 0; i < 26; i++) {
        count[i] = 0;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a'] = count[s[i] - 'a'] + 1;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}
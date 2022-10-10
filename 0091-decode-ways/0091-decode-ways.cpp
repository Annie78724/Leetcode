class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        int len = s.size(), dp[3];
        dp[0] = 1;
        dp[1] = (s[0] == '1' || s[0] == '2' && s[1] < '7' ? 1 : 0) + (s[1] != '0');
        for (int i = 2, curr, prev; i < len; i++) {
            curr = i % 3;
            prev = curr ? curr - 1 : 2;
            if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0')) return 0;
            dp[curr] = s[i] != '0' ? dp[prev] : 0;
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7') dp[curr] += dp[prev ? prev - 1 : 2];
        }
        return dp[(len - 1) % 3];
    }
};
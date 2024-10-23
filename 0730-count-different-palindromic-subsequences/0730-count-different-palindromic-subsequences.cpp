
    class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.length();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        return count(0, n - 1, S, mem);
    }

private:
    int count(int i, int j, string &s, vector<vector<int>> &mem) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (mem[i][j] != -1) return mem[i][j];

        int num = 0;
        if (s[i] == s[j]) {
            num = 2 * count(i + 1, j - 1, s, mem);

            int left = i + 1, right = j - 1;
            while (left <= right && s[left] != s[i]) left++;
            while (left <= right && s[right] != s[i]) right--;

            if (left < right) num -= count(left + 1, right - 1, s, mem);
            else if (left == right) num += 1;
            else num += 2;
        } else {
            num = count(i + 1, j, s, mem) + count(i, j - 1, s, mem) - count(i + 1, j - 1, s, mem);
        }

        mem[i][j] = (num < 0) ? num + 1000000007 : num % 1000000007;
        return mem[i][j];
    }
};
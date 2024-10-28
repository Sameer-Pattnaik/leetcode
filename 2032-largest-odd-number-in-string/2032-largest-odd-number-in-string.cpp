class Solution {
public:
    string largestOddNumber(string num) {
        int idx = num.length() - 1;
        while (idx >= 0 && ((num[idx] - '0') & 1) == 0) --idx;
        return num.substr(0, idx + 1);
    }
};
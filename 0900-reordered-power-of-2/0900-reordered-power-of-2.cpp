class Solution {
public:
    vector<int> digitFreq(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
        return freq;
    }
    bool equalFreq(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < 10; ++i)
            if (a[i] != b[i]) return false;
        return true;
    }

    bool reorderedPowerOf2(int N) {
        vector<int> target = digitFreq(N);
        for (int i = 0; i <= 30; ++i) {
            int powerof2 = (int)pow(2, i);; // 2^i
            if (equalFreq(target, digitFreq(powerof2)))
                return true;
        }
        return false;
    }
};
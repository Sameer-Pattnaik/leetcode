static long long floor_div(long long x, long long y) {
    long long d = x / y;
    if ((x ^ y) < 0 && x % y) --d;
    return d;
}

static long long ceil_div(long long x, long long y) {
    long long d = x / y;
    if ((x ^ y) >= 0 && x % y) ++d;
    return d;
}

class Solution {
public:
    long long kthSmallestProduct(vector<int>& n1, vector<int>& n2, long long k) {
        if (n1.size() > n2.size()) swap(n1, n2);
        long long m2 = n2.size();
        auto cnt = [&](long long x) {
            long long c = 0;
            for (long long a : n1) {
                if (a > 0) {
                    long long t = floor_div(x, a);
                    c += upper_bound(n2.begin(), n2.end(), t) - n2.begin();
                } else if (a < 0) {
                    long long t = ceil_div(x, a);
                    c += m2 - (lower_bound(n2.begin(), n2.end(), t) - n2.begin());
                } else if (x >= 0) {
                    c += m2;
                }
            }
            return c;
        };
        long long lo = min({
            (long long)n1.front() * n2.front(),
            (long long)n1.front() * n2.back(),
            (long long)n1.back()  * n2.front(),
            (long long)n1.back()  * n2.back()
        });
        long long hi = max({
            (long long)n1.front() * n2.front(),
            (long long)n1.front() * n2.back(),
            (long long)n1.back()  * n2.front(),
            (long long)n1.back()  * n2.back()
        });
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cnt(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
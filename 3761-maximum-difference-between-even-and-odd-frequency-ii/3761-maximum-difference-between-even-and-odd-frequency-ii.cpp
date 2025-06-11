class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        vector<int> vals(n);
        for (int i = 0; i < n; ++i) 
            vals[i] = s[i] - '0';

        int res = INT_MIN;
        vector<int> d(n+1), pa(n+1), cb(n+1);
        array<vector<int>,4> cb_list, dm;
        array<int,4> ptr;
        for (auto &v : cb_list) v.reserve(n+1);
        for (auto &v : dm)      v.reserve(n+1);
        for (int a = 0; a < 5; ++a) {
            for (int b = 0; b < 5; ++b) {
                if (a == b) continue;
                d[0] = pa[0] = cb[0] = 0;
                for (int i = 1; i <= n; ++i) {
                    int da = vals[i-1] == a;
                    int db = vals[i-1] == b;
                    d[i]  = d[i-1] + da - db;
                    pa[i] = pa[i-1] ^ da;
                    cb[i] = cb[i-1] + db;
                }
                for (int t = 0; t < 4; ++t) {
                    cb_list[t].clear();
                    dm[t].clear();
                    ptr[t] = 0;
                }
                for (int j = k; j <= n; ++j) {
                    int i   = j - k;
                    int idx = (pa[i] << 1) | (cb[i] & 1);
                    int di  = d[i];
                    if (dm[idx].empty()) 
                        dm[idx].push_back(di);
                    else 
                        dm[idx].push_back(min(dm[idx].back(), di));
                    cb_list[idx].push_back(cb[i]);
                    int tidx = ((pa[j] ^ 1) << 1) | (cb[j] & 1);
                    int T    = cb[j] - 2;
                    auto &lst = cb_list[tidx];
                    int p    = ptr[tidx];
                    int L    = lst.size();
                    while (p < L && lst[p] <= T) 
                        ++p;
                    ptr[tidx] = p;
                    if (p > 0) {
                        int diff = d[j] - dm[tidx][p-1];
                        res = max(res, diff);
                    }
                }
            }
        }
        return res;
    }
};
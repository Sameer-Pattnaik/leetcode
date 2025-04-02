class Solution {
public:
    using int2 = pair<int, int>;

    static int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        const int n= profits.size();
        vector<int2> cp(n);

        for (int i = 0; i < n; i++) 
            cp[i] = {capital[i], profits[i]};

        sort(cp.begin(), cp.end());

        priority_queue<int> pq;

        int curr=0;
        for (int i = 0; i<k; i++) {
        //    cout<<idx<<":"<<w<<endl;
            for ( ; curr<n && cp[curr].first<=w; curr++) 
                pq.push(cp[curr].second);

            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            else break;
        }
        return w;
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int left = 0, right = costs.size() - 1;
        for (int i = 0; i < candidates; i++)
        {
            if (left > right)
            {
                break;
            }
            if (left == right)
            {
                pq.push({costs[left], left++});
                right--;
                break;
            }
            pq.push({costs[left], left++});
            pq.push({costs[right], right--});
        }
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            int cost = pq.top().first, index = pq.top().second;
            pq.pop();

            ans += cost;
            if (index < left && left <= right)
            {
                pq.push({costs[left], left++});
            }
            else if (index > right && left <= right)
            {
                pq.push({costs[right], right--});
            }
        }
        return ans;
    }
};
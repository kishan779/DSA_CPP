class Solution {
public://@CodeVed
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        for (int i = 0; i <= K; i++) {
            vector<int> temp = cost;
            for (auto f : flights) {
                if (cost[f[0]] != INT_MAX)
                    temp[f[1]] = min(temp[f[1]], cost[f[0]] + f[2]);
            }//@CodeVed
            cost = temp;
        }//@CodeVed
        return cost[dst] != INT_MAX ? cost[dst] : -1;
    }//@CodeVed
};
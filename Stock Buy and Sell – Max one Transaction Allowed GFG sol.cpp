class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int maxProfit = 0;
        int mini = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit,cost);
            mini = min(mini,prices[i]);
        }
        return maxProfit;
    }
};

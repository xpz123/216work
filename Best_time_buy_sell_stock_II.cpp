//Best time to buy and sell stock II

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0 || n == 1) return 0;
		int min = prices[0];
		int max = prices[1] - prices[0];
		int sum = 0;
		for (int i = 1; i < n; i++){
			if (prices[i] < prices[i - 1]) {
				min = prices[i];
				if (max > 0) sum += max;
				max = 0;
			}
			else if (max < prices[i] - min) max = prices[i] - min;
		}

		return sum + max;
	}
};
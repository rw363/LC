class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
	if (coins.empty())
		return -1;
	//sort(coins.begin(), coins.end());
 	vector<int> counts(amount+1, amount+1);
	counts[0] = 0;
	for (int i  = 0; i <= amount; i++)
	{
		for (auto c:coins)
		{
			if (c <=i )
				counts[i] = min(counts[i], counts[i-c] + 1);
		}
	}
	if (counts.back() > amount)
	{
		return -1;
	}
	return counts.back();
    }
};

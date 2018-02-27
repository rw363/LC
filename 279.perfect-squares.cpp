class Solution {
public:
    int numSquares(int n) {
        vector<int> counts(n+1, n+1);
	counts[0] = 0;
	for (int i = 0; i <= n; i++)
	{
		for(int x = 1; x*x <= i; x++)
		{
			counts[i] = min(counts[i], counts[i-x*x] + 1);
		}
	}
	return counts.back();
    }
};

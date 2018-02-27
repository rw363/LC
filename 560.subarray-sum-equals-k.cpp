class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
	if (nums.empty())
		return 0;
	unordered_map<int, int>count;
	count.emplace(0,1);
	int ways = 0;
	int sum = 0;
	for (auto n:nums)
	{
		sum += n;
		if(count.find(sum-k) != count.end())
		{
			ways += count[sum-k];
		}
		count[sum]++;
	}
	return ways;
    }
};

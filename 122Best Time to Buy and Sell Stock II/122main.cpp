/*122. Best Time to Buy and Sell Stock ||
此题在于，对于所有的阶升，全部相加*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1)
			return 0;
		int max = 0;
		int minus;
		for (int i = 1; i < n; i++)
		{
			minus = prices[i] - prices[i - 1];
			if (minus > 0)
				max += minus;
				
		}
		return max;
	}
};

int main()
{
	Solution so;
	int aa[6] = { 7, 6, 4, 3, 1 };
	vector<int> nums(aa, aa + 5);
	cout << so.maxProfit(nums) << endl;
	system("pause");
	return 0;
}
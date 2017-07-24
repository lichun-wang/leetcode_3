/*121. Best Time to Buy and Sell Stock 
此题在于找到最小值，然后跟最小值相减找到最大值*/
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
		int min = prices[0];
		int sell_Max = 0;
		for (int i = 1; i < n; i++)
		{
			if (prices[i] < min)
			{
				min = prices[i];
				continue;
			}
			int minus = prices[i] - min;
			if (minus > sell_Max)
				sell_Max = minus;
		}
		return sell_Max;
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
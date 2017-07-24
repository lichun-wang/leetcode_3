#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int maxSub = INT_MIN;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum >= 0)
				sum += nums[i];
			else
				sum = nums[i];

			if (sum > maxSub)
				maxSub = sum;

		}
		return maxSub;
	}
};


int main()
{
	int a1[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int > nums(a1, a1 + 9);
	Solution so;
	cout<<so.maxSubArray(nums)<<endl;

	system("pause");
	return 0;
}
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int size = nums.size();
		if (size == 0)
			return false;

		int maxReach = 0;
		int i = 0;
		int count = 0;
		for (i = 0; i < size && i<=maxReach; i++)
		{
			int maxDis = i + nums[i];
			if (maxDis > maxReach)
			{
				maxReach = maxDis;
				count++;
			}
		}

		return i == size;
	}
};

int main()
{
	Solution so;
	int aa[5] = {2,3,1,1,4 };
	vector<int> nums(aa, aa + 5);
	cout<<so.canJump(nums)<<endl;
	system("pause");
	return 0;
}
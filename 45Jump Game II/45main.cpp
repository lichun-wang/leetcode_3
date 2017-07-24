#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		int size = nums.size();
		int* jumpFrom = new int[size];
		if (size == 0)
			return false;
		int maxReach = 0;
		int i;
		for (i = 0; i < size; i++)
		{
			if (maxReach >= i)
			{
				int maxDis = nums[i] + i;
				if (maxDis > maxReach)
				{
					for (int j = maxReach + 1; j <= maxDis && j < size; j++)
					{
						jumpFrom[j] = i;
						cout << j << "::" << i << endl;
					}
					maxReach = maxDis;
				}
			}
		}
	
		if (i != size)
			return 0;
		else
		{
			int step = 0;
			int k = size - 1;
			while (k > 0)
			{
				k = jumpFrom[k];
				step++;
			}
			return step;
		}
		
	}
};

int main()
{
	Solution so;
	int aa[5] = { 2, 3, 1, 1, 4 };
	vector<int> nums(aa, aa + 5);
	cout << so.jump(nums) << endl;
	system("pause");
	return 0;
}
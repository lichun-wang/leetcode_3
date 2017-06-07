#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



bool cmp(int a, int b)
{
	if (a > b)
		return true;
	else
		return false;
}

class Solution {
public:


	int nextGreaterElement(int n) {
		if (n < 10)
			return -1;
		long result = 0;
		vector<int >nums;
		int n_use = n;
		for (int i = 0; n_use != 0; i++)
		{
			int remain = n_use % 10;
			nums.push_back(remain);
			n_use = n_use / 10;
		}

		int index = 1;
		for (; index< nums.size(); index++)
		{
			if (nums[index] < nums[index - 1])
				break;
		}
		if (index == nums.size())
			return -1;

		int changeNum = nums[index];
		

		int i = 0;
		for (i = 0; i<index; i++)
		{
			if (nums[i] > changeNum)
				break;
		}

		int temp = nums[index];
		nums[index] = nums[i];
		nums[i] = temp;

		sort(nums.begin(), nums.begin() + index, cmp);

		for (int i = nums.size()-1; i >= 0; i--)
		{
			result = result * 10 + nums[i];
		}

		if (result > INT_MAX)
			return -1;
		else
		    return result;
	}
};

int main()
{
	Solution so;
	cout<<so.nextGreaterElement(52431);
	getchar();
	return 0;
}
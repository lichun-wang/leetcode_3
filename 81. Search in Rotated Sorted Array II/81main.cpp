#include<iostream>
#include<algorithm>
#include <io.h>
#include<vector>
#include<fstream>

using namespace std;



class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return false;
		int low = 0;
		int high = nums.size() - 1;
		int mid = 0;
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			if (nums[mid] == target)
				return true;

			if (nums[low] < nums[mid])  //正常排序
			{
				if (nums[low] <= target && nums[mid] > target)
					high = mid - 1;
				else
					low = mid + 1;
			}
			else if (nums[low] > nums[mid]) //不正常排序
			{
				if (target <= nums[high] && target > nums[mid])
					low = mid + 1;
				else
					high = mid - 1;
			}
			else
				low++;

		}
		return false;
	}
};

int main()
{
	Solution so;
	vector<int> putin = { 3,1,1 };
	cout<<so.search(putin,3);
	return 0;
}
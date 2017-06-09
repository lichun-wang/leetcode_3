#include<iostream>
#include<algorithm>
#include <io.h>
#include<vector>
#include<fstream>

using namespace std;



class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return vector<int >(2, -1);

		int low = 0;
		int high = nums.size() - 1;


		bool foundFlag = false;
		int  targetIndex = -1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] == target)
			{
				foundFlag = true;
				targetIndex = mid;
				break;
			}
			else{
				if (nums[mid] > target)
					high = mid - 1;
				else
					low = mid + 1;
			}

		}
		if (foundFlag == true)
		{
			int left = 0;
			int right = 0;
			int low = 0;
			int high = targetIndex;
			while (low <= high)
			{
				int mid = (low + high) / 2;
				if (nums[mid] == target)
					high = mid - 1;
				else
					low = mid + 1;
			}
			left = low;

			low = targetIndex;
			high = nums.size() - 1;
			while (low <= high)
			{
				int mid = (low + high) / 2;
				if (nums[mid] == target)
					low = mid + 1;
				else
					high = mid - 1;
			}
			right = high;

			return vector<int>(left, right);


		}
		else
		{
			return vector<int>(2, -1);
		}


	}
};

int main()
{
	Solution so;
	vector<int> putin = { 5, 7, 7, 8, 8, 10 };
	so.searchRange(putin,8);
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	struct len_dir{
		int length;
		bool up;
		len_dir(int len, bool u) :length(len), up(u){}
	};

	void del(vector<int> &nums)
	{
		if (nums.size() <= 1)
			return;
		
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[i - 1])
			{
				nums.erase(nums.begin() + i);
				i--;
			}
		}
		return;
	}

	int wiggleMaxLength(vector<int>& nums) {
		vector<len_dir> result;  //存放对应位置的length,以及up or down

		del(nums);
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return 1;
		if (nums.size() == 2)
			return 2;
		

		result.push_back(len_dir(1, 0));
		result.push_back(len_dir(2, nums[1] - nums[0] > 0 ? 1 : 0));

		for (int i = 2; i< nums.size(); i++)
		{
			int maxLength = 2;
			int up = nums[i] - nums[0]> 0 ? 1 : 0;
			for (int j = 1; j< i; j++)
			{
				if (nums[i] - nums[j] > 0 && result[j].up == 0 && result[j].length + 1 > maxLength)
				{
					maxLength = result[j].length + 1;
					up = nums[i] - nums[j]> 0 ? 1 : 0;
				}
				if (nums[i] - nums[j] < 0 && result[j].up == 1 && result[j].length + 1 > maxLength)
				{
					maxLength = result[j].length + 1;
					up = nums[i] - nums[j]> 0 ? 1 : 0;
				}
			}
			result.push_back(len_dir(maxLength, up));
			//cout << maxLength << endl;
		}
		return result[result.size() - 1].length;
	}
};

int main()
{
	Solution so;
	vector<int > pri{486, 431, 132, 46, 441, 383, 199, 476, 87, 225, 491, 3, 315, 32, 441, 195, 188, 72, 299, 404, 224, 473, 124, 279, 301, 145, 429, 77, 423, 472, 388, 387, 29, 348, 22, 327, 276, 448, 396, 269, 382, 436, 382, 160, 156, 34, 303, 264, 271, 409};
	//vector<int > pri{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << so.wiggleMaxLength(pri) << endl;
	system("pause");
	return 0;
}
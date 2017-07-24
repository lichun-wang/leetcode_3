#include<iostream> 
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int > result;
		if (nums.size() == 0)
			return result;
		vector< pair<int, int > > pairNums;
		for (int i = 0; i< nums.size(); i++)
		{
			pairNums.push_back(make_pair(nums[i], i));
		}
		sort(pairNums.begin(), pairNums.end());
		for (int i = 0, j = nums.size() - 1; i<j;)
		{
			if (pairNums[i].first + pairNums[j].first == target)
			{
				result.push_back(pairNums[i].second);
				result.push_back(pairNums[j].second);
				break;
			}
			if (pairNums[i].first + pairNums[j].first < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}

		return result;
	}
};

int main()
{
	
	vector<int > nums = { 3, 2, 4 };
	Solution so;
	so.twoSum(nums, 6);
	return 0;
}
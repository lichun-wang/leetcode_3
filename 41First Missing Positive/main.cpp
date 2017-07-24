//41. First Missing Positive QuestionEditorial Solution  My Submissions
//Total Accepted : 85920
//Total Submissions : 344222
//Difficulty : Hard
//Contributors : Admin
//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given[1, 2, 0] return 3,
//and[3, 4, -1, 1] return 2.
//Your algorithm should run in O(n) time and uses constant space.

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int count = 1;
		if (nums.size() == 0)
			return 1;
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= 0)
				continue;

			if (nums[i] == count)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		return count;
	}
};

int main()
{
	int aa[5] = { 0,2,2,1,1 };
	vector<int > nums(aa, aa + 5);
	Solution so;
	int result = so.firstMissingPositive(nums);
	cout << result << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//int totalHammingDistance(vector<int>& nums) {
	//	if (nums.size() == 0)
	//		return 0;
	//	int sum = 0;
	//	int dis = 0;
	//	for (int i = 0; i < nums.size();i++)\
		//	{
	//		for (int j = i + 1; j < nums.size(); j++)
	//		{
	//			dis = distance(nums[i], nums[j]);

	//			sum += dis;
	//		}
	//	}

	//	return sum;
	//}

	//int distance(int a, int b)
	//{
	//	int answer = 0;
	//	int c = a ^ b; //Та»т


	//	for (; c != 0;)
	//	{
	//		answer++;
	//		c = c & (c - 1);
	//	}

	//	return answer;
	//}

	int totalHammingDistance(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int answer = 0;
		for (int i = 0; i < 32; i++)
		{
			int count = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				if (nums[j] & 1)
					count++;
				nums[j] = nums[j]>>1;
			}
			answer += count*(nums.size() - count);
		}

		return answer;
    }


};


int main()
{
	int a[3] = { 4, 12, 2 };
	vector<int > nums(a,a+3);
	Solution so;
	cout << so.totalHammingDistance(nums)<<endl;
	system("pause");
	return 0;
}
/*400. Nth Digit
  根据所给的位数，找到该数字为什么
  思路，首先确定该数字为几位数
        然后确定该数字的具体数值以及数中的第几位
		最后找出这个数字
		
  bug:::  此题在计算第几位数字的时候 很可能会数组越界，特别讨厌的事情
          对于数字的把控 需要在强化一下
		  */


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findNthDigit(int n) {

		int n_copy = n;
		int count1 = 0;
		int count2 = 0;
		int base = 9;
		int i;

		for (i = 0; i<8 && n_copy > base * (i + 1); i++)
		{
			count1 += base * (i + 1);
			n_copy -= base* (i + 1);
			base = base * 10;
		}

		count2 = n - count1;
		int num = (count2) / (i + 1);
		if ((count2) % (i + 1) == 0)
			num = num - 1;
		   
		int num_2 = count2 - num*(i+1);

		int result = pow(10,i) + num;

		vector<int> nums;
		while (result != 0)
		{
			int a = result % 10;
			result = result / 10;
			nums.push_back(a);
		}

		return nums[nums.size() - num_2];
	}
};

int main()
{
	Solution so;
	cout << so.findNthDigit(1000000000);
	system("pause");
	return 0;
}
/*96. Unique Binary Search Trees*/
/*����Ĺؼ��������ö�̬�滮�㷨���м���*/
/*G(n) = G(0)* G(n-1) + G(1)*G(n-2) ....   */
/*G(0)==1  G(1) == 1  */

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		if (n == 0 || n == 1)
			return 1;
		int * nums = new int[n+1];
		for (int i = 0; i < n + 1; i++)
			nums[i] = 0;///��ʼ��
		nums[0] = 1;
		nums[1] = 1;
		for (int i = 2; i < n+1; i++)
		{
			for (int j = 0; j < i; j++)
				nums[i] += nums[j] * nums[i - j - 1];
		}
		return nums[n];
	}
};

int main()
{
	Solution so;
	cout << so.numTrees(3) << endl;
	system("pause");
	return 0;
}
/*此题找规律， a[n] = a[n-1] + a[n-2]   */

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		int *a = new int[n];
		a[0] = 1;
		a[1] = 2;
		for (int i = 2; i < n; i++)
			a[i] = a[i - 1] + a[i - 2];
		return a[n - 1];
	}
	
};

int main()
{
	Solution so;
	cout<<so.climbStairs(44)<<endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		if (x == 0) 
			return 0;

		int max = 0x7fffffff;
		int min = 0x80000000;
		int sign = -1;
		if (x > 0)
			sign = 1;

		x = abs(x);
		double answer = 0;
		int temp = 0;
		for (; x != 0;)
		{
			temp = x % 10;
			x = x / 10;
			answer = answer * 10 + temp;

		}
		answer = answer * sign;
		if (answer > max || answer < min)
			return 0;
		return answer;
	}
};

int main()
{
	Solution so;
	long aa = -1 * 123;
	cout << so.reverse(aa);
	system("pause");
}

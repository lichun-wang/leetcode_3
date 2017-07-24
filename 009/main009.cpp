#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {

		if (x < 0)
			return false;
		int or = x;
		int answer = 0;
		int i = 0;
		for (; x != 0;)
		{
			answer = answer * 10 + x % 10;
			x = x / 10;
		}

		if (answer == or)
			return true;
		else
			return false;

	}
};

int main()
{
	int aa = -1233421;
	Solution so;
	cout << so.isPalindrome(aa)<<endl;

	
	system("pause");
}

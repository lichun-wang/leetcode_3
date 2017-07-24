#include <math.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {

		string roman[4][10] = {
			{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
			{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
			{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
			{ "", "M", "MM", "MMM" } };

		string result;
		int col;
		int row = 0;
		for (; num != 0;)
		{
			col = num % 10;
			num = num / 10;
			result = roman[row][col] + result;
			row++;
		}

		return result;
	}
};

int main()
{
	Solution so;
	cout<<so.intToRoman(0);
	int a;
	cin >> a;
	return 0;
}
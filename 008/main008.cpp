#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
	public:
	int myAtoi(string str) {
		if (str.length() == 0)  //×Ö·û´®Îª¿Õ
			return 0;

		int max = 0x7FFFFFFF;
		int min = 0x80000000;
		int len = str.length();
		char singleChar;
		double answer = 0;
		int temp = 0;
		int sign = 1;
		int i = 0;
		for (i = 0; i < len; i++)
		{
			//if (  (str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
			if (str[i]!=' ')
			    break;
		}

		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
			

		for (; i < len; i++)
		{
			if (str[i] < '0' || str[i] > '9')
				break;
			
			temp = str[i] - '0';
			answer = answer * 10 + temp;
		}
		
		answer = answer * sign;

		if (answer > max )
			return max;
		if (answer < min)
			return min;

		return answer;
	}
	
};

int main()
{
	string str = " 11228552307";
	Solution so;
	cout << so.myAtoi(str)<<endl;
	cout<<atoi(str.c_str());
	
	system("pause");
}

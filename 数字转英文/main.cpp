#include<iostream>
#include<vector>
#include<string>
using namespace std;

string GeWei[10] = { "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
string ShiWei_20[10] = { "TEN","ELEVEN", "TWEIVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINTEEN" };
string ShiWei[10] = { "TWENTY", "THIRTY", "FOURTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINTY" };
string steps[5] = { "thousand", "million", "billion" };
class Solution {
public:
	

	string change(string num,int step)
	{
		string result;
		if (num.size() != 3)
			return result;
		if (num[0] != '0')
		{
			result.append(GeWei[num[0] - '1']);
			result.push_back(' ');
			result.append("Hundred ");
		}
		
		if (num[1] != '0')
		{
			int n = num[1] - '0';
			if (n >= 2)
			{
				result.append(ShiWei[n-2]);
				result.append(" ");
			}
			else if (n == 1)
			{
				result.append(ShiWei_20[num[2] - '0']);
				result.append(" ");
			}
		}

		if (num[1] != '1')
		{
			if (num[2] != '0')
			{
				int n = num[2] - '1';
				result.append(GeWei[n]);
				result.push_back(' ');
			}

		
		}
		if (step >= 2)
		{
			result.append(steps[step - 2]);
			result.append(" ");
		}

		return result;
	}
	string numToEnglish(int num) {
		if (num == 0)
			return "ZERO";
		string result;
		string strNum;
		char str[100] = { 0 };
		_itoa(num,str,10);
		for (int i = 0; str[i] != 0; i++)
			strNum.push_back(str[i]);


		int length = strNum.length();
		if (length % 3 != 0)
		{
			for (int i = 0; i < 3-length % 3; i++)
				strNum.insert(0, "0");
		}

		for (int i = 0; i < strNum.length()/3; i++)
		{
			string subStr = strNum.substr(i * 3, 3);
			int step = strNum.length() / 3 - i;

			result.append( change(subStr, step) );
			
		}

		result.erase(result.begin() + result.size()-1);
		return result;
	}
};

int main()
{
	Solution so;
	cout << so.numToEnglish(12345)<<endl;

	
	



	system("pause");
	return 0;
}
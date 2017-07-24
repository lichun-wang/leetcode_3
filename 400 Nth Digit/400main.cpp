/*400. Nth Digit
  ����������λ�����ҵ�������Ϊʲô
  ˼·������ȷ��������Ϊ��λ��
        Ȼ��ȷ�������ֵľ�����ֵ�Լ����еĵڼ�λ
		����ҳ��������
		
  bug:::  �����ڼ���ڼ�λ���ֵ�ʱ�� �ܿ��ܻ�����Խ�磬�ر����������
          �������ֵİѿ� ��Ҫ��ǿ��һ��
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
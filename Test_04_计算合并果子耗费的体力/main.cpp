#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//ÿһ�κϲ�����֮�󣬶���Ҫ�Ѻϲ��������²���������������
int main()
{
	char NoUse[50];
	cin.getline(NoUse, 52);
	vector<int> Amount;
	int tempInt;
	while (cin >> tempInt)
	{
		Amount.push_back(tempInt);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	sort(Amount.begin(), Amount.end());
	int result = 0;
	while (Amount.size() > 1)
	{
		result += Amount[0] + Amount[1];
		int tempValue = Amount[0] + Amount[1];
		for (vector<int>::iterator it = Amount.begin(); it < Amount.end(); ++it)
		{
			if (tempValue <= *it)
			{
				Amount.insert(it, tempValue);
				break;
			}
			else if (it == Amount.end() - 1)//��Ҫ�жϱ߽�
			{
				Amount.push_back(tempValue);
				break;
			}
		}
		Amount.erase(Amount.begin());
		Amount.erase(Amount.begin());
	}
	cout << result;
	return 0;
}
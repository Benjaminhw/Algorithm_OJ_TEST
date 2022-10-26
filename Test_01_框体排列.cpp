#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int main()
{
	int amount = 0, width = 0, count = 0;
	cin >> amount >> width;
	vector<int> Numbers;
	int toNumber=0;
	while (cin>>toNumber)
	{
		Numbers.push_back(toNumber);
		if (cin.get() == '\n')
		{
			break;
		}
	};
	sort(Numbers.begin(), Numbers.end());//≈≈–Ú
	int tempValue = Numbers[0];
	if (Numbers.size() == 0)
	{
		cout << count;
		return 0;
	}
	++count;
	for (int i=0; i<Numbers.size(); ++i)
	{
		if (Numbers[i] > tempValue + width)
		{
			++count;
			tempValue = Numbers[i];
		}
	}
	cout << count;
	return 0;
}

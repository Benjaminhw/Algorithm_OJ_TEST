#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

//WA 40

int main()
{
	int Nouse = 0, width = 0;
	cin >> Nouse >> width;
	vector<int> Numbers;
	long int count = 0;
	Numbers.resize(Nouse);
	//�����س��ٽ�����һ��
	while (getchar() != '\n') {}
	int i = 0;
	char tempc = 0;
	//unordered_map<int, int> NumberMap;
	while (tempc != '\n')
	{
		tempc = getchar();
		if (tempc != '-' && (tempc < '0' || tempc > '9'))
		{
			continue;
		}//�ǿո��ֱ�ӽ�����һ��ѭ��
		int x = 0, w = 1;
		char c = tempc;//��tempc����c������Ҫ����ָ��ǰ��һ��
		while (c < '0' || c > '9') {
			if (c == '-') w = -1;
			c = getchar();
		}
		while (c >= '0' && c <= '9') {
			x = x * 10 + (c - '0');
			c = getchar();
		}
		Numbers[i] = x * w;
		++i;
		if (c == '\n')
		{
			break;
		}
	}
	if (Nouse <= 1)
	{
		cout << 0;
		return 0;
	}
	int size = Numbers.size();

	vector<int> CountArray;
	CountArray.resize(4000001);

	int sizeC = CountArray.size();
	fill(CountArray.begin(), CountArray.end(), 0);//��0

	width = abs(width);

	for (int z = 0; z < size; ++z)
	{
		++CountArray[Numbers[z]+2000000];
	}

	for (int z = 0; z < sizeC&&z+width<sizeC; ++z)
	{
		count += (long int)CountArray[z] * (long int)CountArray[z+width];
	}

	cout << count;
	return 0;
}
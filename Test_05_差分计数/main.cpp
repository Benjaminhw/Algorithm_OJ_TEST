#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

//�о�����˼·�ʹ��ˣ�д����Ķ��ֲ���- -��
//лл���б����ϵ�˼·�󵼵��������������˫ָ�밡����������������1������¶������������˷ѵ�ʱ�䰡��������
//void Search(vector<int>Numbers, int low, int high, int target, int& count)
//{
//	if (target > Numbers[high] || target < Numbers[low])
//	{
//		return;
//	}
//	int mid = (low + high) / 2;
//	if (Numbers[mid] == target)
//	{
//		++count;
//		int i = mid - 1;
//		while (i > low && Numbers[i] == target)
//		{
//			++count;
//			--i;
//		}
//		i = mid + 1;
//		while (i < high && Numbers[i] == target)
//		{
//			++count;
//			++i;
//		}
//		return;
//	}
//	else if (target > Numbers[mid])
//	{
//		low = mid + 1;
//		Search(Numbers, low, high, target, count);
//	}
//	else
//	{
//		high = mid - 1;
//		Search(Numbers, low, high, target, count);
//	}
//	if (low == high)
//	{
//		return;
//	}
//	return;
//}

long long factorial(int n)
{
	long long result = 1;
	for (int i = 1; i <= n; ++i)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int Nouse = 0, width = 0;
	cin >> Nouse >> width;
	vector<int> Numbers;
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

	sort(Numbers.begin(), Numbers.end());
	//for (int i = 0; i < Numbers.size() - 1; ++i)//���һ����������
	//{
	//	int low = i + 1, high = Numbers.size() - 1;
	//	int target = Numbers[i] + width;
	//	Search(Numbers, low, high, target, count);
	//}

	int count = 0;
	int x = 0, y = 1;
	int size = Numbers.size();

	if (width)
	{//��Ȳ�Ϊ0
		while (x < size - 1 && y < size)
		{
			if (Numbers[y] < Numbers[x] + width)
			{
				++y;
			}
			else if (Numbers[y] == Numbers[x] + width)
			{

				int a = 1, b = 1, flaga = Numbers[x], flagb = Numbers[y];
				//��������д�ĺô��ǲ��߻�ͷ·��һ�����ף����Ӷ�ΪO(n) ֻ������
				while (x < size - 2 && Numbers[x + 1] == flaga)//x<y-1��Ϊ���������������ص������ұ������ж�x���ж�y
				{
					++a;
					++x;
				}
				while (y < size - 1 && Numbers[y + 1] == flagb)//Խ������дǰ��������Խ���
				{
					++b;
					++y;
				}
				count += a * b;//û����ͬ����1*1
				++x;//�ж����� ��һλ
			}
			else
			{
				++x;
			}
		}
	}
	else
	{//���Ϊ0��
		//ע�����ﲢ����Ҫ�ж��Ƿ�������������0��ʱ��x��y��Ȼ��ʼ�ս����ġ���ʱֻ��Ҫһ��ָ��
		int flag = Numbers[x], N = 0;
		while (x < size)
		{
			if (x < size - 1 && Numbers[x + 1] == flag)
			{//�����һ��Ԫ����ǰһ��Ԫ����ͬ
				++x;
				++N;
			}
			else
			{//��ͬ�����ǵ����������ĩ��
				count += N*(N+1);//����������һ�����Ľ׳�
				N = 0;
				++x;
				if (x < size)
				{//û�е���ĩ��
					flag = Numbers[x];
				}
			}
		}
	}

	cout << count;
	return 0;
}
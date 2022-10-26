#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

//自定义比较函数，从高位比到低位，有不同位则退出。如果一方比完了另一方还有位数，那么位多者小
bool MyCmp(string a, string b)//返回true则a排前面，返回false则a排后面
{
	//下面这一段是没有必要的，但是加了之后速度可以快2-3倍
	for (int i = 0; i < a.size() && i < b.size(); ++i)
	{
		if (a[i]!=b[i])
		{
			return a[i] > b[i];//希望什么就是什么
		}
	}
	//↓没有必要判断，判断不了
	////先前的所有比较都一致,则位多者需要判断
	//if (a.size() < b.size())
	//{
	//	int flag = a[0];//a的首位
	//	for (int j = a.size(); j < b.size(); ++j)
	//	{
	//		if (b[j] > flag)//如果后面的某一位比共有最后一位大,b排前面
	//		{
	//			return false;
	//		}
	//		if (b[j] < flag)
	//		{
	//			return true;//反之a排前面
	//		}
	//		//如果一直相等，则还是要按位数排，等最终跳出即可
	//	}
	//	return true;//这个不能动
	//}
	//else//a的位数更多
	//{
	//	int flag = b[0];//b的首位
	//	for (int j = b.size(); j < a.size(); ++j)
	//	{
	//		if (a[j] > flag)//如果后面的某一位比共有最后一位大,a排前面
	//		{
	//			return true;
	//		}
	//		if (a[j] < flag)
	//		{
	//			return false;//反之b排前面
	//		}
	//		//如果一直相等，则还是要按位数排，等最终跳出即可
	//	}
	//	return false;
	//}

	//直接比较拼接在一起谁更大
	return a + b > b + a;
}

int main()
{
	vector<string> Numbers;
	string tempNumber;
	char NoUse[40];
	cin.getline(NoUse,50);
	while (cin >> tempNumber)
	{
		Numbers.push_back(tempNumber);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	sort(Numbers.begin(), Numbers.end(),MyCmp);//排序
	string result;
	for (vector<string>::iterator it = Numbers.begin(); it != Numbers.end(); ++it)
	{
		/*cout << *it <<" ";*/
		result.append(*it);
	}
	//int resulti=atoi(result.c_str());
	cout << result;
	return 0;
}


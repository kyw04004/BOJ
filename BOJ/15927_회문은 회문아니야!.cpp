#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int len = str.size();
	int chk = 0;
	for (int i = 0; i < len / 2; i++) // ���ڿ��� �Ӹ�������� Ȯ��
		if (str[i] != str[len - i -1])
			chk = 1;
	if (chk == 1) // ���ڿ��� �Ӹ����X
		printf("%d", len);
	else // ���ڿ��� �Ӹ����
	{
		for (int i = 0; i < len - 1; i++)
			if (str[i] != str[i + 1])
				chk = 1;
		if (chk == 0) // ��� ���ڰ� ������ �׻� �Ӹ����
			printf("-1");
		else // ���� �Ӹ������ 1���ڸ� ���� �Ӹ����X
			printf("%d", len - 1);
	}
	return 0;
}
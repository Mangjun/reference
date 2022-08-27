// ���־� (�ذ�)
// https://www.acmicpc.net/problem/16464
// 
// 1 ~ K-1 ������ ���� �����ִ� ī�忡�� N���� �������� �������� �� ���� K�� ���� �� �ִ��� Ȯ���϶�. 
// ���ӵ� ������ ������ K�� ���� �� �ִ��� Ȯ��
// 
// N : ���� Ƚ��
// K : �������ϴ� ��
// 

#include<iostream>
#include<vector>

using namespace std;


bool is_possible(int n)
{

	while (n != 1)
	{
		if (n % 2 == 1)
			return 1;
		n /= 2;
	}
	
	return false;
}


void solve()
{
	int n;
	cin >> n;

	if (is_possible(n))
		cout << "Gazua" << "\n";
	else
		cout << "GoHanGang" << "\n";
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	// n�� �ݺ���
	for (size_t i = 0; i < n; i++)
	{
		solve();
	}
	return 0;
}

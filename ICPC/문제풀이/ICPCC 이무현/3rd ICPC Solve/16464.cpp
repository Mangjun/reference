// ���־� (����)
// https://www.acmicpc.net/problem/16464
// 
// 1 ~ K-1 ������ ���� �����ִ� ī�忡�� N���� �������� �������� �� ���� K�� ���� �� �ִ��� Ȯ���϶�. 
// ���ӵ� ������ ������ K�� ���� �� �ִ��� Ȯ��
// 
// N : ���� Ƚ��
// K : �������ϴ� ��

#include<iostream>
#include<vector>

using namespace std;


bool is_possible(int n)
{
	int start, end;
	int total;	// ���� �κ����� ������ ����

	start = end = n / 2;
	total = 0;

	// �� ���� �ϳ��� 0 ���ϰ� �Ǹ� ����
	while (start > 0 && end > 0)
	{
		if (total == n)
			return true;

		// ������ ���� �ϳ� ��
		if (total > n)
		{
			total -= end;
			end--;
		}
		// ���ʰ��� �ϳ� ����
		else
		{
			total += start;
			start--;
		}
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

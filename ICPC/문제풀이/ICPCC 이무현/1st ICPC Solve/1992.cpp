#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>>map;

// �ش� ������ ������ ���ڷ� �̷���� �ִ��� Ȯ��
// ���� ó�� ���� ���ڸ� ���� �� �� �ٸ� ���ڰ� ���� false ��ȯ
bool check(int x, int y, int width)
{
	char t = map[y][x];
	for (size_t i = y; i < y + width; i++)
	{
		for (size_t j = x; j < x + width; j++)
		{
			if (t != map[i][j])
			{
				return false;		// ����ġ �ϴ� ���ڰ� �ϳ��� ���� false ��ȯ
			}
		}
	}
	return true;		// �������� ��� ���ڰ� ������ ��� true ��ȯ
}

// ���� ���Ժ�
// �������� �� ���� �ذ��� ����
int solve(int x, int y, int width)
{
	// ��� ���ڰ� ���ٸ� �ش� ���� ���
	if (check(x, y, width))
	{
		cout << map[y][x];
	}
	// �ٸ� ���ڰ� �ִٸ� �׺κ����� ���� Ǯ��
	else
	{
		int half = width / 2;		// �ݺ����� ���� ���̱� ���� �ӽú���
		cout << "(";
		solve(x, y, half);			// �»�

		solve(x + half, y, half);	// ���

		solve(x, y + half, half);	// ����

		solve(x + half, y + half, half);	// ����
		cout << ")";
	}
	return 0;
}

int main(void)
{
	int n;			// 2�� ������ 2 4 8 16 32 64�� ���´�.
	cin >> n;		// n�� �Է� �޴´�.

	map = vector<vector<char>>(n, vector<char>(n, 0));

	// ���� ����
	for (size_t y = 0; y < n; y++)
	{
		for (size_t x = 0; x < n; x++)
		{
			cin >> map[y][x];
		}
	}
	solve(0, 0, n);		// 0,0�� �������� ��ü�� Ž���ϸ� ����
	return 0;
}



// ���� (����)
// https://www.acmicpc.net/problem/2615
// 
// 5���� ���� �������� ���ΰ�� ���� �� ���� �̰�ٰ� �����Ѵ�.
// �ٵ����� ���°� �Է����� �־��� �� ���¿� ���� ���� ���� ��ġ�� ����϶� (�ºΰ� ���� ���� ���� ��ġ�� ������� �ʴ´�.)
// 
// ���ÿ� �̱���, �α��� �̻󿡼� ���ÿ� �̱���� ������ �ʴ´�.
// �������� �̱� ��� 1, ����� �̱��� 2, ���� �ºΰ� ���� ���� ��� 0

// ���� ���ʿ� �ִ� ���� ��ǥ�� ����Ѵ�.
// ���� ���Ϸ� ��� �þ��� �ִ� ��� ���� ���� ��ǥ�� ����Ѵ�.
//

#include <iostream>

#define NONE 0
#define BLACK 1
#define WHITE 2

using namespace std;

int board[19][19];	// �ٵ����� ���¸� ���� �迭

		// ��, ��, ��, ��, ���, ����, �»�, ����
int dx[] = { -1, 1, 0, 0, 1, -1, -1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };


// �ش� �������� ��� ���� �� �ΰ�?
// �߽��� ������ ������ ��ȯ
// x,y�� �����ϰ� Ư�� �������� ��� ���� ���� ������ ���� ���� �Լ�
int move_check(int x, int y, int dx, int dy)
{
	int temp_x = x + dx, temp_y = y + dy;
	int count = 0;
	do
	{
		// count �� 5�� �Ѿ� ���ٸ�
		if (count >= 5)
			break;

		// ��ǥ�� ���� ������ �Ѿ�ٸ�
		if (temp_x < 0)
			break;
		if (19 <= temp_x)
			break;
		if (temp_y < 0)
			break;
		if (19 <= temp_y)
			break;

		// ���� ���� ��� ����
		if (board[temp_y][temp_x] == NONE)
			break;

		// �ٸ� ������ ���� �´ٸ�
		if (board[y][x] != board[temp_y][temp_x])
			break;

		//���� ������ 1 ������Ű�� ���� ��ǥ�� �̵���
		temp_x += dx;
		temp_y += dy;
		count++;

	} while (true);

	// ���ӵ� ���� ���� ��ȯ
	return count;
}

// ��Ȯ�ϰ� 5�� �Ǻ��س��� ��
// ���� ��ġ���� 5���� ���޾� �����ϴ��� Ȯ��
bool five_check(int x, int y)
{
	int count;			// ���ӵ� ���� ������ �� ����

	// dx dy�� �̿��Ͽ� ���⼺�� �ָ� Ž����
	// count �� ��Ȯ�ϰ� 5��� true ��ȯ
	for (int i = 0; i < 8; i += 2)
	{
		count = 1;
		count += move_check(x, y, dx[i], dy[i]);
		count += move_check(x, y, dx[i + 1], dy[i + 1]);

		// ��Ȯ�ϰ� 5���� ���޾� �ִٸ� true ��ȯ
		if (count == 5)
			return true;
	}

	// 5���� �ƴ϶�� false ��ȯ
	return false;
}

// ���� ���ÿ� �̱�� ���� ����
int solve()
{
	// x��ǥ
	for (int x = 0; x < 19; x++)
	{
		// y��ǥ
		for (int y = 0; y < 19; y++)
		{
			// ���� �÷��� ���� �ʴٸ� continue
			if (board[y][x] == NONE)
				continue;

			// 5���� �����̶��
			if (five_check(x, y))
			{
				// ���ڰ� �ִٸ� ���ڿ� ��ǥ�� ����ϰ� �Լ� ����
				cout << board[y][x] << "\n";
				cout << y + 1 << " " << x + 1;
				return board[y][x];
			}
		}
	}
	// ���ڰ� ���ٸ� 0 ����ϰ� �Լ� ����
	cout << NONE;
	return NONE;
}

int main()
{
	// �������� �Է¹���
	for (auto& i : board)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}

	// Ǯ�� �ڵ带 ȣ�� ��
	solve();
	return 0;
}
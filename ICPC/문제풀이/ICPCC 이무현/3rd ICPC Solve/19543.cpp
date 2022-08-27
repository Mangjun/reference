// �������� (����)
// https://www.acmicpc.net/problem/19543
// 
// ������ ���� �������� ã�ư��� �Ѵ�
// ��� ������ ���� �� �� ���� �� ���������� ���� �� �ִ� ���� ���� ����϶�.
// 
// N * M ũ�� y * x �� ���� ũ�Ⱑ �־�����.
// ������ ���� �־�����.
// ������ �� ��ŭ ���ڿ��� �־�����.
// N ��ŭ ���ڿ��� �־����� �� ���ڿ��� ������ ����� �ǹ��Ѵ�.

// ���� ������ ���� ���ʿ��� U�� �ƴ϶�� ���� false�̴�.

#include<iostream>
#include<vector>
#include<algorithm>

//#define DEBUG

#define UP		'U'
#define RIGHT	'R'
#define FAIL	'F'
#define SUCCESS	'S'

using namespace std;

struct input {
	int Y_boundary;		// y���� �ִ�
	int X_boundary;		// x���� �ִ�
	int	number_tile;	// Ÿ���� ��
	string tile_list;	// Ÿ���� ������ �Է¹���
} input = {0,0,0};

vector<string> temp_tile;	// Ÿ���� �ӽ� ������ ����

long long int solve()
{
	long long int start, end;
	long long int result = 0;
	string tile;

	// ���� ������ �� ĭ���� ������
	// ���� �������� �ε��� ��ȣ�� ������.
	start = end = input.X_boundary - 1;	

	tile = temp_tile[input.tile_list[input.tile_list.size() - 1] - 'A'];
	// ���������� ������ U�� �ϰ� �����Ѵ�.
	tile[tile.size() - 1] = 'U';

	
	for (long long int i = input.tile_list.size() - 1 ; i >= 0; i--)
	{
		// start�� �ű�
		// ���� ��ġ�� ���ʿ� R�� �ִٸ� �������� ��ĭ �ű�
		// �ڽ��� ������ U�� �� ���� �������� ��ĭ �� �ű�
		do
		{
			// �������� �̵��� �� ������ �״�� ����
			// ������ ���� ������ ���� R�̵� U�̵� ���� ���� �����ϱ� ������ ���� ���� �ǵ� ��� ����.
			if (start - 1 < 0)
				break;

			// ������ ������ ���� U ��� �̵��� �Ұ���
			if (tile[start - 1] != RIGHT)
				break;

			// start �� ���� ���� �����鼭 ������ R���̶�� �̵�
			start--;
		} while (true);

		// end�� �ű�
		// ���� ��ġ�� �� �ƴ϶�� �������� ��ĭ �ű�
		// U�� ���ö� ���� ��ġ�� ��� �ű�
		do
		{
			// end�� �Ű�µ� start ���� end�� �� �۾����ٸ� �� �̻� ���� �� �� �ִ� ���� �����Ƿ� ����
			if (end < start)
				break;

			// ���� ���� U��� �̵��� �ʿ䰡 ����
			if (tile[end] == UP)
				break;

			end--;
		} while (true);		
/*
#ifdef DEBUG
		cout << start + 1 << " " << end + 1 << " " << end - start + 1 << "\n";
		cout << tile << "\n\n";
#endif // DEBUG
*/
		// end�� start ���� �۾����� ���ǿ� �����ϴ� ���� �����Ƿ� ����
		if (end < start)
			break;

		// ������� ���� 
		result += end - start + 1;

		if (i - 1 < 0)
			break;
		// tile�� ������ Ȯ���ؾ��ϴ� ��ġ�� Ÿ�� ���¸� �ӽ� ����
		tile = temp_tile[input.tile_list[i - 1] - 'A'];
	}

	return result;
}

int main(void)
{
	char temp;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// �� ũ��� Ÿ���� ���� �Է¹޾� ����
	cin >> input.Y_boundary >> input.X_boundary;
	cin >> input.number_tile;

	// Ÿ�� ������ �Է¹���
	// A : 0 
	// Ÿ���� ������ŭ ũ�⸦ �Ҵ���
	temp_tile = vector<string>(input.number_tile);
	for (long long int i = 0 ; i < temp_tile.size() ; i++)
		cin >> temp_tile[i];

	// Ÿ���� ��ġ������ �Է� ����
	cin >> input.tile_list;

	cout << solve();

/*
#ifdef DEBUG
	srand(time(NULL));
	while (true)
	{
		cin >> temp;
		input.tile_list.clear();
		for (int i = 0; i < input.Y_boundary; i++)
		{
			input.tile_list.push_back(rand() % temp_tile.size() + 'A');
		}

		for (int i = input.tile_list.size() - 1; i >= 0; i--)
		{
			cout << temp_tile[input.tile_list[i] - 'A'] << "\n";
		}

		cout << solve() << "\n";
	}
#endif // DEBUG
*/
	
}

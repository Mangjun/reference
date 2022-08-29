// �������� (����)
// https://www.acmicpc.net/problem/19543


// ���̵��1	: ���� ���� ����� �Ʒ��������� dfs ������� Ž������
// öȸ ����	: 200000 * 200000 �� �����͸� ���� ������ �� ����.
// 
// ���̵�� 2	: ���� ��ܿ������� ���� ������ �Ǵ��ϸ� ���� �� �� �ִ��� Ȯ�� �� �� �ִ�
//					�̸� ���� ������ ���� ���� �������
// 
//

// ���п��� 1	: �����÷ο�	�ڷ��� �ִ�ũ�Ⱑ long long int ���� �Ǵ°��� Ȯ������ ���ϰ� Ǯ����
// ���п��� 2	: �ð��ʰ�		string �ڷ����� ���Կ��꿡�� ���� ���簡 �Ͼ�� ���� �������� ���Ͽ���
//								�̸� ������ �������� �����Ͽ� �ذ���
// ���п��� 3	: ������		������ ����� ���õ��� ���� ������� �ۼ��Ͽ� ȥ���� ������, 
//								�ε��� ������ �ʰ��ϰų� ������ ���� �� ��Ÿ�� ������ �߻���Ŵ
//

 
// size() �Լ� ��� �ּ�ȭ �ϱ�


#include<iostream>
#include<vector>
#include<algorithm>


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
} input = { 0,0,0 };

vector<string> temp_tile;	// Ÿ���� �ӽ� ������ ����

long long int solve()
{
	long long int start, end;
	long long int result = 0;
	string * tile;			// Ÿ���� �ּҰ��� ���� ������ (���� ����)
	string top;

	// ���� ������ �� ĭ���� ������
	// ���� �������� �ε��� ��ȣ�� ������.
	start = end = input.X_boundary - 1;

	// ���� ���� Ÿ���� �����Ͽ� ��������(���� ������ ĭ)�� U�� ǥ����
	top = temp_tile[ input.tile_list[input.tile_list.size()-1] - 'A' ];
	top[top.size() - 1] = 'U';
	
	// �˻��� tile�� ���� ���� Ÿ���� �����
	tile = &top;

	for (long long int i = input.tile_list.size() - 1; i >= 0; i--)
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
			if ((*tile)[start - 1] != RIGHT)
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
			if ((*tile)[end] == UP)
				break;

			end--;
		} while (true);

		// end�� start ���� �۾����� ���ǿ� �����ϴ� ���� �����Ƿ� ����
		if (end < start)
			break;

		// ������� ���� 
		result += end - start + 1;

		if (i - 1 < 0)
			break;

		// tile�� ������ Ȯ���ؾ��ϴ� ��ġ�� Ÿ�� ���¸� �ӽ� ����
		tile = &temp_tile[(input.tile_list[i - 1] - 'A')];
	}
	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// �� ũ��� Ÿ���� ���� �Է¹޾� ����
	cin >> input.Y_boundary >> input.X_boundary;
	cin >> input.number_tile;

	// Ÿ�� ������ �Է¹���
	// A : 0 
	// Ÿ���� ������ŭ ũ�⸦ �Ҵ���
	temp_tile = vector<string>(input.number_tile);
	for (long long int i = 0; i < temp_tile.size(); i++)
		cin >> temp_tile[i];

	// Ÿ���� ��ġ������ �Է� ����
	cin >> input.tile_list;

	cout << solve();
	return 0;
}

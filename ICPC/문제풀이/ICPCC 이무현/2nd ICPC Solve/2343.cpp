// ����
// 2343 [�ǹ� 5] ��Ÿ ����
// https://www.acmicpc.net/problem/2343

// ����
// https://movefast.tistory.com/311

// n���� ���� m���� ��緹��
// dvd�� �ּҿ䱸 ũ�� ���ϱ� 

#include<iostream>
#include<vector>
using namespace std;

#define LEFT -1
#define NONE 0
#define RIGHT 1

struct start_end
{
	int start;
	int end;
};

vector<int> videos;		// video�� ���̸� �Է¹��� ����
vector<int> sum_cd;		// cd�� ũ�⸦ ���� �����س��� ����
vector<start_end> cd_point;		// cd�� �������� ���� ������ ����

// ��谪�� �ű�� ���� �� ���� ���� ������ Ȯ���ϴ� �޼ҵ�
// a < b �� �׻� �����ؾ��Ѵ�.
int move_is_lower(int a, int b)
{
	int left, right;	// ����� ���ʿ� �ִ� ��, �����ʿ� �ִ� ��

	left = videos[cd_point[a].end];		// ����� ���ʿ� �ִ� �� �� ���� �����ʿ� �ִ� ��
	right = videos[cd_point[b].start];	// ����� �����ʿ� �ִ� �� �� ���� ���ʿ� �ִ� ��

	// �� �κ����� ������� �ű��� �ʴ� ���� ����.
	if (sum_cd[a] == sum_cd[b])
		return NONE;
	
	// ��踦 �̵��� ���
	// ������ �ִ밪���� �Ű��� ���� �ִ밪 ���� �������� �ű�� ���� ����.

	// ��踦 �������� �̵��� ���
	// a�� �հ�� �������� b�� �հ�� ��������.
	if (max(sum_cd[a], sum_cd[b]) > max(sum_cd[a] - left, sum_cd[b] + left))
	{
		// ���� ��� �������� �ű�� ���� ����
		return LEFT;
	}

	// ��踦 ���������� �̵��� ���
	// a�� �հ�� �������� b�� �հ�� ��������.
	if (max(sum_cd[a], sum_cd[b]) > max(sum_cd[a] + right, sum_cd[b] - right))
	{
		// ���� ��� �������� �ű�� ���� ����
		return RIGHT;
	}

	return NONE;
}

// �� ������ ��輱�� �� ��� �ű��.
bool boundary_move(int a, int b, int direction)
{
	int temp;
	// ����� �̵��� ���� �����̶��
	if (LEFT == direction)
	{
		temp = videos[cd_point[a].end];		// ������ ���� ���� �����ʿ� �ִ� ��

		sum_cd[a] -= temp;		// �հ��� ���� �����Ѵ�.
		sum_cd[b] += temp;		// �հ��� ���� �����Ѵ�.

		cd_point[a].end -= 1;	// ���� ���� ������ �Ѱ谡 �������� ��ĭ �̵��Ѵ�.
		cd_point[b].start -= 1;	// ������ ���� ���� �Ѱ谡 �������� ��ĭ �̵��Ѵ�.
		return true;
	}
	// ����� �̵��� ������ �����̶��
	else if (RIGHT == direction)
	{
		temp = videos[cd_point[b].start];		// �������� ���� ���� ���ʿ� �ִ� ��

		sum_cd[a] += temp;		// �հ��� ���� �����Ѵ�.
		sum_cd[b] -= temp;		// �հ��� ���� �����Ѵ�.

		cd_point[a].end += 1;	// ���� ���� ������ �Ѱ谡 ���������� ��ĭ �̵��Ѵ�.
		cd_point[b].start += 1;	// ������ ���� ���� �Ѱ谡 ���������� ��ĭ �̵��Ѵ�.
		return true;
	}
	return false;		// ���ʵ� �����ʵ� �ƴ϶�� false ��ȯ

}

int main()
{
	int temp;			// �ӽú���
	int n, cd;			// ������ ��, cd�� �� 
	int result = 0;

	cin >> n >> cd;		// ������ ���� cd�� ���� �Է¹޴´�.

	videos = vector<int>(n, 0);		// video�� ������ŭ ���� �Ҵ�
	sum_cd = vector<int>(cd, 0);	// cd�� ������ŭ ���� �Ҵ�
	cd_point = vector<start_end>(cd, { 0,0 });		// cd�� ������ŭ ���� �Ҵ�

	// ������ �Է¹޴´�.
	for (auto& i : videos)	
	{
		cin >> i;
	}

	// cd�� ������ �����Ͽ� �ӽ� ����
	temp = n / cd;
	for (int i = 0; i < cd; i++)
	{
		cd_point[i].start = i * temp;			
		cd_point[i].end = (i + 1) * temp - 1;
		//cout << cd_point[i].start << " " << cd_point[i].end << "\n";
	}

	cd_point[cd - 1].end = n - 1;	// ������ ������ �迭�� ������ ����Ű���� ��

	// �� ������ �κ����� ���
	temp = 0;
	for (auto const& i : cd_point)
	{
		for (int j = i.start; j <= i.end; j++)
		{
			sum_cd[temp] += videos[j];
		}
		temp++;
	}

	bool is_change = false; // ���� ������ �߻��� �� �ִ��� Ȯ���ϴ� �÷��� ���� 
	do
	{
		is_change = false;	// �ѹ��� �� ������ �ʱ�ȭ ���ش�.
		
		// cd�� ���� -1 ��ŭ�� �ݺ����� �����Ѵ�.
		for (int i = 0; i < cd - 1; i++)
		{
			// �ű�� ���� ������ Ȯ�� �� �ű��.
			// ���� ��ȯ���� true ��� �ű��� �߻��� �� �̹Ƿ� is_change�� ������Ʈ �Ѵ�.
			is_change = boundary_move(i, i + 1, move_is_lower(i, i + 1)) ? true: is_change;	
		}

	} while (is_change);	// ���� ������ �߻��� �� ���ٸ� �����Ѵ�.

	// ���� ū ���� ã�´�.
	for (auto& i : sum_cd)
		result = max(result, i);

	for (auto const& i : cd_point)
	{
		temp = 0;
		cout << i.start << " " << i.end << "\n";
		for (int j = i.start; j <= i.end; j++)
		{
			cout << videos[j] << " ";
			temp += videos[j];
		}
		cout << "\nsum : " << temp << "\n\n";
	}

	cout << result;

	return 0;
}
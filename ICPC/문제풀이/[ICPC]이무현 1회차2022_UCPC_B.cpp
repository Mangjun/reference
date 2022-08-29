#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define INT_MAX 2147483647
// B�� ����

// Conter Clockwise
// �� �������Ͽ� �� ���� �ð���⿡ �ִ��� �ݽð� ���⿡ �ִ��� Ȯ���ϴ� �ڵ�
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
	int op = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	op -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
	if (op > 0)
		return 1;
	else if (op == 0)
		return 0;
	else
		return -1;
}

struct point
{
	int x;
	int y;
};

class slicing
{
public:
	int weight;
	int cross_count;
	int cost;
	point p1;
	point p2;

	int ret_cost()
	{
		return (cross_count + 1) * weight;
	}
	void cal_cost()
	{
		cost = (cross_count + 1) * weight;
	}

	// ��ü�� target �� ��ġ���� Ȯ���ϱ� ���� �˰���
	bool is_cross(slicing target)
	{
		int ta;
		int tb;

		ta = ccw({ p1.x, p1.y }, { p2.x, p2.y }, { target.p1.x, target.p1.y });
		ta *= ccw({ p1.x, p1.y }, { p2.x, p2.y }, { target.p2.x, target.p2.y });

		tb = ccw({ target.p1.x, target.p1.y }, { target.p2.x, target.p2.y }, { p1.x, p1.y });
		tb *= ccw({ target.p1.x, target.p1.y }, { target.p2.x, target.p2.y }, { p2.x, p2.y });

		return (ta < 0) && (tb < 0);
	}
	// ��ü�� ������ ����ϴ� �޼ҵ�
	void prt(void) {
		cout << p1.x << " ";
		cout << p1.y << " ";
		cout << p2.x << " ";
		cout << p2.y << " ";
		cout << weight << " ";
		if (cross_count)
			cout << cross_count << " ";
		if (cost)
			cout << cost << " ";
		cout << "\n";
	}
};

// �������� ����
// cross_count �������� ����
int slicing_sort_by_cross_count(slicing a, slicing b)
{
	return a.cross_count > b.cross_count;
}
// weight �������� ����
int slicing_sort_by_weight(slicing a, slicing b)
{
	return a.weight < b.weight;
}

// ���꿡 �ʿ��� �ڷ���� ����
vector <slicing> slices;
vector <vector<bool>> cross_map;
map<int, slicing*> slicing_map;	// map�� �ƴ� vector�� �����ص� ��

int main(void)
{
	// Ž�� ����
	// cross�� ���� ���� ��
	// weight�� ���� ���� ��
	// 
	// �� ���¿��� cost�� ���� ���� ��

	int result = 0;	// ����� ������ ����
	int n;			// �˼� ������ ���� ����
	cin >> n;

	slices = vector<slicing>(n);	// �˼� Ƚ�� �ʱ�ȭ
	cross_map = vector < vector < bool >>(n, vector<bool>(n, false)); // ��ġ�� �˼������� ������ map

	// �˼��� ������ �Է� ����
	for (size_t i = 0; i < n; i++)
	{
		cin >> slices[i].p1.x >> slices[i].p1.y;
		cin >> slices[i].p2.x >> slices[i].p2.y;
		cin >> slices[i].weight;
		slicing_map.insert({ i,&slices[i] });
		// ������ ���� �����Ƿμ� vector�� �����ϴ���
		// map�� �ε��� ������ �����־� ���� �ӵ��� ����
		// �����͸� �����ϴ� �迭�� �����Ͽ��� �����ϰ� �۵���(�׳� �ͼ����������� ���.)
	}

	// ��ġ�� �˼� ������ ����
	// �տ������� ��ġ�� �κи� ������ ������
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			// �� �˼��� ��ģ�ٸ�
			// �� �� �� �˼��� ���� �˼��� ���ɼ��� ����
			if (slices[i].is_cross(slices[j]))
			{
				slices[i].cross_count++;
				slices[j].cross_count++;
				cross_map[i][j] = true;
				cross_map[j][i] = true;
			}
		}
		slices[i].cal_cost();
	}

	// �˼��� cross_count �������� �������� ����
	sort(slices.begin(), slices.end(), slicing_sort_by_cross_count);

	// �˼��� ��ġ�� �ʴ� �˼� �켱 ����
	int temp = 0;
	for (temp = 0; temp < n; temp++)
	{
		if (slices[temp].cross_count != 0)
			break;
		result += slices[temp].cost;
		slices[temp].cost = -1;
	}
	// �� �� temp �� �˼��� ��ġ�� ������ ���� �ε��� ��ȣ�� ������ �ִ�.

	// ��ġ�°� �ִ� �˼� �� cost�� ���� ���� �˼��� �����Ѵ�.
	do
	{
		int temp_cost = INT_MAX;
		int temp_i = -1;
		for (size_t i = 0; i < n; i++)
		{
			slicing* temp_slicing = slicing_map[i];
			if (temp_slicing->cost == -1)
				continue;
			if (temp_slicing->cost < temp_cost)
			{
				temp_i = i;
				temp_cost = temp_slicing->cost;
			}
		}

		// ���� ���ǹ��� �����Ѵٸ� ���̻� ã�� ���� ����.
		if (temp_i <= -1)
			break;

		// ã�� �˼��� cross_map ���� �����Ѵ�.
		for (size_t i = 0; i < n; i++)
		{
			if (cross_map[temp_i][i])
			{
				// cross_count �� 1 ���߰� ������
				slicing_map[i]->cross_count--;
				slicing_map[i]->cal_cost();

				cross_map[temp_i][i] = false;
				cross_map[i][temp_i] = false;
			}
		}

		// -1�� �ƴ� �ּҰ��� �ִٸ� �� ���� �����Ѵ�.
		result += slicing_map[temp_i]->cost;
		slicing_map[temp_i]->cost = -1;

	} while (true);

	cout << result;
}

// 18809 Gaaaaaaaaaarden
// https://www.acmicpc.net/problem/18809
// ������ �Ѹ� �� �ִ� ��ġ�� 10���� �����̴�.
// �ǿ�� ���� �ִ� ������ ��ȯ
// �ð����� 2��

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

#define NONE 0
#define LIVER -1
#define UNABLEPLACE -2
#define ABLEPLACE -3
#define GREEN 1
#define RED 2
#define FLOWER 3

using namespace std;

// ��ġ�� ������ �� �ִ� ����ü ����
struct point {
	int x;
	int y;
};

// 
//			 ��, ��, ��, ��
int dx[4] = { -1, 0 ,1 , 0 };
int dy[4] = { 0 ,-1 ,0 , 1 };

// �ڷ��� ���� 
vector<vector<int>> state_map;	// ���� ��Ȳ�� ������ �� �ִ� �� ���� (���� ����)
vector<vector<int>> temp_map;	// ���� ��Ȳ�� ������ �� �ִ� �� ���� (������ ����)
queue <point> red;				// red ����� ��ġ�� �����ϴ� queue
queue <point> green;			// green ����� ��ġ�� �����ϴ� queue
vector<point> ablePlace;	// ����� ���� �� �ִ� ���� ��ǥ�� ����� ������ ���¸� ����

queue <pair<int, point>> bfs_queue;

// ���� �� �ִ��� Ȯ��
bool is_spread(point spot)
{
	int temp;
	do
	{
		if (spot.x < 0)
			break;
		if (spot.x >= temp_map[0].size())
			break;
		if (spot.y < 0)
			break;
		if (spot.y >= temp_map.size())
			break;

		temp = temp_map[spot.y][spot.x];

		if (temp == LIVER)
			break;
		if (temp == FLOWER)
			break;
		// �̹� RED�� GREEN�� �ִٸ� �� ȸ������ �ѷ��� �� �̱� ������ ���� ����
		if (temp == RED)
			break;
		if (temp == GREEN)
			break;

		return true;
	} while (true);
	return false;
}

// bfs_queue�� ������ �ҷ��� ��� ó�� ��, bfs_queue�� ������ ������ ����

int bfs()
{
	queue <pair<int, point>> temp_queue;	
	pair<int, point> temp_point;
	int flower = 0;

	// ��ü�� ��ġ�Ѵ�.
	// flower �� �����ƴ��� Ȯ���Ѵ�.
	while (!bfs_queue.empty())
	{
		temp_point = bfs_queue.front();
		bfs_queue.pop();
		int& temp = temp_map[temp_point.second.y][temp_point.second.x];

		// ����� �����µ� ���� 3�̸� ���� �ȴ�.
		if (temp + temp_point.first == FLOWER)
		{
			temp = FLOWER;
			flower++;
			continue;
		}
		// ABLEPLACE �Ǵ� UNABLEPLACE �� �ƴ϶�� �̹� �ٸ������ �ִ� ��
		else if(temp != ABLEPLACE && temp != UNABLEPLACE)
			continue;

		// ���� ���� �ʰ�, �̹� �ٸ� ����� �ڸ��� ���� ���� �ƴ϶��
		// �ڽ��� ����� ���� ��ġ�Ѵ�.
		temp = temp_point.first;

		temp_queue.push(temp_point);
	}

	// ��ġ�� ���� �� ��ü�� ������ Ȯ���Ѵ�.
	while (!temp_queue.empty())
	{
		temp_point = temp_queue.front();
		temp_queue.pop();
		int x = temp_point.second.x;
		int y = temp_point.second.y;

		// �ش� ������ ���� �ִٸ� ���̻� ���� �� ����.
		if (temp_map[y][x] == FLOWER)
			continue;

		for (int i = 0; i < 4; i++)
		{
			// ���� �� �ִٸ� 
			if (is_spread({ x + dx[i] , y + dy[i] }))
			{
				bfs_queue.push({ temp_point.first, {x + dx[i] , y + dy[i]} });
			}
		}
	}

	// ��ü�� ������ ���̻� �Ͼ�� �ʴ� ���
	if (bfs_queue.empty())
		return flower;

	// ��ü�� ������ �� �Ͼ�� ���
	return flower + bfs();
}


int solve(int r, int g)
{
	int empty = ablePlace.size() - (r + g);		// ������� ���� ����
	int result = 0;
	vector<int> v;

	// �ߺ����� �ڵ�
	// next_permutation ���� ������ ���ϴ� �޼ҵ�
	// �������� ������ �Ǿ��־�� �Ѵ�.
	for (size_t i = 0; i < empty; i++)
		v.push_back(NONE);
	for (size_t i = 0; i < g; i++)
		v.push_back(GREEN);
	for (size_t i = 0; i < r; i++)
		v.push_back(RED);
	sort(v.begin(),v.end());

	do
	{
		int temp = 0;
		while (!bfs_queue.empty()) bfs_queue.pop();

		temp_map = state_map;
		
		for(int i = 0 ; i < v.size() ; i++)
		{
			if (v[i] == RED)
				bfs_queue.push({ RED,ablePlace[i] });
			if (v[i] == GREEN)
				bfs_queue.push({ GREEN,ablePlace[i] });
		}
		result = max(bfs(), result); // ���� �� ū���� ����
	} while (next_permutation(v.begin(), v.end())); 
	
	return result;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, m;
	int r, g;
	int result = 0;

	// n * m ũ��
	// ��, ��    y, x
	cin >> n >> m;
	state_map = vector<vector<int>>(n, vector<int>(m, 0));

	// �ʷϻ�, ������ ���� ����
	cin >> r >> g;

	// ���� ���� �Է�
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> state_map[y][x];
			state_map[y][x] = (state_map[y][x] + 1) * -1;
			
			// ������ �Ѹ� �� �ִ� ������ Ȯ��
			if (state_map[y][x] == ABLEPLACE)	
				ablePlace.push_back(point{ x ,y });
		}
	}

	cout << solve(r, g) << endl;
}


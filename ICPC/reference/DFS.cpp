#include <iostream>
#include <queue>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

// ������ ���� ������ ����� ��� �׷���
vector<int> tree[100001];

// ���� �湮üũ�� �迭
vector<int> visted(10001);

void DFS(int current_node)
{
    // �ʱ� ��ġ ����
    visted[current_node] = true;

    // ���� ������ ������ ���� push
    for (int idx = 0; idx < tree[current_node].size(); idx++)
    {
        int next = tree[current_node][idx];

        if (visted[next] == true) continue;

        DFS(next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ���� ������ ���� ���� 
    int V, E;
    cin >> V >> E;

    // �ʱ� ����
    for (int idx = 1; idx <= E; idx++)
    {
        char start, end;   
        cin >> start >> end;

        start -= 64;
        end -= 64;
        tree[start].push_back(end);
        tree[end].push_back(start);
    }

    // DFS(Depth First Search)
    DFS(1);

    cout << "Ž�� ����";

    return 0;
}
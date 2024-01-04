#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int id;
    vector<int> neighbors;
};

int main() {
    setlocale(0, "");
    int M, N; 
    cin >> M >> N;

    vector<vector<Cell>> field(M, vector<Cell>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            field[i][j].id = i * N + j;
        }
    }
    int start, end;
    cin >> start >> end;

    queue<int> q;
    vector<bool> visited(M * N, false);
    vector<int> distance(M * N);
    vector<int> parent(M * N, -1);

    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == end) {
            break;
        }

        for (int neighbor : field[curr / N][curr % N].neighbors) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                distance[neighbor] = distance[curr] + 1;
                parent[neighbor] = curr;
            }
        }
    }

    if (visited[end]) {
        vector<int> path;
        int curr = end;

        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }

        cout << "Кратчайший путь: " << distance[end] << endl;
        cout << "Путь: ";

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Путь не найден" << endl;
    }

    return 0;
}

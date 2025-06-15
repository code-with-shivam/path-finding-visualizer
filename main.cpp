#include <bits/stdc++.h>

using namespace std;

const int rows = 20;
const int cols = 30;

enum CellType
{
    Empty,
    Wall,
    Start,
    End,
    Visited,
    Path
};

struct Cell
{
    CellType type = Empty;
};

Cell grid[rows][cols];
pair<int, int> start = {-1, -1}, endPos = {-1, -1};

void drawGrid()
{
    system("clear"); // use "cls" on Windows

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            switch (grid[i][j].type)
            {
            case Empty:
                cout << ".";
                break;
            case Wall:
                cout << "#";
                break;
            case Start:
                cout << "S";
                break;
            case End:
                cout << "E";
                break;
            case Visited:
                cout << "v";
                break;
            case Path:
                cout << "*";
                break;
            }
        }
        cout << "\n";
    }

    this_thread::sleep_for(chrono::milliseconds(100));
}

bool isValid(int x, int y)
{
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y].type != Wall;
}

void dijkstra()
{
    if (start.first == -1 || endPos.first == -1)
        return;

    using Node = pair<int, pair<int, int>>; // {distance, position}
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<vector<int>> dist(rows, vector<int>(cols, numeric_limits<int>::max()));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    dist[start.first][start.second] = 0;
    pq.push({0, start});

    const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    while (!pq.empty())
    {
        auto [d, pos] = pq.top();
        pq.pop();
        int x = pos.first, y = pos.second;

        if (grid[x][y].type == Empty)
            grid[x][y].type = Visited;

        drawGrid();

        if (pos == endPos)
            break;

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (isValid(nx, ny))
            {
                int newDist = d + 1;
                if (newDist < dist[nx][ny])
                {
                    dist[nx][ny] = newDist;
                    parent[nx][ny] = {x, y};
                    pq.push({newDist, {nx, ny}});
                }
            }
        }
    }

    pair<int, int> p = endPos;
    while (p != start && parent[p.first][p.second] != make_pair(-1, -1))
    {
        p = parent[p.first][p.second];
        if (p != start)
            grid[p.first][p.second].type = Path;
        drawGrid();
    }
}

int main()
{
    // Manual walls
    grid[1][2].type = Wall;
    grid[2][2].type = Wall;
    grid[3][2].type = Wall;
    grid[4][2].type = Wall;
    grid[5][2].type = Wall;

    // Set start & end
    start = {0, 0};
    endPos = {10, 25};
    grid[start.first][start.second].type = Start;
    grid[endPos.first][endPos.second].type = End;

    drawGrid();
    this_thread::sleep_for(chrono::seconds(1));

    dijkstra();

    cout << "\nPress Enter to exit...";
    cin.ignore();

    return 0;
}

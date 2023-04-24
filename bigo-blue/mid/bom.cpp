#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
using namespace std;

#define ll long long

int main()
{
    while (true)
    {
        vector<vector<int> > matrix; // 1 boom, 0 none
        ll row, col, n_row;
        cin >> row >> col;
        if (row == 0 && col == 0)
        {
            break;
        }
        bool visited[row][col];

        for (int i = 0; i < row; i++)
        {
            vector<int> vrow(col, 0);
            matrix.push_back(vrow);

            for (int j = 0; j < col; j++)
            {
                visited[i][j] = false;
            }
        }

        cin >> n_row;
        for (int i = 0; i < n_row; i++)
        {
            ll r, n_boom, c;
            cin >> r >> n_boom;
            for (int j = 0; j < n_boom; j++)
            {
                cin >> c;

                matrix[r][c] = 1;
            }
        }

        ll rr, cc;
        pair<ll, ll> start, end;
        cin >> rr >> cc;
        start = make_pair(rr, cc);
        cin >> rr >> cc;
        end = make_pair(rr, cc);

        queue<pair<pair<ll, ll>, ll> > q; // {x,y}, dist
        q.push(make_pair(start, 0));
        bool found = false;

        while (!q.empty())
        {
            pair<ll, ll> nextp = q.front().first;
            ll dist = q.front().second;
            q.pop();
            if (nextp.first == end.first && nextp.second == end.second)
            {
                cout << dist << endl;
                found = true;
            }

            static const int arr[] = {0, 0, 1, -1};
            vector<int> ri(arr, arr + sizeof(arr) / sizeof(arr[0]));
            static const int arr1[] = {1, -1, 0, 0};
            vector<int> ci(arr1, arr1 + sizeof(arr) / sizeof(arr1[0]));

            for (int i = 0; i < 4; i++)
            {
                ll nextp_r = nextp.first + ri[i], nextp_c = nextp.second + ci[i];
                if (nextp_r >= 0 && nextp_r < row && nextp_c >= 0 && nextp_c < col && matrix[nextp_r][nextp_c] == 0 && !visited[nextp_r][nextp_c])
                {
                    // cout << nextp_r << " " << nextp_c;
                    q.push(make_pair(make_pair(nextp_r, nextp_c), dist + 1));
                    visited[nextp_r][nextp_c] = true;
                }
            }
        }

        if (!found)
        {
            cout << 0 << endl;
        }
    }

    return 0;
}
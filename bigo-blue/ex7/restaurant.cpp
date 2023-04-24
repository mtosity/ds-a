#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, type, nreviews = 0;
    priority_queue<int, vector<int>, greater<int> > top3;
    priority_queue<int> rest;
    cin >> n;

    while (n--)
    {
        cin >> type;

        if (type == 1)
        {
            cin >> x;
            nreviews++;

            if (!top3.empty() && top3.top() < x)
            {
                rest.push(top3.top());
                top3.pop();
                top3.push(x);
            }
            else
            {
                rest.push(x);
            }

            if (nreviews % 3 == 0)
            {
                top3.push(rest.top());
                rest.pop();
            }
        }
        else
        {
            if (top3.empty())
            {
                cout << "No reviews yet" << endl;
            }
            else
            {
                cout << top3.top() << endl;
            }
        }
    }
    return 0;
}
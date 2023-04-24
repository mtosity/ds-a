#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()

{

    ll n;

    cin >> n;

    priority_queue<pair<ll, ll> > pq;
    unordered_map<ll, ll> mp;

    for (int i = 0; i < n; i++)
    {

        ll topic_id, z_score, z_new, diff, post, likes, comm, shares;
        cin >> topic_id >> z_score >> post >> likes >> comm >> shares;
        z_new = (post * 50 + likes * 5 + comm * 10 + shares * 20);
        diff = abs(z_new - z_score);

        pq.push({diff, topic_id});
        mp.insert({topic_id, z_new});
    }

    for (int i = 0; i < 5; i++)
    {
        cout << pq.top().second << " ";
        auto it = mp.find(pq.top().second);
        cout << it->second << endl;
        pq.pop();
    }

    return 0;
}

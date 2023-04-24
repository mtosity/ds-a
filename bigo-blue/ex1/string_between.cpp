#include <iostream>
#include <vector>
#include <string>

using namespace std;

string readString()
{
    string s;
    getline(cin, s);
    return s;
}

bool have_between(string s, string t)
{
    int n = s.size();

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] < t[i])
        {
            return true;
        }
    }

    if (s[n - 1] < t[n - 1] - 1)
    {
        return true;
    }

    return false;
}

int main()
{
    string s = readString();
    string t = readString();
    int n = s.size();
    if (!have_between(s, t))
    {
        cout << "No such string";
        return 0;
    }

    string result = s;
    int k = n - 1;
    while (k >= 0)
    {
        if (result[k] != 'z')
        {
            result[k] += 1;

            cout << result;
            return 0;
        }
        else
        {
            result[k] = 'a';
            k--;
        }
    }

    cout << result;
    return 0;
}
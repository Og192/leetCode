#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    long long  n, k;
    cin >> n >> k;
    vector<long long > scores(n, 0);
    vector<long long > sleeps(n, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> scores[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> sleeps[i];
    }
    long long result = 0;
    int pos = 0;
    for(int i = 0; i < n; ++i)
    {
        if(sleeps[i] == 0)
        {
            int j = i;
            long long temp = 0;
            for(int m = 0; m < k && j < n; ++j, ++m)
            {
                if(sleeps[j] == 0)
                {
                    temp += scores[j];
                }
            }
            if(temp > result)
            {
                result = temp;
                pos = i;
            }
        }
    }
    long long finalRe = 0;
    for(int i = 0; i < pos; ++i)
    {
        if(sleeps[i] == 1)
        {
            finalRe += scores[i];
        }
    }
    for(int i = pos; i < pos + k; ++i)
    {
        finalRe += scores[i];
    }
    for(int i = pos + k; i < n; ++i)
    {
        if(sleeps[i] == 1)
        {
            finalRe += scores[i];
        }
    }
    cout << finalRe << endl;
    return 0;
}
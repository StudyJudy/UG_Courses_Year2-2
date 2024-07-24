#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int rabin_karp(const string& text, const string& pattern) 
{
    int n = text.length();
    int m = pattern.length();
    if (n < m) 
    {
        return -1;
    }

    const int prime = 101; // 可选的素数
    const int prime_power = static_cast<int>(pow(prime, m - 1)) % n;

    int pattern_hash = 0;
    int window_hash = 0;
    for (int i = 0; i < m; ++i)
    {
        pattern_hash = (pattern_hash * prime + pattern[i]) % n;
        window_hash = (window_hash * prime + text[i]) % n;
    }

    for (int i = 0; i <= n - m; ++i)
    {
        if (pattern_hash == window_hash)
        {
            bool match = true;
            for (int j = 0; j < m; ++j) 
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return i;
            }
        }

        if (i < n - m) 
        {
            window_hash = (prime * (window_hash - text[i] * prime_power) + text[i + m]) % n;
            if (window_hash < 0) 
            {
                window_hash += n; // 处理负数取模结果
            }
        }
    }

    return -1;
}

int main() 
{
    string text;
    string pattern;
    cin >> text;
    cin >> pattern;
    int result = rabin_karp(text, pattern);
    cout << result << endl;

    return 0;
}

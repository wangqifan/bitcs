#include <string>
#include <iostream>
using namespace std;
bool ishuiwen(string str)
{
    if (str.length() <= 1)
        return true;
    int left = 0;
    int right = str.length() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}
int main()
{
    string str;
    cin >> str;
    cout << ishuiwen(str);
    return 0;
}
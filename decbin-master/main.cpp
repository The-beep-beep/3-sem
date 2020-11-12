#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// 1) кое-где съехало форматирование
// 2) можно было бы написать while (n > 0) и убрать push_back(1)
// 3) внесите, пожалуйста, имя/фамилию в профиль на github

int main ()
{
    int n;
    cin >> n;
    vector <int> v;
    while (n >= 2)
    {
       int c = n%2;
        n = n/2;
        v.push_back(c);
    }
    v.push_back(1);
    for ( auto it = v.rbegin(); it != v.rend(); ++it )
       cout << *it << ' ';
}

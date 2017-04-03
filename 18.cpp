#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 3e5;

string str,s;
int len1,len2,p[maxn],ans;

void init()
{
    str[0] = '$';
    str[1] = '#';
    /*for(int i = 0; i < len1; i ++){
        str[2 * i + 2] = s[i];
        str[2 * i + 3] = '#';
    }*/
    for(int i = 1; i <= len1; i ++){
        str[2 * i] = s[i];
        str[2 * i + 1] = '#';
    }
    len2 = len1 * 2 + 2;
    str[len2] = '*';
    for(int i = 0; i <= len2; i ++)
        cout << str[i];
}

void manacher()
{
    int id = 0,mx = 0;
    for(int i = 1; i < len2; i ++){
        if(i < mx)  p[i] = min(p[2 * id - 1],mx - i);
        else p[i] = 1;
        for(; str[i + p[i]] == str[i - p[i]]; p[i] ++);
        if(p[i] + i > mx){
            mx = p[i] + i;
            id = i;
        }
    }
}

int main(void)
{
    while(cin >> s){
        len1 = s.size();
        init();
        manacher();
        ans = 0;
        for(int i = 0; i < len2; i ++)
            ans = max(ans,p[i]);
        cout << ans - 1 << endl;
    }
    return 0;
}

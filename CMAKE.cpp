//
// Created by defjia on 18-5-12.
// use case:
// 2
// Love
// Aou
// 用例没过全
//
#include <string>
#include <iostream>
using namespace std;
int is(char a){
    if(a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u')
        return 1;
    a += 32;
    if(a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u')
        return 1;
    else return 0;
}

int main(){
    int n;
    if(scanf("%d\n", &n) != 1) exit(1);
    while (n--){
        string tmp;
        getline(cin, tmp);
        for (int i = 0; i < tmp.size(); ++i) {
            if(!is(tmp[i])) cout << tmp[i];
        }
        cout << "\n";
    }
    return 0;
}

/*

 */

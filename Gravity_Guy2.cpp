#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define LIM 200011
#define INF LIM<<3

char words[2][LIM];
int main() {
    int z;
    scanf("%d", &z);
    while (z--) {
        scanf("%s%s", words[0], words[1]);
        int n = strlen(words[0]);
        int curr = -1, ans = 0;
        for (int i = 0; i < n; i++) {  // 0  for . and 1 for #

           bool dirty0 = words[0][i] == '#'; // words[0][i]==# set 1 else 0  
           bool dirty1 = words[1][i] == '#'; // words[1][i]==# set 1 else 0 
           // printf("%d", dirty0);   // give 0 or 1
           // printf("%d", dirty1);  // give 0 or 1
            cout<<"\n";
            if (dirty0 && dirty1) {  //dirty0 && dirty1 both are same -1 && 1 return true
                ans = INF;
              // printf("%s", words[0][i]);
              // printf("&");
               // printf("%s", words[1][i]);
                break;
            }
            if (dirty0) {    
              // printf("%s", words[0][i]);  //  check if dirty0== # ?
                if (curr == 0) ans++; // curr ==0, lane 1
                curr = 1;  // curr== 1, lane 2
            }
            if (dirty1) {  
               // printf("%s", words[1][i]);    //  check if dirty1==# ? 
                if (curr == 1) ans++;
                curr = 0;
            }
        }
        if (ans >= INF) {
            printf("No\n");
        } else {
            printf("Yes\n%d\n", ans);
        }
    }
}
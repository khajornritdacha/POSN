#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    while(n >= 5) {
        n /= 5;
        ans += n;
    }
    printf("%d", ans);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char a[10] = "NO";
    printf("Enter number : ");
    scanf("%d", &n);
    if(n > 0) {
        strcpy(a, "YES");
    }
    printf("%s.", a);
    return 0;
}

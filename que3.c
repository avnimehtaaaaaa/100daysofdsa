/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)*/
#include <stdio.h>

int main() {
    int n, k;
    int arr[100];
    int found = 0;
    int comparisons = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        comparisons++;          
        if (arr[i] == k) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found\n");
    }

    
    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}

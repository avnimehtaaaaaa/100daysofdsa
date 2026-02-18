#include <stdio.h>

int main() {
    int n, k;
    
    // Read size of array
    scanf("%d", &n);

    int arr[n], rotated[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read k
    scanf("%d", &k);

    // Handle cases where k > n
    k = k % n;

    // Right rotation logic
    for (int i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr[i];
    }

    // Print rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }

    return 0;
}

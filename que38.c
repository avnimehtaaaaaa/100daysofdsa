#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
            break;
    }
}

void heapifyDown(int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x)
{
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin()
{
    if(size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

int peek()
{
    if(size == 0)
        return -1;

    return heap[0];
}

int main()
{
    int n;
    scanf("%d", &n);

    char operation[20];
    int x;

    for(int i = 0; i < n; i++)
    {
        scanf("%s", operation);

        if(operation[0] == 'i')   // insert
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(operation[0] == 'e')  // extractMin
        {
            printf("%d\n", extractMin());
        }
        else if(operation[0] == 'p')  // peek
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}
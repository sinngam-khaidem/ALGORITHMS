#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Job {
    char id;
    int dead;
    int profit;
};

int compare(const void* a, const void* b)
{
    struct Job* temp1 = (struct Job*)a;
    struct Job* temp2 = (struct Job*)b;
    return (temp2->profit - temp1->profit);
}

int min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

void printJobScheduling(struct Job arr[], int n)
{
    qsort(arr, n, sizeof(struct Job), compare);
    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)  {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }

    for(int i = 0; i < n; i++){
        if (slot[i] == true)
            printf("%c ", arr[result[i]].id);
    }
}

int main()
{
    struct Job arr[] = { { 'A', 2, 20 },{ 'B', 7, 15 },{ 'C', 1, 10 },{ 'D', 3, 5 },{ 'E', 6, 1 } };
    int n = sizeof(arr) / sizeof(arr[0]); // n = number of jobs
    printf("Following is maximum profit sequence of jobs \n");

    printJobScheduling(arr, n);
    return 0;
}


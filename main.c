#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MAX 8000
void bubbleSort(int *a)
{
    int temp;
    int flag = 1;
    for (int j = 0; j < MAX && flag; j++)
    {
        flag = 0;
        for (int i = 0; i < MAX-1-j; i++)
        {
            if (a[i+1] > a[i])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                flag = 1;
            }
        }
    }
}
void quickSort (int *a, int left, int right)
{
    int pivot, i, j;

    if(left >= right) return;
    i = left;
    j = right+1;
    pivot = a[left];
    do
    {
        do i++; while(a[i] < pivot && i<right);
        do j--; while(a[j] > pivot && left<j);
        if(i < j)
        {
            int temp;
            temp = a[i];  a[i] = a[j];  a[j] = temp;
        }
    } while(i < j);

    int temp;
    temp = a[left];  a[left] = a[j];  a[j] = temp;

    quickSort(a, left, j-1);
    quickSort(a, j+1, right);
    return;

}
void merge(int a[], int Lstart, int Lend, int Rstart, int Rend)
{
    int size=Rend-Lstart+1, i=Lstart, j=Rstart;
    int buffer[size], k=0;

    while(i<=Lend && j<=Rend)
        if(a[i] <= a[j])
            buffer[k++] = a[i++];
        else
            buffer[k++] = a[j++];


    while(i<=Lend)  buffer[k++] = a[i++];
    while(j<=Rend)  buffer[k++] = a[j++];

    for (i=Lstart, j=0; i<=Rend; i++)
        a[i] = buffer[j++];

    return;
}
void mergeSort (int *a,int left ,int right)
{
    if(left==right)   return;

    int mid = (left+right)/2;

    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a, left, mid, mid+1, right);

    return;
}
int main()
{
    srand(time(NULL));
    int a[MAX],b[MAX],c[MAX];
    clock_t time1 = 0, time2 = 0, time3 = 0, tt;

    for (int j = 0; j < 10; j++)
    {
        //printf("%ld %ld %ld\n",time1,time2,time3);
        for(int i=0; i<MAX; i++) a[i] = b[i] = c[i] = rand()%10000;
        tt = clock();
        bubbleSort(a);
        time1 += clock() - tt;

        tt = clock();
        quickSort(b, 0, MAX-1);
        time2 += clock() - tt;

        tt = clock();
        mergeSort(c, 0, MAX-1);
        time3 += clock() - tt;
    }

    printf("Bubble: %.3lf Quick: %.3lf Merge: %.3lf\n",time1/(double)1000,time2/(double)1000,time3/(double)1000);
    system("pause");
    return 0;
}

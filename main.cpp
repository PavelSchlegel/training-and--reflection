#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <functional>
#include "Qsort_Pool/threadpool.hpp"

Thread_Pool q_sort;

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            std::swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    std::swap (a[pIndex], a[end]);
    return pIndex;
}

void quicksort(int a[], int start, int end)
{
    if (start >= end) {
        return;
    }
 
    int pivot = partition(a, start, end);
    q_sort.push_task(quicksort, a, start, pivot - 1);
    // quicksort(a, start, pivot - 1);
    quicksort(a, pivot + 1, end);
}

int main()
{
    int a[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
    int n = sizeof(a)/sizeof(a[0]);
    q_sort.start();
    q_sort.push_task(quicksort, a, 0, n - 1).get();
    q_sort.stop();
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}
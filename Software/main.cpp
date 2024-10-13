#include <iostream>
#include "employee.h"
#include "minHeap.h"

using namespace std;

int main() {

    Employee* employees = load_data();
    int size = 1000;
    minHeap* heap = init_MinHeap(size);

    for (int i = 0; i < size; i++) {
        heap = insert(heap, employees[i]);
    }

    heapSort(heap);
    print_heap(heap);

    return 0;
}
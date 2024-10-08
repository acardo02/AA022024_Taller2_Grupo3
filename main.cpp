#include <iostream>
#include "employee.hpp"

using namespace std;

void print_data(Employee* employees, int size) {
    for (int i = 0; i < size; i++) {
        cout << employees[i].name << " " << employees[i].salary << endl;
    }
}

void swap(Employee* a, Employee* b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeapify(Employee *array, int i, int size)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < size && array[l].salary < array[i].salary)
        smallest = l;
    else
        smallest = i;

    if (r < size && array[r].salary < array[smallest].salary)
        smallest = r;

    if (smallest != i)
    {
        swap(array[i], array[smallest]);
        MinHeapify(array, smallest, size);
    }
}

void BuildMinHeap(Employee *array, int size)
{
    for (int i = (size /2) -1; i >= 0; i--)
        MinHeapify(array, i, size);
}

void Heapsort(Employee* arr, int n){
    int heap_size = n;
    BuildMinHeap(arr, n);
    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heap_size--;
        MinHeapify(arr, 0, heap_size);
    }
}

int main() {

    Employee* employees = load_data();
    int size = 1000;

    print_data(employees, 1000);

    Heapsort(employees, size);

    cout << "Sorted data: " << endl;

    print_data(employees, size);
    return 0;
}
#ifndef MINHEAP_H
#define MINHEAP_H

#include <string>
#include <iostream>
#include "employee.h"

using namespace std;

struct minHeap{
   Employee* arr;
   int size;
   int capacity;
};

int parent(int i) {
    return (i - 1) / 2;
} 

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void swap(Employee* a, Employee* b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
    }

    minHeap* init_MinHeap(int capacity) {
    minHeap* heap = new minHeap;
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = new Employee[capacity];
    return heap;
}

minHeap* insert(minHeap* heap, Employee employee) {
    if (heap->size == heap->capacity) {
        cout << "Overflow: Could not insert key\n";
        return heap;
    } 
    
    heap->size++;
    heap->arr[heap->size - 1] = employee;

    int key = heap->size - 1;

    while(key > 0 && heap->arr[parent(key)].salary > heap->arr[key].salary) {
        swap(&heap->arr[parent(key)], &heap->arr[key]);

        key = parent(key);
    }
    return heap;
}

void minHeapify(minHeap* heap, int i) {
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < heap->size && heap->arr[l].salary < heap->arr[smallest].salary) {
        smallest = l;
    }

    if (r < heap->size && heap->arr[r].salary < heap->arr[smallest].salary) {
        smallest = r;
    }

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }

}

void print_heap(minHeap* heap) {
    cout << "-------------------------------------" << endl;
    cout << "|            Empleados              |" << endl;
    cout << "-------------------------------------" << endl;
    cout << "|     Nombre     |      Salario     |" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < heap->size; i++) {
        cout << heap->arr[i].name << "     " << heap->arr[i].salary << endl;
    }
}

void buildMinHeap(minHeap* heap) {
    for (int i = (heap->size / 2) - 1; i >= 0; i--) {
        minHeapify(heap, i);
    }
}

void heapSort(minHeap* heap) {
    buildMinHeap(heap);
    int originalSize = heap->size;
    for (int i = heap->size - 1; i > 0; i--) {
        swap(&heap->arr[0], &heap->arr[i]);
        heap->size--;
        minHeapify(heap, 0);
    }
    heap->size = originalSize;  
}


#endif
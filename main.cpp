#include <iostream>
#include "employee.h"
#include "minHeap.h"

using namespace std;

void showMenu() {
    cout << "---------- Menu Almacenes Salem ----------" << endl;
    cout << "1. Insertar empleado" << endl;
    cout << "2. Mostrar heap" << endl;
    cout << "3. Eliminar empleado" << endl;
    cout << "4. Buscar empleado" << endl;
    cout << "5. Salir" << endl;
    cout << "----------------------------------";
}

Employee typingEmployee() {
    string name;
    float salary; 
    cout << "Ingresa el nombre del empleado: ";
    cin >> name;
    cout << "Ingresa el salario del empleado: ";
    cin >> salary;
    Employee employee;
    employee.name = name;
    employee.salary = salary;
    return employee;
}

void insertEmployee(minHeap* heap) {
    Employee employee = typingEmployee();
    insert(heap, employee); 
}

void deleteEmployee(minHeap* heap) {
    Employee employee = typingEmployee();
    deleteOneEmployee(heap, &employee);
}

void searchEmployee(minHeap* heap) {
    Employee employee = typingEmployee();
    int i = findOne(heap, &employee);
    printElement(heap, i);
}

int main() {

    Employee* employees = load_data();
    int size = 1000;

    minHeap* heap = init_MinHeap(5000);

    for (int i = 0; i < size; i++) {
        heap = insert(heap, employees[i]);
    }

    bool flag = true;
    int choice;

    while (flag) {
        showMenu();
        cout << "Ingrese una opcion: ";
        cin >> choice;

        switch(choice) {
            case 1: 
                insertEmployee(heap);
                break;
            case 2: 
                heapSort(heap);
                print_heap(heap);
                break;
            case 3: 
                deleteEmployee(heap);
                break;
            case 4:
                searchEmployee(heap);
                break;
            case 5: 
                flag = false;
                break;  
            default:
             cout << "Opcion invalida por favor intentalo de nuevo" << endl;

        }
    }

    deleteHeap(heap); 
    return 0;
}
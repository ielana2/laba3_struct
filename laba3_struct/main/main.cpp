#include <iostream>
#include <iterator>
#include "Heap.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Heap* test;
    test = new Heap();

    int* test_array = new int[5];

    Iterator* test_bft;
    Iterator* test_dft;
    test_bft = new Heap::bft(test_array, 5);
    test_dft = new Heap::dft(test_array, 5);

    cout << "Куча" << endl;
    for (int i = 0; i < 5; i++) {
        test_array[i] = 5 - i;
        cout << test_array[i] << " ";
    }

    cout << endl << "Обход в ширину" << endl;
    for (int i=0; i<5; i++)
        cout << test_bft->next() << endl;

    cout << endl << "Обход в глубину" << endl;

    for (int i = 0; i < 5; i++)
        cout << test_dft->next() << endl;

    cout << endl;

    test->Insert(4);
    test->Insert(5);
    test->Insert(2);
    test->Insert(1);
    test->Insert(8);

    cout << "До и после удаления элемента" << endl;
    cout << test->Contains(8) << endl;
    test->Remove(8);
    cout << test->Contains(8) << endl;
}

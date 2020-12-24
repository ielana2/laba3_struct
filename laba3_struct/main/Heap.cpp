#include "Heap.h"
#include <iostream>
#include <iterator>
using namespace std;

Heap::Heap() { //constructor
	heap_array = new int[MAX_HEAP_SIZE]; //initialization of the array, where elements of the heap are going to be kept
	heap_size = 0;
	index = 0;
}

Heap::~Heap() { //destructor
	delete[]heap_array; //deleting the heap array
	heap_size = 0;
	index = 0;
}

void Heap::Heapify(int current) { //arranging array in the form of the heap
	int largest = current; //root is the max element

	int left = 2 * current + 1;
	int right = 2 * current + 2;

	if (left < heap_size && heap_array[left] > heap_array[largest]) //if left "kid" element is bigger than the root
		largest = left;

	if (right < heap_size && heap_array[right] > heap_array[largest]) //if right "kid" is bigger than the root
		largest = right;

	if (largest != current) //if the root is not the biggest element
	{
		swap(heap_array[current], heap_array[largest]);

		Heapify(largest); //recursion to make a heap from the part of the array with the largest element
	}
}
void Heap::ArrangeHeap(){
		for (int i = heap_size / 2 - 1; i >= 0; i--) //regroup of the array
			Heapify(i);

		for (int i = heap_size - 1; i >= 0; i--) //taking elements from the not grouped heap
		{
			swap(heap_array[0], heap_array[i]); //placing element in the end

			Heapify(0); //group smaller heap
		}
	}

int Heap::GetByIndex(int index) { //get the element from the heap by the array index
	return heap_array[index];
}

void Heap::Insert(int new_element) { //insert element to the heap
	if (heap_size == 0)
		heap_array[heap_size] = new_element;
	else {
		int current;
		current = heap_size;
		heap_array[current] = new_element; //element is inserted in the end of the heap

	}
	heap_size++;

	ArrangeHeap(); //so the heap is going to be sorted
}

bool Heap::RecContains(int current, int find_element) { //private function for containes to form recursion
	if (heap_array[current] == find_element) { //if the element has been found
		index = current;
		return true;
	}
	if (heap_array[current] < find_element) //if element is bigger than current element of the heap
		return false;
	//the element hasn't been found, so the recursion will try to find it in smaller elements
	RecContains(2 * current + 1, find_element); //in the left side
	RecContains(2 * current + 2, find_element); //in the right side
}

bool Heap::Contains(int find_element) {//to checl if there id the needed element
	int current = 0;
	return RecContains(current, find_element);//recursion
}

void Heap::Remove(int delete_element) {//to remove element of the heap
	int current = 0;
	if (Contains(delete_element) == true) {
		heap_array[index] = heap_array[heap_size - 1];
		heap_size--;
		ArrangeHeap();
	}
	index = 0;
	return;
}

Iterator* Heap::create_dft_iterator() //making iterator dft object
{
	return new dft(heap_array, heap_size);
}

Iterator* Heap::create_bft_iterator() //making iterator bft object
{
	return new bft(heap_array, heap_size);
}

bool Heap::dft::has_next() { //dft checking of the next element
	int tmp = itter_position;
	if (tmp + 1 >= size)
		return false;
	else
		return true;
}

int Heap::dft::next() { //dft returning next
	//this functions always tries to go to the left side
	if (itter_position == -2) {//there is no next element
		itter_position = 0;
		throw "Out of range";
	}
	int current = itter_position;

	if (2 * current + 1 < size) { //the element has an element under him
		itter_position = 2 * current + 1; //the index of the next element
		return heap_data[current];
	}
	if (current % 2 != 0 && current+1 < size) { //the element does't have under elements, but it has am element in the right (and they have one "parent")
		itter_position++;
		return heap_data[current];
	}
	else {
		int parent_position = itter_position;
		while (((parent_position - 1) / 2) % 2 != 0 && (parent_position - 1) / 2 != 0) { //the element doesn't have "kids" or "brothers", so it's needed to go up, until there will be found an element with a "brother" or the zero
			parent_position = (parent_position - 1) / 2;
		}
		if (parent_position == 0) { //the root of the heap, so all elements are passed
			itter_position = -2;
			return heap_data[current];
		}
		else { //found a "brother"
			itter_position=++parent_position;
			return heap_data[current];
		}
	}
}

bool Heap::bft::has_next() { //bft has next
	int tmp = itter_position;
	if (tmp  >= size)
		return false;
	else
		return true;
}

int Heap::bft::next() { //bft next
	if (itter_position + 1 <= size)
		return heap_data[itter_position++];
	else {
		itter_position = 0;
		throw "Out of range";
	}
}
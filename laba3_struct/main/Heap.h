#pragma once

class Iterator
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};

class Heap {
	static const int MAX_HEAP_SIZE = 100; // maximum size of the heap
	int* heap_array;         // pointer to heap array
	int heap_size; // size of the heap
	int index; //index of the chosen element of the heap

	bool RecContains(int current, int find_element);
	void Heapify(int);
public:
	Heap();  // heap constructor
	~Heap(); //heap destructor
	void Insert(int);  // adding element to heap by value
	bool Contains(int); //finding the element in the heap by the value
	void Remove(int);  // delete the element of the heap by the value
	Iterator* create_dft_iterator();
	Iterator* create_bft_iterator();

	void ArrangeHeap(); //arranging elements in the form of the heap
	int GetByIndex(int);// get the heap element by array index


	class dft : public Iterator { //class for dft iterator
	public:
		dft(int* heap, int heap_size) {
			heap_data = heap;
			itter_position = 0;
			size = heap_size;
		};
		int next() override;
		bool has_next() override;

	private:
		int* heap_data;
		int itter_position;
		int size;
	};

	class bft : public Iterator { //class for bft iterator
	public:
		bft(int* heap, int heap_size) {
			heap_data = heap;
			itter_position = 0;
			size = heap_size;
		};
		int next() override;
		bool has_next() override;

	private:
		int* heap_data;
		int itter_position;
		int size;
	};
};


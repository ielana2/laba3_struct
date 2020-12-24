#include "pch.h"
#include "CppUnitTest.h"
#include "../main/Heap.h"
#include "../main/Heap.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		Heap* Test_heap;
		Iterator* test_dft;
		Iterator* test_bft;
		int* test_array = new int[5];

		TEST_METHOD_INITIALIZE(setUp) //inizialization list's test
		{
			Test_heap = new Heap();
			test_dft = new Heap::dft(test_array, 5);
			test_bft = new Heap::bft(test_array, 5);

		}

		TEST_METHOD_CLEANUP(cleanUp) //deleting list's test
		{
			delete Test_heap;
		}
		
		TEST_METHOD(contains) //contains testiong
		{
			Test_heap->Insert(4);

			Assert::AreEqual(Test_heap->Contains(4), true);
		}

		TEST_METHOD(get_by_index)//getting by index testing
		{
			Test_heap->Insert(4);

			Assert::AreEqual(Test_heap->GetByIndex(0), 4);
		}

		TEST_METHOD(insert) {//insert testing
			Test_heap->Insert(4);
			Test_heap->Insert(2);
			Test_heap->Insert(1);

			Assert::AreEqual(Test_heap->GetByIndex(2), 1);
		}

		TEST_METHOD(arrange_heap) { //arrange testing
			Test_heap->Insert(4);
			Test_heap->Insert(5);
			Test_heap->Insert(2);
			Test_heap->Insert(1);
			Test_heap->Insert(8);
			Test_heap->ArrangeHeap();

			Assert::AreEqual(Test_heap->GetByIndex(0), 8);
			Assert::AreEqual(Test_heap->GetByIndex(3), 1);
		}

		TEST_METHOD(remove) { //remove testiong
			Test_heap->Insert(4);
			Test_heap->Insert(5);
			Test_heap->Insert(2);
			Test_heap->Insert(1);
			Test_heap->Insert(8);

			Assert::AreEqual(Test_heap->Contains(8), true);

			Test_heap->Remove(8);

			Assert::AreEqual(Test_heap->Contains(8), false);
		}

		TEST_METHOD(iterator_next_dft) { //dft next checking
			for (int i = 0; i < 5; i++) {
				test_array[i] = 5 - i;
			}

			test_dft->next();

			Assert::AreEqual(test_dft->next(), 4);

			try { //catching out of range
				test_dft->next();
				test_dft->next();
				test_dft->next();
			}
			catch (const char* error) {
				Assert::AreEqual(error, "Out of range");
			}
		}

		TEST_METHOD(iterator_has_next_dft) { //dft has next checking
			for (int i = 0; i < 5; i++) {
				test_array[i] = 5 - i;
			}

			Assert::AreEqual(test_dft->has_next(), true);
		}

		TEST_METHOD(iterator_next_bft) { //bft next checking
			for (int i = 0; i < 5; i++) {
				test_array[i] = 5 - i;
			}

			test_bft->next();

			Assert::AreEqual(test_bft->next(), 4);

			try { //catching out of range
				test_bft->next();
				test_bft->next();
				test_bft->next();
			}
			catch (const char* error) {
				Assert::AreEqual(error, "Out of range");
			}
			
		}

		TEST_METHOD(iterator_has_next_bft) { //bft has next checking
			for (int i = 0; i < 5; i++) {
				test_array[i] = 5 - i;
			}

			Assert::AreEqual(test_bft->has_next(), true);
		}
	};
}

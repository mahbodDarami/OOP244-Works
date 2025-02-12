
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
class Intlist {

	int* m_data;
	size_t m_size;

public:

	IntList() {
		m_data = nullptr;
		m_size = 0;
	}
	IntList(size_t size) {
		m_data = new int[size];
		m_size = size;
	}
	~IntList() {
		delete[] m_data;
		m_data = nullptr;
	}
	
	void resize(size_t newSize) {
		int* temper = new int[newSize];
		memcpy(temper, m_data, newSize * sizeof(int));
		delete m_data;
		m_data = temper;
	}
	void set(size_t index, int value) {
		m_data[index] = value;
	}
	int get(size_t index) const {
		return m_data[index];

	}
	size_t size() const {
		return m_size;
	}
};
int main() {
	/*Problem 1: Dynamic Integer List
		Create a class IntList that stores a list of integers dynamically.

		The class should allocate memory dynamically.
		It should support resizing when needed.
		It must have a constructor, destructor, and methods to add and retrieve elements.
		📌 Requirements
		Data Members(private) :

		int* m_data; → Pointer to store the list dynamically.
		size_t m_size; → Stores the current size of the list.
		Constructor& Destructor(public) :

		IntList(size_t size); → Constructor that initializes the list with a given size.
		~IntList(); → Destructor to release memory.
		Methods(public) :

		void resize(size_t newSize); → Resize the list dynamically.
		void set(size_t index, int value); → Set a value at a given index.
		int get(size_t index) const; → Get a value from a given index.
		size_t size() const; → Return the current size of the list.*/
	return 0;
}
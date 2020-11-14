#pragma once
class Array
{
private:

	int mLength;
	int* mArr;
	int mSize;

	//size is total allocated space
	//length is number of valid elements

	void swap(int& a, int& b);

	//Resize array if length >= size
	void resize();

public:
	Array(int a[], int size, int len);

	const int length();
	const int size();

	void insert(int index, int value);

	void append(int value);

	int remove(int index);

	int linear_search(int value);

	int binary_search(int low, int high, int value);

	void selectionSort();

	const int get(int index);

	int set(int index, int value);

	int max();

	int min();

	int sum();

	int rsum(int n);

	float average();

	void reverse();

	void left_shift();

	void right_shift();

	void insert_sorted(int value);

	bool is_sorted();

	void seperate_negative();

	Array merge_sorted(int a[], int size, int length);

	//Combine two arrays, only copy single instance of arrays
	Array _union(int a[], int size, int length);	//O(n^2)

	//Combine two arrays, only copy duplicate instances
	Array intersection(int a[], int size, int length); //O(n)

	//all elements in array A, not in array B (A-B)
	Array difference(int a[], int size, int length);

	void print();

	~Array();
};


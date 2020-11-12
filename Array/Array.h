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

	int linearSearch(int value);

	int binarySearch(int low, int high, int value);

	const int get(int index);

	int set(int index, int value);

	int max();

	int min();

	int sum();

	int rsum(int n);

	float average();

	void reverse();

	void print();

	~Array();
};


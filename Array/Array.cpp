#include "Array.h"
#include <iostream>

Array::Array(int a[], int size, int len) : mLength(len), mSize(size)
{
	mArr = new int[size];

	for (int i = 0; i < len; i++)
	{
		mArr[i] = a[i];

	}
}

void Array::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Array::resize()
{
	if (mSize == mLength)
	{
		mSize *= 2;

		int* arr = new int[mSize];


		for (int i = 0; i < mLength; i++)
		{
			arr[i] = mArr[i];
		}

		delete[] mArr;
		mArr = arr;
		arr = nullptr;

	}
}

const int Array::length()
{
	return mLength;
}

const int Array::size()
{
	return mSize;
}


void Array::insert(int index, int value)	//O(n)
{

	if (index >= 0 && index <= mLength)
	{
		resize();

		for (int i = mLength; i > index; i--)
		{
			mArr[i] = mArr[i - 1];
		}

		mArr[index] = value;
		mLength++;
	}

}

void Array::append(int value) //O(1)
{
	if (mLength < mSize)
	{
		mArr[mLength++] = value;
	}
	else
	{
		resize();
		mArr[mLength++] = value;
	}
}

int Array::remove(int index)	//O(n)
{
	if (index >= 0 && index < mLength)
	{
		int x = mArr[index];

		for (int i = index; i < mLength - 1; i++)
		{
			mArr[i] = mArr[i + 1];
		}

		mLength--;
		return x;
	}

	return 0;
}

int Array::linear_search(int value)	//O(n)
{
	for (int i = 0; i < mLength; i++)
	{
		if (mArr[i] == value)
		{
			//swap(mArr[i], mArr[0]); swaps key index with first
			//swap(mArr[i], mArr[i - 1]); swaps key index with previous index
			return i;
		}
	}

	return -1;
}

int Array::binary_search(int low, int high, int value)	//O(logn)
{
	/*iterative
	int mid = (low + high) / 2;

	while (low <= high)
	{
		if (value == mArr[mid])
			return mid;
		else if (value < mArr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
	*/

	if (!is_sorted())
		return -1;

	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (value == mArr[mid])
		return mid;
	else if (value < mArr[mid])
		return binary_search(low, mid - 1, value);
	else
		return binary_search(mid + 1, high, value);
}

void Array::selectionSort()
{
	int min;

	for (int i = 0; i < mLength - 1; i++)
	{
		min = i;

		for (int j = i + 1; j < mLength; j++)
		{
			if (mArr[j] < mArr[min])
				min = j;
		}

		swap(mArr[i], mArr[min]);
	}
}

const int Array::get(int index)	//O(1)
{
	if (index >= 0 && index < mLength)
		return mArr[index];

	return -1;
}

int Array::set(int index, int value)	//O(1)
{
	if (index >= 0 && index < mLength)
		mArr[index] = value;

	return -1;
}

int Array::max()	//O(n)
{
	int max = mArr[0];

	for (int i = 1; i < mLength; i++)
	{
		if (mArr[i] > max)
		{
			max = mArr[i];
		}
	}

	return max;
}

int Array::min()	//O(n)
{
	int min = mArr[0];

	for (int i = 0; i < mLength; i++)
	{
		if (mArr[i] < min)
		{
			min = mArr[i];
		}
	}

	return min;
}

int Array::sum()	//O(n)
{
	int total = 0;

	for (int i = 0; i < mLength; i++)
	{
		total += mArr[i];
	}

	return total;
}

int Array::rsum(int n)	//O(n)
{
	if (n < 0)
		return 0;

	return rsum(n - 1) + mArr[n];

}

float Array::average() //O(n)
{
	return (float)sum() / 2.f;
}

void Array::reverse()
{
	/*
	int* temp = new int[mLength];

	//reverse copy elements from arr into temp
	for (int i = mLength - 1, int j = 0; i >= 0; i++, j++)
	{
		temp[j] = mArr[i];
	}

	//copy elements from temp into array
	for (int i = 0; i < mLength; i++)
	{
		mArr[i] = temp[i];
	}
	*/

	//Swap elements from head and end of array. Increment head, decrement end
	for (int i = 0, j = mLength - 1; i < j; i++, j--)
	{
		swap(mArr[i], mArr[j]);
	}
}

void Array::left_shift()
{
	int temp = mArr[0];
	for (int i = 0; i < mLength; i++)
	{
		mArr[i] = mArr[i + 1];
	}

	mArr[mLength - 1] = temp;
}

void Array::right_shift()
{
	int temp = mArr[mLength - 1];
	for (int i = mLength - 2; i >= 0; i--)
	{
		mArr[i + 1] = mArr[i];
	}

	mArr[0] = temp;
}

void Array::insert_sorted(int value)
{
	if (!is_sorted())
		return;

	int i = mLength - 1;

	resize();

	while (mArr[i] > value)
	{
		mArr[i + 1] = mArr[i];
		i--;
	}

	mArr[i + 1] = value;

	mLength++;

}

bool Array::is_sorted()	//O(n)
{
	for (int i = 0; i < mLength - 1; i++)
	{
		if (mArr[i] > mArr[i + 1])
			return false;
	}

	return true;
}

void Array::seperate_negative() //O(n), scanning array once
{
	int i = 0, j = mLength - 1;

	while (i < j)
	{
		while (mArr[i] < 0) { i++; }
		while (mArr[j] >= 0) { j--; }

		if (i < j)
			swap(mArr[i], mArr[j]);
	}
}

Array Array::merge_sorted(int a[],int size, int length)
{


	int i = 0, j = 0, k = 0;

	Array arr(a, size, length);

	if (!is_sorted())
		this->selectionSort();

	if (!arr.is_sorted())
		arr.selectionSort();

	int* temp = new int[mSize + arr.mSize];

	while (i < mLength && j < arr.mLength)
	{
		if (mArr[i] < arr.get(j))
			temp[k++] = mArr[i++];
		else
			temp[k++] = arr.get(j++);
	}

	for (; i < mLength; i++)
		temp[k++] = mArr[i];

	for (; j < arr.mLength; j++)
		temp[k++] = arr.get(j);

	return Array(temp, mSize + arr.mSize, mLength + arr.mLength);
}

Array Array::_union(int a[], int size, int length)
{
	int i = 0, j = 0, k = 0;

	Array arr(a, size, length);

	int* temp = new int[mSize + arr.mSize];

	if (!is_sorted())
		this->selectionSort();

	if (!arr.is_sorted())
		arr.selectionSort();

	while (i < mLength && j < arr.mLength)
	{

		if (mArr[i] < arr.get(j))
		{
			temp[k++] = mArr[i++];
		}
		else if (arr.get(j) == mArr[i])
		{
			temp[k++] = mArr[i++];
			j++;
		}
		else
		{
			temp[k++] = arr.get(j++);
		}
	}

	for (; i < mLength; i++)
	{
		temp[k++] = mArr[i];
	}
		
	for (; j < arr.mLength; j++)
	{
		temp[k++] = arr.get(j);
	}
		
	return Array(temp, k * 2, k);
}

Array Array::intersection(int a[], int size, int length)
{
	int i = 0, j = 0, k = 0;

	Array arr(a, size, length);

	int* temp = new int[mSize + arr.mSize];

	if (!is_sorted())
		this->selectionSort();

	if (!arr.is_sorted())
		arr.selectionSort();

	while (i < mLength && j < arr.mLength)
	{

		if (mArr[i] < arr.get(j))
		{
			i++;
		}
		else if (arr.get(j) == mArr[i])
		{
			temp[k++] = mArr[i++];
			j++;
		}
		else
		{
			j++;
		}
	}

	return Array(temp, k * 2, k);
}

Array Array::difference(int a[], int size, int length)
{
	int i = 0, j = 0, k = 0;

	Array arr(a, size, length);

	if (!is_sorted())
		this->selectionSort();

	if (!arr.is_sorted())
		arr.selectionSort();

	int* temp = new int[mSize + arr.mSize];


	while (i < mLength && j < arr.mLength)
	{
		if (mArr[i] < arr.get(j))
		{
			temp[k++] = mArr[i++];
		}
		else if (mArr[i] == arr.get(j))
		{
			i++;
			j++;
		}
		else
		{
			j++;
		}

	}

	for (; i < mLength; i++)
	{
		temp[k++] = mArr[i];
	}

	return Array(temp, k * 2, k);
}

void Array::print()
{
	for (int i = 0; i < mLength; i++)
	{
		std::cout << mArr[i] << " ";
	}

	std::cout << std::endl;
}

Array::~Array()
{
	delete[] mArr;
}
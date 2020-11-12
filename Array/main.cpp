#include <iostream>

class Array
{
	int mLength;
	int* mArr;
	int mSize;
	//size is total allocated space
	//length is number of valid elements

	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

public:
	Array(int a[], int size, int len) : mLength(len), mSize(size)
	{
		mArr = new int[size];

		for (int i = 0; i < len; i++)
		{
			mArr[i] = a[i];

		}
	}

	const int length()
	{
		return mLength;
	}


	void insert(int index, int value)	//O(n)
	{
		if (index >= 0 && index <= mLength)
		{
			for (int i = mLength; i > index; i--)
			{
				mArr[i] = mArr[i - 1];
			}

			mArr[index] = value;
			mLength++;
		}

	}

	void append(int value) //O(1)
	{
		if (mLength < mSize)
			mArr[mLength++] = value;
	}

	int remove(int index)	//O(n)
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

	int linearSearch(int value)	//O(n)
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

	int binarySearch(int low, int high, int value)	//O(logn)
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

		if (low > high)
			return -1;

		int mid = (low + high) / 2;

		if (value == mArr[mid])
			return mid;
		else if (value < mArr[mid])
			return binarySearch(low, mid - 1, value);
		else
			return binarySearch(mid + 1, high, value);
	}

	const int get(int index)	//O(1)
	{
		if (index >= 0 && index < mLength)
			return mArr[index];

		return -1;
	}

	int set(int index, int value)	//O(1)
	{
		if (index >= 0 && index < mLength)
			mArr[index] = value;

		return -1;
	}

	int max()	//O(n)
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

	int min()	//O(n)
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

	int sum()	//O(n)
	{
		int total = 0;

		for (int i = 0; i < mLength; i++)
		{
			total += mArr[i];
		}

		return total;
	}

	int rsum(int n)	//O(n)
	{
		if (n < 0)
			return 0;

		return rsum(n - 1) + mArr[n];

	}

	float average() //O(n)
	{
		return (float)sum() / 2.f;
	}



	void print()
	{
		for (int i = 0; i < mLength; i++)
		{
			std::cout << mArr[i] << " ";
		}

		std::cout << std::endl;
	}

	~Array()
	{
		delete[] mArr;
	}

};

int main()
{
	int a[] = { 1, 2, 5, 4, 0, 6, 2, 8 };

	int len = sizeof(a) / sizeof(a[0]);

	Array arr(a, len * 2, len);

	//arr.insert(2, 5);
	//arr.remove(1);
	//arr.append(7);

	std::cout << arr.average();

	//std::cout << arr.contains(7);

	//arr.print();



	return 0;
}
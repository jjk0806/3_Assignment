#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class SimpleVector
{
public:
	SimpleVector() : currentCapacity(10), currentSize(0)
	{ 
		data = new T[10];
	}

	SimpleVector(const int& capacity) : currentCapacity(capacity), currentSize(0)
	{
		data = new T[capacity];
	}

	SimpleVector(const SimpleVector& vec)
	{
		currentCapacity = vec.currentCapacity;
		currentSize = vec.currentSize;

		data = new T[currentCapacity];

		for (int i = 0; i < currentSize; i++)		
			data[i] = vec.data[i];
	}

	int size()
	{
		return currentSize;
	}

	int capacity()
	{
		return currentCapacity;
	}

	void push_back(const T& t)
	{
		if (currentSize < currentCapacity)
		{
			data[currentSize] = t;
			currentSize++;		
		}
		else
		{
			T* temp = new T[currentCapacity + 5];

			for (int i = 0; i < currentCapacity; i++)			
				temp[i] = data[i];

			temp[currentCapacity] = t;
			currentSize++;
			currentCapacity += 5;

			delete[] data;
			data = temp;
		}
	}

	void pop_back()
	{
		if (currentSize == 0)
			return;

		currentSize--;
	}

	void resize(const int& size)
	{
		if (size < currentCapacity)
		{
			cout << "현재 배열 크기보다 작습니다 return" << endl;
			return;
		}		

		T* temp = new T[size];

		for (int i = 0; i < currentCapacity; i++)
			temp[i] = data[i];

		currentCapacity = size;

		delete[] data;
		data = temp;
	}

	void sortData(const bool& greater)
	{
		for (int i = 0; i < currentSize - 1; i++)
		{
			int number = i;

			for (int j = i + 1; j < currentSize; j++)
			{
				if (greater == false ? data[number] > data[j] : data[number] < data[j])
					number = j;
			}

			T temp = data[number];
			data[number] = data[i];
			data[i] = temp;
		}
	}

	void Print()
	{
		for (int i = 0; i < currentSize; i++)
			cout << data[i] << " ";

		cout << endl;
		cout << "원소 갯수 : " << currentSize << endl;
		cout << "배열 크기 : " << currentCapacity << endl;
	}

	~SimpleVector()
	{
		delete[] data;
		cout << "소멸자 호출" << endl;
	}

	T& operator [] (const int& index)
	{
		if (index > currentSize)
		{
			cout << "배열 범위 초과" << endl;
			std::terminate();
		}

		return data[index];
	}

private:
	T* data;
	int currentSize;
	int currentCapacity;
};

int main()
{
	SimpleVector<int> vec_int(10);
	
	for (int i = 0; i < vec_int.capacity(); i++)
		vec_int.push_back(i);

	vec_int.Print(); // 현재 원소 출력

	vec_int.push_back(44); // 배열 크기 꽉 찬 상태에서 원소 추가 - 배열 크기 + 5
	vec_int.Print();

	vec_int.resize(3); // 인자가 배열의 크기보다 작으면 return
	vec_int.resize(17);
	vec_int.Print(); // 배열의 원소는 그대로, 배열 크기 증가

	vec_int.pop_back(); // 가장 뒤의 배열 원소 제거
	vec_int.pop_back();
	vec_int.Print();

	vec_int.push_back(28);
	vec_int.push_back(3);
	vec_int.push_back(0);
	vec_int.Print(); // 정렬 테스트

	bool greater = true;
	vec_int.sortData(greater); // 배열 정렬 - 선택 정렬로 구현
	vec_int.Print(); // bool이 true일 때 내림차순 false일 때 오름차순
	vec_int.sortData(!greater);
	vec_int.Print();

	return 0;
}
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
			cout << "���� �迭 ũ�⺸�� �۽��ϴ� return" << endl;
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
		cout << "���� ���� : " << currentSize << endl;
		cout << "�迭 ũ�� : " << currentCapacity << endl;
	}

	~SimpleVector()
	{
		delete[] data;
		cout << "�Ҹ��� ȣ��" << endl;
	}

	T& operator [] (const int& index)
	{
		if (index > currentSize)
		{
			cout << "�迭 ���� �ʰ�" << endl;
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

	vec_int.Print(); // ���� ���� ���

	vec_int.push_back(44); // �迭 ũ�� �� �� ���¿��� ���� �߰� - �迭 ũ�� + 5
	vec_int.Print();

	vec_int.resize(3); // ���ڰ� �迭�� ũ�⺸�� ������ return
	vec_int.resize(17);
	vec_int.Print(); // �迭�� ���Ҵ� �״��, �迭 ũ�� ����

	vec_int.pop_back(); // ���� ���� �迭 ���� ����
	vec_int.pop_back();
	vec_int.Print();

	vec_int.push_back(28);
	vec_int.push_back(3);
	vec_int.push_back(0);
	vec_int.Print(); // ���� �׽�Ʈ

	bool greater = true;
	vec_int.sortData(greater); // �迭 ���� - ���� ���ķ� ����
	vec_int.Print(); // bool�� true�� �� �������� false�� �� ��������
	vec_int.sortData(!greater);
	vec_int.Print();

	return 0;
}
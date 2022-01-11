#include <iostream>
#include <cstring>

template <class T, int size> // size является non-type параметром шаблона
class StaticArray_Base
{
protected:
	// Параметр size отвечает за длину массива
	T m_array[size];
 
public:
	T* getArray() { return m_array; }
 
	T& operator[](int index)
	{
		return m_array[index];
	}
	virtual void print()
	{
		for (int i = 0; i < size; i++)
			std::cout << m_array[i] << ' ';
		std::cout << "\n";
	}
};
 
template <class T, int size> // size является non-type параметром шаблона
class StaticArray: public StaticArray_Base<T, size>
{
public:
	StaticArray()
	{
 
	}
};
 
template <int size> // size является non-type параметром шаблона
class StaticArray<double, size>: public StaticArray_Base<double, size>
{
public:
 
	virtual void print() override
	{
		for (int i = 0; i < size; i++)
			std::cout << std::scientific << this->m_array[i] << " ";
// Примечание: Префикс this-> на вышеприведенной строке необходим. Почему? Читайте здесь - https://stackoverflow.com/a/6592617
		std::cout << "\n";
	}
};
 
int main()
{
	// Объявляем целочисленный массив длиной 5
	StaticArray<int, 5> intArray;
 
	// Заполняем его, а затем выводим
	for (int count = 0; count < 5; ++count)
		intArray[count] = count;
	intArray.print();
	
	// Объявляем массив типа double длиной 4
	StaticArray<double, 4> doubleArray;
 
	// Заполняем его, а затем выводим
	for (int count = 0; count < 4; ++count)
		doubleArray[count] = (4. + 0.1*count);
	doubleArray.print();
 
	return 0;
}
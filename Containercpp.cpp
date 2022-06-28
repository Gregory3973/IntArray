#include "Container.h"
#include <iostream>

IntArray::IntArray() = default;

int& IntArray::operator [] (int index)
{
	if (index < 0 && index > _length)
	{
		throw "Bad_range";
	}
	int &i = _data[index];
		
	return i;
}

IntArray::IntArray(int length) : _length(length)
{
	_data = new int[length];
}


ostream& operator<< (ostream& output, const IntArray& arr)
{
	return output;
}

void IntArray::arrase()
{
	delete [] _data;
	_data = nullptr;
	_length = 0;
}

void IntArray::reallocate(int newLength)
{
	arrase();
	
	if (newLength <= 0)
	{
		return;
	}
		
	_data = new int[newLength];
	_length = newLength;
}

void IntArray::resize(int newLength)
{
	if (newLength == _length)
	{
		return;
	}
		
	if (newLength <= 0)
	{
		arrase();
		return;
	}

	int* data = new int[newLength] ;
	
	if (newLength > 0)
	{
		int u = (newLength > _length) ? _length : newLength;
		

		for (int index = 0 ; index < u; ++index)
		{
			if (index < 0 && index > _length)
				throw "bad range";
			data[index] = _data[index];
		}
			
	}
	delete[] _data;
	_data = data;
	_length = newLength;
}

void IntArray::insertBefore(int value, int index)
{
	
	int* data  = new int[_length + 1] ;

	for (int before = 0 ; before < index; ++before)
	{
		data[before] = _data[before];
	}
	data[index] = value;

	for (int after = index; after < _length; ++after)
	{
		data[after + 1] = _data[after];
	}		
	delete[] _data;
	_data = data;
	++_length;

}

void IntArray::remove(int index)
{
	
	if (_length == 1)
	{
		arrase();
		return;
	}

	int* data =  new int[_length - 1];

	for (int before = 0 ; before < index; ++before)
	{
		data[before] = _data[before];
	}
	
	for (int after = (index + 1) ; after < _length; ++after)
	{
		data[after - 1] = _data[after];
	}
		
	delete[] _data;
	_data = data;
	--_length;
}

void IntArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value)
{
	insertBefore(value, _length);
}

IntArray::~IntArray()
{
	delete[] _data;
}

int IntArray::getLength() const
{
	return _length;
}

#pragma once
#include <iostream>
using namespace std;

class IntArray
{
public:
	
	IntArray();
	IntArray(int lengh);
	int & operator [] (int index);
	friend ostream& operator<<(ostream& output, const IntArray& arr);
	~IntArray();

	void arrase();
	int getLength() const;
	
    void reallocate(int newLength);
    void resize(int newLength);
	void insertBefore(int value, int index);
	void remove(int index);

	void insertAtBeginning(int value);
	void insertAtEnd(int value);
	
private:
	int _length {};
	int *_data {};

};


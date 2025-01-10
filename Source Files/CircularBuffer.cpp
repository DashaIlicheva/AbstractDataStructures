#include "../Header Files/CircularBuffer.h"

CircularBuffer::CircularBuffer(int capacity)
{
	_capacity = capacity;
	_size = 0;
	_head = 0;
	_tail = 0;

	_buffer = new int[_capacity];
}

CircularBuffer::~CircularBuffer()
{
	delete[] _buffer;
}

int* CircularBuffer::Buffer()
{
	return _buffer;
}

int CircularBuffer::Capacity()
{
	return _capacity;
}

int CircularBuffer::FreeSpace()
{
	return _capacity - _size;
}

int CircularBuffer::OccupiedSpace()
{
	return _size;
}

void CircularBuffer::Insert(int value)
{
	if (_size == _capacity)
	{
		_head = (_head + 1) % _capacity;
	}
	else
	{
		_size++;
	}
	
	_buffer[_tail] = value;
	_tail = (_tail + 1) % _capacity;
}

int CircularBuffer::GetValue()
{
	if (_size == 0)
	{
		return -1;
	}

	int value = _buffer[_head];
	_head = (_head + 1) % _capacity;
	_size--;
	return value;
}

void CircularBuffer::Resize(int newSize) 
{
	int* newBuffer = new int[newSize];
	int elementsToCopy = (newSize < _size) ? newSize : _size;

	for (int i = 0; i < elementsToCopy; ++i) {
		newBuffer[i] = _buffer[(_tail + i) % _capacity];
	}

	delete[] _buffer;
	_buffer = newBuffer;
	_head = elementsToCopy;
	_tail = 0;
	_capacity = newSize;
	_size = elementsToCopy;
}

#include "../Header Files/QueueUsingCurcularBuffer.h"

QueueUsingCircularBuffer::QueueUsingCircularBuffer(int capacity)
{
	_buffer = new CircularBuffer(capacity);
}

QueueUsingCircularBuffer::~QueueUsingCircularBuffer()
{
	delete _buffer;
}

CircularBuffer* QueueUsingCircularBuffer::Buffer()
{
	return _buffer;
}

void QueueUsingCircularBuffer::Enqueue(int value)
{
	if (_buffer->OccupiedSpace() == _buffer->Capacity())
	{
		_buffer->Resize(_buffer->Capacity() * 2);
	}

	_buffer->Insert(value);
}

int QueueUsingCircularBuffer::Dequeue()
{
	
	return _buffer->GetValue();
}

int QueueUsingCircularBuffer::Size()
{
	return _buffer->OccupiedSpace();
}



#include "../Header Files/QueueUsingStack.h"

QueueUsingStack::~QueueUsingStack()
{
	_stack1.~Stack();
	_stack2.~Stack();
}

Stack QueueUsingStack::Stack1()
{
	return _stack1;
}

Stack QueueUsingStack::Stack2()
{
	return _stack2;
}

void QueueUsingStack::Enqueue(int value)
{
	_stack1.Push(value);
}

int QueueUsingStack::Dequeue()
{
	if (_stack2.IsEmpty())
	{
		while (!_stack1.IsEmpty())
		{
			_stack2.Push(_stack1.Pop());
		}
	}

	return _stack2.Pop();
}

bool QueueUsingStack::IsEmpty()
{
	return _stack1.IsEmpty() && _stack2.IsEmpty();
}

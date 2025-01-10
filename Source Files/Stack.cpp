#include "../Header Files/Stack.h"

Stack::Stack()
{
	_top = nullptr;
}

Stack::~Stack()
{
	StackComponent* current = _top;
	while (current != nullptr)
	{
		StackComponent* next = current->Next;
		delete current;
		current = next;
	}
}

StackComponent* Stack::Top()
{
	return _top;
}

void Stack::Push(int value)
{
	StackComponent* newElement = new StackComponent(value);
	newElement->Next = _top;
	_top = newElement;
}

int Stack::Pop()
{
	if (_top == nullptr)
	{
		return -1;
	}

	StackComponent* temp = _top;
	int poppedValue = _top->Value;
	_top = _top->Next;
	delete temp;

	return poppedValue;
}

bool Stack::IsEmpty()
{
	return _top == nullptr;
}

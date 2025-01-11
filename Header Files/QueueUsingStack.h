#pragma once
#include "../Header Files/Stack.h"

// TODO: Полетела кодировка
//! \brief ��������� ������� �� ���� ���� ������.
struct QueueUsingStack
{
private:
	// TODO: Использовать указатели
	//! \brief ����1.
	Stack _stack1;

	//! \brief ����2.
	Stack _stack2;

public:

	//! \brief ���������� �������.
	~QueueUsingStack();

	// ��������� �����1
	Stack Stack1();

	// ��������� �����2
	Stack Stack2();

	//! \brief ���������� �������� � �������.
	//! \param value �������� ������ ��������.
	void Enqueue(int value);

	//! \brief ���������� �������� �� �������.
	int Dequeue();

	//! \brief �������� ������� �� �������.
	bool IsEmpty();
};

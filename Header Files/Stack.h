#pragma once
#include "../Header Files/StackComponent.h"

// TODO: Полетела кодировка
//! \brief ��������� �����.
//! \param value �������� �������� �����.
struct Stack
{
private:

	//! \brief ��������� ����������� ������� �����.
	StackComponent* _top;

public:

	//! \brief ����������� �����.
	Stack();

	//! \brief ���������� �����.
	~Stack();

	//! \brief �������� Top.
	StackComponent* Top();

	//! \brief ������� ��������� � ����.
	void Push(int value);

	//! \brief ������� ���������� �� �����.
	int Pop();

	//! \brief �������� ����� �� �������.
	bool IsEmpty();
};

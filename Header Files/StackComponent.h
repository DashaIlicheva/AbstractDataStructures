#pragma once

//! \brief ��������� �������� �����.
//! \param value �������� �������� �����.
struct StackComponent
{
	//! \brief �������� �������� �����.
	int Value;

	//! \brief ����������� �� ��������� ������� �����.
	StackComponent* Next;

	//! \brief ����������� ���������.
	StackComponent(int value);
};

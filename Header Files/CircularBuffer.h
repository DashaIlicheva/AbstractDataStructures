#pragma once
// TODO: Полетела кодировка
//! \brief ��������� ���������� ������.
//! \param capacity ����������� ���������� ������.
//! \param value �������� �������� �����.
struct CircularBuffer
{
private:

	//! \brief ������ ���������� ������.
	int* _buffer;

	//! \brief ����������� ���������� ������.
	int _capacity;

	//! \brief ������ ���������� ������.
	int _size;

	//! \brief ������ ������ ���������� ������.
	int _head;

	//! \brief ������ ������ ���������� ������.
	int _tail;

public:

	//! \brief ����������� ���������� ������.
	CircularBuffer(int capacity);

	//! \brief ���������� ���������� ������.
	~CircularBuffer();

	// ��������� �������
	int* Buffer();

	//! \brief �������� ����������� ���������� ������.
	int Capacity();

	//! \brief ��������� ���������� ����� � ��������� ������.
	int FreeSpace();

	//! \brief ��������� �������� ����� � ��������� ������.
	int OccupiedSpace();

	//! \brief ���������� ������ �������� � ��������� �����.
	void Insert(int value);

	//! \brief ��������� �������� �� ���������� ������.
	int GetValue();

	//! \brief ���������� ����������� ���������� ������.
	void Resize(int newSize);
};

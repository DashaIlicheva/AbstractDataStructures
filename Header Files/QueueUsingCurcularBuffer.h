#pragma once
#include "../Header Files/CircularBuffer.h"

// TODO: Полетела кодировка
//! \brief ��������� ������� �� ���� ���������� ������.
struct QueueUsingCircularBuffer 
{
private:

    //! \brief ��������� �����.
    CircularBuffer* _buffer;

public:

    // ��������� �������
    CircularBuffer* Buffer();

    //! \brief ����������� �������.
    //! \param capacity ����������� �������.
    QueueUsingCircularBuffer(int capacity);

    //! \brief ���������� �������.
    ~QueueUsingCircularBuffer();

    //! \brief ���������� �������� � �������.
    //! \param value �������� ������ ��������.
    void Enqueue(int value);

    //! \brief ���������� �������� �� �������.
    int Dequeue();

    //! \brief ������ �������.
    int Size();
};

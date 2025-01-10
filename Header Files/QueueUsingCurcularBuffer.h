#pragma once
#include "../Header Files/CircularBuffer.h"

//! \brief Структура очереди на базе кольцевого буфера.
struct QueueUsingCircularBuffer 
{
private:

    //! \brief Кольцевой буфер.
    CircularBuffer* _buffer;

public:

    // Получение массива
    CircularBuffer* Buffer();

    //! \brief Конструктор очереди.
    //! \param capacity Вместимость очереди.
    QueueUsingCircularBuffer(int capacity);

    //! \brief Деструктор очереди.
    ~QueueUsingCircularBuffer();

    //! \brief Добавления элемента в очередь.
    //! \param value Значение нового элемента.
    void Enqueue(int value);

    //! \brief Извлечение элемента из очереди.
    int Dequeue();

    //! \brief Размер очереди.
    int Size();
};

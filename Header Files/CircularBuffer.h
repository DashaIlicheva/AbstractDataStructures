#pragma once

//! \brief Структура кольцевого буфера.
//! \param capacity вместимость кольцевого буфера.
//! \param value значение элемента стека.
struct CircularBuffer
{
private:

	//! \brief Массив кольцевого буфера.
	int* _buffer;

	//! \brief Вместимость кольцевого буфера.
	int _capacity;

	//! \brief Размер кольцевого буфера.
	int _size;

	//! \brief Индекс головы кольцевого буфера.
	int _head;

	//! \brief Индекс хвоста кольцевого буфера.
	int _tail;

public:

	//! \brief Конструктор кольцевого буфера.
	CircularBuffer(int capacity);

	//! \brief Деструктор кольцевого буфера.
	~CircularBuffer();

	// Получение массива
	int* Buffer();

	//! \brief Свойство вместимости кольцевого буфера.
	int Capacity();

	//! \brief Получение свободного места в кольцевом буфере.
	int FreeSpace();

	//! \brief Получение занятого места в кольцевом буфере.
	int OccupiedSpace();

	//! \brief Добавление нового элемента в кольцевой буфер.
	void Insert(int value);

	//! \brief Получение элемента из кольцевого буфера.
	int GetValue();

	//! \brief Изменнение вместимости кольцевого буфера.
	void Resize(int newSize);
};

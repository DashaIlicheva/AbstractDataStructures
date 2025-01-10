#pragma once
#include "../Header Files/Stack.h"

//! \brief Структура очереди на базе двух стеков.
struct QueueUsingStack
{
private:

	//! \brief Стек1.
	Stack _stack1;

	//! \brief Стек2.
	Stack _stack2;

public:

	//! \brief Деструктор очереди.
	~QueueUsingStack();

	// Получение стека1
	Stack Stack1();

	// Получение стеке2
	Stack Stack2();

	//! \brief Добавления элемента в очередь.
	//! \param value Значение нового элемента.
	void Enqueue(int value);

	//! \brief Извлечение элемента из очереди.
	int Dequeue();

	//! \brief Проверка очереди на пустоту.
	bool IsEmpty();
};

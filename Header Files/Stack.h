#pragma once
#include "../Header Files/StackComponent.h"

//! \brief Структура стека.
//! \param value значение элемента стека.
struct Stack
{
private:

	//! \brief Последний добавленный элемент стека.
	StackComponent* _top;

public:

	//! \brief Конструктор стека.
	Stack();

	//! \brief Деструктор стека.
	~Stack();

	//! \brief Свойство Top.
	StackComponent* Top();

	//! \brief Функция помещения в стек.
	void Push(int value);

	//! \brief Функция извлечения из стека.
	int Pop();

	//! \brief Проверка стека на пустоту.
	bool IsEmpty();
};

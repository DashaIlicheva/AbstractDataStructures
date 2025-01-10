#pragma once

//! \brief Структура элемента стека.
//! \param value значение элемента стека.
struct StackComponent
{
	//! \brief Значение элемента стека.
	int Value;

	//! \brief Указательна на следующий элемент стека.
	StackComponent* Next;

	//! \brief Конструктор структуры.
	StackComponent(int value);
};

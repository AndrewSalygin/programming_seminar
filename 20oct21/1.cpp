void cycle_in_letter_line(char &letter, bool &inc)
{
	// Рисуем клетки для обозначений игрового поля (Буквы)
	for (int x = 0; x < 10; ++x)
	{
		std::cout << VERTICAL_LINE;

		// Оставляем пустые клетки на углах
		if (x == 0 || x == 9)
		{
			std::cout << "   ";
			continue;
		}

		// Если буквы выводятся по алфавиту
		if (inc)
		{
			// Выводим буквенные обозначения
			std::cout << " " << g_letter_color << letter++ << g_un_letter_color 
			<< " " << "";
		}
		// Против
		else
		{
			// Выводим буквенные обозначения
			std::cout << " " << g_letter_color << letter-- << g_un_letter_color 
			<< " " << "";
		}
		
	}
	std::cout << VERTICAL_LINE;
}

void print_letter_line()
{
	// Для белых
	// Буква A
	char letter = 65;
	bool inc    = true;

	cycle_in_letter_line(letter, inc);

	// Оставляем пробел
	print_space();

	// Для чёрных
	// Буква H
	letter = 72;
	inc    = false;

	cycle_in_letter_line(letter, inc);

	std::cout << '\n';
}

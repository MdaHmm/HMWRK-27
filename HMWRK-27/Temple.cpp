#include <iostream>
#include <string>


struct movies {
	std::string title;
	int year;
	std::string genre;
	unsigned int duration;
	unsigned int price;
};

void show_movie(const movies& mov) {
	std::cout << "Название		   : " << mov.title << '\n';
	std::cout << "Год			   : " << mov.year << '\n';
	std::cout << "Жанр			   : " << mov.genre << '\n';
	std::cout << "Продолжительность: " << mov.duration << " мин\n";
	std::cout << "Цена			   : " << mov.price << " руб.\n\n";
}

movies expensive(movies& mov1, movies& mov2, movies& mov3) {
	unsigned int max_price = mov1.price;
	const movies* max = &mov1;
	if (mov2.price > max_price) {
		max_price = mov2.price;
		max = &mov2;
	}
	if (mov3.price > max_price) {
		max_price = mov3.price;
		max = &mov3;
	}
	return *max;
}

void update_info(movies& mov) {
	std::cout << "Выберите поле для редактирования:\n" << "1 - Название\n" << "2 - Год\n" << "3 - Жанр\n" << "4 - Продолжительность\n" << "5 - Цена\n" << "-> ";
	int field;
	std::cin >> field;
	switch (field) {
	case 1:
		std::cout << "Введите новое имя -> ";
		std::cin.ignore();
		std::getline(std::cin, mov.title);
		break;
	case 2:
		std::cout << "Введите новую дату -> ";
		std::cin >> mov.year;
		break;
	case 3:
		std::cout << "Введите новый жанр -> ";
		std::cin.ignore();
		std::getline(std::cin, mov.genre);
		break;
	case 4:
		std::cout << "Введите новую продолжительность в минутах -> ";
		std::cin >> mov.duration;
		break;
	case 5:
		std::cout << "Введите новую цену в рублях -> ";
		std::cin >> mov.price;
		break;
	default:
		std::cout << "\nПоле не найдено.\n\n";
		return;
	}
	std::cout << "\nИнформация обновлена.\n\n";
}



int main() {
	setlocale(LC_ALL(NULL), "Russian");

	int n,m;
	
	movies mov1{ "Властелин Колец: Братство кольца", 2001, "фентези", 178, 500 };
	movies mov2{ "Звездные войны: Возвращение Джедая", 1983, "фантастика", 131, 700 };
	movies mov3{ "Титаник", 1997, "мелодрама", 194, 850 };
	show_movie(mov1);
	show_movie(mov2);
	show_movie(mov3);


	std::cout << "Самая высокая цена = " << expensive(mov1, mov2, mov3).price << " рублей.\n\n";

	std::cout << "Хотите изменить данные? Да - 1, Нет - 2 ->";
	std::cin >> n;

	if (n == 1) {
		std::cout << "Выберите фильм (1 - 3) ->";
		std::cin >> m;
		if (m == 1) {
			update_info(mov1);
			show_movie(mov1);
			return 0;
		}
		if (m == 2) {
			update_info(mov2);
			show_movie(mov2);
			return 0;
		}
		if (m == 3) {
			update_info(mov3);
			show_movie(mov3);
			return 0;
		}
		else {
			std::cout << "Ошибка.";
			return 0;
		}
	}
	else{
		std::cout << "До свидания!";
		return 0;
	}
		


	return 0;
}

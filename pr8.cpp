
#include <iostream>

struct Order {
	int number;
	double total;
	bool completed;
};
struct Node {
	Order order;
	Node* next;
	Node* prev;

	Node(const Order& o) :order(o), next(nullptr), prev(nullptr) {}
};
class List {
private:
	Node* head;
	Node* tail;
	int size;
public:
	~List() {}
	
	void push_front(const Order& o)
	{
		Node* newN = new Node(o);
		if (!head) { head = tail = newN; }
		else {
			newN->next = head;
			head->prev = newN;
			head = newN;
		}
		size++;
	
	}

	void push_back(const Order& o) {
		Node* newN = new Node(o);
		if (!tail) { head = tail = newN; }
		else {
			newN->prev = tail;
			tail->next = newN;
			tail = newN;
		}
		size++;
	}

	void pop_front() {
		if (!head) {
			throw std::invalid_argument("Список пуст");
		}
		Node* temp = head;
		head = head->next;
		if (head)head->prev = nullptr;
		else tail = nullptr;
		delete head;
		size--;
	}

	void pop_back() {
		if (!head) {
			throw std::invalid_argument("Список пуст");
		}
		Node* temp = tail;
		tail = tail->prev;
		if (tail)tail->next = nullptr;
		else head = nullptr;
		delete tail;
		size--;
	}

	void display_forward() {
		if (!head) {
			throw std::invalid_argument("Список пуст");
		}
		Node* cur = head;
		while (cur) {
			std::cout << "Номер " << cur->order.number << std::endl;
			std::cout << "Цена " << cur->order.total << std::endl;
			if (cur->order.completed)
				std::cout << "Выполнен";
			else
				std::cout << "В доставке";
			cur = cur->next;

		}
	}
	void display_backward() {
		if (!head) {
			throw std::invalid_argument("Список пуст");
		}
		Node* cur = tail;
		while (cur) {
			std::cout << "Номер " << cur->order.number << std::endl;
			std::cout << "Цена " << cur->order.total << std::endl;
			if (cur->order.completed)
				std::cout << "Выполнен";
			else
				std::cout << "В доставке";
			cur = cur->prev;
		}
	}

	void find(int num) {
		if (!head) {
			throw std::invalid_argument("Список пуст");
		}
		Node* cur = head;
		bool find = false;
		while (find) {
			if (cur->order.number == num)
				find = true;
			else {
				cur = cur->next;
			}
			if (!cur) {
				throw std::invalid_argument("Элемент не найден");
			}

		}
		std::cout << "НАЙДЕНО\nНомер " << cur->order.number << std::endl;
		std::cout << "Цена " << cur->order.total << std::endl;
		if (cur->order.completed)
			std::cout << "Выполнен";
		else
			std::cout << "В доставке";
		
	}

	void findMax() {
		if (!head) {
			throw std::invalid_argument("Список пуст");
		}
		Node* max = head;
		Node* cur = head;
		while (cur) {
			if (!cur->order.completed && cur->order.total > max->order.total)
				max = cur;
			cur = cur->next;
		}
		std::cout << "Номер " << max->order.number << std::endl;
		std::cout << "Цена " << max->order.total << std::endl;
		if (max->order.completed)
			std::cout << "Выполнен";
		else
			std::cout << "В доставке";
	}

	void deleteOrd() {
		if (!head) {
			throw std::invalid_argument("Список пуст");
		}
		Node* cur = head;
		while (cur) {
			if (cur->order.completed)
			{
				cur = cur->next;
				if (cur)delete cur->prev;
				size--;
			}
		}
		std::cout << "Выполнено";
	}

	void insert(int num) {
		if (!head) {
			throw std::invalid_argument("Список пуст");
		}
		Node* cur = head;
		bool find = false;
		while (find) {
			if (cur->order.number == num)
				find = true;
			else {
				cur = cur->next;
			}
			if (!cur) {
				throw std::invalid_argument("Элемент не найден");
			}

		}
		push_front(cur->order);
		//разобраться как удалить текущее
		/*while (cur) {
			cur=cur->next;
			cur->next = nullptr;
			if (cur->next == tail) {
				cur = cur->next;
				tail = cur;
			}
		}*/
	}
};




int main()
{
	setlocale(LC_ALL, "Russian");
	int answ=0;
	List list[10];


	try {
		while (answ != 11) {
			std::cout << "1. Добавить элемент в начало" << std::endl;
			std::cout << "2. Добавить элемент в конец" << std::endl;
			std::cout << "3. Удалить первый элемент" << std::endl;
			std::cout << "4. Удалить последний элемент" << std::endl;
			std::cout << "5. Вывести список" << std::endl;
			std::cout << "6. Вывести список в обратном порядке" << std::endl;
			std::cout << "7. Найти элемент" << std::endl;
			std::cout << "8. Найти незавершённый заказ с максимальной стоимостью" << std::endl;
			std::cout << "9. Удалить все завершённые заказы" << std::endl;
			std::cout << "10. Переместить заказ с указанным номером в начало списка" << std::endl;
			std::cout << "11. Выход" << std::endl;
			std::cin >> answ;

			switch (answ) {
			case 1: {
				Order n;

				std::cout << "Введите номер\n";
				std::cin >> n.number;

				std::cout << "Введите цену\n";
				std::cin >> n.total;

				std::cout << "Введите статус(true/false)";
				std::string ans;
				std::cin >> ans;
				if (ans == "true") { n.completed = true; }
				else { n.completed = false; }

				//push_front(n);
			}
				  break;
			case 2: {
				Order n;

				std::cout << "Введите номер\n";
				std::cin >> n.number;

				std::cout << "Введите цену\n";
				std::cin >> n.total;

				std::cout << "Введите статус(true/false)";
				std::string ans;
				std::cin >> ans;
				if (ans == "true") { n.completed = true; }
				else { n.completed = false; }

				
			}
				  break;
			case 3: {
				
			}
				  break;
			case 4: {
				
			}
				  break;
			case 5: {
				//display_forward();
			}
				  break;
			case 6: {
				//display_backward();
			}
				  break;
			case 7: {
				std::cout << "Введите номер заказа\n";
				int num;
				std::cin >> num;
				//met
			}
				  break;
			case 8: {
				
				//met
			}
				  break;
			case 9: {
				
			}
				  break;
			case 10: {
				std::cout << "Введите номер заказа\n";
				int num;
				std::cin >> num;
				//search
				//push_front(ord);
			}
				   break;
			case 11: {}
				   break;
			default:
				throw std::invalid_argument ("Неправильный ответ");
			}
		}
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what();
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}



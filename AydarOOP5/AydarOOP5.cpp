#include <iostream>


using namespace std;

class Cat{

private:
	string CN = "Cat";

public:
	string name,colors;
	int height, weight;

	Cat() {
		this->height = 0;
		this->weight = 0;
		this->name = "";
		this->colors = "";
		cout << "Конструктор по умолчанию Cat\n";
	}

	Cat(int a, int b, string c, string d) {
		this->height = a;
		this->weight = b;
		this->name = c;
		this->colors = d;
		cout << "Конструктор с параметрами Cat\n";
	}

	Cat(Cat& A) {
		this->height = A.height;
		this->weight = A.weight;
		this->name = A.name;
		this->colors = A.colors;
		cout << "Конструктор копирующий Cat\n";
	}

	virtual bool isA(string classname) {
		cout << "Виртуальный метод isA Cat\n";
		if (classname == CN)
			return 1;
		else
			return 0;
	}

	virtual string ClassName() {
		cout << "Виртуальный метод ClassName Cat\n";
		return CN;
	}

	void Method() {
		cout << "Метод Cat\n";
	}

	virtual ~Cat() {
		cout << "Деструктор Cat\n";
	}

};

class My_cat:public Cat{

private:
	string CN = "My_cat";

public:

	My_cat() {
		this->height = 70;
		this->weight = 6;
		this->name = "Tisha";
		this->colors = "red & white";
		cout << "Конструктор по умолчанию My_cat\n";
	}

	My_cat(int a, int b, int c, string d) {
		this->colors = a;
		this->height = b;
		this->weight = c;
		this->name = d;
		cout << "Конструктор с параметрами My_cat\n";
	}

	My_cat(My_cat& C) {
		this->colors = C.colors;
		this->height = C.height;
		this->weight = C.weight;
		this->name = C.name;
		cout << "Конструктор копирующий My_cat\n";
	}

	bool isA(string classname) {
		cout << "Невиртуальный метод isA My_cat\n";
		if (classname == CN)
			return 1;
		else
			return 0;
	}

	string ClassName() {
		cout << "Невиртуальный метод ClassName My_cat\n";
		return CN;
	}

	void Method() {
		cout << "Метод My_cat\n";
	}

	~My_cat() {
		cout << "Деструктор My_cat\n";
	}
};

class Base{
public:
	Base() {
		cout << "Конструктор по умолчанию Base\n";
	}

	Base(Base * obj) {
		cout << "Конструктор *objBase\n";
	}

	Base(Base & obj) {
		cout << "Конструктор&obj Base\n";
	}
	virtual ~Base() {
		cout << "Деструктор Base\n";
	}
};

class Desc: public Base{
public:
	Desc() {
		cout << "Конструктор по умолчанию Desc\n";
	}

	Desc(Desc * obj) {
		cout << "Конструктор *objDesc\n";
	}

	Desc(Desc & obj) {
		cout << "Конструктор &objDesc\n";
	}
	~Desc() {
		cout << "Деструктор Desc\n";
	}
};

void func1(Base obj) { //принимает объект
	cout << "Функция 1\n";
}
void func2(Base* obj) {//принимает указатель на объект
	cout << "*Функция 2\n";
}
void func3(Base& obj) {//принимает ссылку на объект
	cout << "&Функция 3\n";
}


int main()
{
	setlocale(LC_ALL, "");

	Cat* Cat1 = new Cat();
	My_cat* My_cat1 = new My_cat();
	Cat* Cat2 = new My_cat();

	cout << "\nПроверка на принадлежность\n";
	cout << "\nС помощью метода Classname:\n";
	cout << Cat1->ClassName() << endl;
	cout << My_cat1->ClassName() << endl;
	cout << Cat2->ClassName() << endl;

	cout << "\nС помощью метода isA:\n";
	cout << Cat1->isA("Cat") << endl;
	cout << My_cat1->isA("My_cat") << endl;
	cout << Cat2->isA("Cat") << endl << endl;

	cout << "Приведение типов dynamic_cast:\n";

	My_cat* My_cat2 = dynamic_cast<My_cat*>(Cat2);
	cout << My_cat2->ClassName() << endl;
	My_cat2->Method();
	Cat2->Method();
	cout << endl;

	My_cat* My_cat3 = new My_cat;
	cout << "\nОпасное приведение типов:\n";
	if (Cat2->isA("Pear_Tree"))
		My_cat3 = (My_cat*)Cat2;
	cout << My_cat3->ClassName() << endl;

	cout << "\nПередача объектов как параметров в функции:\n\n";
	cout << "Base:\n\n";
	Base base1;
	func1(base1);
	cout << endl;
	Base* base2 = new Base();
	func2(base2);
	cout << endl;
	Base base3; 
	func3(base3);
	cout << endl;

	cout << "\tDesk:\n";
	Desc desc1;
	func1(desc1);
	cout << endl;
	Desc* desc2 = new Desc();
	func2(desc2);
	cout << endl;
	Desc desc3;
	func3(desc3);
	cout << endl;
	delete desc2;

	return 0;
}

//Реализовать класс SharedPtr для класса File, реализация класса File не имеет значение(может быть пустым).
//SharedPtr - это умный указатель хранящий счетчик ссылок на ресурс, который он хранит.
//Каждый раз когда вызывается оператор = или конструктор копирования счетчик увеличивается на 1.
//Когда вызывается деструктор - счетчик уменьшается на 1.
//Когда счетчик становится равным 0 объект удаляется(вызывается delete для File).
//Класс должен также реализовать оператор->оператор разименования * и оператор bool.

#include <iostream>
#include "MySharedPtr.h"
#include "File.h"

int main()
{
	if (true)
	{
		MySharedPtr<File> SharedPtr1(new File);
		MySharedPtr<File> SharedPtr2(SharedPtr1);
		MySharedPtr<File> SharedPtr3(SharedPtr2);
		MySharedPtr<File> SharedPtr4(SharedPtr3);

		SharedPtr1->SetData(23);

		File &file = *SharedPtr1;
	}
	return 0;
}
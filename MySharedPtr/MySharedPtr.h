//Реализовать класс SharedPtr для класса File, реализация класса File не имеет значение(может быть пустым).
//SharedPtr - это умный указатель хранящий счетчик ссылок на ресурс, который он хранит.
//Каждый раз когда вызывается оператор = или конструктор копирования счетчик увеличивается на 1.
//Когда вызывается деструктор - счетчик уменьшается на 1.
//Когда счетчик становится равным 0 объект удаляется(вызывается delete для File).
//Класс должен также реализовать оператор->оператор разименования * и оператор bool.

template <typename TYPE>
class MySharedPtr
{
public:
	MySharedPtr(TYPE *data)
		: m_ptr(data), m_refCount(new size_t(1))
	{
	}
	MySharedPtr(const MySharedPtr<TYPE> &obj)
		: m_ptr(obj.GetPtr()), m_refCount(obj.m_refCount)
	{
		std::cout << "MySharedPtr(Copied) " << *(m_refCount) << std::endl;
		++*(m_refCount);
	}
	~MySharedPtr()
	{
		--*(m_refCount);
		if (m_ptr && *(m_refCount) == 0)
		{
			delete m_ptr;
			delete m_refCount;
			std::cout << "~MySharedPtr() " << *(m_refCount) << std::endl;
			m_ptr = nullptr;
			m_refCount = nullptr;
		}
	}
	bool operator==(const TYPE &obj) const
	{
		return m_ptr == obj.GetPtr();
	}
	bool operator!=(const TYPE &obj) const
	{
		return m_ptr != obj.GetPtr();
	}
	bool operator bool()
	{
		return m_ptr != nullptr;
	}
	TYPE *GetPtr() const
	{
		return m_ptr;
	}
	TYPE *operator->() const
	{
		return m_ptr;
	}
	TYPE &operator*()
	{
		return m_ptr;
	}
	MySharedPtr &operator=(MySharedPtr<TYPE> &obj)
	{
		++*(m_refCount);
		return obj.getPtr;
	}

private:
	TYPE *m_ptr = nullptr;
	size_t *m_refCount = nullptr;
};

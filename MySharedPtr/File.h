#pragma once
#include <iostream>

class File
{
public:
	File()
		: m_someValue(0)
	{
	}
	File(int data)
		: m_someValue(data)
	{
	}
	void SetData(int data)
	{
		m_someValue = data;
	}
	int GetData() const
	{
		return m_someValue;
	}

private:
	int m_someValue;
};

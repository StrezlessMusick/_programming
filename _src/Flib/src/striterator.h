//(c) FeelUs
#ifndef END_HPP
#define END_HPP

#include <string.h>
#include <wchar.h>

namespace str
{

template<class T>
inline bool atend(const T & x)
{	return *x==0;	}

template<class T>
inline void putend(const T & x)
{	*x=0;	}

/*
������ �������� �����
���������� � 0
����������� ��� 0
��������������� � bool
*/

/*
����������� �������� 
capacity - ���� ����� ����������� ����
unused - ��� ����
*/

};//str
#endif//END_HPP

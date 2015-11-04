//(c)FeelUs
#ifndef STR_H
#define STR_H
#include <string.h>
#include <wchar.h>
#include <iterator>
#include "striterator.h"

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

/*
����� ����� �������� ������ ����������
� ����������� ��������� � cpp ����, ������� ����������� ���� ����� ����������� � ������� �������

�� �� ������� ���, ��� ��� char namespace �� ���� ���������, � ��� ��������� ����� - ����, 
��� using namespace str
*/
/*
����� �������� � ���������� int �� distance_type & size_type
�� � �������������� ���
*/

		//TEMPLATE FUNCTION end
template<class T>
T end(T x)
{	
	while(*x!=0) x++;
	return x;
}
inline const char * end(const char * s)
{	return s+strlen(s);	}
inline const signed char * end(const signed char * s)
{	return s+strlen((const char *)s);	}
inline const unsigned char * end(const unsigned char * s)
{	return s+strlen((const char *)s);	}
inline const wchar_t * end(const wchar_t * s)
{	return s+wcslen(s);	}

		//TEMPLATE FUNCTION strlen
/*���������� ��������������� ����� ������*/
template<class It>
	typename std::iterator_traits<It>::distance_type
	strlen(It it)
	{
		typedef typename std::iterator_traits<It>::distance_type Td;
		Td ans=0;
		for(;!str::atend(it); ++it)
			++ans;
		return ans;
	}
/* for mingw
std::iterator_traits<wchar_t*>::distance_type
	strlen(const wchar_t * it)
	{	return wcslen(it);	}
*/
		//TEMPLATE FUNCTION strcpy
/*��������, ������ �����, ���������� ������ ��������*/
template<class InIt, class OutIt>
	OutIt strcpy(OutIt out, InIt in)
	{
		OutIt ans=out;
		for(; !str::atend(in); ++in, ++out)
			*out = *in;
		str::putend(out);
		return ans;
	}
wchar_t * strcpy(wchar_t * s, const wchar_t * ct)
	{	return wcscpy(s,ct);	}

		//TEMPLATE FUNCTION strncpy
/*��������, �������� ������ �����, ���������� ������ ��������*/
template<class InIt, class OutIt, class Dt>
	OutIt strncpy(OutIt out, InIt in, Dt maxd)
	{
		OutIt ans=out;
		for(; !str::atend(in) && maxd>0; ++in, ++out, --maxd)
			*out = *in;
		if(maxd!=0)	str::putend(out);
		return ans;
	}
wchar_t * strncpy(wchar_t * s, const wchar_t * ct, int maxd)
	{	return wcsncpy(s,ct,maxd);	}

		//TEMPLATE FUNCTION strcat
/*��������, ������ �����, ���������� ������ ��������*/
template<class InIt, class OutIt>
	OutIt strcat(OutIt out, InIt in)
	{
		OutIt ans=out;
		strcpy(end(out),in);
		return ans;
	}
wchar_t * strcat(wchar_t * s, const wchar_t * ct)
	{	return wcscat(s,ct);	}

		//TEMPLATE FUNCTION strncat
/*��������, �������� ������ �����, ���������� ������ ��������*/
template<class InIt, class OutIt, class Dt>
	OutIt strncat(OutIt out, InIt in, Dt maxd)
	{
		OutIt ans=out;
		strncpy(end(out),in,maxd);
		/*
		out=str::end(out);
		for(; !str::atend(in) && maxd>0; ++in, ++out, --maxd)
			*out = *in;
		str::putend(out);
		*/
		return ans;
	}
wchar_t * strncat(wchar_t * s, const wchar_t * ct, int maxd)
	{	return wcsncat(s,ct,maxd);	}

		//TEMPLATE FUNCTION strcmp
/*���������� 0+-1*/
template<class InIt, class OutIt>
	int strcmp(OutIt out, InIt in)
	{
		for(; ; ++in, ++out)
			if(str::atend(in))
				return str::atend(out) ? 0 : 1;
			else if(str::atend(out))
				return str::atend(in) ? 0 : -1;
			else if(*out < *in)
				return -1;
			else if(*in < *out)
				return 1;
		return 0;
	}
int strcpy(const wchar_t * s, const wchar_t * ct)
	{	return wcscmp(s,ct);	}

		//TEMPLATE FUNCTION strncmp
/*���������� 0+-1*/
template<class InIt, class OutIt, class Dt>
	int strncmp(OutIt out, InIt in, Dt maxd)
	{
		for(; maxd>0; ++in, ++out, --maxd)
			if(str::atend(in))
				return str::atend(out) ? 0 : 1;
			else if(str::atend(out))
				return str::atend(in) ? 0 : -1;
			else if(*out < *in)
				return -1;
			else if(*in < *out)
				return 1;
		return 0;
	}
int strncmp(const wchar_t * s, const wchar_t * ct, int maxd)
	{	return wcsncmp(s,ct,maxd);	}

		//TEMPLATE FUNCTION strchr
/*���������� �������� �� ��������� ������ ��� 0 � �������� ���������*/
template<class OutIt, class T>
	OutIt strchr(OutIt out, T ch)
	{
		for(; !str::atend(out); ++out)
			if(*out == ch)
				return out;
		return 0;
	}
const wchar_t * strchr(const wchar_t * s, wchar_t t)
	{	return wcschr(s,t);	}

		//TEMPLATE FUNCTION strrchr
/*���������� �������� �� ��������� ������ ��� 0 � �������� ���������*/
template<class OutIt, class T>
	OutIt strrchr(OutIt out, T ch)
	{
		OutIt ans=0;
		for(; !str::atend(out); ++out)
			if(*out == ch)
				ans = out;
		return ans;
	}
const wchar_t * strrchr(const wchar_t * s, wchar_t t)
	{	return wcsrchr(s,t);	}

		//TEMPLATE FUNCTION strspn
/*���������� ��������������� ���-�� ���������� ��������*/
template<class InIt, class OutIt>
	int strspn(OutIt in, InIt set)
	{
		int count =0;
		for(; !str::atend(in); ++in, ++count)
			if(!strchr(set,*in))//������� �����
				break;
		return count;
	}
int strspn(const wchar_t * s, const wchar_t * ct)
	{	return wcsspn(s,ct);	}

		//TEMPLATE FUNCTION strcspn
/*���������� ��������������� ���-�� ���������� ��������*/
template<class InIt, class OutIt>
	int strcspn(OutIt in, InIt set)
	{
		int count =0;
		for(; !str::atend(in); ++in, ++count)
			if(strchr(set,*in))//������� �����
				break;
		return count;
	}
int strcspn(const wchar_t * s, const wchar_t * ct)
	{	return wcscspn(s,ct);	}

		//TEMPLATE FUNCTION strpbrk
/*���������� �������� �� ���������� ������ ��� 0 � �������� ���������*/
template<class InIt, class OutIt>
	OutIt strpbrk(OutIt in, InIt set)
	{
		for(; !str::atend(in); ++in)
			if(strchr(set,*in))
				return in;
		return 0;
	}
const wchar_t * strpbrk(const wchar_t * s, const wchar_t * ct)
	{	return wcspbrk(s,ct);	}

		//TEMPLATE FUNCTION strstr
/*���������� �������� �� ��������� ��������� ��� 0 � �������� ���������*/
template<class InIt, class OutIt>
	OutIt strstr(OutIt _First1, InIt _First2)
	{
	for (; !str::atend(_First1); ++_First1)
		{	// room for match, try it
		OutIt _Mid1 = _First1;
		for (InIt _Mid2 = _First2; ; ++_Mid1, ++_Mid2)
			if (str::atend(_Mid2))
				return (_First1);//�����
			else if (str::atend(_Mid1))
				return (0);//�� �����
			else if (!(*_Mid1 == *_Mid2))
				break;//���������� ��������
		}
	return (0);
	}
const wchar_t * strstr(const wchar_t * s, const wchar_t * ct)
	{	return wcsstr(s,ct);	}

#ifdef _MSC_VER
#pragma warning(default:4996)
#endif

#endif//STR_H

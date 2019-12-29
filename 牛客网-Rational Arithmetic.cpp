#include <iostream>
#include <cmath>
//long long�������ؼ���ƴ�����ģ��������ܲ����㣬������һ��
typedef long long _sint64;
//�������������
class RationalNumber {
	bool m_infinate; //�������Ϊ��
	bool m_negative; //������
	_sint64 m_numerator; //���ӣ��������
	_sint64 m_denominator; //��ĸ
	_sint64 m_integer; //��������
	_sint64 m_numeratorAll; //��¼�����������ķ��ӣ������������
	_sint64 calcGCD(_sint64 a, _sint64 b); //�����Լ���ĺ���
public:
	RationalNumber(_sint64 numerator, _sint64 denominator); //���캯��
	RationalNumber operator+(RationalNumber const& o) const; //������������
	RationalNumber operator-(RationalNumber const& o) const;
	RationalNumber operator*(RationalNumber const& o) const;
	RationalNumber operator/(RationalNumber const& o) const;
	//��������������
	friend std::ostream &operator<<(std::ostream &os, RationalNumber const& o);
};
//��������ÿ��������ʵ��
_sint64 RationalNumber::calcGCD(_sint64 a, _sint64 b)
{
	if (b == 0)
	{
		return a;
	}
	//շת�����
	return calcGCD(b, a % b);
}
RationalNumber::RationalNumber(_sint64 numerator, _sint64 denominator)
{
	m_negative = false;
	m_infinate = false;
	//�����ĸΪ������
	if (denominator == 0)
	{
		m_infinate = true;
		return;
	}
	//��������д������Ϊ��ͨ�����������й�������У��п��ܳ��ַ��ӷ�ĸ��Ϊ���������
	if (numerator < 0)
	{
		m_negative = !m_negative;
	}
	if (denominator < 0)
	{
		m_negative = !m_negative;
	}
	//�������������ӡ���ĸ�����з�ĸҪ������������㣬���Բ����Ǹ��ģ���absȡ����ֵ������Ҫ����
	ԭֵ
		m_integer = numerator / denominator;
	m_numerator = numerator - m_integer * denominator;
	m_denominator = abs(denominator);
	//Լ�֣�ע�⴫���Ӻ����ķ��ӱ��������ģ���ĸ���洦�����
	if (m_numerator)
	{
		_sint64 maxtmp = calcGCD(abs(m_numerator), m_denominator);
		if (maxtmp)
		{
			m_numerator /= maxtmp;
			m_denominator /= maxtmp;
		}
	}
	//����Լ�ֺ�ٷ�����ķ��ӣ���Ϊ���������ǲ���Ҫ�������ֵģ����Ա����üٷ����ķ����㡣
	m_numeratorAll = m_numerator + m_integer * m_denominator;
}
//����Ϊ�����ļӼ��˳���ͳͳʹ��m_numeratorAll���ٷ����ķ��ӣ��������㡣
RationalNumber RationalNumber::operator+(RationalNumber const& o) const
{
	_sint64 numerator = (m_numeratorAll * o.m_denominator) +
		(o.m_numeratorAll * m_denominator);
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
}
RationalNumber RationalNumber::operator-(RationalNumber const& o) const
{
	_sint64 numerator = (m_numeratorAll * o.m_denominator) -
		(o.m_numeratorAll * m_denominator);
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
}
RationalNumber RationalNumber::operator*(RationalNumber const& o) const
{
	_sint64 numerator = m_numeratorAll * o.m_numeratorAll;
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
}
RationalNumber RationalNumber::operator/(RationalNumber const& o) const
{
	_sint64 numerator = m_numeratorAll * o.m_denominator;
	_sint64 denominator = m_denominator * o.m_numeratorAll;
	return RationalNumber(numerator, denominator);
}
std::ostream &operator<<(std::ostream &os, RationalNumber const& o)
{
	//��ĸΪ0������Ͳ��ü�����
	if (o.m_infinate)
	{
		os << "Inf";
		return os;
	}
	//�����ͷ���Ϊ0�Ǹɴ����0��
	if (o.m_numerator == 0 && o.m_integer == 0)
	{
		os << "0";
		return os;
	}
	//������ӡ���ź͸���
	if (o.m_negative)
	{
		os << "(-";
	}
	//�������ʹ�����
	if (o.m_integer)
	{
		os << abs(o.m_integer);
		if (o.m_numerator) //����С�����оʹ���ո����
		{
			os << " ";
		}
	}
	//�з����ʹ��������ĸ�Ѿ�abs���ˣ�������Բ���
	if (o.m_numerator)
	{
		os << abs(o.m_numerator) << '/' << o.m_denominator;
	}
	//�����ĺ�������
	if (o.m_negative)
	{
		os << ")";
	}
	return os;
}
int main()
{
	_sint64 n1, d1, n2, d2;
	scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
	RationalNumber rn1(n1, d1), rn2(n2, d2);
	//����+����ʹ�ú���ʱ��
	std::cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << '\n';
	std::cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << '\n';
	std::cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << '\n';
	std::cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << '\n';
	return 0;
}
#pragma once
#define _F_LOGIN "./Data/login.ini"
#define _F_STOCK "./Data/stock.txt"
#include <vector>
#include <fstream>
#include <iomanip>		//���������������setw����

using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;
using std::setw;
typedef struct Account_Message {
	CString m_Tax;
	CString m_Account;			//�˻�ID��Ϣ
	CString m_Name;		//�˻���ʵ����
	CString m_PWD;		//����
	CString m_WorkYear;	//����
	CString m_Psition;	//ְ��
	CString m_Salary;		//����
}message;


class CInfofile
{
public:
	CInfofile();
	~CInfofile();

	//��ȡ��½��Ϣ
	bool ReadLoginAccount(CString &name);
	bool ReadLoginPwd(CString& pwd);
	//�޸�����
	void WritePwd(char* name, char* pwd);

	// ��ȡԱ������
	void ReadDocline();

	//Ա����Ϣд���ļ�
	void WirteDocline();


	//�����Ա����Ϣ
	void Addline(CString name, int num, int price);

	std::vector<Account_Message> MessVec;			//Ա����Ϣ���������ڶԽ��ļ�ϵͳ

	double Tax(double money);
};


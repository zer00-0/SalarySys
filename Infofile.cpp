#include "stdafx.h"
#include "Infofile.h"
#include "GlobalVal.h"

CInfofile::CInfofile()
{
}


CInfofile::~CInfofile()
{ 
}


//��ȡ��½��Ϣ

//��֤�˺�
bool CInfofile::ReadLoginAccount(CString &account) {
	for (vector<message>::iterator it = MessVec.begin(); it != MessVec.end(); it++)
	{
		if (it->m_Account == account) {
			now_account = account;
			return true;
		}
	}
	return false;
}

//��֤����
bool CInfofile::ReadLoginPwd(CString &pwd) {
	for (vector<message>::iterator it = MessVec.begin(); it != MessVec.end(); it++)
	{
		if (it->m_PWD == pwd)
			return true;
	}
	return false;
}

//�޸�����
void CInfofile::WritePwd(char* name, char* pwd) {
	int lenth = MessVec.size();
	for (int i = 0; i < lenth; i++) {
		if (MessVec[i].m_Account == name)
			MessVec[i].m_PWD = pwd;
	}
}

// ��ȡԱ������
void CInfofile::ReadDocline() {

	CFileFind fileFind;//�����ļ��Ƿ����
	CString strFileName;
	strFileName = _T("Data/stock.txt");
	if (!fileFind.FindFile(strFileName))
	{
		::MessageBox(NULL, TEXT("��ȡ�û���Ϣ�ļ�ʧ��"), NULL, MB_OK);
	}

	CStdioFile file;
	file.Open(strFileName, CFile::modeRead);
	CString strTemp,str;
	file.ReadString(strTemp);					//��һ��Ϊ���Ա�ǣ��������ļ�

	while (file.ReadString(strTemp))				//strTemp��ȡ����
	{
		AfxExtractSubString(str, strTemp, 0, '|');
		if (str == "�˺���")
			continue;
		if (str == "")
			break;
		message* mes = new message;
		//���ж�ȡ���ú��������ַ���
		AfxExtractSubString(mes->m_Account, strTemp, 0, '|');		//��strTemp�����ַ����иAfxExtractSubString�ĸ���������ţ��ַ������ڼ������ָ��־��
		AfxExtractSubString(mes->m_Name, strTemp, 1, '|');
		AfxExtractSubString(mes->m_PWD, strTemp, 2, '|');
		AfxExtractSubString(mes->m_WorkYear, strTemp, 3, '|');
		AfxExtractSubString(mes->m_Psition, strTemp, 4, '|');
		AfxExtractSubString(mes->m_Salary, strTemp, 5, '|');
		mes->m_Tax.Format(_T("%lf"),Tax(_ttoi64(mes->m_Salary)));
		MessVec.push_back(*mes);
		delete mes;
	}
	file.Close();
}

//Ա����Ϣд���ļ�
void CInfofile::WirteDocline() {
	ofstream ofs(_F_STOCK);//�����ʽ���ļ�

	if (MessVec.size() > 0)	//Ա����Ϣ�����ݲ�ִ��
	{
		ofs << "�˺���" << '|' << "Ա������" << '|' << "����" << '|'
			<< "����"  << '|' << "ְ��"  << '|' << "����"<< endl; //д���ͷ

											//ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
		for (vector<message>::iterator it = MessVec.begin(); it != MessVec.end(); it++)
		{
			ofs << it->m_Account << '|';
			ofs << it->m_Name << '|';
			ofs << it->m_PWD << '|';
			ofs << it->m_WorkYear << '|';
			ofs << it->m_Psition << '|';
			ofs << it->m_Salary  << endl;
		}
	}
	ofs.close();
}

//�����Ա����Ϣ
void CInfofile::Addline(CString name, int num, int price) {

}

double CInfofile::Tax(double money)
{
	money = money - 5000;
	float mshui;
	//˰��������
	if (money <= 0)
	{
		mshui = 0;
	}
	if (money <= 3000 && money >= 0)
	{
		mshui = money *0.03;
	}
	if (money <= 12000 && money > 3000)
	{
		mshui = money *0.1 - 210;
	}
	if (money <= 25000 && money > 12000)
	{
		mshui = money * 0.2 - 1410;
	}
	if (money <= 35000 && money > 25000)
	{
		mshui = money * 0.25 - 2660;
	}
	if (money <= 55000 && money > 35000)
	{
		mshui = money * 0.3 - 4410;
	}
	if (money <= 80000 && money > 55000)
	{
		mshui = money * 0.35 - 7160;
	}
	if (money > 80000)
	{
		mshui = money * 0.45 - 15160;
	}
	return mshui;
}

#include <iostream>
#include<string>
#include<string.h>
#include<bitset>
#include<sstream>
#include<stdlib.h>
using namespace std;
typedef struct
{
	uint32_t fdata[4];
}Qfloat;
//chia phan nguyen :B1
char numToString(int n)     // chuyen so sang char
{
	return (char)(n + 48);
}
int stringToNum(char c)     // chuyen char sang so
{
	return c - '0';//theo ma ASCII
}
string layPhanNguyen(string struser)
{
	int chiSo;
	string temp;
	for (int i = 0; i < struser.length(); i++)
	{
		temp.push_back(struser[i]);
		if (struser[i] == ',' || struser[i] == '.')
		{
			break;
		}
	}
	temp.erase(temp.length() - 1);
	/*if (temp.at(0) == '-')
	{
	temp.erase(0, 1);
	}*/
	/*chiSo = stringToNum(temp);*/
	//chiSo = stoi(temp, 0, 10);// chi dung duoc voi C++11 tro len 
	return temp;
}
string chia2(string bigInt)
{

	string tmp;
	unsigned short int i = 0, j = 0, k = 0;
	tmp.resize(bigInt.length());
	if (bigInt[0] - '0' < 2)
	{
		i = 1;
		j = 10;
	}
	for (; i < bigInt.length(); i++)
	{
		tmp[k++] = ((bigInt[i] - '0' + j) / 2 + '0');
		j = ((bigInt[i] - 48 + j) % 2) * 10;
	}
	tmp.resize(k);
	return tmp;
}
int* reverse15(int *a)
{
	static int rev_arr[15] = { 0 };
	for (int i = 0; i < 15; i++)
	{
		rev_arr[i] = a[15 - i - 1];
	}
	return rev_arr;
}
int* DecToBinNguyen(string userInputStr)
{
	int binary[15] = { 0 };

	if (userInputStr[0] == '-')
	{
		
		userInputStr.erase(0, 1);
	}

	for (unsigned short int i = 0; userInputStr.length() != 0; i++)
	{
		if ((userInputStr[userInputStr.length() - 1] - 48) % 2 != 0) {
			binary[i] = 1;
			userInputStr[userInputStr.length() - 1] -= 1;
		}
		else binary[i] = 0;
		userInputStr = chia2(userInputStr);
	}
	int* res = reverse15(binary);

	return res;

}
string numToStringNguyen(int* soNguyen)
{
	string str;
	for (int i = 0; i < 15; i++)
	{
		str.push_back(numToString(soNguyen[i]));
	}
	return str;
}
string xuLiSoNguyen(string userStr)
{
	return numToStringNguyen(DecToBinNguyen(layPhanNguyen(userStr)));

}
//xu li so thap phan : B2
float layPhanThapPhan(string struser)
{
	if (struser[0] == '-') struser.erase(0, 1);
	
	return stod(struser) - (float)stoi(layPhanNguyen(struser));
}
double _2_mu_n(int n)
{
	double res = 1;
	for (int i = 1; i <= n; i++)
	{
		res = res * 2;
	}
	return res;

}
int* reverse112(int *a)
{
	static int rev_arr[112] = { 0 };
	for (int i = 0; i < 112; i++)
	{
		rev_arr[i] = a[112 - i - 1];
	}
	return rev_arr;
}
int* copy112(int *a)
{
	static int rev_arr[112] = { 0 };
	for (int i = 0; i < 112; i++)
	{
		rev_arr[i] = a[i];
	}
	return rev_arr;
}
int* copy128(int *a)
{
	static int rev_arr[128] = { 0 };
	for (int i = 0; i < 112; i++)
	{
		rev_arr[i] = a[i];
	}
	return rev_arr;
}
int *decToBinThapPhan(string struser)
{
      float SoThapPhan = layPhanThapPhan(struser);
	  double soDauTien =(double) SoThapPhan*_2_mu_n(112);
	  int mang[112] = { 0 };
	  for (int i = 111; i >= 0; i--)
	  {
		  if ((soDauTien - _2_mu_n(i)) > 0|| (soDauTien - _2_mu_n(i)) == 0)
		  {
			  mang[i] = 1;
			  /*cout <<"tai"<<i<<":" <<soDauTien << "-"<<_2_mu_n(i)<<"=";*/
			  soDauTien = soDauTien - _2_mu_n(i);
			 /* cout << soDauTien << ">0" << endl;*/
		  }
		  else
		  {
			  mang[i] = 0;
		  }
	  }
	  int * res = reverse112(mang);
	  return res;
}
string numToStringThapPhan(int* soThapPhan)
{
	string str;
	for (int i = 0; i <112; i++)
	{
		str.push_back(numToString(soThapPhan[i]));
	}
	return str;
}
string xuLiSoThapPhan(string userStr)
{
	return numToStringThapPhan(decToBinThapPhan(userStr));

}
//B3: xu li 
string soNhiPhanHoanChinh(string struser)
{
	string temp;
	temp.append(xuLiSoNguyen(struser));
	temp.push_back('.');
	temp.append(xuLiSoThapPhan(struser));
	return temp;
}
 string intToString(int num)
{
	string result;
	ostringstream convert;
	convert << num;
	result = convert.str();
	return result;
}
int* timSoMu(string struser)
{
	int soDauCham;
	int So1Dau;
	int soMu;
	int phanMu;
	string temp = soNhiPhanHoanChinh(struser);
 	soDauCham=temp.find_first_of('.');
	So1Dau = temp.find_first_of('1');
	soMu = soDauCham - So1Dau - 1;
	phanMu = soMu + 127;
	string phanMuStr;
	phanMuStr = intToString(phanMu);
	int *res = DecToBinNguyen(phanMuStr);
	return res;
	
}
int* phanSignificand(string struser)
{
	int phan3[112] = { 0 };
	string nhiPhan;
	nhiPhan = soNhiPhanHoanChinh(struser);
	int viTriDauCham = nhiPhan.find_first_of('.');
	nhiPhan.erase(viTriDauCham, 1);
	int vitri;
	vitri = nhiPhan.find_first_of('1') + 1;

	for (int i = 0; i < 112; i++)
	{
		phan3[i]= stringToNum(nhiPhan[i + vitri]);
		/*cout << phan3[i];*/
	}
	cout << endl;
	int *res = copy112(phan3);
	return res;
}
int* nhiPhanIEE(string struser)
{
	int mangIEE[128] = { 0 };
	if (struser[0] = '-')
	{
		mangIEE[0] = 1;
	}
	else
	{
		mangIEE[0] = 0;
	}
	int* soMu = timSoMu(struser);
	
	for (int i = 1; i < 16; i++)
	{
		mangIEE[i]= soMu[i-1];
	}
	cout << endl;
	
	
	

	/*for (int i = 1; i < 16; i++)
	{
		mangIEE[i] = soMu[i-1];
		
	
	}*/
	int* soCuoi = phanSignificand(struser);
	for (int i = 16; i < 128; i++)
	{
		mangIEE[i] = soCuoi[i - 16];
		
	}
	int *res = copy128(mangIEE);
	return res;
}
void main()
{
	string thu = "-3.56125";
	int *res = nhiPhanIEE(thu);
	for (int i = 0; i < 128; i++)
	{
		cout << res[i];
	}
}
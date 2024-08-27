#pragma once
using namespace System;
using namespace System::Windows::Forms;
ref class Weapon
{
public:
	String^ name;
	double calibre;
	int clipCapasity;
	bool license;
	DateTime ^ dateOfIssue;
	Weapon(String ^ Sname, String ^ Scalibre, String ^ SclipCapasity, String ^ Slicense, String ^ SdateOfIssue) {
		name = Sname;calibre = Convert::ToDouble(Scalibre); clipCapasity = Convert::ToInt32(SclipCapasity);
		if (Slicense == "yes" || Slicense == "Yes" || Slicense == "Y" || Slicense == "1" || Slicense == "да" || Slicense == "Да" || Slicense == "Д")
			license = 1;
		else if (Slicense == "no" || Slicense == "No" || Slicense == "N" || Slicense == "0" || Slicense == "нет" || Slicense == "Нет" || Slicense == "Н")
			license = 0;
		try
		{
			dateOfIssue = DateTime::Parse(SdateOfIssue);
		}
		catch (...)
		{
			MessageBox::Show("Произошла ошибка при чтении даты" + SdateOfIssue, "На дату ругается", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	};
	Weapon(String ^ n, double c, int cC, bool l, DateTime ^ dOI) :name(n), calibre(c), clipCapasity(cC), license(l), dateOfIssue(dOI) {};
	~Weapon() { };
};


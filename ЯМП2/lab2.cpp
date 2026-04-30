#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;


class SymbString
{
protected:
	char* id;
	char* workStr;

	void PrintStr(char* str) {
		while (*str != '\0') {
			cout << *str;
			str++;
		}
	}

	char* copy(const char* str) {
		int len = 0;
		while (str[len] != '\0')
			len++;
		char* result = new char[len + 1];
		for (int i = 0; i <= len; i++) result[i] = str[i];
		return result;
	}		

	char* DeleteStr(char* str, char* delMe) {
		char* delMe2 = delMe;
		char* result = copy(str);
		int len = 0, delLen = 0, start;

		while (str[len] != '\0') {
			if (str[len] == delMe[delLen]) {
				if (delLen == 0)
					start = len;
				delLen++;
			}
			else if (delMe[delLen] != '\0' && delLen != 0) {
				delLen = 0;
				len--;
			}
			len++;
		}

		if (delLen != 0) {
			delete[] result;
			result = new char[len - delLen + 1];
			int j = 0;

			for (int i = 0; i < start; i++)result[j++] = str[i];
			for (int i = start + delLen; i < len; i++)result[j++] = str[i];
			result[j] = '\0';
		}
		

		return result;
	}

public:
	SymbString(){}
	SymbString(char* id, char* workStr)
	{
		this->id = copy(id);
		this->workStr = copy(workStr);
	}

	SymbString(string id, char* workStr)
	{
		this->id = copy(id.c_str());
		this->workStr = copy(workStr);
	}

	SymbString(const SymbString& other) {
		this->id = copy(other.id);
		this->workStr = copy(other.workStr);
	}

	virtual ~SymbString()
	{
		delete[] id;
		delete[] workStr;
	}

	void print() {
		cout << "\nid: ";
		PrintStr(id);
		cout << "\nString: ";
		PrintStr(workStr);
	}

	char* getID() {
		return id;
	}

	char* getSTR() {
		return workStr;
	}

	SymbString operator-(const SymbString& b) {
		char* str = DeleteStr(workStr, b.workStr);
		SymbString res(id, str);
		delete[] str;
		return res;
	}

	SymbString& operator=(const SymbString& other) {
		if (this != &other) {
			delete[] id;
			delete[] workStr;
			this->id = copy(other.id);
			this->workStr = copy(other.workStr);
		}
		return *this;
	}
};

class OctString : public SymbString {
private:
	int OctToInt(const char* s) {
		int result = 0;
		int i = 0;
		while (s[i] != '\0') {
			result = result * 8 + s[i]-'0';
			i++;
		}
		return result;
	}

	char* IntToOct(int num) {
		if (num == 0) return copy("0");

		char buf[64];
		int n = 0;
		while (num > 0) {
			buf[n++] = (num % 8) + '0';
			num /= 8;
		}
		buf[n] = '\0';

		char* res = new char[n + 1];
		for (int j = 0; j < n; j++)
			res[j] = buf[n  - j-1];
		res[n] = '\0';
		return res;
	}
	bool isValid(char* s) {
		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] < '0' || s[i] > '7') return false;
		}
		return true;
	}

public:
	OctString(){}
	OctString(char* id, char* workStr) : SymbString(id, workStr) {
		if (!isValid(workStr)) {
			this->workStr = copy((char*)"0");
			cout << "Введеное число неявляется 8ричным, заменено на 0. ID:" << id;
		}
	}

	OctString(SymbString other) : SymbString(id, workStr) {
		if (this != &other) {
			this->id = copy(other.getID());
			this->workStr = copy(other.getSTR());
		}
	}

	void print() {
		cout << "\nid: ";
		PrintStr(id);
		cout << "\nString: ";
		PrintStr(workStr);
		cout << "\nInteger: "<<(OctToInt(workStr));
	}

	OctString operator-(const OctString& b) {
		int x = OctToInt(this->workStr);
		int y = OctToInt(b.workStr);

		int result = x - y;
		if (result < 0) result = 0;

		char* newStr = IntToOct(result);
		OctString res(this->id, newStr);

		delete[] newStr;
		return res;
	}

	OctString& operator=(SymbString& other) {
		if (this != &other) {
			delete[] id;
			delete[] workStr;
			this->id = copy(other.getID());
			this->workStr = copy(other.getSTR());
		}
		return *this;
	}
};

enum Type{ STR, OCT };


class Factory {
private:
	map <string, SymbString*> STRs;
	int freeId;
public:
	Factory() {
		freeId = 0;
	}
	
	Type SetType(int num) {
		switch (num) {
		case 1:
			return STR;
		case 2:
			return OCT;
		default:
			cout << "Ошибка в воде данных, возвращена строка";
			return STR;
		}
	}
	void Add()
	{
		cout << "Выберете тип данных\n";
		cout << "1 - строка\n";
		cout << "2 - число\n";

		int type;
		cin >> type;
		Type item = SetType(type);

		cout << "Введите восьмеричное число" << endl;
		char str[100];
		cin >> str;

		SymbString* newObj = nullptr;
		string ID = to_string(freeId);
		char* objId = new char[ID.size()+1];
		if (item == STR) {
			newObj = new SymbString(objId, str);
		}
		else if (item == OCT) {
			newObj = new OctString(objId, str);
		}
		else {
			cout << "ERROR" << endl;
			return;
		}

		if (newObj != nullptr && STRs.count(ID)==0) {
			STRs[ID]=newObj;
			cout << "Объект " << ID << " успешно создан." << endl;
			freeId++;
		}
		else if (STRs.count(ID) != 0) {
			cout << "Ошибка во время создания объекта ID ", ID, " уже занят";
			freeId++;
		}
	}

	SymbString* GetSTR(string id) {
		if (STRs.count(id) != 0)
			return STRs[id];
		cout << "Объект с id: ", id, "несуществует";
		return nullptr;
	}

	void Delete() {
		string searchID;
		cout << "Введите ID, который нужно удалить" << endl;
		cin >> searchID;

		if (STRs.count(searchID) != 0) {
			delete STRs[searchID];
			STRs.erase(searchID);

			cout << "Объект успешно удален" << endl;
			return;
		}
		cout << "Объект с Id " << searchID << " не найден." << endl;
}
};


int main()
{
	Factory factory;
	factory.Add();
	factory.Add();
	OctString a, b;
	a = *factory.GetSTR("0");
	b = *factory.GetSTR("1");

	a = a - b;
	a.print();

	return 0;
}

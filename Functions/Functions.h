// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа FUNCTIONS_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции FUNCTIONS_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifndef LIB_F 
#define LIB_F 
#ifdef FUNCTIONS_EXPORTS
#define FUNCTIONS_API __declspec(dllexport)
#else
#define FUNCTIONS_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <fstream>
#include <clocale>
#include <cwctype>
#include <codecvt>
#include <iomanip>
#include <algorithm>
#include <combaseapi.h>
#include <strsafe.h>

class Edition {
protected:
	std::wstring number = L"";
	std::wstring name = L"";
	int ageRating = 0;
	int strNumber = 0;
	std::wstring formatType = L"";
	int type = 0;
	int circulation = 0;
	std::wstring state = L"";
public:
	Edition();
	std::wstring getNumber();
	std::wstring getName();
	std::wstring getFormatType();
	int getAgeRating();
	int getStrNumber();
	int getType();
	int getCirculation();
	std::wstring getState();
	void setNumber(std::wstring number);
	void setName(std::wstring name);
	void setFormatType(std::wstring formatType);
	void setAgeRating(int ageRating);
	void setStrNumber(int strNumber);
	void setType(int type);
	void setCirculation(int circulation);
	void setState(std::wstring state);
	Edition(const Edition& temp);
	Edition* copy();
	virtual ~Edition();
	virtual std::wstring getAuthor();
	virtual void setAuthor(std::wstring);
	virtual std::vector<std::wstring>& getAuthors();
	virtual void setAuthors(std::vector<std::wstring>&);
};

class Book : public Edition {
private: 
	std::wstring author;
public:
	Book(std::wstring number, std::wstring name, std::wstring author, int ageRating, int strNumber, std::wstring formatType, int circulation, std::wstring state);
	std::wstring getAuthor();
	void setAuthor(std::wstring author);
	Book(const Book& temp);
	Edition* copy();
	~Book();
};

class Magazine : public Edition {
public:
	Magazine(std::wstring number, std::wstring name, int ageRating, int strNumber, std::wstring formatType, int circulation, std::wstring state);
	Magazine(const Magazine& temp);
	Edition* copy();
	~Magazine();
};

class Collection : public Edition {
private:
	std::vector<std::wstring> authors;
public:
	Collection(std::wstring number, std::wstring name, std::vector<std::wstring> authors, int ageRating, int strNumber, std::wstring formatType, int circulation, std::wstring state);
	std::vector<std::wstring>& getAuthors();
	void setAuthors(std::vector<std::wstring>& authors);
	Collection(const Collection& temp);
	Edition* copy();
	~Collection();
};

struct Comp {
	bool operator() (Edition* a, Edition* b) const;
};
struct CompByCirc {
	bool operator() (Edition* a, Edition* b) const;
};
struct CompByISBN {
	bool operator() (Edition* a, Edition* b) const;
};
struct CompByName {
	bool operator() (Edition* a, Edition* b) const;
};
struct CompByAuthor {
	bool operator() (Edition* a, Edition* b) const;
};
struct CompByRating {
	bool operator() (Edition* a, Edition* b) const;
};
struct CompByStr {
	bool operator() (Edition* a, Edition* b) const;
};
struct RangeComp
{
	bool operator()(Edition* s, std::wstring i);
	bool operator()(std::wstring i, Edition* s);
};

class DB {
public:
	std::vector<Edition*>* books;
	std::vector<Edition*>* magazines;
	std::vector<Edition*>* collections;
	DB();
	~DB();
	DB(const DB& temp);
	DB& operator=(const DB& temp);
	void saveFile();
};

void FUNCTIONS_API getAll(std::vector<int>(&types), std::vector<int>(&ageRatings), std::vector<int>(&strNumbers), std::vector<int>(&circulations), std::vector<std::vector<std::wstring>>(&str), std::wstring filter, int number);
void FUNCTIONS_API addEdition(std::wstring number, std::wstring name, std::wstring author, std::wstring ageRating, std::wstring strNumber, std::wstring formatType, std::wstring circulation, std::wstring state, int type);
void FUNCTIONS_API editState(std::wstring number, std::wstring state);
void FUNCTIONS_API deleteEdition(std::wstring number);
LONG_PTR FUNCTIONS_API Memory(wchar_t** s_array, int& s_len);
void FUNCTIONS_API close();

#endif
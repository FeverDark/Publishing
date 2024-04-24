// Functions.cpp : Определяет экспортируемые функции для DLL.
//

#include "pch.h"
#include "framework.h"
#include "Functions.h"

const std::locale loc = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>);

Edition::Edition() {
}

std::wstring Edition::getNumber() {
	return number;
}
std::wstring Edition::getName() {
	return name;
}
std::wstring Edition::getFormatType() {
	return formatType;
}
std::wstring Edition::getState() {
	return state;
}
int Edition::getAgeRating() {
	return ageRating;
}
int Edition::getStrNumber() {
	return strNumber;
}
int Edition::getType() {
	return type;
}
int Edition::getCirculation() {
	return circulation;
}
void Edition::setNumber(std::wstring number) {
	this->number = number;
}
void Edition::setName(std::wstring name) {
	this->name = name;
}
void Edition::setFormatType(std::wstring formatType) {
	this->formatType = formatType;
}
void Edition::setAgeRating(int ageRating) {
	this->ageRating = ageRating;
}
void Edition::setStrNumber(int strNumber) {
	this->strNumber = strNumber;
}
void Edition::setType(int type) {
	this->type = type;
}
void Edition::setCirculation(int circulation) {
	this->circulation = circulation;
}
void Edition::setState(std::wstring state) {
	this->state = state;
}
Edition::Edition(const Edition& temp) {}
Edition* Edition::copy() { return NULL; }
Edition::~Edition()
{
}
std::wstring Edition::getAuthor() { return L""; };
void Edition::setAuthor(std::wstring) {};
std::vector<std::wstring>& Edition::getAuthors() {
	std::vector<std::wstring> temp;
	return temp;
};
void Edition::setAuthors(std::vector<std::wstring>&) {};


Book::Book(std::wstring number, std::wstring name, std::wstring author, int ageRating, int strNumber, std::wstring formatType, int circulation, std::wstring state) {
	this->number = number;
	this->name = name;
	this->ageRating = ageRating;
	this->strNumber = strNumber;
	this->formatType = formatType;
	this->type = 1;
	this->circulation = circulation;
	this->state = state;
	this->author = author;
}
Book::Book(const Book& temp) {
	this->number = temp.number;
	this->name = temp.name;
	this->ageRating = temp.ageRating;
	this->strNumber = temp.strNumber;
	this->formatType = temp.formatType;
	this->type = temp.type;
	this->circulation = temp.circulation;
	this->state = temp.state;
	this->author = temp.author;
}
std::wstring Book::getAuthor() { return author; };
void Book::setAuthor(std::wstring author) { this->author = author; };
Edition* Book::copy() {
	return new Book(*this);
}
Book::~Book()
{
}

Magazine::Magazine(std::wstring number, std::wstring name, int ageRating, int strNumber, std::wstring formatType, int circulation, std::wstring state) {
	this->number = number;
	this->name = name;
	this->ageRating = ageRating;
	this->strNumber = strNumber;
	this->formatType = formatType;
	this->type = 2;
	this->circulation = circulation;
	this->state = state;
}
Magazine::Magazine(const Magazine& temp) {
	this->number = temp.number;
	this->name = temp.name;
	this->ageRating = temp.ageRating;
	this->strNumber = temp.strNumber;
	this->formatType = temp.formatType;
	this->type = temp.type;
	this->circulation = temp.circulation;
	this->state = temp.state;
}
Edition* Magazine::copy() {
	return new Magazine(*this);
}

Magazine::~Magazine()
{
}

Collection::Collection(std::wstring number, std::wstring name, std::vector<std::wstring> authors, int ageRating, int strNumber, std::wstring formatType, int circulation, std::wstring state) {
	this->number = number;
	this->name = name;
	this->authors = authors;
	this->ageRating = ageRating;
	this->strNumber = strNumber;
	this->formatType = formatType;
	this->type = 3;
	this->circulation = circulation;
	this->state = state;
}
Collection::Collection(const Collection& temp) {
	this->number = temp.number;
	this->name = temp.name;
	this->authors = temp.authors;
	this->ageRating = temp.ageRating;
	this->strNumber = temp.strNumber;
	this->formatType = temp.formatType;
	this->type = temp.type;
	this->circulation = temp.circulation;
	this->state = temp.state;
}
std::vector<std::wstring>& Collection::getAuthors() { return authors; };
void Collection::setAuthors(std::vector<std::wstring>& authors) { this->authors = authors; };
Edition* Collection::copy() {
	return new Collection(*this);
}

Collection::~Collection()
{
}

bool Comp::operator() (Edition* a, Edition* b) const {
	std::wstring t1 = a->getNumber(), t2 = b->getNumber();
	std::string temp1, temp2;
	std::transform(t1.begin(), t1.end(), std::back_inserter(temp1), [](wchar_t c) { return (char)c; });
	std::transform(t2.begin(), t2.end(), std::back_inserter(temp2), [](wchar_t c) { return (char)c; });
	return t1 < t2;
}
bool CompByCirc::operator() (Edition* a, Edition* b) const {
	return a->getCirculation() < b->getCirculation();
}
bool CompByISBN::operator() (Edition* a, Edition* b) const {
	return a->getNumber() < b->getNumber();
}
bool CompByName::operator() (Edition* a, Edition* b) const {
	return a->getName() < b->getName();
}
bool CompByAuthor::operator() (Edition* a, Edition* b) const {
	return a->getAuthor() < b->getAuthor();
}
bool CompByRating::operator() (Edition* a, Edition* b) const {
	return a->getAgeRating() < b->getAgeRating();
}
bool CompByStr::operator() (Edition* a, Edition* b) const {
	return a->getStrNumber() < b->getStrNumber();
}
bool RangeComp::operator()(Edition* s, std::wstring i) {
	std::wstring t1 = s->getNumber();
	std::string temp1;
	std::transform(t1.begin(), t1.end(), std::back_inserter(temp1), [](wchar_t c) { return (char)c; });
	return t1 < i;
}
bool RangeComp::operator()(std::wstring i, Edition* s) {
	std::wstring t1 = s->getNumber();
	std::string temp1;
	std::transform(t1.begin(), t1.end(), std::back_inserter(temp1), [](wchar_t c) { return (char)c; });
	return i < t1;
}

DB::DB() {
	books = new std::vector<Edition*>;
	magazines = new std::vector<Edition*>;
	collections = new std::vector<Edition*>;
	std::wstring number = L"";
	std::wstring name;
	std::wstring formatType;
	std::wstring state;
	int ageRating;
	int strNumber;
	int circulation;
	std::wstring author;
	std::vector<std::wstring> authors;
	std::wifstream file("books.txt");
	file.imbue(loc);
	for (; file.is_open() && !file.eof();) {
		size_t posn;
		number = L"";
		file >> number >> name >> author >> ageRating >> strNumber >> formatType >> circulation >> state;
		while (std::wstring::npos != (posn = number.find(L"_"))) number.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = name.find(L"_"))) name.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = author.find(L"_"))) author.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = formatType.find(L"_"))) formatType.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = state.find(L"_"))) state.replace(posn, 1, L" ");
		if (number != L"")
			books->push_back(new Book(number, name, author, ageRating, strNumber, formatType, circulation, state));
	}
	file.close();
	file = std::wifstream("magazines.txt");
	file.imbue(loc);
	for (; file.is_open() && !file.eof();) {
		size_t posn;
		number = L"";
		file >> number >> name >> ageRating >> strNumber >> formatType >> circulation >> state;
		while (std::wstring::npos != (posn = number.find(L"_"))) number.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = name.find(L"_"))) name.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = formatType.find(L"_"))) formatType.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = state.find(L"_"))) state.replace(posn, 1, L" ");
		if (number != L"")
			magazines->push_back(new Magazine(number, name, ageRating, strNumber, formatType, circulation, state));
	}
	file.close();
	file = std::wifstream("collections.txt");
	file.imbue(loc);
	for (; file.is_open() && !file.eof();) {
		size_t posn;
		number = L"";
		file >> number >> name >> author >> ageRating >> strNumber >> formatType >> circulation >> state;
		while (std::wstring::npos != (posn = number.find(L"_"))) number.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = name.find(L"_"))) name.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = author.find(L"_"))) author.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = formatType.find(L"_"))) formatType.replace(posn, 1, L" ");
		while (std::wstring::npos != (posn = state.find(L"_"))) state.replace(posn, 1, L" ");
		if (number != L"") {
			std::vector<std::wstring> authors;
			wchar_t* input = new wchar_t[1024];
			wcscpy_s(input, 1024, author.c_str());;
			wchar_t* buffer;
			wchar_t* token = wcstok_s(input, L" ", &buffer);
			while (token)
			{
				authors.push_back(std::wstring(token));
				token = wcstok_s(nullptr, L" ", &buffer);
			}
			delete[] input;
			delete token;
			collections->push_back(new Collection(number, name, authors, ageRating, strNumber, formatType, circulation, state));
		}
	}
	file.close();
};
DB::~DB() {
	saveFile();
	for (std::vector<Edition*>::iterator it = books->begin(); it != books->end(); ++it) {
		delete* it;
	}
	for (std::vector<Edition*>::iterator it = magazines->begin(); it != magazines->end(); ++it) {
		delete* it;
	}
	for (std::vector<Edition*>::iterator it = collections->begin(); it != collections->end(); ++it) {
		delete* it;
	}
	books->clear();
	magazines->clear();
	collections->clear();
	delete books;
	delete magazines;
	delete collections;
}
DB::DB(const DB& temp) {
	for (std::vector<Edition*>::iterator it = books->begin(); it != books->end(); ++it) {
		delete* it;
	}
	for (std::vector<Edition*>::iterator it = magazines->begin(); it != magazines->end(); ++it) {
		delete* it;
	}
	for (std::vector<Edition*>::iterator it = collections->begin(); it != collections->end(); ++it) {
		delete* it;
	}
	books->clear();
	magazines->clear();
	collections->clear();
	delete books;
	delete magazines;
	delete collections;
	books = new std::vector<Edition*>;
	magazines = new std::vector<Edition*>;
	collections = new std::vector<Edition*>;
	for (std::vector<Edition*>::iterator i = temp.books->begin(); i != temp.books->end(); ++i) {
		books->push_back((*i)->copy());
	}
	for (std::vector<Edition*>::iterator i = temp.magazines->begin(); i != temp.magazines->end(); ++i) {
		magazines->push_back((*i)->copy());
	}
	for (std::vector<Edition*>::iterator i = temp.collections->begin(); i != temp.collections->end(); ++i) {
		collections->push_back((*i)->copy());
	}
};
DB& DB::operator=(const DB& temp) {
	if (this != &temp) {
		for (std::vector<Edition*>::iterator it = books->begin(); it != books->end(); ++it) {
			delete* it;
		}
		for (std::vector<Edition*>::iterator it = magazines->begin(); it != magazines->end(); ++it) {
			delete* it;
		}
		for (std::vector<Edition*>::iterator it = collections->begin(); it != collections->end(); ++it) {
			delete* it;
		}
		books->clear();
		magazines->clear();
		collections->clear();
		delete books;
		delete magazines;
		delete collections;
		books = new std::vector<Edition*>;
		magazines = new std::vector<Edition*>;
		collections = new std::vector<Edition*>;
		for (std::vector<Edition*>::iterator i = temp.books->begin(); i != temp.books->end(); ++i) {
			books->push_back((*i)->copy());
		}
		for (std::vector<Edition*>::iterator i = temp.magazines->begin(); i != temp.magazines->end(); ++i) {
			magazines->push_back((*i)->copy());
		}
		for (std::vector<Edition*>::iterator i = temp.collections->begin(); i != temp.collections->end(); ++i) {
			collections->push_back((*i)->copy());
		}
	}
	return *this;
};
void DB::saveFile() {
	std::wofstream file("books.txt", std::wofstream::trunc);
	file.imbue(loc);
	for (std::vector<Edition*>::iterator i = books->begin(); i != books->end(); ++i) {
		size_t posn;
		std::wstring number = (*i)->getNumber();
		std::wstring name = (*i)->getName();
		std::wstring author = (*i)->getAuthor();
		std::wstring formatType = (*i)->getFormatType();
		std::wstring state = (*i)->getState();
		while (std::wstring::npos != (posn = number.find(L" "))) number.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = name.find(L" "))) name.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = author.find(L" "))) author.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = formatType.find(L" "))) formatType.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = state.find(L" "))) state.replace(posn, 1, L"_");
		file << number << " " << name << " " << author << " " << (*i)->getAgeRating() << " " << (*i)->getStrNumber() << " " << formatType << " " << (*i)->getCirculation() << " " << state;
		file << std::endl;
	}
	file.close();
	file = std::wofstream("magazines.txt", std::wofstream::trunc);
	file.imbue(loc);
	for (std::vector<Edition*>::iterator i = magazines->begin(); i != magazines->end(); ++i) {
		size_t posn;
		std::wstring number = (*i)->getNumber();
		std::wstring name = (*i)->getName();
		std::wstring formatType = (*i)->getFormatType();
		std::wstring state = (*i)->getState();
		while (std::wstring::npos != (posn = number.find(L" "))) number.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = name.find(L" "))) name.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = formatType.find(L" "))) formatType.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = state.find(L" "))) state.replace(posn, 1, L"_");
		file << number << " " << name << " " << (*i)->getAgeRating() << " " << (*i)->getStrNumber() << " " << formatType << " " << (*i)->getCirculation() << " " << state;
		file << std::endl;
	}
	file.close();
	file = std::wofstream("collections.txt", std::wofstream::trunc);
	file.imbue(loc);
	for (std::vector<Edition*>::iterator i = collections->begin(); i != collections->end(); ++i) {
		size_t posn;
		std::vector<std::wstring> authors = (*i)->getAuthors();
		std::wstring authors_str = L"";
		std::wstring number = (*i)->getNumber();
		std::wstring name = (*i)->getName();
		std::wstring formatType = (*i)->getFormatType();
		std::wstring state = (*i)->getState();
		while (std::wstring::npos != (posn = number.find(L" "))) number.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = name.find(L" "))) name.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = formatType.find(L" "))) formatType.replace(posn, 1, L"_");
		while (std::wstring::npos != (posn = state.find(L" "))) state.replace(posn, 1, L"_");
		for (int i = 0; i < authors.size(); ++i) {
			authors_str += authors[i];
			if (i != authors.size() - 1) authors_str += L"_";
		}
		file << number << " " << name << " " << authors_str << " " << (*i)->getAgeRating() << " " << (*i)->getStrNumber() << " " << formatType << " " << (*i)->getCirculation() << " " << state;
		file << std::endl;
	}
	file.close();
}

DB* db = new DB();

void FUNCTIONS_API getAll(std::vector<int> &types, std::vector<int>(&ageRatings), std::vector<int>(&strNumbers), std::vector<int>(&circulations), std::vector<std::vector<std::wstring>>(&str), std::wstring filter, int number) {
	std::locale::global(std::locale(""));
	std::transform(filter.begin(), filter.end(), filter.begin(), towlower);
	std::multiset<Edition*, Comp> temp;
	std::multiset<Edition*, Comp> all;
	std::vector<Edition*> sorting;
	std::set_union(db->books->begin(), db->books->end(), db->magazines->begin(), db->magazines->end(), std::inserter(temp, temp.begin()), Comp());
	std::set_union(temp.begin(), temp.end(), db->collections->begin(), db->collections->end(), std::inserter(all, all.begin()), Comp());
	if (number == 0) {
		std::multiset<Edition*, CompByISBN> t;
		for (std::multiset<Edition*, Comp>::iterator i = all.begin(); i != all.end(); ++i) {
			t.insert(*i);
		}
		for (std::multiset<Edition*, CompByCirc>::iterator i = t.begin(); i != t.end(); ++i) {
			sorting.push_back(*i);
		}
	}
	else if (number == 1) {
		std::multiset<Edition*, CompByName> t;
		for (std::multiset<Edition*, Comp>::iterator i = all.begin(); i != all.end(); ++i) {
			t.insert(*i);
		}
		for (std::multiset<Edition*, CompByCirc>::iterator i = t.begin(); i != t.end(); ++i) {
			sorting.push_back(*i);
		}
	}
	else if (number == 2) {
		std::multiset<Edition*, CompByAuthor> t;
		for (std::multiset<Edition*, Comp>::iterator i = all.begin(); i != all.end(); ++i) {
			t.insert(*i);
		}
		for (std::multiset<Edition*, CompByCirc>::iterator i = t.begin(); i != t.end(); ++i) {
			sorting.push_back(*i);
		}
	}
	else if (number == 3) {
		std::multiset<Edition*, CompByRating> t;
		for (std::multiset<Edition*, Comp>::iterator i = all.begin(); i != all.end(); ++i) {
			t.insert(*i);
		}
		for (std::multiset<Edition*, CompByCirc>::iterator i = t.begin(); i != t.end(); ++i) {
			sorting.push_back(*i);
		}
	}
	else if (number == 4) {
		std::multiset<Edition*, CompByStr> t;
		for (std::multiset<Edition*, Comp>::iterator i = all.begin(); i != all.end(); ++i) {
			t.insert(*i);
		}
		for (std::multiset<Edition*, CompByCirc>::iterator i = t.begin(); i != t.end(); ++i) {
			sorting.push_back(*i);
		}
	}
	else if (number == 5) {
		std::multiset<Edition*, CompByCirc> t;
		for (std::multiset<Edition*, Comp>::iterator i = all.begin(); i != all.end(); ++i) {
			t.insert(*i);
		}
		for (std::multiset<Edition*, CompByCirc>::iterator i = t.begin(); i != t.end(); ++i) {
			sorting.push_back(*i);
		}
	}
	else {
		std::multiset<Edition*, Comp> t;
		for (std::multiset<Edition*, Comp>::iterator i = all.begin(); i != all.end(); ++i) {
			t.insert(*i);
		}
		if (filter.find(L"978") != std::wstring::npos or filter.find(L"979") != std::wstring::npos) {
			auto range = std::equal_range(t.begin(), t.end(), filter, RangeComp{});
			for (auto i = range.first; i != range.second; ++i) {
				sorting.push_back(*i);
			}
		} else {
			for (std::multiset<Edition*, Comp>::iterator i = t.begin(); i != t.end(); ++i) {
				sorting.push_back(*i);
			}
		}
	}
	int j = 0;
	for (std::vector<Edition*>::iterator i = sorting.begin(); i != sorting.end(); ++i) {
		std::wstring number = (*i)->getNumber();
		std::wstring name = (*i)->getName();
		std::transform(name.begin(), name.end(), name.begin(), towlower);
		std::wstring formatType = (*i)->getFormatType();
		std::transform(formatType.begin(), formatType.end(), formatType.begin(), towlower);
		std::wstring state = (*i)->getState();
		std::transform(state.begin(), state.end(), state.begin(), towlower);
		std::wstring ageRating = std::to_wstring((*i)->getAgeRating());
		std::wstring strNumber = std::to_wstring((*i)->getStrNumber());
		std::wstring circulation = std::to_wstring((*i)->getCirculation());
		std::wstring author = (*i)->getAuthor();
		std::transform(author.begin(), author.end(), author.begin(), towlower);
		if (filter == L"" || number.find(filter) != std::wstring::npos || name.find(filter) != std::wstring::npos || ageRating.find(filter) != std::wstring::npos || strNumber.find(filter) != std::wstring::npos || formatType.find(filter) != std::wstring::npos || circulation.find(filter) != std::wstring::npos || state.find(filter) != std::wstring::npos || author.find(filter) != std::wstring::npos) {
			str.push_back(std::vector<std::wstring>());
			str[j].push_back((*i)->getNumber());
			str[j].push_back((*i)->getName());
			str[j].push_back((*i)->getFormatType());
			str[j].push_back((*i)->getState());
			if ((*i)->getAuthor() != L"") {
				str[j].push_back((*i)->getAuthor());
				types.push_back(1);
			}
			else if (!(*i)->getAuthors().empty()){
				std::vector<std::wstring> tmp = (*i)->getAuthors();
				std::wstring temp = L"";
				for (int i = 0; i < tmp.size(); ++i) {
					temp += tmp[i];
					if (i != tmp.size() - 1) temp += L" ";
				}
				str[j].push_back(temp);
				types.push_back(3);
			}
			else {
				str[j].push_back(L"");
				types.push_back(2);
			}
			ageRatings.push_back((*i)->getAgeRating());
			strNumbers.push_back((*i)->getStrNumber());
			circulations.push_back((*i)->getCirculation());
			++j;
		}
	}
}

void FUNCTIONS_API addEdition(std::wstring number,
	std::wstring name, std::wstring author, std::wstring ageRating, std::wstring strNumber, std::wstring formatType, std::wstring circulation, std::wstring state, int type) {
	int ar = std::stoi(ageRating.c_str());
	int strnum = std::stoi(strNumber.c_str());
	int circ = std::stoi(circulation.c_str());
	if (type == 1) {
		db->books->push_back(new Book(
			number,
			name,
			author,
			ar,
			strnum,
			formatType,
			circ,
			state));
	}
	else if (type == 2) {
		db->magazines->push_back(new Magazine(
			number,
			name,
			ar,
			strnum,
			formatType,
			circ,
			state));
	}
	else {
		std::vector<std::wstring> aths;
		wchar_t* input = new wchar_t[1024];
		wcscpy_s(input, 1024, author.c_str());;
		wchar_t* buffer;
		wchar_t* token = wcstok_s(input, L" ", &buffer);
		while (token)
		{
			aths.push_back(input);
			token = wcstok_s(nullptr, L" ", &buffer);
		}
		db->collections->push_back(new Collection(
			number,
			name,
			aths,
			ar,
			strnum,
			formatType,
			circ,
			state));
		delete[] input;
		delete token;
	}
}
void FUNCTIONS_API editState(std::wstring number, std::wstring state) {
	std::set<Edition*, Comp> temp;
	std::set<Edition*, Comp> all;
	std::set_union(db->books->begin(), db->books->end(), db->magazines->begin(), db->magazines->end(), std::inserter(temp, temp.begin()), Comp());
	std::set_union(temp.begin(), temp.end(), db->collections->begin(), db->collections->end(), std::inserter(all, all.begin()), Comp());
	for (std::set<Edition*, Comp>::iterator i = all.begin(); i != all.end(); ++i) {
		if ((*i)->getNumber() == number) {
			(*i)->setState(state);
			break;
		}
	}
}
void FUNCTIONS_API deleteEdition(std::wstring number) {
	bool flag = false;
	for (std::vector<Edition*>::iterator i = db->books->begin(); i != db->books->end(); ++i) {
		if ((*i)->getNumber() == number) {
			delete *i;
			db->books->erase(i);
			flag = true;
			break;
		}
	}
	if (flag) {
		return;
	}
	for (std::vector<Edition*>::iterator i = db->magazines->begin(); i != db->magazines->end(); ++i) {
		if ((*i)->getNumber() == number) {
			delete* i;
			db->magazines->erase(i);
			flag = true;
			break;
		}
	}
	if (flag) {
		return;
	}
	for (std::vector<Edition*>::iterator i = db->collections->begin(); i != db->collections->end(); ++i) {
		if ((*i)->getNumber() == number) {
			delete* i;
			db->collections->erase(i);
			flag = true;
			break;
		}
	}
}

LONG_PTR FUNCTIONS_API Memory(wchar_t** s_array, int& s_len) {
	close();
	char* c = new char('W');
	HANDLE hLogFile;
	hLogFile = CreateFile(L"log.txt", GENERIC_WRITE,
		FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, hLogFile);
	_CrtDumpMemoryLeaks();
	CloseHandle(hLogFile);
	std::wifstream in(L"log.txt");
	std::wstring  ws((std::istreambuf_iterator<wchar_t >(in)), std::istreambuf_iterator<wchar_t>());
	wchar_t* n_sarr = (wchar_t*)CoTaskMemAlloc((ws.size() + 1) * sizeof(wchar_t*));
	ZeroMemory((n_sarr), (ws.size() + 1) * sizeof(wchar_t));
	StringCchCatW(n_sarr, ws.size() + 1, ws.data());

	*s_array = n_sarr;
	s_len = ws.size() + 1;
	return 1;
}

void FUNCTIONS_API close() {
	delete db;
}
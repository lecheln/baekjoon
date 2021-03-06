#include "String.h"

mystd::String::String() {
	str = NULL;
	textsize = 1;
}

mystd::String::String(String &text) {
	textsize = text.textsize;
	str = new char[textsize];
	strncpy(str, text.str, textsize);
}
mystd::String::String(const char * text){
	textsize = strlen(text) + 1;
	str = new char[textsize];
	strncpy(str, text, textsize);
}
mystd::String::String(char text){
	textsize = 2;
	str = new char[textsize];
	str[0] = text;
	str[1] = '\0';
}

mystd::String::~String() {
	delete[] str;
}


void  mystd::String::assign(const char *text) {
	textsize = strlen(text) + 1;
	str = new char[textsize];
	strncpy(str, text, textsize);
}
void  mystd::String::assign(String &text) {
	textsize = text.textsize;
	str = new char[textsize];
	strncpy(str, text.str, textsize);
}
void  mystd::String::assign(int count, char word) {
	textsize = count + 1;
	str = new char[textsize];
	for (int i = 0; i < textsize - 1; i++)
		str[i] = word;
	str[textsize - 1] = '\0';
}
void  mystd::String::assign(const char *text, int start, int count) {
	textsize = count + 1;
	str = new char[textsize];
	for (int i = 0; i < textsize - 1; i++)
		str[i] = text[start + i];
	str[textsize - 1] = '\0';

}
void  mystd::String::assign(String &text, int start, int count) {
	textsize = count + 1;
	str = new char[textsize];
	for (int i = 0; i < textsize - 1; i++)
		str[i] = text.str[start + i];
	str[textsize - 1] = '\0';
}


void  mystd::String::append(const char *text) {
	str = (char*)realloc(str, textsize + strlen(text));
	for (int i = 0; i < strlen(text); i++)
		str[textsize - 1 + i] = text[i];
	textsize += strlen(text);
	str[textsize - 1] = '\0';
}
void  mystd::String::append(String &Text) {
	str = (char*)realloc(str, textsize + Text.textsize - 1);
	for (int i = 0; i < Text.textsize; i++)
		str[textsize - 1 + i] = Text.str[i];
	textsize += Text.textsize - 1;
	str[textsize - 1] = '\0';
}
void  mystd::String::append(int count, char word) {
	str = (char*)realloc(str, textsize + count);
	for (int i = 0; i < count; i++)
		str[textsize - 1 + i] = word;
	textsize += count;
	str[textsize - 1] = '\0';
}
void  mystd::String::append(const char *text, int start, int count) {
	str = (char*)realloc(str, textsize + count);
	for (int i = 0; i < count; i++)
		str[textsize - 1 + i] = text[start+ i];
	textsize += count;
	str[textsize - 1] = '\0';
}
void  mystd::String::append(String &text, int start, int count) {
	str = (char*)realloc(str, textsize + count);
	for (int i = 0; i < count; i++)
		str[textsize - 1 + i] = text.str[start + i];
	textsize += count;
	str[textsize - 1] = '\0';
}


void  mystd::String::clear() {
	delete[] str;
	textsize = 1;
	str = NULL;
}

int mystd::String::compare(String &text) {
	return strcmp(str, text.str);
}
int  mystd::String::compare(const char *text) {
	return strcmp(str, text);
}

bool mystd::String::empty() const {
	if (textsize == 1) return 1;
	else return 0;
}

void  mystd::String::erase(int start, int num) {
	for (int i = start; i < textsize - num; i++)
		str[i] = str[i + num];
	textsize -= num;
	str = (char*)realloc(str, textsize);
	str[textsize - 1] = '\0';
}

int  mystd::String::find(char text){
	for (int i = 0; i < textsize; i++)
		if (str[i] == text) return i;
	return -1;
}

int  mystd::String::find(const char * text) {
	char * tmp = strstr(str, text);
	if (tmp == NULL) return -1;
	return (tmp - str);
}

int  mystd::String::find(const char * text, int start){
	char * tmp = strstr(str + start, text);
	if (tmp == NULL) return -1;
	return (tmp - str);
}

int  mystd::String::find(String & text, int start){
	char * tmp = strstr(str + start, text.str);
	if (tmp == NULL) return -1;
	return (tmp - str);
}

void  mystd::String::insert(int start, const char * text) {
	textsize += strlen(text);
	str = (char*)realloc(str, textsize);
	for (int i = start; i + strlen(text) < textsize; i++)
		str[i + strlen(text)] = str[i];
	for (int i = 0; i < strlen(text); i++)
		str[i + start] = text[i];
}

void  mystd::String::insert(int start, String & text) {
	textsize += strlen(text.str);
	str = (char*)realloc(str, textsize);
	for (int i = start; i + strlen(text.str) < textsize; i++)
		str[i + strlen(text.str)] = str[i];
	for (int i = 0; i < strlen(text.str); i++)
		str[i + start] = text.str[i];
}

char  mystd::String::pop_back() {
	int tmp = str[textsize - 2];
	str[textsize - 2] = '\0';
	str = (char*)realloc(str, textsize - 1);
	textsize -= 1;
	return tmp;
}

void  mystd::String::push_back(char text){
	str = (char*)realloc(str, textsize + 1);
	str[textsize] = '\0';
	str[textsize - 1] = text;
	textsize += 1;
}

void  mystd::String::resize(size_t n) {
	textsize = n+1;
	str = (char*)realloc(str, n);
	str[textsize - 1] = '\0';
}

void  mystd::String::resize(size_t n, char c) {
	str = (char*)realloc(str, n + 1);
	str[textsize-1] = c;
	str[textsize] = '\0';
	textsize = n +1 ;
}

void  mystd::String::replace(int start, int count, const char * text) {
	for (int i = 0; i < count; i++)
		str[i + start] = text[i];
}

void  mystd::String::replace(int start, int count, String & text) {
	for (int i = 0; i < count; i++)
		str[i + start] = text.str[i];
}

size_t mystd::String::size() const{
	return textsize - 1;
}

size_t mystd::String::length() const {
	return textsize - 1;
}

size_t mystd::String::max_size() const {
	return textsize;
}

size_t mystd::String::capacity() const {
	return textsize;
}

void  mystd::String::reserve(size_t n) {
	str = (char*)realloc(str, textsize + n);
	textsize += n;
}

char& mystd::String::substr(int start) {
	char*tmp;
	tmp = new char[textsize - start];
	for (int i = 0; i < textsize - start; i++)
		tmp[i] = str[start + i];
	return tmp;
}

char&  mystd::String::substr(int start, int count) {
	char*tmp;
	tmp = new char[count + 1];
	for (int i = 0; i < count; i++)
		tmp[i] = str[start + i];
	tmp[count] = '\0';
	return &tmp;
}


void  mystd::String::swap(String & text) {
	String temp = text;
	delete []text.str;
	text.str = new char[textsize];
	strncpy(text.str, str, textsize);
	text.textsize = textsize;
	delete[]str;
	str = new char[temp.textsize];
	strncpy(str, temp.str, temp.textsize);
	textsize = temp.textsize;
}

char&  mystd::String::at(size_t start) {
	return str[start];
}

char * mystd::String::c_str() {
	return str;
}

char&  mystd::String::front(){
	return str[0];
}

char&  mystd::String::back(){
	return str[textsize - 2];
}

mystd::String&  mystd::String::operator=(const String & text){
	delete[] str;
	textsize = text.textsize;
	str = new char[textsize];
	strncpy(str, text.str, textsize);
	return *this;
}

mystd::String&  mystd::String::operator=(const char* s) {
	delete[] str;
	textsize = strlen(s) + 1;
	str = new char[textsize];
	strncpy(str, s, textsize);
	return *this;
}

mystd::String&  mystd::String::operator=(char c) {
	delete[] str;
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
	textsize = 2;
	return *this;
}

char& mystd::String::operator[](size_t pos) {
	return str[pos];
}

std::istream&  mystd::String::getline(std::istream& os, String& obj) {
	char a[100000];
	int i;
	for (i = 0; a[i] != '\n';i++) {
		os.get(a[i]);
		if (a[i] == '\n')break;
	}
	obj.str = new char[i + 1];
	obj.textsize = i + 1;
	strncpy(obj.str, a, obj.textsize);
	return os;
}

void  mystd::operator+=(String & left, String & right) {
	left.str = (char*)realloc(left.str, left.textsize + right.textsize - 1);
	for (int i = 0; i < right.textsize; i++)
		left.str[left.textsize - 1 + i] = right.str[i];
	left.textsize += right.textsize - 1;
	left.str[left.textsize - 1] = '\0';
}

void  mystd::operator+=(String & left, const char * right) {
	left.str = (char*)realloc(left.str, left.textsize + strlen(right));
	for (int i = 0; i < strlen(right)+1; i++)
		left.str[left.textsize - 1 + i] = right[i];
	left.textsize += strlen(right);
	left.str[left.textsize - 1] = '\0';
}

void  mystd::operator+=(String & left, char right) {
	left.str = (char*)realloc(left.str, left.textsize + 1);
	left.str[left.textsize] = '\0';
	left.str[left.textsize - 1] = right;
}

std::ostream &  mystd::operator<<(std::ostream & os, String & obj) {
	for (int i = 0; i < obj.textsize - 1; i++) {
		if (obj.str[i] == '\0') break;
		else os << obj.str[i];
	}
	return os;
}

std::istream &  mystd::operator>>(std::istream & os, String & obj) {
	char tmp[100000];
	os >> tmp;
	strcpy(obj.str, tmp);
	obj.textsize = strlen(obj.str) + 1;
	return os;
}

#pragma once
#include <iostream>

enum {
	SUM,	//sum
	MUL,	//mul
	COMMA,	// ,
	R_BRACE,// )
	NUM,	// число
	ERR,	// ошибка
	END,	// конец предложения
};

class Parser {

public:
	Parser();
	~Parser() {};

	void get_sentence();
	int scan();
	void get_res();
	void print_res();

	std::string sent;
private:
	FILE* file;

	int i;
	int val;
	int sym;
	int res;

	int mul();
	int sum();
	int count();
};
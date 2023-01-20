#pragma once
#include <iostream>


/*	Грамматика
* 
	< O > :: = <FUNC> | num
	< FUNC > :: = <F>(<K>,<K>{,<K>})
	< K > :: = < O > 
*/

enum {
	FUNC,	// функция
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
	void result();
	void print_res();

	
private:
	FILE* file;

	int i;
	int val;
	std::string function;
	int sym;
	int res;

	std::string sent;

	int O();
	int func();
	int mul();
	int sum();
	int K();

	int scan();
	
};
#pragma once
#include <iostream>


/*	����������
	< O > :: = <SUM> | <MUL>
	< SUM > :: = sum(<K>,<K>{,<K>})
	< MUL > :: = mul(<K>,<K>{,<K>})
	< K > :: = <O> | num
*/

enum {
	SUM,	//sum
	MUL,	//mul
	COMMA,	// ,
	R_BRACE,// )
	NUM,	// �����
	ERR,	// ������
	END,	// ����� �����������
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
	int sym;
	int res;

	std::string sent;

	int O();
	int mul();
	int sum();
	int K();

	int scan();
	
};
#include "Parser.h"

using namespace std;

Parser::Parser() :i(0), val(0), res(0) 
{};

void Parser::get_sentence() {

	char symbol = ' ';

	file = fopen("sentence.txt", "r");
	if (file == NULL) {
		perror("Error");
	}

	while (symbol != EOF) {
	if(symbol != ' ')
		sent += symbol;
	symbol = fgetc(file);
	} 
};

int Parser::scan() {

	size_t len = sent.length();

	if (i < len) {
		if (sent[i] >= 'a' && sent[i] <= 'z') {
			function = sent[i];
			i++;
			while (sent[i] >= 'a' && sent[i] <= 'z') {
				function += sent[i];
				i++;
			}
			if (sent[i] != '(') {
				cout << "Invalid input";
				exit(-1);
			}
			i++;
			return FUNC;
		}
		else if (sent[i] == ',') {
			i++;
			return COMMA;
		}
		else if (sent[i] == ')') {
			i++;
			return R_BRACE;
		}
		else if (sent[i] >= '0' && sent[i] <= '9') {
			val = sent[i] - '0';
			i++;
			while (sent[i] >= '0' && sent[i] <= '9')
			{
				val = val * 10 + sent[i] - '0';
				i++;
			}
			return NUM;
		}
		else {
			return ERR;
		}
	}
	return END;
};

void Parser::result() {
	sym = scan();
	res = O();
	sym = scan();
	if (sym != END) {
		cout << "Invalid input";
		exit(-1);
	}

}

int Parser::O() {
	if (sym != FUNC && sym != NUM) {
		cout << "Invalid input";
		exit(-1);
	}

	int res_o = 0;
	switch (sym) {
	case (FUNC):
		res_o = func();
		break;
	case (NUM):
		res_o = val;
		break;
	}
return res_o;
}

int Parser::func() {
	int res_func = 0;
	if (function == "sum") {
		res_func = sum();
	}
	else if (function == "mul"){
		res_func = mul();
	}
	else {
		cout << "Invalid input";
		exit(-1);
	}
	return res_func;
}

int Parser::sum() {
	sym = scan();
	int res_sum = K();
	int flg = 0;
	while (sym == COMMA) {
		sym = scan();
		res_sum += K();
		flg += 1;
	}
	if (sym != R_BRACE) {
		cout << "Invalid input";
		exit(-1);
	}
	if (flg < 1) {
		cout << "Too few arguments!";
		exit(-1);
	}
	return res_sum;
}

int Parser::mul() {
	sym = scan();
	int res_mul = K();
	int flg = 0;
	while (sym == COMMA) {
		sym = scan();
		res_mul *= K();
		flg += 1;
	}
	if (sym != R_BRACE) {
		cout << "Invalid input";
		exit(-1);
	}
	if (flg < 1) {
		cout << "Too few arguments!";
		exit(-1);
	}
	return res_mul;
}

int Parser::K() {
			int res_k = O();
			sym = scan();
			return res_k;
}

void Parser::print_res() {
	cout << res;
}
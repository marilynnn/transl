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
		if (sent[i] == 's' && sent[i + 1] == 'u' && sent[i + 2] == 'm' && sent[i + 3] == '(') {
			i += 4;
			return SUM;
		}
		else if (sent[i] == 'm' && sent[i + 1] == 'u' && sent[i + 2] == 'l' && sent[i + 3] == '(') {
			i += 4;
			return MUL;
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

void Parser::get_res() {
	sym = scan();
	if (sym != SUM && sym != MUL) {
		cout << "Invalid input";
		exit(-1);
	}
	res = count();
}

void Parser::print_res() {
	cout << res;
}

int Parser::sum() {
	int res_s = count();
	int flg = 0;
	while (sym == COMMA) {
		sym = scan();
		res_s += count();
		flg += 1;
	}
	if (flg < 1) {
		cout << "Too few arguments!";
		exit(-1);
	}
	return res_s;
}

int Parser::mul() {
	int res_s = count();
	int flg = 0;
	while (sym == COMMA) {
		sym = scan();
		res_s *= count();
		flg += 1;
	}
	if (flg < 1) {
		cout << "Too few arguments!";
		exit(-1);
	}
	return res_s;
}

int Parser::count() {
	switch (sym) {
		case SUM: {
			sym = scan();
			int res_c = sum();
			if (sym != R_BRACE) {
				cout << "There is brace disbalance!";
				exit(-1);
			}
			sym = scan();
			return res_c;
		}
		case MUL: {
			sym = scan();
			int res_c = mul();
			if (sym != R_BRACE) {
				cout << "There is brace disbalance!";
				exit(-1);
			}
			sym = scan();
			return res_c;
		}
		case NUM: {
			int res_c = val;
			sym = scan();
			return res_c;
		}
		default: {
			cout << "Invalid input!";
			exit(-1);
		}
	}
}

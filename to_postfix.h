#pragma once
#include <string>
#include <iostream>

struct element {
	std::string postfix_notation;
	int result;
	element() {
		postfix_notation = ' ';
		result = 0;
	}
};
std::ostream& operator<<(std::ostream& os, element& elem);

int convert_to_int(std::string operand);
int calculate_postfix(std::string);
int calculate_postfix(std::string expression);
element to_postfix(std::string);
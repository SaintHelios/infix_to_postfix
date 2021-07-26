#include "to_postfix.h"
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;


ostream& operator<<(ostream& os, element& elem) {
	os << elem.postfix_notation << " = " << elem.result;
	return os;
}

int convert_to_int(string operand) {
	return stoi(operand);
}

int calculate_postfix(string expression) {
	stack<string> input_stack;
	int to_return;
	for (size_t i = 0; expression[i] != '\0'; ++i) {
		if (expression[i] == ' ') continue;

		if (expression[i] >= 48 && expression[i] <= 57) {
			string operand;
			if (expression[i + 1] >= 48 && expression[i + 1] <= 57) {
				size_t num_iterator = i;

				while (expression[num_iterator] >= 48 && expression[num_iterator] <= 57) {
					operand.push_back(expression[num_iterator]);
					++num_iterator;
				}
				i = num_iterator;
				input_stack.push(operand);
			}
			else {
				operand.push_back(expression[i]);
				input_stack.push(operand);
			}
			operand.clear();
		}

		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			string left_operand;
			string right_operand;
			string operand;
			switch (expression[i]) {
			case '+':
				int result;

				if (input_stack.top()[1] >= 48 && input_stack.top()[1] <= 57) {
					size_t num_iterator = 0;
					while (input_stack.top()[num_iterator] >= 48 && input_stack.top()[num_iterator] <= 57) {
						operand.push_back(input_stack.top()[num_iterator]);
						++num_iterator;
					}
					input_stack.pop();
				}
				else {
					operand.push_back(input_stack.top()[0]);
					input_stack.pop();
				}
				right_operand = operand;
				operand.clear();

				if ((input_stack.top())[1] >= 48 && (input_stack.top())[1] <= 57) {
					size_t num_iterator = 0;
					while (input_stack.top()[num_iterator] >= 48 && input_stack.top()[num_iterator] <= 57) {
						operand.push_back(input_stack.top()[num_iterator]);
						++num_iterator;
					}
					input_stack.pop();
				}
				else {
					operand.push_back(input_stack.top()[0]);
					input_stack.pop();
				}
				left_operand = operand;
				operand.clear();

				result = convert_to_int(left_operand) + convert_to_int(right_operand);
				input_stack.push(to_string(result));
				left_operand.clear();
				right_operand.clear();
				break;
			case '-':
				result;
				if ((input_stack.top())[1] >= 48 && (input_stack.top())[1] <= 57) {
					size_t num_iterator = 0;
					while ((input_stack.top())[num_iterator] >= 48 && (input_stack.top())[num_iterator] <= 57) {
						operand.push_back(input_stack.top()[num_iterator]);
						++num_iterator;
					}
					input_stack.pop();
				}
				else {
					operand.push_back(input_stack.top()[0]);
					input_stack.pop();
				}
				right_operand = operand;
				operand.clear();

				if ((input_stack.top())[1] >= 48 && (input_stack.top())[1] <= 57) {
					size_t num_iterator = 0;
					while ((input_stack.top())[num_iterator] >= 48 && (input_stack.top())[num_iterator] <= 57) {
						operand.push_back(input_stack.top()[num_iterator]);
						++num_iterator;
					}
					input_stack.pop();
				}
				else {
					operand.push_back(input_stack.top()[0]);
					input_stack.pop();
				}
				left_operand = operand;
				operand.clear();

				result = convert_to_int(left_operand) - convert_to_int(right_operand);
				input_stack.push(to_string(result));
				left_operand.clear();
				right_operand.clear();
				break;
			case '*':
				result;
				if (input_stack.top()[1] >= 48 && input_stack.top()[1] <= 57) {
					size_t num_iterator = 0;
					while (input_stack.top()[num_iterator] >= 48 && input_stack.top()[num_iterator] <= 57) {
						operand.push_back(input_stack.top()[num_iterator]);
						++num_iterator;
					}
					input_stack.pop();
				}
				else {
					operand.push_back(input_stack.top()[0]);
					input_stack.pop();
				}
				right_operand = operand;
				operand.clear();

				if (input_stack.top()[1] >= 48 && input_stack.top()[1] <= 57) {
					size_t num_iterator = 0;
					while (input_stack.top()[num_iterator] >= 48 && input_stack.top()[num_iterator] <= 57) {
						operand.push_back(input_stack.top()[num_iterator]);
						++num_iterator;
					}
					input_stack.pop();
				}
				else {
					operand.push_back(input_stack.top()[0]);
					input_stack.pop();
				}
				left_operand = operand;
				operand.clear();

				result = convert_to_int(left_operand) * convert_to_int(right_operand);
				input_stack.push(to_string(result));
				left_operand.clear();
				right_operand.clear();
				break;
			case '/':
				result;
				if (input_stack.top()[1] >= 48 && input_stack.top()[1] <= 57) {
					size_t num_iterator = 0;
					while (input_stack.top()[num_iterator] >= 48 && input_stack.top()[num_iterator] <= 57) {
						operand.push_back(input_stack.top()[num_iterator]);
						++num_iterator;
					}
					input_stack.pop();
				}
				else {
					operand.push_back(input_stack.top()[0]);
					input_stack.pop();
				}
				right_operand = operand;
				operand.clear();

				if (input_stack.top()[1] >= 48 && input_stack.top()[1] <= 57) {
					size_t num_iterator = 0;
					while (input_stack.top()[num_iterator] >= 48 && input_stack.top()[num_iterator] <= 57) {
						operand.push_back(input_stack.top()[num_iterator]);
						++num_iterator;
					}
					input_stack.pop();
				}
				else {
					operand.push_back(input_stack.top()[0]);
					input_stack.pop();
				}
				left_operand = operand;
				operand.clear();

				result = convert_to_int(left_operand) / convert_to_int(right_operand);
				input_stack.push(to_string(result));
				left_operand.clear();
				right_operand.clear();
				break;
			}

		}
	}
	to_return = convert_to_int(input_stack.top());
	input_stack.pop();
	return to_return;
}

size_t define_priority(char to_define) {
	switch (to_define) {
	case '(':
		return 0;
		break;
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	}
}

element to_postfix(string input_string) {

	element to_return;
	stack<char> operators_stack;
	string result_string;
	size_t iter = 0;

	input_string.push_back(' ');
	while (input_string[iter] != '\0') {
		if (input_string[iter] == '+' || input_string[iter] == '-' || input_string[iter] == '*' || input_string[iter] == '/') {
			input_string.insert(iter, " ");
			iter += 2;
		}
		if (input_string[iter] == ')') {
			input_string.insert(iter, " ");
			iter += 2;
		}
		else ++iter;
	}

	for (size_t i = 0; input_string[i] != '\0'; ++i) {

		if (input_string[i] == ' ' || input_string[i] == '\n') continue;

		if (input_string[i] >= 48 && input_string[i] <= 57) {
			if (input_string[i + 1] >= 48 && input_string[i + 1] <= 57) {
				string operand;
				size_t num_iterator = i;

				while (input_string[num_iterator] >= 48 && input_string[num_iterator] <= 57) {
					operand.push_back(input_string[num_iterator]);
					++num_iterator;
				}
				i = num_iterator;

				size_t num_iterator_2 = 0;
				while (operand[num_iterator_2] != '\0') {
					result_string.push_back(operand[num_iterator_2]);
					++num_iterator_2;
				}
				result_string.push_back(' ');
			}
			else { 
				result_string.push_back(input_string[i]);
				result_string.push_back(' ');
			}

		}

		else if (input_string[i] == '(') {
			operators_stack.push('(');
		}

		else if (input_string[i] == ')') {
			char iterator;
			iterator = operators_stack.top();
			operators_stack.pop();
			result_string.push_back(iterator);
			result_string.push_back(' ');

			while (iterator != '(') {
				iterator = operators_stack.top();
				operators_stack.pop();
				if (iterator != '(') {
					result_string.push_back(iterator);
					result_string.push_back(' ');
				}
			}
		}

		else if (input_string[i] == '+' || input_string[i] == '-' || input_string[i] == '*' || input_string[i] == '/') {

			if (operators_stack.empty()) operators_stack.push(input_string[i]);

			else {
				while (( !operators_stack.empty() ) && ( define_priority(input_string[i]) <= define_priority(operators_stack.top() ) )) {
					result_string.push_back(operators_stack.top());
					result_string.push_back(' ');
					operators_stack.pop();
				}

				operators_stack.push(input_string[i]);
			}
		}
	}

	while (!operators_stack.empty()) {
		result_string.push_back(operators_stack.top());
		result_string.push_back(' ');
		operators_stack.pop();
	}

	to_return.postfix_notation = result_string;
	to_return.result = calculate_postfix(result_string);
	return to_return;
}
#pragma once
#include <iostream>
class Field
{
	public:
		enum fieldType {
			EMPTY,
			WELL,
			TRAP,
			RELIC
		};
		char symbol;
		fieldType type;
};


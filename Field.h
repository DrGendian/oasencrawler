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
		struct strFieldType {
			char symbol;
			fieldType type;
		};
};


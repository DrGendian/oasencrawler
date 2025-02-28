#pragma once
#include <iostream>
class Field
{
	public:
		enum fieldType {
			EMPTY,
			WELL,
			TRAP,
			RELIC,
			ENEMY
		};
		char symbol;
		fieldType type;
};


#include "Data.h"
#include "List.h"

void IntData::addToList(List * list) {list->insert(*this);}
void StringData::addToList(List * list) {list->insert(*this);}
void FloatData::addToList(List * list) {list->insert(*this);}
void Boolean::addToList(List * list) {list->insert(*this);}
FloatData::~FloatData() {}//std::cout << "~IntData\n";}
IntData::~IntData() {}//std::cout << "~sIntData\n";}
StringData::~StringData() {}//std::cout << "~StringData\n";}
Boolean::~Boolean() {}//std::cout << "~Boolean\n";}
bool FloatData::is_num = true;
bool IntData::is_num = true;
bool StringData::is_num = false;
bool Boolean::is_num = false;
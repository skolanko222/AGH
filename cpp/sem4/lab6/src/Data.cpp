#include "Data.h"
#include "List.h"

void IntData::addToList(List * list) {list->insert(*this);}
void StringData::addToList(List * list) {list->insert(*this);}
void FloatData::addToList(List * list) {list->insert(*this);}
FloatData::~FloatData() {}//std::cout << "~IntData\n";}
IntData::~IntData() {}//std::cout << "~sIntData\n";}
StringData::~StringData() {}//std::cout << "~StringData\n";}
#include "Data.h"
#include "List.h"

void IntData::addToList(List * list) {list->insert(this->_x);}
void StringData::addToList(List * list) {list->insert(this->_str);}
IntData::~IntData() {std::cout << "~IntData\n";}
StringData::~StringData() {std::cout << "~StringData\n";}
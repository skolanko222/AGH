#include "Data.h"
#include "List.h"

void IntData::addToList(List * list) {list->insert(*this);}
void StringData::addToList(List * list) {list->insert(*this);}
void Boolean::addToList(List * list) {list->insert(*this);}
IntData::~IntData() {/*std::cout << "~IntData\n";*/}
StringData::~StringData() {/*std::cout << "~StringData\n";*/}
Boolean::~Boolean() {/*std::cout << "~Boolean\n";*/}
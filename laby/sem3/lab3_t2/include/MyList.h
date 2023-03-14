struct list{
    
    list * next;
    const char * data;

};

struct MyList{
    
    const char * name;
    list * head;

};

void init(MyList * list, const char * name);
void append(MyList * list, const char * str);
bool empty( const MyList * list);
void print(const MyList * list);
void replace(const MyList * list, const char * replace, const char * new_str);
void insertAfter(const MyList * list, const char * before,const  char * after);
void clear(const MyList * list);
void removeAfter(const MyList * list, const char * str);
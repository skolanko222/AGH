#include <iostream>

/**
 * @brief Wstawianie elementu na początek listy
 * Funkcja, jeżeli nie ma wystarczająco pamięci nic nie zmieni, jeżeli ma stworzy nowy element wskazujący na head z wartością przesłaną do funckji
 * @param head wskaźnik do pierwszego elementu listy
 * @param val wartość dodawanego elementu
 * @return node* wskaźnik do pierwszego elemntu listy
 */
node *insert_item_begin(node *head, int val)
{
   node * temp = new node; //stworzenie nowego elementu listy
    if (!temp ) 
    {
        std::cout << "Brak pamieci" << std::endl;
        return head;
    }
    temp -> value = val; //przypisanie wartości nowemu elemntowi
    temp -> next = head; //przypsianie wskaźnika nowego elementu na pierwszy element listy
    return temp; 
}

/**
 * @brief Wstawianie elementu na koniec listy
 * 
 * @param head wskaźnik do pierwszego elementu listy
 * @param val wartość dodawanego elementu
 */
void insert_item_end ( node ** head , int val ) 
{
    node * temp = new node; //stworzenie nowego elementu listy
    if (!temp ) return; //Gdyby nie było wystarczająco pamięci
    temp -> value = val;
    temp -> next = NULL;
    if (* head ) //Jeśli lista nie jest pusta, pętla for przejdzie na sam jej koniec i doda tam element
    {
        node * ele = * head;
        for( ; ele -> next ; ele = ele -> next );
        ele -> next = temp;
    }
    else //Jeśli lista jest pusta doda element jako head
        * head = temp;
}

/**
 * @brief Wstawianie elementu na koniec listy
 * Od dodawania wyżej różni się tym że przekazujemy wskaźnik do heada a nie podwójny wskaźnik
 * @param head wskaźnik do pierwszego elementu listy
 * @param val wartość dodawanego elementu
 * @return node* wskaźnik do pierwszego elementu listy
 */
node * insert_item_end_scnd ( node * head , int val ) 
{
    node * temp = new node;
    if (!temp ) return head; 
    temp -> value = val;
    temp -> next = NULL;
    if ( head ) 
    {
        node *ele = head;
        while ( ele -> next )
            ele = ele -> next;
        ele -> next = temp;
    } 
    else
        head = temp;
    return head;
}

/**
 * @brief wypisuje całą listę
 * Jeżeli lista jest pusta to wypisze odpowiedni komunikat, jeżeli nie, wypisze wszystkie jej elementy
 * @param elem wskaźnik do pierwszego elementu listy
 */
void print_list ( const node * elem ) 
{
    if (! elem ) 
    {
        std::cout << "Lista jest pusta" << std::endl;
        return;
    }
    for (; elem ; elem = elem -> next )
        std::cout << "[" << elem << "]=" << elem -> value << " -> " <<  elem -> next  << std::endl;
}

/**
 * @brief usuwanie wszystkich elementów listy
 * 
 * @param elem wskaźnik do pierwszego elemntu listy
 * @return node* Zwraca NULL do pierwszego elemntu listy
 */
node * delete_all ( node * elem )
{
    while ( elem ) 
    {
        node * next = elem -> next ; //pomocnicza zmienna wskazująca na kolejny element listy
        std::cout << "Usuwam  element" << elem << std::endl;
        delete elem; //usuwanie elementu
        elem = next; //nowym headaem staje się kolejny elemnt listy
    }
    return NULL;
}

/**
 * @brief Przeszukiwanie za pomocą fora
 * 
 * @param elem wskaźnik na pierwszy element listy
 * @param key szukana wartość
 * @return node* wskaźnik do szukanej wartości
 */
node * search_f ( node * elem , int key ) 
{
    for (; elem && elem -> value != key ; elem = elem ->next ); //for przechodzi albo do końca listy, albo do szukanego elementu
    return elem;
}

/**
 * @brief przeszukwanie za pomocą while
 * 
 * @param elem wskaźnik na pierwszy element listy
 * @param key szukana wartość
 * @return node* wskaźnik do szukanej wartości
 */
node * search_w ( node * elem , int key ) 
{
    while ( elem && elem -> value != key ) //while przechodzi albo do końca listy albo do znalezionego elementu
        elem = elem -> next;
    return elem;
}

/**
 * @brief usuwanie wybranego elemntu listy
 * 
 * @param head wskaźnik do pierwszego elementu listy
 * @param key wartość usuwanego elementu
 * @return node* wskaźnik do pierwszego elementu listy
 */
node * del_nod ( node * head , int key ) 
{
    node *cur = head , *prev = NULL; //wskaźnik na aktualny i poprzedni element
    for (; cur && cur -> value != key ; prev = cur , cur= cur -> next ); //for przechodzi do momentu aż znajdzie element albo do końca listy
    if (!cur )
        return head; //Gdy nie znaleniozno usuwanego elementu
    if (!prev )
        head = head -> next; //Gdy usuwany element jest headem, headem staję sięmkolejny element
    else
        prev -> next = cur -> next;
    delete cur;
    return head;
}

/**
 * @brief Odwracanie listy
 * 
 * @param head wskaźnik do pierwszegoo elementu
 * @return node* wskaźnik do pierwszegoo elementu
 */
node * rev_all ( node * head ) 
{
    node * cur = head ; // aktualny
    node * prev = NULL ; // poprzedni
    node * next = NULL ; // nastepny
    while ( cur ) 
    {
        next = cur -> next ;
        cur -> next = prev ;
        prev = cur ;
        cur = next ;
    }
    return prev ;
}

/**
 * @brief Wstawainie elementu do posortowanej listy
 * 
 * @param head wskaźnik do pierwszegoo elementu
 * @param key wartość wstawianego elementu
 * @return node* wskaźnik do pierwszegoo elementu
 */
node * insert_item_sort ( node * head , int key ) 
{
    node * elem = new node;
    if (! elem )
        return head;
    elem -> value = key;
    elem -> next = NULL;
    if( head ) 
    {
        if( head -> value > key ) //Jeśli pierwszy element listy jest większy od key wstawia element jako pierwszy
        {
            elem -> next = head ;
            head = elem ;
        } 
        else //Jeśli nie szuka forem odpowiedniego miejsca dla wstawianego elementu
        {
            node * tp = head ;
            for (; tp -> next && tp -> next -> value < key ; tp =tp -> next ) ;
            elem -> next = tp -> next ;
            tp -> next = elem;
        }
    } 
    else //Jeśli lista jest pusta wstawia element jako head
        head = elem ;
    return head ;
}

/**
 * @brief Łączenie dwóch posrotowancyh list w jedną listę posortowaną
 * 
 * @param l1 Wskaźnik do pierwszego elementu pierwszej listy
 * @param l2 Wskaźnik do pierwszego elementu drugiej listy
 * @return node* Wskaźnik do pierwszego elementu połączonych już list
 */
node * recur_sort_merge ( node * l1 , node * l2 ) 
{
    node * head2 = NULL;
    if (!l1 ) return l2;
    if (!l2 ) return l1;
    if ( l1 -> value <= l2 -> value ) 
    {
        head2 = l1 ;
        head2 -> next = recur_sort_merge ( l1 -> next , l2 ) ;
    } 
    else 
    {
        head2 = l2 ;
        head2 -> next = recur_sort_merge ( l1 , l2 -> next ) ;
    }
    return head2 ;
}
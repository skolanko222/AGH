struct TItem
{
    int value;
    TItem * next;

};
/**
 * @brief Inicjalizacja pamieci
 * 
 * @return TItem* zwraca adres elementu
 */
TItem *InitItem();
/**
 * @brief Wypisuje liste
 * 
 * @param head wskaznik na poczatek listy
 */
void show(TItem *head);
/**
 * @brief dodaje element do listy (przepraszam, niedoczytalem i zrobilem odwrotnie :( )
 * 
 * @param head wskaznik na poczatek listy
 * @param value wartosc dodawanego elementu do listy
 */
void push(TItem **head, int value);
/**
 * @brief funkcja pobiera element z listy
 * 
 * @param head wskaznik na poczatek listy
 * @return int zwraca wartosc liczby rzeczywistej pobranej z listy
 */
int pop(TItem **head);
/**
 * @brief funkcja zwalniajaca miejsce pamieci (chyba nie dziala :( )
 * 
 * @param head wskaznik na poczatek listy
 */
void clear(TItem **head); //sciagnac wszystkie!1

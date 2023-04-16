/**
 * @brief Funkcja wypisuje kazdy string z tablicy stringow (napis)
 * 
 * @param napis tablica stringow
 */
void cat(char ** napis);

/**
 * @brief funkcja zwraca ilosc wieszy - lini - tablicy "napis"
 * 
 * @param napis tablica stringow
 * @return int ilosc lini
 */
int wc_lines(char ** napis);
/**
 * @brief funkcja zwraca ilosc znakow w calej tabeli "napis"
 * 
 * @param napis  tablica stringow
 * @return int ilosc znakow
 */
int wc_char(char ** napis);
/**
 * @brief zwraca ilosc znakow w stringu
 * 
 * @param napis tablica stringow
 * @return int ilosc znakow
 */
int wc_char(char * napis);
/**
 * @brief liczy ile slow w calej tablicy stringow zakladajac, ze wyraz rozdzielony '_' to 2 osobne slowa
 * 
 * @param napis tablica stringow
 * @return int int ilosc znakow
 */
int wc_words(char ** napis);
/**
 * @brief zwalnia pamiec dynamicznej tablicy (zwroconej przez np funkcje  head/tail)
 * 
 * @param buf tablica do zwolnienia
 */
void clear(char ** buf);
/**
 * @brief wypisuje 'ile' ostatnich linijek
 * 
 * @param ile ilos linijek
 * @param napis tablica string 
 * @return char** 
 */
char ** tail(int ile, char ** napis);
/**
 * @brief wypisuje 'ile' pierwszych linijek
 * 
 * @param ile ilos linijek
 * @param napis tablica string 
 * @return char** 
 */
char ** head(int ile, char ** napis);

//probowalem cos wymyslic z uniq ;)
bool str_cmp(char * napis1, char * napis2);
char ** uniq(char ** napis);

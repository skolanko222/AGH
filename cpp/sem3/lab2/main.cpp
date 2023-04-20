/**
Proszę uzupełnić kod, aby program się kompilował i wygenerował odpowiedni output.
Tematem zadania jest zaimplementowanie elementu prostych operacji na liście jednokierunkowej w języku C z wykorzystaniem struct.
Proszę zadbać o odpowiednią strukturę plików (.h, .cpp)

Pliku main.cpp, nie wolno modyfikowac.
Podczas zajęć nie można korzystać z notatek, Internetu i materiałów pomocniczych oraz wcześniej przygotowanych plików z wyjątkiem Makefile/CMakeLists.txt

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
Pod koniec zajęć proszę przesłać na UPEL spakowane zadanie:
* archiwum najlepiej zip, ew. tar.gz albo tar)
* nazwa archiwum G1_Nazwisko (numer grupy zgodny z UniTime)
* pakujemy dodane pliki rozwiązania oraz main.cpp i Makefile/CMakeFiles.txt - bez katalogu build
* archiwum nie zawiera żadnych anonimowych katalogów typu Lab2, jeśli już to G1_Nazwisko.
*/

#include "SimplyStruct.h"
#include <stdio.h>

int main()
{
    
    TItem* head = NULL; // Inicjacja pustej listy
    
    show(head);
    
    TItem* newItem = InitItem();
    
    newItem->value = 1;
    newItem->next = head;
    head = newItem;
    
    show(head);
    
    push(&head, 2); //dodaje do przodu
    push(&head, 3);
    push(&head, 4);
    
    show(head);
    pop(&head);
    
    int val = pop(&head);
    
    printf("Pobrano %d\n", val);
    show (head);
    // czyszczenie listy
    
    clear(&head);
    
    show(head);
    return 0;
}
/** Wynik dzialania programu:
Aktualny stan listy:
<>
Aktualny stan listy:
<1>
Aktualny stan listy:
<4,3,2,1>
Pobrano 3
Aktualny stan listy:
<2,1>
Aktualny stan listy:
<>

*/

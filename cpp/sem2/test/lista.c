#include "lista.h"
node * i_i_b ( node *head , int val )
{
node * temp = malloc ( sizeof ( node ));
if (! temp ){
	printf (" Brak pamieci !!!\n");
	return head ;
}
temp -> value = val ;
temp -> next = head ;
return temp ;
}
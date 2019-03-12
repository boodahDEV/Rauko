#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	 char str[] ="Hola\nmundo";
  char * pch;
  printf ("%s\n\n",str);
  pch = strtok (str,"\n");   // Aqui deja solo la coma
  while (pch != NULL)
  {
    printf ("%s\n",pch);     // Aqui deberias guardar tu dato en el array!
    pch = strtok (NULL, "\n");  // Aca tambien iria solo la coma.!!
  }
	return 0;
}
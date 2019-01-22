// AQUI SE CONSTRUIRA LA LIBRERIA DEL SISTEMA LEXICO EN EL CUAL SUS FUNCIONES HARAN LAS BUSQUEDA Y CLASIFICACION POR TOKEN.
void LOAD_ALPHABET(char * , char *);





void LOAD_ALPHABET(char *url, char *Arr_Com)
{
    FILE *archivo;
    archivo = fopen(url, "r");

    if (archivo == NULL)
    {
        printf("\nError en la carga del alfabeto.\n");
    }
    else
    {
        for (int i = 0; i < 40; i++)
        {
            fscanf(archivo, "%c", &Arr_Com[i]);
        }
    }
    fclose(archivo);
} //---=== END BUSCA ===---

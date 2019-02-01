// AQUI SE CONSTRUIRA LA LIBRERIA DEL SISTEMA LEXICO EN EL CUAL SUS FUNCIONES HARAN LAS BUSQUEDA Y CLASIFICACION POR TOKEN.
void LOAD_ALPHABET(char *, char[][2]);

void LOAD_ALPHABET(char *url, char MCOM[][2])
{
    FILE *archivo;
    archivo = fopen(url, "r");
    char Arr_Com[35]; // TEMPORAL
    int res_pal = 0;  // resto de la palabra reservada
    int cant_pal = 0; // cantidad de palabras reservadas

    if (archivo == NULL)
    {
        printf("\nError en la carga de los recursos del alfabeto.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            fscanf(archivo, "%c", &Arr_Com[i]); //De alguna manera esto en el futuro debe ser directo a la matriz
            if (Arr_Com[i] != '\n' && Arr_Com[i])
            {
                MCOM[cant_pal][res_pal] = Arr_Com[i];
                res_pal++;
            }
            else
            {
                MCOM[cant_pal][res_pal] = '\0';
                res_pal = 0;
                cant_pal++;
            }
            //Carga todas las palabras reseradas en el arreglo
        } //END FOR
    }
    fclose(archivo);
} //---=== END BUSCA ===---

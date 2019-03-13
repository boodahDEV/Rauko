// AQUI SE CONSTRUIRA LA LIBRERIA DEL SISTEMA LEXICO EN EL CUAL SUS FUNCIONES HARAN LAS BUSQUEDA Y CLASIFICACION POR TOKEN.
#define MAX_COLUM 2
#define THIS_OK() (printf("\x1B[32m O K "))
#define THIS_ERROR() (printf("\x1B[31mERROR"))
#define THIS_NRM(a) ((a == 0)? printf("\x1B[0m ["): printf("\x1B[0m] "))


char ** LOAD_ALPHABET(char *[MAX_COLUM]);

char ** LOAD_ALPHABET(char *MCOM[MAX_COLUM])
{
    FILE *archivo;

     char **ALPHABET_M = (char **) malloc (6*sizeof(char *));
        for(int i = 0; i < 6; i++)
            ALPHABET_M[i]=(char *) malloc ( 20 *sizeof(char));

        /*--CARGA DE LOS ALFABETOS--*/
        strcpy(*(ALPHABET_M),   "../dll/data_pr.dll"); //THIS_NRM(0);THIS_OK();THIS_NRM(1); printf(" Correcta carga del pr.\n");
        strcpy(*(ALPHABET_M+1), "../dll/data_op.dll"); //THIS_NRM(0);THIS_ERROR();THIS_NRM(1); printf(" Correcta carga del pr.\n");
        strcpy(*(ALPHABET_M+2), "../dll/data_se.dll");
        /*--CARGA DE LOS ALFABETOS--*/

    int k=0; char temp[10];
    int x = 0; //CONTADOR POR ARCHIVO
    while( x != 3){ // EL 1 INDICA LA CANTIDAD DE ARCHIVOS A LEER
        archivo = fopen(*(ALPHABET_M + x), "r"); 
        if(archivo == NULL){
            THIS_NRM(0);THIS_ERROR();THIS_NRM(1); printf("Archivo '%s' en conflicto.\n",*(ALPHABET_M  + x));
            exit(EXIT_FAILURE);
        } else {
            while (!feof(archivo)){
                fscanf(archivo, "%s" ,temp);
                //printf("*[%s]*\n",temp);
                strcpy(*(MCOM+k),temp);
                k++;
            }//fin while que manipula los alfabetos
        } //end else
        x++;
    }//fin del whihle encargado de tomar cada archivo
     THIS_NRM(0);THIS_OK();THIS_NRM(1);printf("Loading Alphabets: %d \n",k);

        fclose(archivo);
        free(ALPHABET_M);ALPHABET_M = NULL; //libero la memoria utilizada para esta matriz
    return MCOM;
} //---=== END BUSCA ===---

typedef struct aba Aba;
typedef struct lista_aba Lista;

void cria_lista(Lista **li);
void destroi_abas(Lista **li);
int insere_aba(Lista *li, char *titulo, char *url);
void imprime(Lista *li);
Aba *procura(Lista *li,char *titulo);
int troca(Lista *li, char *titulo, int pos);


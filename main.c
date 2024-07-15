#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE
#define TAM 1000
typedef struct arv{
    char id[TAM] ;
    char game[TAM] ;
    char series[TAM];
    char country[TAM];
    char details[TAM];
    char ban_category[TAM];
    char ban_status[TAM];
    char wikipedia_Profile[TAM];
    char image[TAM];
    char summary[TAM];
    char developer[TAM];
    char publisher[TAM];
    char genre[TAM];
    char homepage[TAM];
    struct arv* esq;
    struct arv* dir;
    int h, fb;
}Arv;


typedef struct Bst{
    Arv* raiz;
    int altura;
    int num_nodos;
}Bst;


/* --------------------------------- FUNÇOES DE ARV ------------------------------------- */
Arv* arv_criavazia() {
    return NULL;
}
int max2(int a, int b){
    return(a>b)? a:b;
}
int arv_vazia(Arv* a){ 
    return (a==NULL);
}
int arv_altura(Arv* a){
    if(arv_vazia(a)){
        return -1;
    }else{
        return 1+ max2(arv_altura(a->esq), arv_altura(a->dir));}
}
void arv_imprime(Arv* a){
    if(!arv_vazia(a)){
        printf(" %s ", a->id); 
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
}
 
Arv* arv_cria(  
    char id[TAM] ,
    char game[TAM] ,
    char series[TAM],
    char country[TAM],
    char details[TAM],
    char ban_category[TAM],
    char ban_status[TAM],
    char wikipedia_Profile[TAM],
    char image[TAM],
    char summary[TAM],
    char developer[TAM],
    char publisher[TAM],
    char genre[TAM],
    char homepage[TAM],
    Arv* sae, Arv* sad
    ){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    strcpy(a->id, id);
    strcpy(a->game, game);
    strcpy(a->series, series);
    strcpy(a->country, country);
    strcpy(a->details ,details);
    strcpy(a->ban_category ,ban_category);
    strcpy(a->ban_status ,ban_status);
    strcpy(a->wikipedia_Profile ,wikipedia_Profile);
    strcpy(a->image ,image);
    strcpy(a->summary ,summary);
    strcpy(a->developer ,developer);
    strcpy(a->publisher ,publisher);
    strcpy(a->genre ,genre);
    strcpy(a->homepage ,homepage);
    a->esq = sae;
    a->dir = sad;
    a->h = 0;
    a->fb = 0;
    return a;
}

/* -------------------------------- FUNÇOES DE AVL-----------------------------------*/
void atualiza_altura(Arv* a){ // Atualiza o H de todos os nodos 
     if(!arv_vazia(a)){
        a->h = arv_altura(a);
        atualiza_altura(a->esq);
        atualiza_altura(a->dir);
    }
}
void atualiza_fb(Arv* a){ // Atualiza o FB de todo os nodos 
    int l,r;
     if(!arv_vazia(a)){
        if(!arv_vazia(a->esq))
            l = a->esq->h;
        else l=-1;
        if(!arv_vazia(a->dir))
            r = a->dir->h;
        else r=-1;
        a->fb = r-l;
        atualiza_fb(a->esq);
        atualiza_fb(a->dir);
    }
}
Arv* rotacao_direita(Arv* p){
    Arv* q;
    Arv* temp;
    //printf("\n \n AAAAAAAA ");
    q = p->esq;
    temp = q->dir;
    q->dir = p;
    p->esq = temp;
    p = q;
     
    return p;
}
Arv* rotacao_esquerda(Arv* p){
    Arv* q;
    Arv* temp;
    q = p->dir;
    temp = q->esq;
    q->esq = p;
    p->dir = temp;
    p = q;
    return p;
}
Arv* rota(Arv** a0, Arv** filho0){
    Arv* a = *a0;
    Arv* filho = *filho0;
    if(a->fb != -2 && a->fb != 2) return a;
    else{
        //printf("\n else");
       // printf("a->fb = %d , filho->fb = %d ", a->fb, filho->fb);
        if(a->fb == -2 && filho->fb == -1){
            //printf("\nRODEI DIREITA");
             *a0 = rotacao_direita(a); 
        }
        if(a->fb == 2 && filho->fb == 1) {
            //printf("\n RODEI ESQUEURDA");
            //printf("\n \n a->id = %s ",a->id );
            *a0 = rotacao_esquerda(a);
            //printf("\n \n a->id = %s ",a->id );

        }
        if(a->fb == 2 && filho->fb == -1){
            a->dir = rotacao_direita(filho); 
            *a0 = rotacao_esquerda(a);
        }if(a->fb == -2 && filho->fb == 1){
            a->esq = rotacao_esquerda(filho); 
            *a0 = rotacao_direita(a);
        }
        return a;
    }
}


Arv* insere(Arv* a,     
    char id[TAM] ,
    char game[TAM] ,
    char series[TAM],
    char country[TAM],
    char details[TAM],
    char ban_category[TAM],
    char ban_status[TAM],
    char wikipedia_Profile[TAM],
    char image[TAM],
    char summary[TAM],
    char developer[TAM],
    char publisher[TAM],
    char genre[TAM],
    char homepage[TAM]){
    
    int result;
   // printf("\n id =  %s / a->id = %s ", id, a->id);
    if(a->id != NULL){
         result = strcmp(id, a->id);    
    }else result = 0;
   
    
    if(a==NULL){
       // printf("\n\n INSERINDO \n");
    a = (Arv*)malloc(sizeof(Arv));
    strcpy(a->id, id);
    strcpy(a->game, game);
    strcpy(a->series, series);
    strcpy(a->country, country);
    strcpy(a->details ,details);
    strcpy(a->ban_category ,ban_category);
    strcpy(a->ban_status ,ban_status);
    strcpy(a->wikipedia_Profile ,wikipedia_Profile);
    strcpy(a->image ,image);
    strcpy(a->summary ,summary);
    strcpy(a->developer ,developer);
    strcpy(a->publisher ,publisher);
    strcpy(a->genre ,genre);
    strcpy(a->homepage ,homepage);
    a->esq = a->dir = NULL;
    a->h = 0;
    a->fb = 0;
    return a;
    }else if(result == 0) {
       // printf("\n Ja esta inserido");
        return a;
    }
    else if(result == -1 ){ // aqui eu verifico se meu valor é menor que o raiz ai eu coloco na esquerdaa
        //printf("\n Coloquei na esquerda ");
        a->esq = insere(a->esq, id, game ,series, country, details, ban_category, ban_status, wikipedia_Profile, image, summary, developer, publisher, genre, homepage );
    }else{ // e aqui na direita que sera maior 
       // printf("\n Coloquei na direita ");
        a->dir = insere(a->dir, id, game ,series, country, details, ban_category, ban_status, wikipedia_Profile, image, summary, developer, publisher, genre, homepage );
    }
    atualiza_altura(a);
    atualiza_fb(a);
    if(a->esq != NULL)  rota(&a, &(a->esq));
    if(a->dir != NULL)  rota(&a, &(a->dir));
   
    return a;
}

Arv* busca (Arv* r, char id[TAM]){
    int result;
    //printf("\n id =  %s / a->id = %s ", id, a->id);
    if(r->id != NULL){
         result = strcmp(id, r->id);    
    }else result = 0;
   
    if(r == NULL) return NULL;
    else if (result == -1 ) return busca(r->esq, id);
    else if (result == 1 ) return busca(r->dir, id);
    else if (result == 0) printf("\n\n VC ACHOU \n\n");
    else return r; 

}

void busca_string(Arv*r, char id[TAM]){
    if(r !=NULL){
        char *str =  r->id;
        char* result;
        result = strstr(str, id);
        //printf("\nhope");
        if(result != NULL){
            printf("\n %s ", r->id);
        }
        busca_string(r->esq, id);
        busca_string(r->dir, id);  
    }return 0;
}

Arv* retira(Arv* r, char id[TAM]){ // NAO MEXI AINDA -
    if(r == NULL) return NULL;
    int result;
    if(r->id != NULL){
        result = strcmp(id, r->id);    
    }
    //printf("\n RESULT = %d ", result);
   // printf("\n id = %s  r->id = %s ",id, r->id);
    if(result == -1){
        r->esq = retira(r->esq, id);
    }else if(result == 1){
       // printf("- Dir -");
        r->dir = retira(r->dir, id);
    }else if(result == 0){
        //printf("Elemento igual");
        if(r->esq == NULL && r->dir==NULL){
            //printf("\n tentei tirar com esq NULL e dir NULL");
            free(r);
            r = NULL;
        }else if(r->esq == NULL){// Só tem filho a direita
           // printf("\n filho a direita");
            Arv* t = r;
            r = r->dir;
            free(t);
         }else if(r->dir == NULL){ //Só tem filho a esquerda
            //printf("\n filho a esqeurda");
            Arv* t = r;
            r = r->esq;
            free(t);
        }else{// Tem dois filhos
            //printf("\n dois filhos");
            Arv* pai = r;
            Arv* f = r->esq;
            while (f->dir != NULL){
                pai = f;
                f = f->dir;
            }
            // troca info
            strcpy( r->id ,f->id);
            strcpy(  f->id  ,id);
            r->esq = retira(r->esq, id);
    
         }   
    }
    return r; 
}


/* ---------------------------------- FUNÇOES DE BST --------------------------------------- */
Bst* Inicializa_Bst(Bst* x){  
    x = (Bst*)malloc(sizeof(Bst));
    x->num_nodos = 0;
    x->altura = 0; // aqui é -1 ou 0 e pq?
    x->raiz = NULL;
    return x;
}
Bst* bst_cria_raiz(Bst* bst, 
    char id[TAM],
    char game[TAM] ,
    char series[TAM],
    char country[TAM],
    char details[TAM],
    char ban_category[TAM],
    char ban_status[TAM],
    char wikipedia_Profile[TAM],
    char image[TAM],
    char summary[TAM],
    char developer[TAM],
    char publisher[TAM],
    char genre[TAM],
    char homepage[TAM]){
    bst->raiz = arv_cria(id, game , series,country,details,ban_category,ban_status,wikipedia_Profile,image,summary,developer,publisher,genre,homepage, arv_criavazia(), arv_criavazia());
    bst->num_nodos++;
    bst->altura = 1;
    return bst;
}
void bst_insere(Bst* bst,
    char id[TAM],
    char game[TAM] ,
    char series[TAM],
    char country[TAM],
    char details[TAM],
    char ban_category[TAM],
    char ban_status[TAM],
    char wikipedia_Profile[TAM],
    char image[TAM],
    char summary[TAM],
    char developer[TAM],
    char publisher[TAM],
    char genre[TAM],
    char homepage[TAM]){
    if(bst->raiz == NULL){
        bst = bst_cria_raiz(bst, id, game , series,country,details,ban_category,ban_status,wikipedia_Profile,image,summary,developer,publisher,genre,homepage);
    }else{
        //Arv* aux = bst->raiz;
        bst->raiz = insere(bst->raiz, id, game , series,country,details,ban_category,ban_status,wikipedia_Profile,image,summary,developer,publisher,genre,homepage);
        bst->altura = arv_altura(bst->raiz); 
        bst->num_nodos++;
    }
}


/* ---------------------------------------------------------------------------------------- */
void graph(Arv* a){
    if(!arv_vazia(a)){
        if(a->esq != NULL){
             printf(" \"%s\" -- \"%s\" \n",a->id, a->esq->id);
        }
        if(a->dir != NULL){
             printf(" \"%s\" -- \"%s\" \n",a->id, a->dir->id);
        }
        graph(a->esq);
        graph(a->dir);
    }
}
/* -------------------------------- LEITURA DE ARQUIVO-----------------------------------*/
void lerArquivo(Bst* x, char nomeArquivo[20]){
    FILE *arquivo;
    struct arv aux;
    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("Aquivo nao existe");
        exit(0);
    }
    //printf("while");
    fscanf(arquivo, "Id@Game@Series@Country@Details@Ban Category@Ban Status@Wikipedia Profile@Image@Summary@Developer@Publisher@Genre@Homepage;"); // e1u pulo isso aqui ?
    while (fscanf(arquivo, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^;];", aux.id, aux.game, aux.series, aux.country, aux.details,  aux.ban_category , aux.ban_status, aux.wikipedia_Profile, aux.image, aux.summary, aux.developer , aux.publisher,aux.genre, aux.homepage)==14 || fscanf(arquivo, "%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^@]@%[^;];", aux.id, aux.game, aux.series, aux.country, aux.details,  aux.ban_category , aux.ban_status, aux.wikipedia_Profile, aux.image, aux.summary, aux.developer , aux.publisher,aux.genre, aux.homepage)==13){ 
        // printf("hope");
        //printf("\n %s ", aux.homepage);

        bst_insere(x, aux.id, aux.game, aux.series, aux.country, aux.details,  aux.ban_category , aux.ban_status, aux.wikipedia_Profile, aux.image, aux.summary, aux.developer , aux.publisher, aux.genre, aux.homepage );
       
    }
    fclose(arquivo);
}

int main(){
    Bst* x = NULL;
    x = Inicializa_Bst(x);
    int option,i;
    char serch[TAM];
    lerArquivo(x, "gamesH.txt"); // gamesH.txt 

    
    while(i!=1){
    printf("\n ------------------------------------- \n");
    
    printf("[1] Buscar :\n");
    printf("[2] Excluir : \n");
    printf("[3] Gerar graph: \n");
    printf("[4] Sair \n");
    fflush(stdin);
    scanf("%d", &option);
    fflush(stdin);
  
    switch (option){
    case 1:
        printf("Digite oq vc quer buscar (case sensitive): \n");
        fflush(stdin);
        scanf("%[^\n]", serch);
        fflush(stdin);
        printf("\n ------------------------------------- \n");
        printf("Encontrados: \n");
        busca_string(x->raiz, serch);
        break;
    case 2:
        printf("Digite oq vc quer Excluir(case sensitive): \n");
        fflush(stdin);
        scanf("%[^\n]", serch);
        fflush(stdin);
        retira(x->raiz, serch);
        x->num_nodos = x->num_nodos-1;
        
        // rotação 
        Arv* r = x->raiz;
        atualiza_altura(r);
        atualiza_fb(r);
        //printf("\n fb = %d ", r->fb);
        if(r->esq != NULL)  rota(&r, &(r->esq));
        if(r->dir != NULL)  rota(&r, &(r->dir));
        x->raiz = r;
        
        graph(x->raiz);
        printf("\n\n Nodos = %d ",x->num_nodos);
        //printf("\nEXCLUI\n");
        break;
    case 3: 
        graph(x->raiz);
        printf("\n\n Nodos = %d ",x->num_nodos);
        break;
    case 4:
        i=1;
        break;
    default:
        printf("Vc nao usou nenhuma das opçoes");
        break;
    }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "./ListDinEncCir.h"

struct elemento{
    struct aluno dado;
    struct elemento *next;
};

typedef struct elemento No;

Lista* criar_lista(){
    Lista* li;
    li = (Lista*) malloc(sizeof(No));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void libera_lista(Lista* lista){
    if((*lista) != NULL || lista != NULL){
        No *aux,*no = (*lista);
        while((*lista) != no){
            aux = no;
            no = no->next;
            free(aux);
        }
        free(no);
        free(lista);
    }
}

int tamanho_lista(Lista* lista){
    if(lista == NULL || (*lista) == NULL) return 0;

    int count = 0;
    No *aux = (*lista);
    do{
        count++;
        aux = aux->next;
    }while(aux != NULL);
    
    return count;

}

int lista_vazia(Lista* lista){
    if(lista == NULL || (*lista) == NULL) return 0;
    return 1;
}

int inserir_lista_inicio(Lista* lista, struct aluno al){
    if(lista == NULL) return 0;

    No *new_elemento = (No*) malloc(sizeof(No));
    if(new_elemento == NULL) return 0;

    new_elemento->dado = al;

    
    if((*lista) == NULL){
        (*lista) = new_elemento;
        new_elemento->next = new_elemento;
    }else{
        No* aux = (*lista);
        while(aux->next != (*lista)){
            aux = aux->next;
        }
        aux->next = new_elemento;
        new_elemento->next = (*lista);
        (*lista) = new_elemento;
    }
    return 1;
}

int inserir_lista_fim(Lista* lista, struct aluno al){
    if(lista == NULL) return 0;
    
    No* new_elemento;
    new_elemento = (No*) malloc(sizeof(No));
    if(new_elemento == NULL) return 0;

    new_elemento->dado = al;

    if((*lista) == NULL){
        new_elemento->next = new_elemento;
        (*lista) = new_elemento;        
    }else{
        No* aux = (*lista);
        while(aux->next != (*lista)){
            aux = aux->next;
        }

        aux->next = new_elemento;
        new_elemento->next = (*lista);
    }

    return 1;
}

int inserir_lista_ordenado(Lista* lista, struct aluno al){
    if(lista == NULL) return 0;

    No* new_elemento;
    new_elemento = (No*) malloc(sizeof(No));
    if(new_elemento == NULL) return 0;

    new_elemento->dado = al;
    if((*lista) == NULL){
        new_elemento->next = new_elemento;
        (*lista) = new_elemento;
        return 1;
    }else{

        // insere no comeco
        if((*lista)->dado.matricula > al.matricula){
            No* aux = (*lista);
            while(aux->next != (*lista)){
                aux = aux->next;
            }
            aux->next = new_elemento;
            new_elemento->next = (*lista);
            (*lista) = new_elemento;
            return 1;
        }

        // insere no meio
        No *ant = (*lista), *atual = (*lista)->next;
        while(atual != (*lista) && atual->dado.matricula < al.matricula){
            ant = atual;
            atual = atual->next;
        }

        ant->next = new_elemento;
        new_elemento->next = atual;

        return 1;
    }
}

int remover_lista_inicio(Lista* lista){
    if(lista == NULL || (*lista) == NULL) return 0;

    // caso lista vazia
    if((*lista) == (*lista)->next){
        free(*lista);
        (*lista) = NULL;
        return 1;
    }

        No* aux = (*lista); 
        No* atual = (*lista);
        while(aux->next != (*lista)){
            aux = aux->next;
        }

        aux->next = atual->next;
        (*lista) = aux->next;        

        free(atual);
        return 1;
}

int remover_lista_fim(Lista* lista){
    if(lista == NULL || (*lista) == NULL) return 0;
    
    if((*lista) == (*lista)->next){
        free(*lista);
        (*lista) = NULL;
        return 1;
    }

    No *atual, *aux = *lista;
    while(aux->next != (*lista)){
        atual = aux;
        aux = aux->next;
    }
    atual->next = aux->next;
    free(aux);
    return 1;
}

int remover_lista_ordenado(Lista* lista,int mat){
    if(lista == NULL || (*lista) == NULL) return 0;

    No* aux = *lista;
    if(aux->dado.matricula == mat){

        // caso tenho so um no
        if(aux == aux->next){
            free(aux);
            (*lista) = NULL;
            return 1;

        // caso tenho mais de um no
        }else{
            No* ult = (*lista);
            while(ult->next != (*lista)){
                ult = ult->next;
            }
            ult->next = (*lista)->next;
            (*lista) = (*lista)->next;

            free(aux);
            return 1;
        }

    }

    No* ant = aux;
    aux = aux->next;
    while(aux != (*lista) && aux->dado.matricula != mat){
        ant = aux;
        aux = aux->next;
    }

    // caso nao tenho encontrado o no
    if(aux == (*lista)) return 0;

    ant->next = aux->next;
    
    free(aux);
    return 1;
}

int consultar_pos(Lista* lista, int pos, struct aluno *al){
    if(lista == NULL || (*lista) == NULL || pos < 0) return 0;
    No* aux = (*lista);
    int count = 1;
    while(aux->next != (*lista) &&  count < pos){
        aux = aux->next;
        count++;
    }

    if(count != pos ) return 0;
    else{
        *al = aux->dado;
        return 1;
    }
}

int consultar_mat(Lista* lista, int mat, struct aluno *al){
    if(lista == NULL || (*lista) == NULL) return 0;

    No* aux = (*lista);
    while(aux->next != (*lista) && aux->dado.matricula != mat){
        aux = aux->next;
    }

    if(aux->dado.matricula != mat)
        return 0;
    else{
        *al = aux->dado;
        return 1;
    }
}

int imprimir_lista(Lista* lista){
    if(lista == NULL) return 0;
    if((*lista) == NULL) return 0;

    printf("IMPRIMINDO LISTA!!!\n\n");
    No* aux = (*lista);
    printf("%f \n", (*lista)->dado.n3);

    printf("Matricula : %d\n",aux->dado.matricula);
    printf("Nome : %s\n",aux->dado.nome);
    printf("Nota1 : %f\n",aux->dado.n1);
    printf("Nota2 : %f\n",aux->dado.n2);
    printf("Nota3 : %f\n",aux->dado.n3);
    printf("\n\n");

    if(aux->next != aux){
        for( No* aux = (*lista)->next; aux != (*lista); aux = aux->next){
            printf("Matricula : %d\n",aux->dado.matricula);
            printf("Nome : %s\n",aux->dado.nome);
            printf("Nota1 : %f\n",aux->dado.n1);
            printf("Nota2 : %f\n",aux->dado.n2);
            printf("Nota3 : %f\n",aux->dado.n3);
            printf("\n\n");
        }
    }

    return 1;
}
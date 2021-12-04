#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"

struct elemento{
    struct elemento *ant;
    struct aluno dado;
    struct elemento *next;
};

typedef struct elemento No;

Lista* criar_lista(){
    Lista *lista;
    lista = (Lista*)malloc(sizeof(Lista));
    if(lista != NULL){
        *lista = NULL;
    }
    return lista;
}

void libera_lista(Lista* lista){
    if((*lista) != NULL){
        No* aux;
        while((*lista)->next != NULL){
            aux = (*lista);
            (*lista) = (*lista)->next;
            free(aux);
        }
        free(lista);
    }
}

int tamanho_lista(Lista* lista){
    if(lista == NULL) return 0;
    if((*lista) == NULL) return 0;
    int count = 1;
    No* aux = *lista;
    while(aux->next != NULL){
        count++;
        aux = aux->next;
    }
    return count;
}

int lista_cheia(Lista* lista){
    return 0;
}

int lista_vazia(Lista* lista){
    if(lista == NULL) return 1;
    if(*lista == NULL) return 1;
    return  0;
}

int inserir_lista_inicio(Lista* lista,struct aluno novoAluno){
    if(lista == NULL) return 0;
    
    No* new_no;
    new_no = (No*)malloc(sizeof(No));
    if(new_no == NULL) return 0;

    new_no->dado = novoAluno;
    new_no->ant = NULL;

    // caso li não for vazio
    if((*lista) != NULL){
        (*lista)->ant = new_no;
        new_no->next = (*lista);
    }

    *lista = new_no;
    return 1;

}

int inserir_lista_fim(Lista*lista,struct aluno novoAluno){
    if(lista == NULL) return 0;
    No* new_no;
    new_no = (No*)malloc(sizeof(No));
    if(new_no == NULL) return 0;

    new_no->dado = novoAluno;
    new_no->next = NULL;

    if((*lista) == NULL){
        new_no->ant = NULL;
        *lista = new_no;
    }else{
        No *aux = *lista;
        while(aux->next != NULL){
            aux = aux->next;
        }

        aux->next = new_no;
        new_no->ant = aux;
    }
    
    return 1;
}


int inserir_lista_ordenado(Lista* lista,struct aluno novoAluno){
    if(lista == NULL) return 0;

    No* new_no;
    new_no = (No*)malloc(sizeof(No));
    if(new_no == NULL) return 0;

    new_no->dado = novoAluno;
    
    if((*lista) == NULL){
        new_no->next = NULL;
        new_no->ant = NULL;
        (*lista) = new_no;
    }else{
        
        No *ante,*aux = *lista;
        while(aux->next != NULL && aux->dado.matricula < new_no->dado.matricula){
            ante = aux;
            aux = aux->next;
        }

        if(*lista == aux){
            
            new_no->ant = NULL;
            (*lista)->ant = new_no;
            new_no->next = (*lista);
            *lista = new_no;    

        }else{
            
            new_no->next = ante->next;
            ante->next = new_no;
            new_no->ant = ante;
            if(aux->next != NULL){
                aux->ant = new_no;
            }   
        }


    }
        return 1;
}

int remover_lista_inicio(Lista* lista){
    if(lista == NULL) return 0;

    if((*lista) == 0) return 0;

    No* aux = *lista;
    *lista = aux->next;
    if(aux->next != NULL){
        aux->next->ant = NULL;
    }
    free(aux);
    return 1;
    
}

int remover_lista_fim(Lista* lista){
    if(lista == NULL) return 0;
    if((*lista) == NULL) return 0;

    No *ante,*aux = *lista;
    while(aux->next != NULL){
        ante = aux;
        aux = aux->next;
    }

    if(aux->ant == NULL){
        *lista = aux->next;
    }else{
        ante->next = NULL;
    }
    free(aux);
    return 1;
}

int remover_lista_ordenado(Lista* lista,int mat){
    if(lista == NULL) return 0;
    if((*lista) == NULL) return 0;

    No* aux = *lista;
    while(aux->next != NULL && aux->dado.matricula != mat){
        aux = aux->next;
    }

    if(aux == NULL){
        return 0;
    }
    if(aux->ant == NULL){
        (*lista) = aux->next;
    }else{
        aux->ant->next = aux->next;
    }
    if(aux->next != NULL){
        aux->next->ant = aux->ant;
    }
    free(aux);
    return 1;
}


int consultar_pos(Lista* lista, int pos, struct aluno *al){
    if(lista == NULL || pos <= 0) return 0;
    
    No *aux = *lista;
    int count = 1;
    while(aux != NULL && count < pos){
        aux = aux->next;
        count++;
    }
    
    if(aux == NULL){ 
        return 0;
    }else{
        *al = aux->dado;
        return 1;
    }

}

int consultar_mat(Lista* lista, int mat, struct aluno *al){
    if(lista == NULL && mat <= 0) return 0;

    No* aux = *lista;
    while(aux != NULL && aux->dado.matricula != mat){
        aux = aux->next;
    }
    if(aux == NULL){
        return 0;
    }else{
        *al = aux->dado;
        return 1;
    }
}

int imprimir_lista(Lista* lista){
    if(lista == NULL) return 0;
    if((*lista) == NULL) return 0;

    printf("IMPRIMINDO LISTA!!!\n\n");

    No *aux = *lista;
    while(aux != NULL){
        printf("Matricula : %d\n",aux->dado.matricula);
        printf("Nome : %s\n",aux->dado.nome);
        printf("Nota1 : %f\n",aux->dado.n1);
        printf("Nota2 : %f\n",aux->dado.n2);
        printf("Nota3 : %f\n",aux->dado.n3);
        aux = aux->next;
    }
    printf("\n\n");
    return 1;
}
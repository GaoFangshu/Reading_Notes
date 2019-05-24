/* Multiplication and Addition of Univariate Polynomials */

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *PtrToPolyNode;

struct PolyNode{
    int Coef;
    int Expon;
    PtrToPolyNode Next;
};

typedef PtrToPolyNode Polynomial;

Polynomial read();
void print(Polynomial P, int newline);
Polynomial add(Polynomial P1, Polynomial P2);
Polynomial multiply(Polynomial P1, Polynomial P2);

int main(){
    Polynomial p1, p2, p_add, p_multiply;
    p1 = read();
    p2 = read();
    p_multiply = multiply(p1, p2);
    print(p_multiply, 1);
    p_add = add(p1, p2);
    print(p_add, 0);

    return 0;
}

Polynomial read(){
    int n, i, coef, expon;

    Polynomial p0 = (Polynomial)malloc(sizeof(struct PolyNode));
    Polynomial p = p0;

    scanf("%d", &n);
    for (i = 0; i < n; i++){
        Polynomial p_new = (Polynomial)malloc(sizeof(struct PolyNode));
        p->Next = p_new;

        scanf("%d %d", &coef, &expon);
        p_new->Coef=coef;
        p_new->Expon=expon;

        p = p->Next;
    }
    p->Next = NULL;
    return p0;
}

void print(Polynomial P, int newline){
    Polynomial p=P->Next;

    while (p){
        printf("%d %d", p->Coef, p->Expon);
        if (p->Next){
            printf(" ");
        } else if (newline){
            printf("\n");
        }
        p = p->Next;
    }
}

Polynomial add(Polynomial P1, Polynomial P2){
    Polynomial p0 = (Polynomial)malloc(sizeof(struct PolyNode));
    Polynomial p = p0;
    Polynomial p1 = P1->Next;
    Polynomial p2 = P2->Next;
    int zero = 1;

    while (p1&&p2){
        if (p1->Expon > p2->Expon){
            p->Next = p1;
            p = p->Next;
            p1 = p1->Next;
        } else if (p1->Expon < p2->Expon){
            p->Next = p2;
            p = p->Next;
            p2 = p2->Next;
        } else {
            if (p1->Coef + p2->Coef != 0){
                Polynomial p_new = (Polynomial)malloc(sizeof(struct PolyNode));
                p_new->Coef = p1->Coef + p2->Coef;
                p_new->Expon = p1->Expon;
                p_new->Next = NULL;
                p->Next = p_new;
                p = p->Next;
            }
            p1 = p1->Next;
            p2 = p2->Next;
        }
    }
    if (p1){
        p->Next = p1;
    } else if (p2){
        p->Next = p2;
    }

    p = p0->Next;
    while (p){
        if (p->Coef != 0){
            zero = 0;
        }
        p = p->Next;
    }

    if (zero){
        p = p0->Next;
        while (p){
            Polynomial temp = p;
            p = p->Next;
            free(temp);
        }

        Polynomial pz = (Polynomial)malloc(sizeof(struct PolyNode));
        pz->Coef = 0;
        pz->Expon = 0;
        pz->Next = NULL;
        p0->Next = pz;

        return p0;
    } else {
        return p0;
    }
}

Polynomial multiply(Polynomial P1, Polynomial P2){
    Polynomial p0 = (Polynomial)malloc(sizeof(struct PolyNode));
    Polynomial pm = (Polynomial)malloc(sizeof(struct PolyNode));
    Polynomial p1 = P1->Next;
    Polynomial p2 = P2->Next;
    int max_expon_p1 = p1->Expon;
    int max_expon_p2 = p2->Expon;
    int result[max_expon_p1+max_expon_p2+1];
    int i;

    for (i = 0; i<max_expon_p1+max_expon_p2+1; i++){
        result[i] = 0;
    }

    Polynomial p = p0;

    for (; p1; p1 = p1->Next){
        p2 = P2->Next;
        for (; p2; p2 = p2->Next){
            Polynomial p_new = (Polynomial)malloc(sizeof(struct PolyNode));
            p_new->Coef = p1->Coef * p2->Coef;
            p_new->Expon = p1->Expon + p2->Expon;
            p_new->Next = NULL;
            p->Next = p_new;
            p = p->Next;
        }
    }

    p = p0->Next;
    free(p0);
    while (p){
        int expon = p->Expon;
        int coef = p->Coef;
        result[expon] += coef;
        Polynomial temp = p;
        p = p->Next;
        free(temp);
    }

    p = pm;
    for (i = max_expon_p1+max_expon_p2; i>=0; i--){
        if (result[i] != 0) {
            Polynomial p_new = (Polynomial)malloc(sizeof(struct PolyNode));
            p_new->Coef = result[i];
            p_new->Expon = i;
            p_new->Next = NULL;
            p->Next = p_new;
            p = p->Next;
        }
    }

    return pm;
}

/* Merge two Ordered List*/

List Merge( List L1, List L2 ){
    List L=(List)malloc(sizeof(struct Node));
    List L1_next=L1->Next, L2_next=L2->Next, p=L;

    while (L1_next&&L2_next){ /* L1_next and L2_next both do not point to NULL, we need to compare the data */
        if (L1_next->Data <= L2_next->Data){ /* merge data of L1_next*/
            p->Next = L1_next;
            L1_next=L1_next->Next;
        } else { /* merge data of L2_next*/
            p->Next = L2_next;
            L2_next=L2_next->Next;
        }
        p=p->Next;
    }
    /* L1_next or L2_next points to NULL */
    if (L1_next){ /* L2_next points to NULL */
        p->Next = L1_next;
    } else if (L2_next){ /* L1_next points to NULL */
        p->Next = L2_next;
    }
    L1->Next=NULL;
    L2->Next=NULL;

    return L;
}


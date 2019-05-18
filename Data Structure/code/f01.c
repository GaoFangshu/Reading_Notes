/* Search X in L */

Position BinarySearch( List L, ElementType X ){
    int left=1, mid, right=L->Last;

    while (left<=right){
        mid=(left+right)/2;
        if (L->Data[mid]==X){
            return mid;
        } else if (L->Data[mid]>X){
            right=mid-1;
        } else {
            left=mid+1;
        }
    }

    return NotFound;
}


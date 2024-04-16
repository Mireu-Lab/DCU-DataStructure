#include <stdio.h>

int insertElement(int List[], int Num, int x) {
    int i, k = 0, move = 0;

    for (i = 0; i < Num; i++) {
        if (List[i] <= x && x <= List[i + 1]) {
            k = i + 1;
            break;
        }
    }
    if (i == Num) k = Num;

    for (i = Num; i > k; i--) {
        List[i] = List[i - 1];
        move++;
    }

    List[k] = x;
    return move;
}

int deleteElement(int List[], int Num, int x) {
    int i, k = Num, move = 0;

    for (i = 0; i < Num; i++) {
        if (List[i] == x) {
            k = i;
            break;
        }
    }

    if (i == Num) move = Num;

    for (i = k; i < Num - 1; i++) {
        List[i] = List[i + 1];
        move++;
    }

    return move;
}

int main() {
    int list[TMP_MAX] = {10, 20, 40, 50, 60, 70};
    int i, move, size = 6;

    printf("\n삽입 전 선형 리스트 : ");
    for (i = 0; i < size; i++) {
        printf("%3d ", list[i]);
    }

    printf("\n원소의 갯수 : %d \n", size);

    move = insertElement(list, size, 30);

    printf("\n삽입 후 선형 리스트 : ");
    for (i = 0; i <= size; i++) {
        printf("%3d ", list[i]);
    }

    printf("\n원소의 갯수 : %d ", ++size);
    printf("\n자리 이동 횟수 : %d \n", move);

    move = deleteElement(list, size, 30);
    if (move == size) {
        printf("\n선형 리스트에 원소가 없어서 삭제할 수 없습니다.\n");

    } else {
        printf("\n삭제 후 선형 리스트 : ");
        for (i = 0; i < size - 1; i++) printf("%3d ", list[i]);
        printf("\n원소의 갯수 : %d ", --size);
        printf("\n자리 이동 횟수 : %d \n", move);
    }

    return 0;
}
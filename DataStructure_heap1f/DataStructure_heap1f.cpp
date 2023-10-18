#include <stdio.h>
#include <stdlib.h>
#define SIZE 11
typedef struct {
    int key;
} element;
typedef struct {
    element heap[SIZE];
    int heap_size;
} HeapType;

// 생성 함수
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h)
{
    h->heap_size = 0;
}
// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_max_heap(HeapType* h, element item)
{
    if (h->heap_size >= SIZE) {
        printf("힙이 가득 찼습니다. 노드를 추가할 수 없습니다.\n");
        return;
    }

    int i = ++(h->heap_size);

    // 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;     // 새로운 노드를 삽입
}
// 삭제 함수
element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        // 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
        if ((child < h->heap_size) &&
            (h->heap[child].key) < h->heap[child + 1].key)
            child++;
        if (temp.key >= h->heap[child].key) break;
        // 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child = 2 * parent;
    }
    h->heap[parent] = temp;
    return item;
}
void print_heap(HeapType* h)
{
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}
void print_level_order(HeapType* h)
{
    int level = 1;
    int count = 0;

    for (int i = 1; i <= h->heap_size; i++) {
        if (i == level) {
            printf("\nLevel %d: ", level);
            level *= 2;
        }
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

int main(void)
{
    element e;
    HeapType* heap;
    heap = create();    // 히프 생성
    init(heap);    // 초기화

    element list[SIZE] = { 90, 89, 70, 36, 75, 63, 65, 21, 18, 15 };

    for (int i = 0; i < SIZE; i++) {
        insert_max_heap(heap, list[i]);
    }

    printf("초기 힙 상태:\n");
    print_heap(heap);

    char menu = 0;
    printf("-----------------\n");
    printf("   i    : 노드 추가\n");
    printf("   d    : 노드 삭제\n");
    printf("   p    : 레벨별 출력\n");
    printf("   c    : 종료\n");
    printf("-----------------\n");

    while (menu != 'c') {
        printf("\n");
        printf("메뉴 입력: ");
        scanf_s(" %c", &menu);

        switch (menu) {

        case 'i':
            printf("추가할 값 입력:");
            scanf_s("%d", &e.key);
            insert_max_heap(heap, e);
            printf("%d를 추가한 후의 힙 상태:\n");
            print_heap(heap);
            break;

        case 'd':
            delete_max_heap(heap);
            printf("노드 삭제 후의 힙 상태:\n");
            print_heap(heap);
            break;
        case 'p':
            printf("트리 레벨별 출력:\n");
            print_level_order(heap);
            break;

        case 'c':
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 메뉴 선택입니다. 다시 시도하세요.\n");
        }
    }
    free(heap); // 메모리 해제
    return 0;
}
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

// ���� �Լ�
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}
// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
    h->heap_size = 0;
}
// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_max_heap(HeapType* h, element item)
{
    if (h->heap_size >= SIZE) {
        printf("���� ���� á���ϴ�. ��带 �߰��� �� �����ϴ�.\n");
        return;
    }

    int i = ++(h->heap_size);

    // Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;     // ���ο� ��带 ����
}
// ���� �Լ�
element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        // ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
        if ((child < h->heap_size) &&
            (h->heap[child].key) < h->heap[child + 1].key)
            child++;
        if (temp.key >= h->heap[child].key) break;
        // �� �ܰ� �Ʒ��� �̵�
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
    heap = create();    // ���� ����
    init(heap);    // �ʱ�ȭ

    element list[SIZE] = { 90, 89, 70, 36, 75, 63, 65, 21, 18, 15 };

    for (int i = 0; i < SIZE; i++) {
        insert_max_heap(heap, list[i]);
    }

    printf("�ʱ� �� ����:\n");
    print_heap(heap);

    char menu = 0;
    printf("-----------------\n");
    printf("   i    : ��� �߰�\n");
    printf("   d    : ��� ����\n");
    printf("   p    : ������ ���\n");
    printf("   c    : ����\n");
    printf("-----------------\n");

    while (menu != 'c') {
        printf("\n");
        printf("�޴� �Է�: ");
        scanf_s(" %c", &menu);

        switch (menu) {

        case 'i':
            printf("�߰��� �� �Է�:");
            scanf_s("%d", &e.key);
            insert_max_heap(heap, e);
            printf("%d�� �߰��� ���� �� ����:\n");
            print_heap(heap);
            break;

        case 'd':
            delete_max_heap(heap);
            printf("��� ���� ���� �� ����:\n");
            print_heap(heap);
            break;
        case 'p':
            printf("Ʈ�� ������ ���:\n");
            print_level_order(heap);
            break;

        case 'c':
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �޴� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
    free(heap); // �޸� ����
    return 0;
}
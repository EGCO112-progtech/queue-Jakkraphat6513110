
// #include "Node.h"

typedef struct
{
  NodePtr head, tail;
  int size;
} Queue;

void enqueue_struct(Queue *q, int order_num, int quant)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  printf("My order is: %d\n", order_num);
  if (new_node)
  {
    new_node->order_number = order_num;
    new_node->qty = quant;
    new_node->nextPtr = NULL;
    if (q->head == NULL)
    {
      q->head = new_node;
      q->tail = new_node;
    }
    else
      q->tail->nextPtr = new_node;
    q->tail = new_node;
    q->size++;
  }
}

void dequeue_struct(Queue *q)
{
  NodePtr t = q->head;
  int cost = 0;
  int money = 1;
  if (t)
  {
    int order_num = t->order_number;
    int qty = t->qty;
    switch (order_num)
    {
    case 1:
      printf("Ramen\n");
      cost = 100 * qty;
      printf("You have to pay %d\n", cost);
      break;
    case 2:
      printf("Somtum\n");
      cost = 20 * qty;
      printf("You have to pay %d\n", cost);
      break;
    case 3:
      printf("Fried Chicken\n");
      cost = 50 * qty;
      printf("You have to pay %d\n", cost);
      break;
    default:
      printf("No Food\n");
      cost = 0;
      break;
    }
    while (money < cost)
    {
      printf("Cash: ");
      scanf("%d", &money);
    }

    q->head = q->head->nextPtr;
    if (q->head == NULL)
      q->tail = NULL;
    free(t);
    q->size--;
    return;
  }
  //  printf("Empty queue");
  return;
}

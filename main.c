#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;
  int i;
  Queue q;
  q.head = headPtr;
  q.tail = tailPtr;
  q.size = 0;
  int counter = 0;
  for(i=1;i<argc;i++)
  {
    int cost = 0;
    int money = 0;
    if(strcmp(argv[i],"x")==0){
      int order_num = 0, quan = 0;
      counter++;
      printf("Customer NO: %d\n", counter);
      dequeue_struct(&q);
      printf("Thank you \n");
    }
    else 
    {
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1]));
      i++;
    }
  }
  printf("========================\n");
  if (q.size == 1) printf("There is 1 ppl left in the queue\n");
  else if (q.size > 1) printf("There are %d ppl left in the queue\n", q.size);
  printf("Clearing queue\n");
  return 0;
}
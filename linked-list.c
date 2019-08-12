#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node * next;
} node_t;

void print_list(node_t * head) {
  node_t * current = head;

  while (current != NULL) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

void push(node_t * head, int val) {
  node_t * current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = malloc(sizeof(node_t));
  current->next->val = val;
  current->next->next = NULL;
}

// create a linked list of 10 nodes
void create_list(node_t * head) {
  int i;

  // inefficient implementation to use push for all of these
  for (i = 1; i < 10; i++) {
    push(head, i + 1);
  }
}

int main() {
  int i;
  node_t * head = NULL;
  head = malloc(sizeof(node_t));
  if (head == NULL) {
    return 0;
  }

  head->val = 1;
  head->next = NULL;

  create_list(head);
  print_list(head);

  return 0;
}

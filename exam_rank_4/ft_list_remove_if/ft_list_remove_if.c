#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;


int cmp(void *p1, void* p2) {
    return !(p1 == p2);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
  t_list *current;
  t_list *prev;
  t_list *tmp;

  prev = 0;
  current = *begin_list;
  while (current) {
    if (cmp(current->data, data_ref) == 0) {
      tmp = current->next;
      if (prev)
        prev->next = tmp;
      else
        *begin_list = tmp;
      free(current);
      current = tmp;
    } else {
      prev = current;
      current = current->next;
    }
  }
}

int main()
{
    t_list *start = malloc(sizeof(t_list));
    start->data = &start;
    t_list *second = malloc(sizeof(t_list));
    second->data = &second;
    t_list *third = malloc(sizeof(t_list));
    third->data = &third;

    ft_list_remove_if(&start, &third, cmp);
    

}
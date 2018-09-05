#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct element
{
    int value;
    struct element* next;
};

struct element* create(int value)
{
    struct element* new_element = malloc(sizeof(struct element));
    new_element->value = value;
    new_element->next = NULL;
    return new_element;
};

struct element* first = NULL;

void print_list()
{
    struct element* temp = first;
    while(temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void insert_node(int value, int position)
{
    struct element* new_element = create(value);

    if(first == NULL)
    {
        first = create(value);
    }
    else
    {
        int it = 0;
        struct element* temp = first;
        while(it < position - 1)
        {
            if(temp->next == NULL)
            {
                temp->next = new_element;
                return;
            }
            temp = temp->next;
            it++;
        }
        new_element->next = temp->next;
        temp->next = new_element;
    }
}

void delete_node(int position)
{
    int it = 0;
    struct element* temp = first;
    struct element* prev = NULL;
    while(it < position)
    {
        prev = temp;
        temp = temp->next;
        it++;
    }
    if(prev != NULL)
    {
        prev->next = temp->next;
        free(temp);
        temp = NULL;
    }
    else if(first->next == NULL)
    {
        free(first);
        first = NULL;
    }
    else
    {
        struct element* del = first->next;
        first->value = first->next->value;
        first->next = first->next->next;
        free(del);
        del = NULL;
    }
}

int main()
{
    insert_node(5, 0);
    print_list();
    insert_node(6, 1);
    print_list();
    insert_node(3, 1);
    print_list();
    insert_node(45, 3);
    print_list();
    insert_node(12, 2);
    print_list();
    delete_node(3);
    print_list();
    delete_node(1);
    print_list();
    delete_node(0);
    print_list();
    delete_node(1);
    print_list();
    delete_node(0);
    print_list();
    return 0;
}

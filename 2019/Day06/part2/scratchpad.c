int planetComp(const void *a, const void *b)
{
    struct planet *ia = (struct planet *)a;
    struct planet *ib = (struct planet *)b;
    return strcmp(ia->planet, ib->planet);
    /* strcmp functions works exactly as expected from
	comparison function */
}

void print_list(planet *head)
{
    planet *current = head;
    while (current != NULL)
    {
        printf("%s\n", current->planet);
        current = current->child;
    }
}

int remove_by_index(planet **head, int n)
{
    int i = 0;
    int retval = -1;
    planet *current = *head;
    planet *temp_node = NULL;

    if (n == 0)
    {
        return pop(head);
    }

    for (i = 0; i < n - 1; i++)
    {
        if (current->child == NULL)
        {
            return -1;
        }
        current = current->child;
    }

    temp_node = current->child;
    retval = temp_node->val;
    current->child = temp_node->child;
    free(temp_node);

    return retval;
}

int add_by_planet(planet **head, char *parent)
{
    int i = 0;
    char *retval;
    planet *current = *head;
    // planet *temp_node = NULL;

    // if (parent == NULL)
    // {
    //     return pop(head);
    // }

    while (current->parent != parent)
    {
        if (current->planet == NULL)
        {
            return -1;
        }
        current = current->planet;
    }

    // temp_node = current->child;
    // retval = temp_node->planet;
    current->planet = temp_node->child;

    return retval;
}

int pop(planet **head)
{
    int retval = -1;
    planet *next_node = NULL;

    if (*head == NULL)
    {
        return -1;
    }

    next_node = (*head)->child;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

void push_to_beginning(planet **head, int val)
{
    planet *new_node;
    new_node = malloc(sizeof(planet));

    new_node->val = val;
    new_node->child = *head;
    *head = new_node;
}

void push_to_end(planet *head, int val)
{
    planet *current = head;
    while (current->child != NULL)
    {
        current = current->child;
    }

    /* now we can add a new variable */
    current->child = malloc(sizeof(planet));
    current->child->val = val;
    current->child->child = NULL;
}
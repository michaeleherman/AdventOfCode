struct node
{
    char planet;
    struct node *left;
    struct node *right;
};

struct node *newNode(char *planet);
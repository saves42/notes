#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  char *s = malloc(13);
  s = "Hello world!";
  char *p = &s[0];
  printf("%s\n", s);
  printf("%p\n", s);

  free(s);
  
  int *x = malloc(sizeof(int));
  *x = 42;

  int i;
  printf("i: ");
  scanf("%i", &i);
  printf("%i\n", i);

  free(x);
  
  return 0;
}

/*
-strings are arrays of characters (char)
to denote the end of a string "\0" is appended to the end

--create a data type--

typedef struct
{
  string name;
  string number;
}
person;

-malloc() (memory allocation) allocates a specified amount of memory (must include <stdlib.h> header file)

#include <stdlib.h>
#include <stdio.h>
int main(void)
{
char *t = malloc(strlen(s + 1)) //dynamic way of allocation

free(t) //frees allocated memory
}

-A pointer is a variable that stores an address in memory, where some other variable might be stored.
The & operator can be used to get the address of some variable, as with &n. And the * operator declares a variable as a pointer, as with int *p, indicating that we have a variable called p that points to an int. So, to store the address of a variable n into a pointer p, we would write:

int *p = &n;

-In C, we can actually see the address with the & operator, which means “get the address of this variable”:

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
}

$ make address
$ ./address
0x7ffcb4578e5c

-%p is the format code to print an address with printf. And we only need to use the name of the variable, p, after we’ve declared it.

-The * operator is also the dereference operator, which goes to an address to get the value stored there. For example, we can say: 

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);
}

$ ./address
0x7ffda0a4767c
50

-Now, we see the value of the pointer itself (an address), and then the value at the address with *p, which is 50.
Since we declared p to be an int *, the compiler knows that *p is an int, so the right number of bytes are read.


--binary trees--

// create a tree data type
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;


// using a tree
int main(void)
{
    // Tree of size 0
    node *tree = NULL;
  
    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

// Add number to list
n = malloc(sizeof(node));
if (n == NULL)
{
    free_tree(tree);
    return 1;
}
n->number = 1;
n->left = NULL;
n->right = NULL;
tree->left = n;

// Add 3rd number to list
n = malloc(sizeof(node));
if (n == NULL)
{
    free_tree(tree);
    return 1;
}
n->number = 3;
n->left = NULL;
n->right = NULL;
tree->right = n;

// Print tree
print_tree(tree);

// Free tree
free_tree(tree);
return 0;

//The print_tree function will start at the root node, and recursively print the tree:

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

// to free the memory for each of the nodes in our tree, we’ll have to recursively free both children first:

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}




*/

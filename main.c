#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct node             //A node structure has been designed that holds the ID and the student's name in it.
{
    int id;
    char name[50];
    struct node *next;
} *head;

struct node *insert(struct node * list, char nam[50], int id)
{
    struct node *helper;
    struct node *pNew;
    pNew=(struct node*)malloc(sizeof(struct node));

    strcpy(pNew->name, nam);        //If a new student information is added with the 
    pNew->id = id;                  //insert function, a new node with name and
    pNew->next=NULL;                //number information is created and the desired
                                    //link list is added. If the generated node is the first
    helper=list;                    //element of the list, the directly created node is returned.

    if (list == NULL)
        return pNew;

    while (helper->next!=NULL)
        helper=helper->next;
    helper->next=pNew;

    return list;
}

struct node *delete(struct node *list, int id)
{
    struct node *helper;
    struct node *clener;

    helper = list;

    if (list == NULL)
        return list;
    if (helper->id == id)                       //It tries to find the desired ID to be removed by                                                
    {                                           //hovering over the link list sent into the delete
        clener = helper;                        //function and removes it from the list. if it can't 
        helper = helper->next;                  //find it, it returns an error message and returns the original list as it is.
        free(clener);                           
        return helper;
    }
    while (helper->next != NULL)
        if (helper->next->id != id)
            helper = helper->next;
        else
            break;
    if (helper->next == NULL)
    {
        printf("No student found with this number");
        printf("\n--------------\n");
        return list;
    }
    else
    {
        clener = helper->next;
        helper->next = helper->next->next;
        free(clener);
    }
    return list;
    
}

struct node *sortbyID(struct node *list)
{
    struct node *helper;
    struct node *min;
    struct node *returner;
    int id, old_id;

    returner = (struct node*)malloc(sizeof(struct node));       //We can say that this function is the most
    returner = NULL;                                            //important function that does almost all the work
                                                                //of the system. First of all, it starts by taking the
    if (list == NULL)                                           //link list that it wants us to sort according to the
        return list;                                            //ID information as an argument. While inside the
    while (list != NULL)                                        //function, it creates a new link list (stack). It finds
    {                                                           //the node with the smallest ID value of the link list
        helper = list;                                          //we have sent and adds it to the list we have just 
        id = helper->id;                                        //defined in the function. After this addition, it
        min = helper;                                           //deletes that node from the link list and starts 
        while (helper != NULL)                                  //scanning the link list again and tries to find the 
        {                                                       //next smallest ID value node..
            if ((id % 10000) <= (helper->id % 10000))
            {
                helper = helper->next;
            }
            else if ((id % 10000) > (helper->id % 10000))
            {
                min = helper;
                id = min->id;
                helper = helper->next;
            }
        }
        returner = insert(returner,min->name,min->id);
        list = delete(list,min->id);
    }
    return returner;
}

struct node *sortbyYears(struct node *list)
{
    struct node *helper;
    struct node *min;
    struct node *returner;
    int id, old_id;

    returner = (struct node*)malloc(sizeof(struct node));
    returner = NULL;

    if (list == NULL)                   //It is almost exactly the same as the ID sorting 
        return list;                    //function, but a slight change has been made in 
    while (list != NULL)                //the desired part of the ID information.
    {
        helper = list;
        id = helper->id;
        min = helper;
        while (helper != NULL)
        {
            if ((id % 1000000) <= (helper->id % 1000000))
            {
                helper = helper->next;
            }
            else if ((id % 1000000) > (helper->id % 1000000))
            {
                min = helper;
                id = min->id;
                helper = helper->next;
            }
        }
        returner = insert(returner,min->name,min->id);
        list = delete(list,min->id);
    }
    return returner;
}

struct node *sortbyFaculty(struct node *list)       //Almost same function like others
{
    struct node *helper;
    struct node *min;
    struct node *returner;
    int id, old_id;

    returner = (struct node*)malloc(sizeof(struct node));
    returner = NULL;

    if (list == NULL)
        return list;
    while (list != NULL)
    {
        helper = list;
        id = helper->id;
        min = helper;
        while (helper != NULL)
        {
            if ((id) <= (helper->id))
            {
                helper = helper->next;
            }
            else if ((id) > (helper->id))
            {
                min = helper;
                id = min->id;
                helper = helper->next;
            }
        }
        returner = insert(returner,min->name,min->id);
        list = delete(list,min->id);
    }
    return returner;
}

int main()
{
char nameInsert[50];
char nameDelete[50];
int idNum, i;
struct node *n=NULL, *curser=NULL;                              //creating first node

head = NULL;

printf("1. Enter school number\n");
printf("2. Display school numbers sorted by ID\n");
printf("3. Display school numbers sorted by year\n");                   //standart menu prints
printf("4. Display school numbers sorted by faculty codes\n");
printf("5. Delete a record by school number\n");
printf("6. Exit\n");

while(i != 6)
{
    printf("\n Enter choice : ");

    if(scanf("%d", &i) <= 0)
    {
        printf("Not valid input, please use integers 1 - 5\n");
        break;
    }
    else
    {
        switch(i)                       //The desired action is selected
        {
            case 1:
                printf("Enter school number: ");
                scanf("%d", &idNum);
                if ((idNum / 100000000) <= 0 || (idNum / 100000000) > 9)
                {
                    printf("Not valid input !!!");
                    break;
                }
                printf("Name & Surname (use underscores instead of spaces): ");
                scanf("%s",nameInsert);
                n = insert(n,nameInsert, idNum); 
                break;
            case 2:
                n = sortbyID(n);
                curser = n;
                printf("Sorted by ID:\n");
                while (curser != NULL)
                {
                    printf("%d %s\n",curser->id, curser->name);
                    curser = curser->next;
                }
                break;
            case 3:
                n = sortbyYears(n);
                curser = n;
                printf("Sorted by year:\n");
                while (curser != NULL)
                {
                    printf("%d %s\n",curser->id, curser->name);
                    curser = curser->next;
                }
                break;
            case 4:
                n = sortbyFaculty(n);
                curser = n;
                printf("Sorted by faculty code:\n");
                while (curser != NULL)
                {
                    printf("%d %s\n",curser->id, curser->name);
                    curser = curser->next;
                }
                break;
            case 5:
                printf("Type the number you want to delete: ");
                scanf("%d", &idNum);
                n = delete(n,idNum);
                break;
                
        }
    }
}
}
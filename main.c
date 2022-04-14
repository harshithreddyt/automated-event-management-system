#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// this global variable stores the priority.
int prty[100];
struct ndy
{
 int prtyy;
 int *address;
 struct ndy *neext;
};
struct ndy *sttart = NULL;
// structure to store node in linked list
struct node
{
 char cellname[50];
 int data;
 struct node *next;
};
struct node *start;
// All functions declaration here.
void display(int num, int *g, int data);
int *create();
int calincome(int *a);
int getpromo(int a);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
int get_i(int j, int *pt);
void put_i(int dat, int j, int *strt);
int *crrt(int count, int *b[100]);
void heapsort(int a);
void ddpp(int *g, int a);
void copy(int *g);
int decd(int a);
void mutual_add(int dat, int *main);
int addd(int dat, int ret, struct ndy *rot);
void display(int num, int *g, int data)
{
 struct node *new_node;
 printf("\nThe %d output Linked List with start '%d' for priority :%d\n", num + 1, g, data);
 new_node = g;
 int i = 0;
 while (new_node != NULL)
 {
 if (i > 0)
 {
 printf("%s : %d\n", new_node->cellname, new_node->data);
 new_node = new_node->next;
 }
 else
 {
 printf("\n%s\n", new_node->cellname);
 new_node = new_node->next;
 }
 i++;
 }
}
int *create()
{
 int i;
 int *p;
 struct node *new_node, *current;
 start = NULL;
 do
 {
 // alloting space to new node
 new_node = (struct node *)malloc(sizeof(struct node));
 switch (i)
 {
 // i default value is 0.
 case 0:
 {
 printf("Enter the Name of the Event: (NOTE: Do not include space but can use '_')\n");
 scanf("%s", new_node->cellname);
 printf("Sucessfully registered the Event name\n");
 break;
 }
 case 1:
 {
 strncpy(new_node->cellname, "SCALE OF EVENT", 50);
 printf("\nChoose the scale of the event (Choose from below): \n");
 printf("VERY SMALL = 1\n");
 printf("LOCAL = 2\n");
 printf("CITY WIDE = 3\n");
 printf("NATIONAL = 4\n");
 printf("INTERNATIONAL = 5\n");
 break;
 }
 case 2:
 {
 strncpy(new_node->cellname, "CAPITAL GIVEN", 50);
 printf("\nEnter the amount of CAPITAL: ");
 break;
 }
 case 3:
 {
 strncpy(new_node->cellname, "MAN FORCE SKILLED", 50);
 printf("\nEnter the number of skilled Man Force available: ");
 break;
 }
 case 4:
 {
 strncpy(new_node->cellname, "MAN FORCE UNSKILLED", 50);
 printf("\nEnter the number of unskilled Man Force available: "
);
 break;
 }
 case 5:
 {
 strncpy(new_node->cellname, "TIME LEFT FOR THE EVENT ", 50);
 printf("\nEnter the time left for the event (in days):");
 break;
 }
 case 6:
 {
 strncpy(new_node->cellname, "TIME TAKEN TO THE EVENT", 50);
 printf("\nEnter the time to be taken by the event (in hours)")
;
 break;
 }
 case 7:
 {
 strncpy(new_node->cellname, "PROMOTIONS", 50);
 printf("\nEnter the promotions rating (1 to 5)");
 }
 }
 int t;
 if (i == 1)
 {
 //storing data to the node that is inputted by user.
 printf("\nEnter the data : ");
 scanf("%d", &t);
 switch (t)
 {
 case 1:
 {
 new_node->data = 50000;
 break;
 }
 case 2:
 {
 new_node->data = 100000;
 break;
 }
 case 3:
 {
 new_node->data = 250000;
 break;
 }
 case 4:
 {
 new_node->data = 600000;
 break;
 }
 case 5:
 {
 new_node->data = 1000000;
 break;
 }
 default:
 {
 printf("ERROR\n");
 break;
 }
 }
 printf("%d", new_node->data);
 }
 if (i > 1 && i < 8)
 {
 //storing data to the node that is inputted by user.
 printf("\nEnter the data : ");
 scanf("%d", &new_node->data);
 }
 else if (i == 8)
 {
 strncpy(new_node->cellname, "prty", 10);
 }
 else if (i == 9)
 {
 strncpy(new_node->cellname, "ratio", 10);
 }
 new_node->next = NULL;
 if (start == NULL) // create a new node and link
 {
 start = new_node;
 p = new_node;
 current = new_node;
 }
 else
 {
 current->next = new_node;
 current = new_node;
 }
 // increment of i here to prompt user for answering the questions.
 i++;
 } while (i < 10);
 // do-while loop ends here.
 printf("The Returned pointer: %d\n", p);
 return p;
}
int calincome(int *a)
{
 int i = 0, j, scale, income, capital, timeLeft, timeTaken, prty, skilledMan, unskilledMan, promo, promo1, ratio;
 float ratio1;
 struct node *new_node;
 new_node = a;
 while (new_node != NULL)
 {
 switch (i)
 {
 case 1:
 scale = new_node->data;
 break;
 case 2:
 {
 capital = new_node->data;
 break;
 }
 case 3:
 {
 skilledMan = new_node->data;
 break;
 }
 case 4:
 {
 unskilledMan = new_node->data;
 break;
 }
 case 5:
 {
 timeLeft = new_node->data;
 break;
 }
 case 6:
 {
 timeTaken = new_node->data;
 break;
 }
 case 7:
 {
 promo = new_node->data;
 break;
 }
 default:
 {
 break;
 }
 }
 new_node = new_node->next;
 i++;
 }
 printf("calculating.........\n");
 promo1 = getpromo(promo);
 // income is calculated as follows: Subtracting the expenses made by skilled,
 // unskilled labour, promotions and scale from initial capital
 income = capital - ((skilledMan * 6000) + (unskilledMan * 1500) + promo1 + scale);
 if (income < 0)
 {
 put_i(0, 8, a);
 return 0;
 }
 printf("Income = %d\n", income);
 // ratio is calculated as ratio of income and capital expenditure multiplied by 1000.
 ratio1 = ((float)income / (float)capital) * 1000;
 ratio = ratio1;
 printf("Ratio = %d\n", ratio);
 put_i(ratio, 9, a);
 switch (scale)
 {
 case 50000:
 {
 scale = 10;
 break;
 }
 case 100000:
 {
 scale = 20;
 break;
 }
 case 250000:
 {
 scale = 30;
 break;
 }
 case 600000:
 {
 scale = 40;
 break;
 }
 case 1000000:
 {
 scale = 50;
 break;
 }
 }
 if (timeLeft <= 3)
 {
 // Priority is calculated as sum of ratio, scale and promotions and 9999
 prty = 9999 + scale + ratio + promo;
 put_i(prty, 8, a);
 return prty;
 }
 else
 {
 // Priority is calculated as sum of ratio, scale and promotions and subtract the count of
 // skilled, unskilled labour, time left and time taken.
 prty = (ratio + scale + promo) - (skilledMan + unskilledMan + timeLeft + timeTaken);
 put_i(prty, 8, a);
 return prty;
 }
}
// function to return promotions value based on passed parameter.
int getpromo(int a)
{
 int p;
 switch (a)
 {
 case 1:
 {
 p = 10000;
 return p;
 break;
 }
 case 2:
 {
 p = 20000;
 return p;
 break;
 }
 case 3:
 {
 p = 50000;
 return p;
 break;
 }
 case 4:
 {
 p = 100000;
 return p;
 break;
 }
 case 5:
 {
 p = 200000;
 return p;
 break;
 }
 default:
 {
 printf("ERROR\n");
 return 0;
 break;
 }
 }
}
// utility function for swapping, used in partition function
void swap(int *a, int *b)
{
 int t = *a;
 *a = *b;
 *b = t;
}
// function to make partition of passed array based in high and low values
// which is used in quick sort.
int partition(int arr[], int low, int high)
{
 int pivot = arr[high];
 int i = (low - 1);
 int j = 0;
 for (j = low; j <= high - 1; j++)
 {
 if (arr[j] <= pivot)
 {
 i++;
 swap(&arr[i], &arr[j]);
 }
 }
 swap(&arr[i + 1], &arr[high]);
 return (i + 1);
}
// function for sorting the array
void quickSort(int arr[], int low, int high)
{
 if (low < high)
 {
 // pi is partitioning index, arr[p] is now at right place
 int pi = partition(arr, low, high);
 // Separately sort elements before partition and after partition
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
// function to retrieve the data from the node with the help of index number via searching
int get_i(int j, int *pt)
{
 struct node *new_node;
 new_node = pt;
 int i = 0;
 while (new_node != NULL)
 {
 if (i == j)
 {
 return new_node->data;
 }
 new_node = new_node->next;
 i++;
 }
}
// function to insert the data into node with the help of index number via searching
void put_i(int dat, int j, int *strt)
{
 struct node *new_node;
 new_node = strt;
 int i = 0;
 while (new_node != NULL)
 {
 if (i == j)
 {
 new_node->data = dat;
 }
 new_node = new_node->next;
 i++;
 }
}
int *crrt(int count, int *b[100])
{
 int *p, *tempp;
 int i = 0, j = 0, tempi;
 struct ndy *new_node, *current;
 do
 {
 new_node = (struct ndy *)malloc(sizeof(struct ndy));
 new_node->neext = NULL;
 sttart = NULL;
 if (j == 0)
 {
 sttart = new_node;
 p = sttart;
 j++;
 current = new_node;
 }
 else
 {
 current->neext = new_node;
 current = new_node;
 }
 tempi = prty[i];
 current->prtyy = tempi;
 tempp = b[i];
 current->address = tempp;
 i++;
 }
 while (i < count);
 // end do-while.
 return p;
}
// function for sorting the priority using heap sort
void heapsort(int a)
{
 int no, i, j, c, heap_root, temp;
 no = a;
 for (i = 1; i < no; i++)
 {
 c = i;
 do
 {
 heap_root = (c - 1) / 2;
 /* to create MAX arr array */
 if (prty[heap_root] < prty[c])
 {
 temp = prty[heap_root];
 prty[heap_root] = prty[c];
 prty[c] = temp;
 }
 c = heap_root;
 } while (c != 0);
 }
 printf("Heap priority array : ");
 for (i = 0; i < no; i++)
 printf("%d ", prty[i]);
 for (j = no - 1; j >= 0; j--)
 {
 temp = prty[0];
 prty[0] = prty[j];
 prty[j] = temp;
 heap_root = 0;
 do
 {
 c = 2 * heap_root + 1;
 if ((prty[c] < prty[c + 1]) && c < j - 1)
 c++;
 if (prty[heap_root] < prty[c] && c < j)
 {
 temp = prty[heap_root];
 prty[heap_root] = prty[c];
 prty[c] = temp;
 }
 heap_root = c;
 } while (c < j);
 }
 printf("\nSorted priority array : ");
 for (i = 0; i < no; i++)
 printf("%d ", prty[i]);
 printf("\n");
}
void ddpp(int *g, int a)
{
 int i = 0;
 int j = 0;
 struct ndy *new_node;
 new_node = g;
 printf("\n*List priority is*\n");
 for (i = 0; i < a; i++)
 {
 printf("%d=%d, ", i, prty[i]);
 }
 printf("\n");
 i = 0;
 while (i < a)
 {
 j = 0;
 new_node = g;
 while (j < a)
 {
 if (prty[a - i - 1] == new_node->prtyy && new_node->prtyy != 0)
 {
 display(i, new_node->address, new_node->prtyy);
 j = a;
 }
 else if (prty[a - i - 1] == new_node->prtyy && new_node->prtyy == 0)
 {
 printf("\n*THE BELOW HAVE NEGATIVE INCOME HENCE DO NOT OPT FOR THESE EVENT*\n");
 display(i, new_node->address, new_node->prtyy);
 new_node = new_node->neext;
 j++;
 }
 else
 {
 new_node = new_node->neext;
 j++;
 }
 }
 i++;
 }
}
void copy(int *g)
{
 int i = 0;
 struct ndy *new_node;
 new_node = g;
 while (new_node != NULL)
 {
 prty[i] = new_node->prtyy;
 new_node = new_node->neext;
 i++;
 }
}
// decider function
int decd(int a)
{
 int temp[a], i, j, k;
 for (i = 0; i < a; i++)
 {
 temp[i] = prty[i];
 }
 quickSort(temp, 0, a - 1);
 i = 0;
 while (i < a)
 {
 if (temp[i] == temp[i + 1] && temp[i] != 0)
 {
 return 0;
 }
 else if (i == a - 1)
 {
 return 1;
 }
 else
 {
 i++;
 }
 }
}
/* These three functions are used to avoid clash of priorities with eqaul
values. */
// add an extra number to priority to avoid confusion
// when we get two priorities with same value.
void mutual_add(int dat, int *main)
{
 struct ndy *new_node, *temp1, *temp2;
 int t1, t2, dd, i, j, k;
 new_node = main;
 while (new_node != NULL) //to fint other number ie=t2
 {
 if (dat == new_node->prtyy)
 {
 dd = get_i(9, new_node->address);
 if (dd != 0)
 {
 dd = dd + 99;
 dd = dd % 100;
 new_node->prtyy = new_node->prtyy + dd;
 k = addd(dat, dd, new_node->neext);
 }
 else
 new_node->prtyy = new_node->prtyy;
 }
 else if (new_node->prtyy > dat)
 {
 new_node->prtyy = new_node->prtyy + dd + k;
 }
 new_node = new_node->neext;
 }
}
int addd(int dat, int ret, struct ndy *rot)
{
 int dd;
 struct ndy *new_node;
 new_node = rot;
 if (new_node->neext == NULL)
 {
 return ret;
 }
 while (new_node != NULL) //to fint other number ie=t2
 {
 if (dat == new_node->prtyy)
 {
 dd = get_i(9, new_node->address);
 dd = dd + 99;
 dd = dd % 100;
 new_node->prtyy = new_node->prtyy + dd;
 ret = addd(dat, dd, new_node);
 dd = dd + ret;
 }
 else if (new_node->prtyy > dat)
 {
 new_node->prtyy + dd;
 }
 new_node = new_node->neext;
 }
 return dd;
}
// check for equal values of priority and differentiate using mutual_add
void checkk(int count, int *getz)
{
 int i, j, k, dd, temp1[count], temp2[count], decider = 0, index = 0;
 struct ndy *new_node;
 new_node = getz;
 i = 0;
 for (i = 0; i < count; i++)
 {
 temp1[i] = prty[i];
 }
 i = 0;
 k = 1;
 while (decider == 0)
 {
 while (i < count)
 {
 for (j = 0; j < count; j++)
 {
 if (new_node->prtyy == temp1[j] && j != index)
 {
 mutual_add(temp1[j], getz);
 index++;
 }
 }
 new_node = new_node->neext;
 i++;
 }
 k = 0;
 copy(getz);
 decider = decd(count);
 }
}
/* */
int main()
{
 int c = 0, *b, *z[100], y, *t, noOfEvents, i, count = 0, *crtp;
 printf("Enter the number of events to be registered for computation: \n");
 scanf("%d", &noOfEvents);
 for (i = 0; i < noOfEvents; i++)
 {
 count++;
 printf("\nEnter details of Event No. %d:\n", i + 1);
 z[i] = create();
 prty[i] = calincome(z[i]);
 printf("The priority is %d\n", prty[i]);
 }
 crtp = crrt(count, z);
 // This below line has to be uncommented for checking for same priority values.
 //checkk(count, crtp);
 printf("\n*Final Priority Array*\n");
 for (i = 0; i < noOfEvents; i++)
 {
 printf(" %d,", prty[i]);
 }
 printf("\n*SORTING*\n");
 heapsort(noOfEvents);
 for (i = 0; i < noOfEvents; i++)
 {
 printf("%d ", prty[i]);
 }
 ddpp(crtp, noOfEvents);
 return 0;
}

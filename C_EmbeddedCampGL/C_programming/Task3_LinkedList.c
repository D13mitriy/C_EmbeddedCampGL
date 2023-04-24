/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

typedef  unsigned short uh_t;
typedef struct 
{
    char *    title;   
    float     price;          
    uh_t     npages;
    char * language;
    float    weight;         
    uh_t       year;
    
} book_t;

book_t HarryPotter_1 = { .title = "Harry Potter and the Philosopher's Stone\0",
                             .price = 27.58,
                             .npages = 223,
                             .language ="English\0",
                             .weight = 10.2,
                             .year = 1997};
                             
    book_t HarryPotter_2 = { .title = "Harry Potter and the Chamber of Secrets\0",
                             .price = 13.64,
                             .npages = 272,
                             .language ="English\0",
                             .weight = 56,
                             .year = 1998};
                             
    book_t HarryPotter_3 = { .title = "Harry Potter and the Prisoner of Azkaban\0",
                             .price = 22.00,
                             .npages = 336,
                             .language ="English\0",
                             .weight = 67.2,
                             .year = 1999};
    
    book_t HarryPotter_4 = { .title = "Harry Potter and the Goblet of Fire\0",
                             .price = 20.42,
                             .npages = 464,
                             .language ="English\0",
                             .weight = 73.6,
                             .year = 2000};
                             
    book_t HarryPotter_5 = { .title = "Harry Potter and the Order of the Phoenix\0",
                             .price = 29.28,
                             .npages = 576,
                             .language ="English\0",
                             .weight = 91.2,
                             .year = 2003};
                             
    book_t HarryPotter_6 = { .title = "Harry Potter and the Half-Blood Prince\0",
                             .price = 34.99,
                             .npages = 607,
                             .language ="English\0",
                             .weight = 36,
                             .year = 2005};
    
    book_t HarryPotter_7 = { .title = "Harry Potter and the Deathly Hallows\0",
                             .price = 29.76,
                             .npages = 607,
                             .language ="English\0",
                             .weight = 38.4,
                             .year = 2007};

typedef struct  
{
    book_t * data_;
    struct Node_t * next;
} Node_t;

Node_t* head = NULL;



void insert(book_t* data) {
   //create a link
   Node_t *link = (Node_t*) malloc(sizeof(Node_t));
	
   
   link->data_ = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}


void print_book(book_t* book)
{
    printf("Title: %s\nPrice: %f\nNumber of pages: %u\nLanguage: %s\nWeight: %f\nYear: %u\n",\
            book->title, book->price, book->npages,       book->language,  book->weight, book->year);
}

void printList() {
   Node_t *ptr = head;
   
	
   //start from the beginning
   while(ptr != NULL) {
      print_book(ptr->data_);
      printf("\n");
      ptr = ptr->next;
   }
	
   
}
int main()
{
    book_t * series[] = { &HarryPotter_1, &HarryPotter_2, &HarryPotter_3, &HarryPotter_4, &HarryPotter_5, &HarryPotter_6, &HarryPotter_7};
    for(int i = 6; i >=0 ; --i)
    {
        insert(series[i]);
    }
    printList();

    return 0;
}

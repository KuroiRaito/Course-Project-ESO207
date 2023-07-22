#include <stdio.h>
#include <stdlib.h>

struct node
{
      int data;
      struct node* next ;
      struct node* prev ;
};

struct node* tl=NULL;
struct node* hd=NULL;
struct node* ptr=NULL;

void insert(int n)
{

      tl->next=(struct node*)malloc(sizeof(struct node));
      tl->next->prev=tl;
      tl=tl->next;
      tl->data=n;
};

void del(int n)
{

   ptr=hd;
         while(ptr!=NULL)
     {

	if(ptr->data==n)
	  {

	     if(ptr->prev!=NULL)
	       {

		  ptr->prev->next=ptr->next;
	       }
	     else
	       {

		  hd=hd->next;
		  hd->prev=NULL;
	       }

	     if(ptr->next!=NULL)
	       {

		  ptr->next->prev=ptr->prev;
	       }
	     else
	       {

		  tl=tl->prev;
		  tl->next=NULL;
	       }


	  }

	ptr=ptr->next;
     }

};

void printnext()
{

   ptr=hd;
   while(ptr!=NULL)
     {

	printf("%d " ,ptr->data);
	ptr=ptr->next;
     }

   printf("\n");
}


void printprev()
{

   ptr=tl;
   while(ptr!=NULL)
     {

	printf("%d " ,ptr->data);
	ptr=ptr->prev;
     }

   printf("\n");
}



int main()
{

      int n=47;

      hd=(struct node*)malloc(sizeof(struct node));
      ptr=hd;

      for(int i=0;i<n;i++)
     {

	tl=ptr;
	ptr->data=2*i+1;
	ptr->next=(struct node*)malloc(sizeof(struct node));
	ptr->next->prev=ptr;
	ptr=ptr->next;
     }


      ptr=hd;
      tl->next=NULL;
   hd->prev=NULL;

   printnext();
   
   int item,k;
while(1){
    
      scanf("%d" ,&k);
      
      if(k==1){
      scanf("%d" ,&item);
      insert(item);
      }
      
      
      else if(k==2){
      scanf("%d" ,&item);
      del(item);
      }
      
      
      else if(k==3){
      del(tl->data);
      }
      
      
      else if(k==4){
      scanf("%d" ,&item);
      insert(item);
      }
      
      
      else if(k==5){
      scanf("%d" ,&item);
      insert(item);
      }
      
      
      else if(k==6){
      del(hd->data);
      }
      
      
      else if(k==7){
      printnext();
      }
      
      
      else if(k==8){
      printprev();
      }
}

}
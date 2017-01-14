#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



typedef struct Kayitlar{
	
	char value;
	struct Kayitlar *onceki;
	struct Kayitlar *sonraki;
		
	
}kayit;

kayit *ilk=NULL, *son=NULL , *gecici=NULL;
	
char key;


void Add(void);
void Listing(void);
void Deleted(void);
void Saved(void);
void Opened(void);

main(){
	
	
	while(true){
		key=getch();
		
		switch(key){
			case 13: {
				
				gecici= (kayit *) malloc(sizeof (kayit));
				gecici->value='\n';
				gecici->sonraki=NULL;
				son ->sonraki = gecici;
        		gecici->onceki = son;
        		son = son->sonraki;
				Listing();
				break;
			}
			case 8:{
				Deleted();
				break;
			}
			
			case 19:{	// Ctrl+S
				
				Saved();
				break;
			}
			case 80:{//asgý80 yuk 72 sag 75 sol 77
				printf("hello");
				break;
			}
			case 14:{  // Ctrl+N
				
				Opened();
				break;
			}
			case 59:{
				
				key=NULL;
				system("CLS");
				
				printf("\n\n");
				printf("	1) Kayit etmek için Ctrl-S tusunu kullanin.\n");
				printf("	1) Kayit acmak için Ctrl-n tusunu kullanin...");
				getch();
				system("CLS");
				if(ilk->value== NULL)
				{
				
				ilk=NULL;
				son=NULL;
				gecici=NULL;
				}
				
				Listing();
				
				break;
			}
			default: {
				
				
				Add();
				Listing();
				break;
			}
		}
		
		
	}
	
	
}

void Add(){
	
	gecici= (kayit *) malloc(sizeof (kayit));
	gecici->value=key;
	gecici->sonraki=NULL;
	
	if(ilk==NULL){
		ilk = gecici;
        son = ilk;
        ilk->onceki = NULL;
    } else {
        son ->sonraki = gecici;
        gecici->onceki = son;
        son = son->sonraki;
        }
        
}

void Listing(){
	system("CLS");
	gecici= ilk;
	
	while(gecici != NULL){
		printf("%c",gecici->value);
		gecici=gecici->sonraki;
		if(gecici== NULL ) break;
	}
	
}
void Deleted(){

	gecici=son;
	
	if(gecici == ilk){
	ilk=NULL;
	son=NULL;
	free(gecici);
	system("CLS");
	Listing();
	
	}else if(gecici->sonraki == NULL) {
	
	son = son->onceki;
	son->sonraki = NULL;
	free(gecici);
	system("CLS");
	Listing();
	
	}
	
}
void Saved(){

	
		FILE *dosya;
		dosya=fopen("kayit.txt","w");
		gecici= ilk;
		char x[10000];
		int i=0;
		while(gecici != NULL){
			x[i]=gecici->value;
			//fprintf(dosya,"%c",gecici->value);
			gecici=gecici->sonraki;
			i++;
		}
		fprintf(dosya,"%s",x);
		fclose(dosya);
		system("CLS");
		printf("\n	-->>Kayit edildi...");
		getch();
		system("CLS");
		Listing();
	
	
	
}

void Opened(){

	system("CLS");
	ilk=NULL;
	son=NULL;
	gecici=NULL;
	
	FILE *dosya;
	dosya=fopen("kayit.txt","r");
	char dizi[1000];
	int i=0;
	if(dosya==NULL) 
	{
	
		printf("\n	-->>Kayitli dosya bulunamadi...");
		getch();
		
		
	
	}else
	
	{
		while( !feof(dosya) )                    /* dosyanýn sonuna kadar */
   	{
      
	  fscanf(dosya,"%c",&dizi[i]);
	  i++;
	  
   	}
  
  
   	for(int k=0;k<i-1;k++) {
   		
   		key=dizi[k];
   		Add();
	   
	   }
	}
	
	
	fclose(dosya);
	Listing();
	
	
}

#include <stdio.h>
#include <conio.h>
#define MAX 5
struct STACK {
    char top;
    char data[MAX][MAX];
}tumpuk;

typedef struct{
    int data[MAX];
    int head;
    int tail;
} Queue;
Queue antrian;
// stack
void inisialisasi1()
{
    tumpuk.top = -1;
}

int IsFull()
{
    if(tumpuk.top == MAX) return 1; else return 0;
}

int IsEmpty()
{
    if(tumpuk.top == -1) return 1; else return 0;
}

void Push(char item[MAX])
{
    tumpuk.top++;
    strcpy(tumpuk.data[tumpuk.top],item);
}

void Pop()
{
    printf("Data yang terambil = %s\n", tumpuk.data[tumpuk.top]);
    tumpuk.top--;
}

void Clear()
{
    tumpuk.top = -1;
}

void TampilStack()
{
    for(int i=tumpuk.top; i>=0; i--)
    {
        printf ("Data Stack ke %d : %s\n", i, tumpuk.data[i]);
    }
}


void menu_stack()
{
    int pil;
    char item[50];
    inisialisasi1();
       // system("cls");
    do{
        system("cls");
        fflush(stdin);
        printf("1. Push Stack\n");
        printf("2. Pop Stack\n");
        printf("3. Print Stack\n");
        printf("4. Delete Stack\n");
        printf("5. Return Main Menu\n");
        printf("Pilihan anda: ");
        scanf ("%d", &pil);
        system("cls");
        switch (pil)
        {
           case 1 :
                if (IsFull()!= 1){
                printf ("Data yang ingin di input : ");
                scanf (" %[^\n]", &item);
                Push(item);
            }
            else
                printf("\nSudah penuh!\n");
                printf ("Press any key to continue . . .");
            break;
            case 2 :
                if (IsEmpty() != 1){
                    Pop();
            }
                    else
                        printf ("\nStack Masih Kosong!\n");
                        printf ("Press any key to continue . . .");
                    break;
            case 3 :
                if(IsEmpty() != 1){
                        TampilStack();
            }
                    else
                        printf ("\nMasih Kosong!\n");
                        printf ("Press any key to continue . . .");
                    break;

            case 4 :
                    Clear();
                        printf ("\nData Sudah Hapus!\n");
                        printf ("Press any key to continue . . .");
            break;
            case 5 : main(); break;

             default:
                    printf("tidak ada di pilihan\n");
                    getch();
                    break;
        }
        getch();
        system("cls");
    }while (pil!=5);
    getch();
}
//queue
int isEmpty1()
    {
        if(antrian.tail == -1)
        {
            return 1;
        }else{
            return 0;
        }
    }

int isFull1()
    {
        if(antrian.tail == MAX -1)
        {
            return 1;
        }else{
            return 0;
        }
    }

void inisialisasi()
    {
        antrian.head=antrian.tail = -1;
    }

void enqueue(int data)
    {
        if(isEmpty1()==1)
        {
            antrian.head=antrian.tail = 0;
            antrian.data[antrian.tail] = data;
            printf("Data %d berhasil diinput!\n",antrian.data[antrian.tail]);
        }
        else{


        if(isFull1() == 0)
        {
            antrian.tail++;
            antrian.data[antrian.tail] = data;
            printf("data %d berhasil di input\n",antrian.data[antrian.tail]);
        }
        }
    }

int dequeue()
    {
      int i;
        int e = antrian.data[antrian.head];
        for(i=antrian.head;i<=antrian.tail-1;i++){
        antrian.data[i] = antrian.data[i+1]; }
        antrian.tail--;
        printf ("Data yang keluar : %d", e);
        return e;
    }



void clear()
    {
        antrian.head = antrian.tail = -1;
        printf("Data telah di reset!\n");
    }

void print()
 {
      if(isEmpty1()==0){
          for(int i=antrian.head;i<=antrian.tail;i++){
              printf("Data ke-%d = %d\n",i,antrian.data[i]);
     }
   }else printf("Data kosong!\n");
}

int menu_queue()
    {
        int inputdt;
        inisialisasi();
        int pilihan;
        do{
               system("cls");
            fflush(stdin);
            printf("1.Enqueue\n");
            printf("2.Dequeue\n");
            printf("3.Print Queue\n");
            printf("4.Clear Queue\n");
            printf("5.Exit\n");
            printf("Input pilihan:");
            scanf("%d",&pilihan);
            system("cls");
            fflush(stdin);
                switch(pilihan)
                {
                case 1:
                    if(isFull1() !=1)
                    {
                        printf("Masukkan data:");
                        scanf("%d",&inputdt);
                        enqueue(inputdt);
                    }else{
                        printf("data sudah penuh!\n");
                    }
                    printf ("\nPress any key to continue . . .");
                    getch();
                    break;
                case 2:
                    if(isEmpty1() != 1)
                        dequeue();
                   else
                        printf("\nData yang keluar : 0\n");
                        printf ("\nPress any key to continue . . .");
                   getch ();
                    break;
                case 3:
                    if(isEmpty1() != 1)
                        print();
                   else
                        printf("Tidak ada data dalam antrian!\n");
                        printf ("Press any key to continue . . .");
                    getch ();
                    break;
                case 4:
                    clear();
                    printf ("\nPress any key to continue . . .");
                    getch();
                    menu_queue();
                    break;
                case 5:
                    main();
                    break;

                }

        }while(pilihan != 5);
    }
void main()
{
    int n;
    system("COLOR 70");
        system("cls");
      fflush (stdin);
    printf("==============================\n");
    printf("  TUGAS QUIS STACK AND QUEUE  \n");
    printf("==============================\n");
    printf("1. Stack String\n");
    printf("2. Queue Integer\n");
    printf("3. Exit\n");
    printf("==============================\n");
    printf("\nMasukkan pilihan anda : ");
    scanf("%d", &n);
     fflush (stdin);
    switch(n)
    {
        case 1: menu_stack(); break;
        case 2: menu_queue(); break;
        case 3: system("cls"); printf("TERIMA KASIH"); break;
        default :printf("Menu Tidak Tersedia\n");
                 printf("Press any key to continue. . .");
                 main(); break;

    }
    getch();
}

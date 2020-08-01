// ������Ʈ�� : ���� �߰� �׷�
//���̸� :
//������ :
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int All_book_number; //�� å ����

struct book {
    char seller_name[30];    // �Ǹ��� �̸�
    char condition[30];    // å ����
    char book_name[30];    // å �̸�
    char author[30];       // ����
    char phone_numbers[30];    // �޴��� ��ȣ
    char book_price[30];       // å ����
    //int book_stock;       // å ���
};

typedef struct book Book;
Book book[100]; //����ü�迭 100��

void read_data() //�޸��忡�� �����о����
{
   int book_number = 0;   //���� ���°����
   int data_type_count=0; //data Ÿ�Թٲ��ִ� ����
   char string_type[30];
   char c;
   FILE *filepointer = fopen("data.txt", "a+"); //���� a+
    if (filepointer == NULL) //data.txt �� ��ã���� ����ó��
    {
        printf("There is no file\n");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
       c = getc(filepointer);
       if(c==EOF) return;          //EOF ������ ����
      else ungetc(c,filepointer); //EOF �ƴϸ� �������ֱ�

      if(data_type_count==0) // å���� �Է�
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].condition,string_type); //string_type�� book ����ü�� ����
      }
      else if(data_type_count==1) //å�̸� �Է�
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].book_name,string_type);
      }
      else if(data_type_count==2) //å �����Է�
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].author,string_type);
      }
      else if(data_type_count==3) //å �����Է�
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].book_price,string_type);
      }
      else if(data_type_count==4) //�Ǹ��� �̸� (�л��̸� , �����̸�)
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].seller_name,string_type);
      }
      else if(data_type_count==5) //�޴��� ��ȣ
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].phone_numbers,string_type);
      }
      else if(data_type_count==6)
      {
         data_type_count=0;
         book_number++;
         All_book_number = book_number;

         if(book_number == 100) return;
         continue;
      }
      data_type_count++;
   } //while��
}

void print_all(int num) //����ü ��� num ������ŭ
{
   printf("------------å  ���ǥ , �� ���� : %d-----------\n",num);
   for(int i=0;i<num;i++)
   {

      printf("---------%d ��----\n",i+1);
      printf("����:   %s\n�̸�:   %s\n����:   %s\n",book[i].condition, book[i].book_name,book[i].author);
      printf("����:   %s\n�Ǹ���:   %s\n�޴�����ȣ: %s\n",book[i].book_price,book[i].seller_name,book[i].phone_numbers);
      printf("------------------\n");
   }
}
void print(int num) //����ü ��� num ��° �Ѱ��� ���
{
   printf("---------%d ��----\n",num+1);
   printf("����:   %s\n�̸�:   %s\n����:   %s\n",book[num].condition, book[num].book_name,book[num].author);
   printf("����:   %s\n�Ǹ���:   %s\n�޴�����ȣ %s\n",book[num].book_price,book[num].seller_name,book[num].phone_numbers);
   printf("------------------\n");
}
int main(void)
{
    int i, j;
    int select;
    int num = 0;
    char input_seller_name[30];    // �Ǹ��� �̸�
    char input_condition[30];       // å ���� �߰� , ��å
    char input_book_name[30];       // å �̸�
    char input_author[30];          // ����
    char input_phone_numbers[30];       // �޴��� ��ȣ
    char input_book_price[30];          // å ����
    //int input_book_stock;       // å ���

    read_data(); //�޸��忡�� �о����

    FILE *fp = fopen("data.txt", "a+"); //�޸��忡 �������ؼ�

    while(1)
   {
        printf("======�޴� ����======\n");
        printf("1.�л� 2.������ 3.å ��� 4.����\n");

        scanf("%d", &select);
        fflush(stdin);
      int ch;
        if(select==1) //1���޴� (�л�ȭ��)
        {
           printf("1.���� 2.�Ǹ�\n", &select);

            scanf("%d", &select);
            fflush(stdin);
            if (select == 1) // å ���� (�л�)
         {
                printf("ã���� 1. å�̸� 2. ���� 3. �Ǹ��� 4.�޴�����ȣ\n");
                scanf("%d", &select);
                if(select == 1) //å�̸�����ã��
            {
               int temp = 0;
               printf("ã�����ϴ� å �̸�: ");
               scanf("%s", input_book_name);
               for(int i=0;i<All_book_number;i++)
               {
                  if( strcmp(book[i].book_name , input_book_name) == 0) //ã�⼺��
                  {
                     print(i); //i���� å���
                     temp=1;
                  }
               }
               if(temp == 0) //��ã�����
                  printf("å�� ã�� ���Ͽ����ϴ�.\n");
            }
            if(select == 2) //å���ڷ�ã��
            {
               int temp = 0;
               printf("ã�����ϴ� å ����: ");
               scanf("%s", input_book_name);
               for(int i=0;i<All_book_number;i++)
               {
                  if( strcmp(book[i].author , input_book_name) == 0) //ã�⼺��
                  {
                     print(i); //i���� å���
                     temp=1;
                  }
               }
               if(temp == 0) //��ã�����
                  printf("å�� ã�� ���Ͽ����ϴ�.\n");
            }
            if(select == 3) //å�Ǹ��ڷ�ã��
            {
               int temp = 0;
               printf("ã�����ϴ� å�� �Ǹ���: ");
               scanf("%s", input_book_name);
               for(int i=0;i<All_book_number;i++)
               {
                  if( strcmp(book[i].seller_name , input_book_name) == 0) //ã�⼺��
                  {
                     print(i); //i���� å���
                     temp=1;
                  }
               }
               if(temp == 0) //��ã�����
                  printf("å�� ã�� ���Ͽ����ϴ�.\n");
            }
            if(select == 4) //�޴�����ȣ��ã��
            {
               int temp = 0;
               printf("ã�����ϴ� �޴�����ȣ: ");
               scanf("%s", input_book_name);
               for(int i=0;i<All_book_number;i++)
               {
                  if( strcmp(book[i].phone_numbers , input_book_name) == 0) //ã�⼺��
                  {
                     print(i); //i���� å���
                     temp=1;
                  }
               }
               if(temp == 0) //��ã�����
                  printf("å�� ã�� ���Ͽ����ϴ�.\n");
            }
            }
            else if (select == 2) // å �Ǹ� (�л�)
         {
                printf("�Ǹ��ϴ� å��  ����, �̸�, ����, ����, �Ǹ��� �̸�, �޴�����ȣ�� �����ּ���\n");
                scanf("%s %s %s %s %s",input_condition, input_book_name,input_author, input_book_price,input_seller_name,input_phone_numbers);
                fprintf(fp,"%s %s %s %s %s %s\n", input_condition, input_book_name, input_author, input_book_price,input_seller_name,input_phone_numbers);
            }
      }
        else if(select == 2) //2���޴� (������ �Ǹ�)
        {
            printf("�Ǹ��ϴ� å �̸�, ����, ����, �����̸�, ���� ��ȭ��ȣ�� �����ּ���\n");
            scanf("%s %s %s %s %s", input_book_name,input_author, input_book_price,input_seller_name,input_phone_numbers);
            fprintf(fp,"��å %s %s %s %s���� %s\n",input_book_name, input_author, input_book_price,input_seller_name,input_phone_numbers);
      }
      else if(select == 3) //3���޴� å���ǥ ���
      {
          print_all(All_book_number); //����� å ������ŭ ���
      }
      else if(select == 4) //4���޴� ����
      {
         printf("�����ϰڽ��ϴ�.\n");
         return 0;
      }
    } //while ��
}//���α׷� ��

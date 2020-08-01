// 프로젝트명 : 도서 중고 그램
//팀이름 :
//구성원 :
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int All_book_number; //총 책 개수

struct book {
    char seller_name[30];    // 판매자 이름
    char condition[30];    // 책 상태
    char book_name[30];    // 책 이름
    char author[30];       // 저자
    char phone_numbers[30];    // 휴대폰 번호
    char book_price[30];       // 책 가격
    //int book_stock;       // 책 재고
};

typedef struct book Book;
Book book[100]; //구조체배열 100개

void read_data() //메모장에서 파일읽어오기
{
   int book_number = 0;   //현재 몇권째인지
   int data_type_count=0; //data 타입바꿔주는 변수
   char string_type[30];
   char c;
   FILE *filepointer = fopen("data.txt", "a+"); //권한 a+
    if (filepointer == NULL) //data.txt 를 못찾을때 예외처리
    {
        printf("There is no file\n");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
       c = getc(filepointer);
       if(c==EOF) return;          //EOF 만나면 종료
      else ungetc(c,filepointer); //EOF 아니면 값돌려주기

      if(data_type_count==0) // 책상태 입력
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].condition,string_type); //string_type을 book 구조체에 복사
      }
      else if(data_type_count==1) //책이름 입력
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].book_name,string_type);
      }
      else if(data_type_count==2) //책 저자입력
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].author,string_type);
      }
      else if(data_type_count==3) //책 가격입력
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].book_price,string_type);
      }
      else if(data_type_count==4) //판매자 이름 (학생이름 , 서점이름)
      {
         fscanf(filepointer,"%s",string_type);
         strcpy(book[book_number].seller_name,string_type);
      }
      else if(data_type_count==5) //휴대폰 번호
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
   } //while끝
}

void print_all(int num) //구조체 출력 num 개수만큼
{
   printf("------------책  목록표 , 총 갯수 : %d-----------\n",num);
   for(int i=0;i<num;i++)
   {

      printf("---------%d 번----\n",i+1);
      printf("상태:   %s\n이름:   %s\n저자:   %s\n",book[i].condition, book[i].book_name,book[i].author);
      printf("가격:   %s\n판매자:   %s\n휴대폰번호: %s\n",book[i].book_price,book[i].seller_name,book[i].phone_numbers);
      printf("------------------\n");
   }
}
void print(int num) //구조체 출력 num 번째 한개만 출력
{
   printf("---------%d 번----\n",num+1);
   printf("상태:   %s\n이름:   %s\n저자:   %s\n",book[num].condition, book[num].book_name,book[num].author);
   printf("가격:   %s\n판매자:   %s\n휴대폰번호 %s\n",book[num].book_price,book[num].seller_name,book[num].phone_numbers);
   printf("------------------\n");
}
int main(void)
{
    int i, j;
    int select;
    int num = 0;
    char input_seller_name[30];    // 판매자 이름
    char input_condition[30];       // 책 상태 중고 , 새책
    char input_book_name[30];       // 책 이름
    char input_author[30];          // 저자
    char input_phone_numbers[30];       // 휴대폰 번호
    char input_book_price[30];          // 책 가격
    //int input_book_stock;       // 책 재고

    read_data(); //메모장에서 읽어오기

    FILE *fp = fopen("data.txt", "a+"); //메모장에 쓰기위해서

    while(1)
   {
        printf("======메뉴 선택======\n");
        printf("1.학생 2.서점원 3.책 목록 4.종료\n");

        scanf("%d", &select);
        fflush(stdin);
      int ch;
        if(select==1) //1번메뉴 (학생화면)
        {
           printf("1.구매 2.판매\n", &select);

            scanf("%d", &select);
            fflush(stdin);
            if (select == 1) // 책 구매 (학생)
         {
                printf("찾기방법 1. 책이름 2. 저자 3. 판매자 4.휴대폰번호\n");
                scanf("%d", &select);
                if(select == 1) //책이름으로찾기
            {
               int temp = 0;
               printf("찾고자하는 책 이름: ");
               scanf("%s", input_book_name);
               for(int i=0;i<All_book_number;i++)
               {
                  if( strcmp(book[i].book_name , input_book_name) == 0) //찾기성공
                  {
                     print(i); //i번쨰 책출력
                     temp=1;
                  }
               }
               if(temp == 0) //못찾은경우
                  printf("책을 찾지 못하였습니다.\n");
            }
            if(select == 2) //책저자로찾기
            {
               int temp = 0;
               printf("찾고자하는 책 저자: ");
               scanf("%s", input_book_name);
               for(int i=0;i<All_book_number;i++)
               {
                  if( strcmp(book[i].author , input_book_name) == 0) //찾기성공
                  {
                     print(i); //i번쨰 책출력
                     temp=1;
                  }
               }
               if(temp == 0) //못찾은경우
                  printf("책을 찾지 못하였습니다.\n");
            }
            if(select == 3) //책판매자로찾기
            {
               int temp = 0;
               printf("찾고자하는 책의 판매자: ");
               scanf("%s", input_book_name);
               for(int i=0;i<All_book_number;i++)
               {
                  if( strcmp(book[i].seller_name , input_book_name) == 0) //찾기성공
                  {
                     print(i); //i번쨰 책출력
                     temp=1;
                  }
               }
               if(temp == 0) //못찾은경우
                  printf("책을 찾지 못하였습니다.\n");
            }
            if(select == 4) //휴대폰번호로찾기
            {
               int temp = 0;
               printf("찾고자하는 휴대폰번호: ");
               scanf("%s", input_book_name);
               for(int i=0;i<All_book_number;i++)
               {
                  if( strcmp(book[i].phone_numbers , input_book_name) == 0) //찾기성공
                  {
                     print(i); //i번쨰 책출력
                     temp=1;
                  }
               }
               if(temp == 0) //못찾은경우
                  printf("책을 찾지 못하였습니다.\n");
            }
            }
            else if (select == 2) // 책 판매 (학생)
         {
                printf("판매하는 책의  상태, 이름, 저자, 가격, 판매자 이름, 휴대폰번호를 적어주세요\n");
                scanf("%s %s %s %s %s",input_condition, input_book_name,input_author, input_book_price,input_seller_name,input_phone_numbers);
                fprintf(fp,"%s %s %s %s %s %s\n", input_condition, input_book_name, input_author, input_book_price,input_seller_name,input_phone_numbers);
            }
      }
        else if(select == 2) //2번메뉴 (서점원 판매)
        {
            printf("판매하는 책 이름, 저자, 가격, 서점이름, 서점 전화번호를 적어주세요\n");
            scanf("%s %s %s %s %s", input_book_name,input_author, input_book_price,input_seller_name,input_phone_numbers);
            fprintf(fp,"새책 %s %s %s %s서점 %s\n",input_book_name, input_author, input_book_price,input_seller_name,input_phone_numbers);
      }
      else if(select == 3) //3번메뉴 책목록표 출력
      {
          print_all(All_book_number); //저장된 책 개수만큼 출력
      }
      else if(select == 4) //4번메뉴 종료
      {
         printf("종료하겠습니다.\n");
         return 0;
      }
    } //while 끝
}//프로그램 끝

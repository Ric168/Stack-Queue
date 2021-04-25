#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct data
{
    int data, angka;
    struct data *next;
} * curr, *head, *tail;

struct queue
{
    struct data *depan;
    struct data *belakang;
};

struct queue *q;

void create_queue(struct queue *q)
{
    q->belakang = NULL;
    q->depan = NULL;
}

void enqueue(int val)
{
    //int val;
    struct data *ptr;
    ptr = (struct data *)malloc(sizeof(struct data));
    ptr->data = val;
    ptr->next = NULL;
    if (q->depan == NULL)
    {
        q->depan = ptr;
        q->belakang = ptr;
    }
    else
    {
        q->belakang->next = ptr;
        q->belakang = ptr;
    }
    return q;
}

void dequeue()
{
    struct data *ptr = q->depan;
    if (ptr == NULL)
    {
        printf("\n Data Kosong\n");
    }
    else
    {
        q->depan = q->depan->next;
        // printf("\n The value being deleted is : %d", ptr->data);
        free(ptr);
        ptr = NULL;
    }
}

void bersihkan()
{
    int counter = 0;
    while (q->depan != NULL)
    {
        ++counter;
        struct data *ptr = q->depan;
        q->depan = q->depan->next;
        free(ptr);
        ptr = NULL;
    }
    if (counter > 0)
    {
        printf("bersihkan() membersihkan sejumlah: %d record", counter);
    }
    q->belakang = NULL;
    free(q);
    q = NULL;
}

int peek()
{
    if (q->depan == NULL)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else
        return q->depan->data;
}

void display()
{
    struct data *ptr = q->depan;
    int angka, val;
    if (ptr == NULL)
    {
        printf("\n QUEUE IS EMPTY");
    }
    else
    {
        printf("\n");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int val, option, temp;
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    system("cls");
    do
    {
        printf("\n Masukkan angka ke queue (negatif untuk mengakhiri): ");
        scanf("%d", &val);
        if (val < 0)
            break;

        if (q->depan == NULL)
        {
            for (int i = 1; i <= val; i++)
            {
                //for (int j=1;j<val;j++)
                enqueue(val);
            }
            //printf("Ini kosong, silahkan input angka\n");

            // ini kosong
            // Jika queue kosong, input angka dan enqueue angka
            // tersebut sebanyak angka tersebut.
        }
        else
        {
            int front = peek();
            if (front < 0)
            {
                continue;
            }

            if (val < front)
            {
                for(int m=0;m<val;m++)
                dequeue();
            }
            else
            {
                // atau sama dengan front, lakukan enqueue sebanyak front tersebut.
                for(int n=1;val>n;n++)
                enqueue(val);
            }
        }
        display();
    } while (1);
    bersihkan();
    return 0;
}

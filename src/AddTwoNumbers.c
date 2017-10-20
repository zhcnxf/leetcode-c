#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    const int size = sizeof(struct ListNode);
    struct ListNode *head = malloc(size);
    struct ListNode *tail = head;
    int val = 0;
    int trib = 0;
    for (; l1 && l2; l1 = l1->next, l2 = l2->next)
    {
        val = l1->val + l2->val + trib;
        trib = val >= 10 ? 1 : 0;
        val %= 10;
        tail->next = malloc(size);
        tail = tail->next;
        tail->val = val;
        tail->next = NULL;
    }

    struct ListNode *l = l1 ? l1 : l2;
    for (; l; l = l->next)
    {
        val = l->val + trib;
        trib = val >= 10 ? 1 : 0;
        val %= 10;
        tail->next = malloc(size);
        tail = tail->next;
        tail->val = val;
        tail->next = NULL;
    }

    if (trib)
    {
        tail->next = malloc(size);
        tail = tail->next;
        tail->val = trib;
        tail->next = NULL;
    }

    tail = head;
    head = head->next;
    free(tail);
    return head;
}

struct ListNode *compose(unsigned int num)
{
    const int size = sizeof(struct ListNode);
    struct ListNode *head = malloc(size);
    struct ListNode *tail = head;
    int n;
    do
    {
        n = num % 10;
        num /= 10;
        tail->next = malloc(size);
        tail = tail->next;
        tail->next = NULL;
        tail->val = n;
    } while (num > 0);
    tail = head;
    head = head->next;
    free(tail);
    return head;
}

char *toString(struct ListNode *head)
{
    struct ListNode *node;
    int i = 0;
    for (node = head; node; node = node->next)
    {
        i++;
    }
    int length = i * 5 + 2 + (i > 0 ? -4 : 0);
    char *str = calloc(sizeof(char), length);
    char buffer[8];
    strcat(str, (char *)"(");
    for (node = head; node; node = node->next)
    {
        if (node->next)
        {
            sprintf(buffer, "%d -> ", node->val);
        }
        else
        {
            sprintf(buffer, "%d", node->val);
        }
        strcat(str, buffer);
    }
    strcat(str, ")");
    return str;
}

int main(int argc, char *argv[])
{
    struct ListNode *l1 = compose(342);
    struct ListNode *l2 = compose(465);
    struct ListNode *l3 = addTwoNumbers(l1, l2);
    printf("%s + %s = %s\n", toString(l1), toString(l2), toString(l3));
    return 0;
}
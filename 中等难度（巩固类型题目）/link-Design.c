
/*-----------------------------------------------------*/
/*
 2024-9-18 题目 LeedCode 707.设计链表
 （Update at 2024.9.20 ）,参考力扣标准答案，才发现自己没看明白题目，把MyLinkedList（在题目中特指整个的链表结构体）误认为链表节点结构体了
*/
/*-----------------------------------------------------*/




#define dataType int
#define MAX(a, b) ((a) > (b) ? (a) : (b))


 
*/
/*-----------------------------------------------------*/
typedef struct {
    struct ListNode *head;
    int size;
} MyLinkedList;

//创建链表节点函数
struct ListNode *ListNodeCreat(int val) {
    struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

//PS：设定obj为一个虚拟链表头
//此题编写过程中出现的错误：在链表尾插法的实现中，没有为obj创建一个临时指针位置
//导致obj在尾插法过后位置发生了变化 , 获取链表的第index个值的函数也是如此
MyLinkedList* myLinkedListCreate() {
    //创建链表
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList) * 1);
    list->head = ListNodeCreat(0);
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index >= obj->size || index < 0)
    {
        printf("obj->next == NULL || index < 0");
        return -1;
    }
    
    //定义真实链表的第一个节点为0位置
    struct ListNode *cur = obj->head;

    for(int i = 0 ; i <= index ; i++)
    {
        cur = cur->next;
    }
    return cur->val;
}



void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    //如果inedx（索引值）大于整个链表的节点数量
    if(index > obj->size)
    {
        return;
    }
    //消除负索引
    index = MAX(0 , index);

    obj->size++;
    struct ListNode *preCur = obj->head;
    for(int i = 0 ; i < index ; i++)
    {
        preCur = preCur->next;
    }
    //创建并添加节点
    struct ListNode *addNode = ListNodeCreat(val);
    addNode->next  = preCur->next;
    preCur->next = addNode;

}


void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
myLinkedListAddAtIndex(obj, obj->size, val);

}



void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return;
    }

    obj->size--;
    struct ListNode *preCur = obj->head;
    for (int i = 0; i < index; i++) {
        preCur = preCur->next;
    }
    struct ListNode *p = preCur->next;
    //删除节点
    preCur->next = preCur->next->next;
    free(p);

}

//释放链表需要从后往前释放
void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode *cur = NULL, *tmp = NULL;
    for (cur = obj->head; cur;) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(obj);


}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/



















#define dataType int


/*-----------------------------------------------------*/
/*
 2024-9-18 题目 LeedCode 707.设计链表
 遇到问题（Update at 2024.9.19）：不知到为啥个测试用例过不去，照着答案看了好一会也没找到问题所在，决定明天晚上再把这题做一遍
 错误范例：
 输入
["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
[[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]

添加到测试用例
标准输出
nowNode == NULL
输出
[null,null,null,null,null,null,null,null,-1,null,null,null]
预期结果
[null,null,null,null,null,null,null,null,4,null,null,null]
*/
/*-----------------------------------------------------*/
typedef struct MyLinkedList_t{
    dataType val;
    struct MyLinkedList_t *next;//链表别名
} MyLinkedList;

//PS：设定obj为一个虚拟链表头
//此题编写过程中出现的错误：在链表尾插法的实现中，没有为obj创建一个临时指针位置
//导致obj在尾插法过后位置发生了变化 , 获取链表的第index个值的函数也是如此
MyLinkedList* myLinkedListCreate() {
    //创建链表
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList) * 1);
    list->val = 0;
    list->next = NULL;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(obj->next == NULL || index < 0)
    {
        printf("obj->next == NULL || index < 0");
        return -1;
    }
    
    //定义真实链表的第一个节点为0位置
    int now = 0;
    MyLinkedList* nowNode = obj->next;

    //遍历链表
    while(now < index)
    {
        if(nowNode == NULL){
            printf("nowNode == NULL");
            return -1;
        }

        nowNode = nowNode->next;
        now++;
    }
    if(nowNode != NULL)
    {
        return nowNode->val;
    }

    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    //链表头部插入法
    //先创建链表节点
    MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->next = NULL;
    node->val = val;
    //两种情况：链表为空和链表不为空
    if(obj->next = NULL)
    {
        obj->next = node;
        return ;
    }
    else
    {
        node->next = obj->next;
        obj->next = node;
    }
    return ;

}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    //链表尾部插入法
    
    //创建节点
    MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->next = NULL;
    node->val = val;
    

        MyLinkedList* objTemp = obj;
        while(objTemp->next != NULL)
        {
            objTemp = objTemp->next;
        }
        objTemp->next = node;
    
    return ;



}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    //在链表内部增加一个节点

    //负索引或零索引
    if(index <= 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    //链表不为空
    //需要遍历链表，创建obj的临时指针
    //并定义链表的第一个真实节点为位置0
    int now = 0;
    MyLinkedList* tempNode = obj->next;
    while(tempNode->next != NULL)
    {
        if(now == index - 1)
        {
            break;
        }
        tempNode = tempNode->next;
        now++;
    }

    if(now != index - 1)
    {
        return ;
    }
    //创建节点
    MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->next = NULL;
    node->val = val;

    node->next = tempNode->next;
    tempNode->next = node;


}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    
    //删除节点
    //如果链表为空
    if(obj->next == NULL || index < 0)
    {
        return ;
    }
    //删除第一个节点
    if(index == 0)
    {
        obj->next = obj->next->next;
		return; 
    }
    //遍历链表
    MyLinkedList* tempNode = obj->next;
    int nowval = 0;

    while(tempNode->next != NULL)
    {
        if(nowval == index - 1)
        {
            break;
        }
        tempNode = tempNode->next;
        nowval++;
    }
    if(nowval == index - 1 && tempNode->next != NULL)
    {
        tempNode->next = tempNode->next->next;
    }



}

//释放链表需要从后往前释放
void myLinkedListFree(MyLinkedList* obj) {
    if(obj->next != NULL)
    {
        myLinkedListFree(obj->next);
        obj->next = NULL;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
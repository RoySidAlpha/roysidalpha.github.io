#include <bits/stdc++.h>
using namespace std;

struct node
{
	string data;
	struct node *ch1 , *ch2 , *ch3;
	bool flag;
};


void create(node *head)
{
    head->data = "S";
	head->ch1 = NULL , head->ch2 = NULL , head->ch3 = NULL;
	head->flag = false;
	
	node *temp = new node;
	temp->data = "NP";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch1 = temp;
	
	temp = new node;
	temp->data = "ART";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch1->ch1 = temp;
	
	temp = new node;
	temp->data = "a";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch1->ch1->ch1 = temp;
	
	temp = new node;
	temp->data = "an";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch1->ch1->ch2 = temp;
	
	temp = new node;
	temp->data = "the";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch1->ch1->ch3 = temp;
	
	temp = new node;
	temp->data = "N";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch1->ch2 = temp;
	
	temp = new node;
	temp->data = "cat";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch1->ch2->ch1 = temp;
	
	temp = new node;
	temp->data = "rat";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch1->ch2->ch2 = temp;
	
	temp = new node;
	temp->data = "dog";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch1->ch2->ch3 = temp;
	
	temp = new node;
	temp->data = "VP";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2 = temp;
	
	temp = new node;
	temp->data = "V";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch1 = temp;
	
	temp = new node;
	temp->data = "killed";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch1->ch1 = temp;
	
	temp = new node;
	temp->data = "ate";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch1->ch2 = temp;
	
	temp = new node;
	temp->data = "chased";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch1->ch3 = temp;
	
	temp = new node;
	temp->data = "NP";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch2 = temp;
	
	temp = new node;
	temp->data = "ART";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch2->ch1 = temp;
	
	temp = new node;
	temp->data = "a";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch2->ch1->ch1 = temp;
	
	temp = new node;
	temp->data = "an";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch2->ch1->ch2 = temp;
	
	temp = new node;
	temp->data = "the";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch2->ch1->ch3 = temp;
	
	temp = new node;
	temp->data = "N";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch2->ch2 = temp;
	
	temp = new node;
	temp->data = "cat";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch2->ch2->ch1 = temp;
	
	temp = new node;
	temp->data = "rat";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch2->ch2->ch2 = temp;
	
	temp = new node;
	temp->data = "dog";
	temp->ch1 = NULL , temp->ch2 = NULL , temp->ch3 = NULL;
	temp->flag = false;
	head->ch2->ch2->ch2->ch3 = temp;
	
}

bool visited(node *n)
{
    if(n == NULL)
        return true;
    else
        return n->flag;
}

bool traverse(node *head , string s)
{
    if(!visited(head))
    {
        if(head == NULL)
            return false;
        else if(head->ch1->ch1 == NULL)
        {
            head->flag = true;
            if(head->ch1->data == s || head->ch2->data == s || head->ch3->data == s)
                return true;
            else
                return false;
        }
        else
        {
            if(!visited(head->ch1) || !visited(head->ch2) || !visited(head->ch3))
            {
                return traverse(head->ch1,s) || traverse(head->ch2,s) || traverse(head->ch3,s) ;
            }
            else
            {
                head->flag = true;
                return false;
            }
        }
    }
    else
        return false;
    
}

void print(node *head)
{
    if(head == NULL)
        return;
    else
    {
        cout << head->data << " ";
        print(head->ch1);
        print(head->ch2);
        print(head->ch3);
    }
}

int main()
{
	node *head = new node;
	create(head);
	
	string str;
	cout << "Enter the string(all in lower case) : ";
	getline (cin, str);
	string s;
	stringstream iss(str);
	while(iss >> s)
	{
	    bool f;
	    f = traverse(head,s);
	    if(!f)
	    {
            cout << "wrong input";
            exit(1);
	    }
	}
	cout << "Right input";
	//print(head);
	
	return 0;
	
}

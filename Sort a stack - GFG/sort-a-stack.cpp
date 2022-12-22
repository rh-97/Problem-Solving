//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void push(stack<int>& s, int temp) {
    if (s.empty() || s.top() <= temp) {
        s.push(temp);
        return;
    }
    int tmp = s.top();
    s.pop();
    push(s, temp);
    s.push(tmp);
}

void sortStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    
    int temp = s.top();
    s.pop();
    sortStack(s);
    push(s, temp);
}


/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   sortStack(s);
}
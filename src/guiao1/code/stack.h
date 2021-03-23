struct StackElem
{
  StackElem(int d, StackElem *n) 
    { data = d; next = n; }
  int data;
  StackElem *next;
};


class Stack
{
 public:
  Stack(); 
  Stack();
  
  void PUSH(int x);
  int POP();  

 private:
  StackElem *head;
};
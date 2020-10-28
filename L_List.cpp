/* Node Definition
struct Node {
  Node * next;
  int data;
}
*/

int Length(Node *head)
{
  Node* temp = head;
  
  if(temp==nullptr)
    return 0;
  
  
  int count=0;
  while(temp!=nullptr)
  {
    temp=temp->next;
    count++;
  }
  return count;
}

int Count(Node *head, int data)
{
  if(head==nullptr)
    return 0;
 
  if(head->data==data)
    return 1+Count(head->next, data);
  else
    return Count(head->next, data);
  
}

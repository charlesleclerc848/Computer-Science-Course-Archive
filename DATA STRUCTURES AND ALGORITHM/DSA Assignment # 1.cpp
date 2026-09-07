#include<iostream>
using namespace std;
class node{
public:
int data;
node *next;
	node(int value){
		data=value;
		next=NULL;
	}
	
	
};

class singlyList{
	private:
	node *head;
	public:
	singlyList(){
		head=NULL;
	}
	
	void insert_at_beginning(int value){
		node *new_node=new node(value);
		new_node->next=head;
		head=new_node;		
	}
	
	void insert_at_end(int value){
		node *new_node=new node(value);
		if(head==NULL){
			head=new_node;
			return;
		}
		node *temp=head;
		while(temp->next !=NULL){
			temp=temp->next;
		}
		temp->next=new_node;	
	}
	
	void insert_at_position(int value, int position){
		node *new_node=new node(value);
		if(position==1){
			new_node->next=head;
			head=new_node;
			return;
		}
		
		node *temp= head;
		for(int i=1;temp !=NULL &&i<position-1;i++){
			temp=temp->next;
		}
		
		if(temp ==NULL){
			cout<<"Position out of bounds"<<endl;
			return;
		}
		new_node->next=temp->next;
		temp->next=new_node;
		
	}
	
	void display(){
		node *temp=head;
		while(temp != NULL){
			cout<<temp->data<<"-->";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	
	void delete_from_beginning(){
		if(head==NULL){
			cout<<"List is empty!"<<endl;
			return;
		}
		node *temp=head;
		head=head->next;
		delete temp;
	}
	
	void delete_from_end(){
		if(head==NULL){
			cout<<"List is empty!"<<endl;
			return;
		}	
		
		if(head->next ==NULL){
			delete head;
			head=NULL;
			return;
		}
		node *temp=head;
		while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
	}
	
	    void delete_node(int key) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        if (head->data == key) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* temp = head;
        node* prev = NULL;

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node not found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }
/*	
	void insertion_Sort(int arr[],int size){
		for(int i=1;i<size;i++){
			int curr=arr[i];
			int prev=temp;
			while(prev>=0 && arr[prev]>curr){
				arr[prev+1]=arr[prev;]
				prev--;
			}
			arr[prev+1]=curr;
			}
		}
*/

void insertion_sort(){
	if(!head || !head->next)
	return;
	
	node *sorted=NULL;
	node *current=head;
	
	while(current){
	node *next_node=current->next;	
		if(!sorted || sorted->data >= current->data){
			current->next=sorted;
			sorted=current;
		}else{
			node *temp = sorted;
                while (temp->next && temp->next->data < current->data) {
                    temp = temp->next;		
		}
		current->next=temp->next;
		temp->next=current;
	}
	current=next_node;
}
head=sorted;
}



	
	int count_nodes(){
		int count=0;
		node *temp=head;
		while(temp !=NULL){
			count++;
			temp=temp->next;
		}
		return count;
	}
	
void find_max_and_min(){
	
	        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
	
	int max_val=head->data;
	int min_val=head->data;
	node *temp=head;
	while(temp){
		if (temp->data > max_val){
			max_val=temp->data;
		}
				if (temp->data < min_val){
			min_val=temp->data;
		}
		
		temp=temp->next;
	}
	
	cout<<"Maximum : "<<max_val<<endl;
	cout<<"Minimum : "<<min_val<<endl;
	cout<<"Maximum - Minimum : "<<max_val-min_val<<endl;
	
}	
	
	
	
	
};




class circular_linked_list{
	private:
	node *head;
	public:
	circular_linked_list(){
		head=NULL;
	}
	
	
	void insert(int value){

node *new_node=new node(value);
if(!head){
	head=new_node;
	new_node->next=head;
	
}else{
node* temp=head;	
	while(temp->next !=head)
	temp=temp->next;
	temp->next=new_node;
	new_node->next=head;
	
}


}



	
	void display(){
if(!head){
return;
}
node *temp=head;
do{
	cout<<temp->data<<"-->";
	temp=temp->next;
}while(temp!=head);
cout<<"back to head"<<endl;

	}	
	
void sum_of_even_numbers(){
	if(!head){
		cout<<"List is empty !"<<endl;  
		return;
	}
	int sum=0;
	node *temp=head;
	do{
		if(temp->data % 2 ==0)
			sum += temp->data;
			temp=temp->next;
		}while(temp!=head);
		
		cout<<"Sum of Even Numbers : "<<sum<<endl;
		
	
	
}
	
	
	

	
	
	
};

class doubly_linked_list{
	
	private:
	struct doubly{
		int data;
		doubly *next;
		doubly *prev;
	
	doubly(int value){
		data=value;
		next=prev=NULL;
	}
	};
	
	doubly *head;
	
public:	
	doubly_linked_list(){
		head=NULL;
	}
	
	
	
	int find_smallest(){
		if(!head){
			cout<<"List is empty!"<<endl;
			return -1;
		}
		
		int min_value=head->data;
		doubly *temp=head;
		while(temp){
			if(temp->data < min_value)
			min_value =temp->data;
			temp=temp->next;
		}
		return min_value;
		
	}
	
	
	
	
	
	void insert_at_end(int value){
		doubly *new_node=new doubly(value);
		if(!head){
			head=new_node;
			return;
		}
		doubly *temp=head;
		
		while(temp->next)
		temp=temp->next;
		temp->next=new_node;
		new_node->prev=temp;
	}
	
	
	void display(){
		doubly *temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }	

	void delete_smallest(){
		if(!head){
			cout<<"List is empty!"<<endl;
			return;
		}
		
		int min_val=find_smallest();
		doubly *temp=head;
		
		while(temp && temp->data !=min_val)
		temp=temp->next;
		
		if(!temp){
		return;
		}
		
		if(temp==head){
			head=head->next;
		}
		
		
		if(temp->next){
			temp->next->prev=temp->prev;
		}
		
			if(temp->prev){
			temp->prev->next=temp->next;
		}
		
		delete temp;
		
		 cout << "Deleted smallest value: " << min_val << endl;
	}
	
	
	
};





int main(){
singlyList list;
    
    //list.insert_at_beginning(NULL);
    list.insert_at_beginning(4);
    list.insert_at_beginning(7);
    list.insert_at_beginning(5);
    list.insert_at_beginning(2);
    list.insert_at_beginning(1);
    
	
	list.insert_at_beginning(8);
	list.display();
	
    list.delete_from_beginning();
	list.insert_at_end(8);
	list.display();
	
	list.delete_from_end();
	list.insert_at_position(8,4);
	list.display();
	
	cout<<endl<<endl;
	
	singlyList list_2;
	
	list_2.insert_at_beginning(4);
	list_2.insert_at_beginning(7);
	list_2.insert_at_beginning(5);
	list_2.insert_at_beginning(2);
	list_2.insert_at_beginning(1);
	
	list_2.delete_from_beginning();
	list_2.display();
	
	list_2.insert_at_beginning(1);
	list_2.delete_from_end();
	list_2.display();
	
	list_2.insert_at_end(4);
	//list_2.display();
	//list_2.insert_at_position();
	list_2.delete_node(5);
	list_2.display();
	
		cout<<endl<<endl<<endl;
	
	singlyList list_3;
	
	list_3.insert_at_beginning(1);
	list_3.insert_at_beginning(2);
	list_3.insert_at_beginning(3);
	list_3.insert_at_beginning(4);
	list_3.insert_at_beginning(5);
	
	list_3.display();
	list_3.insertion_sort();
		list_3.display();
		
	list_3.find_max_and_min();
	
	cout<<endl;
		
		circular_linked_list cll;
    cll.insert(2);
    cll.insert(5);
    cll.insert(8);
    cll.insert(7);
    cll.insert(10);
    
    cout<<endl;
    cll.display();
    cout<<endl;
    cll.sum_of_even_numbers();
    
    
    doubly_linked_list dll;
    int num,values;
    
    cout<<"Enter number of elements: ";
    cin>>num;
    
    cout << "Enter elements: ";
    for (int i = 0; i<num; i++) {
        cin>>values;
        dll.insert_at_end(values);
    }
    
    dll.display();
    
        cout<<endl;

    cout<<"Smallest value : "<<dll.find_smallest()<<endl;
		        cout<<endl;

		
dll.delete_smallest();
dll.display();
		
}


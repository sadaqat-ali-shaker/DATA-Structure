#include<iostream>
using namespace std;
class list{
	int *arr;
	int capacity;
	int size;
	int *curr;
public:
	list(){
	capacity=0;
	size=0;
	curr=arr;
	arr=NULL;
	}
	void createlist(int icapacity){
		arr=new int[icapacity];
		capacity=icapacity;
	}
	void copy(list ob){
		this->capacity=ob.capacity;
		this->size=ob.size;
		for (int i=0;i<ob.size;i++) {
			arr[i]=ob.arr[i];
		}
	}
void clear(){
	delete[] arr;
	size=0;
	capacity=0;
	curr=arr;
	}
	void insert(int num){
		if(size>=capacity) {
		cout<<"Lst full."<<endl;
		return;
		}
	*curr=num;
	size++;
	curr++;
	}
	void insertat(int num,int pos){
		if(pos<0||pos>size){
		cout<<"invalid pos "<<endl;
			return;
		}
		if(size>=capacity){
		cout<<"full list "<<endl;
			return;
		}
	for(int i=size-1;i>=pos;i--){
		*(curr+i+1)=*(curr+i);
		}
		*(curr+pos)=num;
		size++;
	}
	int remove(int pos){
		if(pos<0||pos>=size){
			cout<<"invalid pos "<<endl;
			return -1;
		}
	for(int i=pos;i<size-1;i++){
	*(curr+i)=*(curr+i+1);
		}
	*(curr+size-1)=0;
		size--;
		return 0;
	}
	int get(int pos){
		if(pos<0||pos>=size){
			cout<<"invalid position "<<endl;
		return -1;
		}
		return *(curr + pos);
	}
	int update(int num, int pos){
		if(pos<0||pos>=size){
		cout<<"invalid pos "<<endl;
		return -1;
		}
	*(curr+pos)=num;
		return 0;
	}
	int find(int num) {
		for(int i=0;i<size;i++) {
		if(*(curr+i)==num){
			return 1;
			}
		}
		return 0;
	}
	int length(){
		return size;
	}
	int printlist(){
		for(int i=0;i<size;i++){
			cout<<*(curr+i)<<" ";
		}
		cout<<endl;
	}
	int full(){
		return(size==capacity)?0:1;
	}
	int empty(){
		return(size==0)?0:1;
	}
	void t(){
		curr=(curr+size);
	}
	void next(){
		curr++;
	}
	void back(){
		curr--;
	}
	void start(){
		curr=arr;
	}
	void tail(){
		curr=curr+size-1;
	}
};
int main(){
	list lst;
	int choice,element,position;
	list copylst;
	do{
	cout<<endl;
	cout<<"------ Menu ------"<<endl;
	cout<<"1. create new list"<<endl;
	cout<<"2. copy list"<<endl;
	cout<<"3. clear list"<<endl;
	cout<<"4. insert element"<<endl;
	cout<<"5. remove element"<<endl;
	cout<<"6. get element at position"<<endl;
	cout<<"7. update element at position"<<endl;
	cout<<"8. find element"<<endl;
	cout<<"9. length of list"<<endl;
	cout<<"10. exit"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	cout<<endl<<endl;
	switch(choice){
	case 1:
		cout<<"enter capacity: ";
	int c;
	cin>>c;
	lst.createlist(c);
	cout<<"list created."<<endl;
		break;
	case 2:
	copylst.copy(lst);
	cout<<"list copied"<<endl;
	break;
	case 3:
	lst.clear();
	cout<<"list cleared "<<endl;
		break;
	case 4:
	cout<<"enter element to insert: "<<endl;
	cin>>element;
	lst.insert(element);
		break;
	case 5:
	cout<<"enter position to remove element from: "<<endl;
	cin>>position;
	lst.remove(position);
		break;
	case 6:
	 	cout<<"Enter position get element from: "<<endl;
		cin>>position;
		cout<<"element at position "<<position<<": "<<lst.get(position)<<endl;
		break;
	case 7:
		cout<<"enter element to update: ";
		cin>>element;
		cout<<"enter position to update at: ";
		cin>>position;
		lst.update(element, position);
		break;
	case 8:
		cout<<"enter element to find: ";
		cin>>element;
	if(lst.find(element)){
		cout<<"element found in the list."<<endl;
		}
	else{
		cout<<"element not found in the list."<<endl;
		}
		break;
	case 9:
		cout<<"length "<<lst.length()<<endl;
		break;
	case 10:
		cout<<"exiting program."<<endl;
		break;
	default:
		cout<<"invalid try again "<<endl;
	}
	}while(choice!=10);

	return 0;
}

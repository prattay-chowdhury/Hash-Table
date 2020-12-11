//Hash Table
//Submitted by Prattay Chowdhury
//Here the hash function is the summation of ASCII values of characters in the string.

#include <fstream>
#include <iostream>
#include<string>
using namespace std;

bool is_prime(int number){
	
	if (number<=1) return false;
	
	bool decision=true;
	
	for (int i=2;i<number;i++)
		if (number%i==0) 
		{
			decision=false;
			break;
		}
	return decision;
}

int find_next_prime(int number){
	bool decision;
	while(1)
	{
		if (is_prime(number))
			break;
		
		number++;
		
	}
	return number;
}

struct node{
  string key;
};


class hash_table{
private:
	int size;
	int node_count;
	node** table; 
	int collision_count;
	void resize_hash_table() {
		int old_table_size = size;
		size = find_next_prime(2*old_table_size);  //new table size is assigned as the prime number next to double of previous size
		node **old_table = table;
		table = new node*[size];
		
		for (int i = 0; i < size; i++)
			table[i] = NULL;        //creating new empty table;
		
		node_count=0;          //Data will be rehashed so node count resets
		collision_count=0;  		//Collision count resets for new table
		for (int i = 0; i < old_table_size; i++)
			if (old_table[i] != NULL) 
			{
				node* A= new node;
				A=old_table[i];
				insert(A->key);   //data is rehashed and inserted into new table
            }
	}
	
public:
	hash_table(int tab_size);
	void insert(string key);
	void print_table();
	void print_collision_count();
};


hash_table::hash_table(int tab_size){
	size=tab_size;
	collision_count=0;
	node_count=0;
	table = new node* [size];
	
	for(int k=0; k<size; k++)
		table[k]=NULL;
}


void print_node(node* root){
	cout<<root->key;
}


void hash_table::insert(string key){
	int sum=0;
	int i;
	int index;
	node* A = new node;
	A->key = key;

	if (node_count>=(size/2))
	{
		resize_hash_table();  //Table resizes and rehased when it is half filled
	}
	
	for (i=0;i<key.size();i++)
		sum = sum+key[i];

  
	index = sum%size;
	
	i=1;
	while(table[index]!=NULL){
		index=(index+(i*i))%size;
		collision_count++;
	}
  
	table[index] = A;
	node_count++;
}



void hash_table::print_table(){
	cout<<"The hash table (index,key):"<<endl;
	for(int i=0; i<size; i++)
    if(table[i]!=NULL){
		cout<<"("<<i<<",";
		print_node(table[i]);
		cout<<")"<<endl;
    }
}

void hash_table::print_collision_count(){
	cout<<"Total number of collision is "<<collision_count<<endl;
}

int main()
{
	hash_table A(31);   //Starting size is 31
	string input;
	ifstream input_file;
	input_file.open("table_inputs.txt");
	while (input_file >> input) {
		A.insert(input);
	}
	input_file.close();
	


	A.print_table();
	A.print_collision_count();
  
	return 0;
}

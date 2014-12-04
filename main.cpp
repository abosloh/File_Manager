
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <iomanip>
#include <string.h>
#include <ctime>

using namespace std;


class file{
public:
	string name;
	int size; // byte
	int timeCreation;
	
	file * next; // pointer to the next file
	file * prev; // pointer to the previous file
	
	file(string n , int s , int t = time(0) ){
		name = n;
		size = s;
		timeCreation =  t ;
		
		/*
		SYSTEMTIME time;
		GetSystemTime(&time);
		WORD millis = (time.wSeconds * 1000) + time.wMilliseconds;
		 */
		
		next = NULL;
		prev = NULL;
	}
	
	void print(){
		cout << name << " : " << size  << " : " << timeCreation << endl;
	}
	
};

class File_Manager{
public:
	
	file * head;
	
	File_Manager(){
		head = NULL;
	}
	
	bool isEmpty(){
		return (head == NULL);
	}
	
	void Add(string n , int s){
		file * new_file = new file( n , s );
		if(isEmpty())
			head = new_file;
		else {
			file * current = head;
			while(current->next != NULL)
				current = current->next;
			
			current->next = new_file;
			new_file->prev = current;
		}
		
		
	}
	
	// delete file 
	void Delete(string n){
		
		file * current_file = getFileByName(n);
		if(current_file == NULL)
			return;
		
		
		if(current_file == head)
			head = head->next;
		
		if(current_file->next != NULL)
			current_file->next->prev = current_file->prev;
		
		if(current_file->prev != NULL)
			current_file->prev->next = current_file->next;
		
		delete current_file;
	}
	
	
	void Rename(string old_n , string new_n){
		// if there is another file have the same new name 
		file * new_file = getFileByName(new_n);
		if(new_file != NULL)
			return;
		
		// find the old file by given name 
		file * old_file = getFileByName(old_n);
		if(old_file == NULL)
			return;
		
		// update the old name with new name
		old_file->name = new_n;
	}
	
	// duplicate a file and add (1) or (2) at the end 
	void Duplicate(string n , int duplicate_n = 1){
		file * c_file = getFileByName(n);
		if(c_file == NULL)
			return;
		
		while(duplicate_n >0 ){
			
			file * Duplicated_file = new file(c_file->name , c_file->size , c_file->timeCreation);

			Duplicated_file->next = c_file->next;
			Duplicated_file->prev = c_file;

			c_file->next = Duplicated_file;
			if(Duplicated_file->next != NULL)
				Duplicated_file->next->prev = Duplicated_file;
			
			duplicate_n--;
		}
	}
	
	// find a file by given name 
	// if it is exists return pointer to the file
	// else return NULL
	file* getFileByName(string n){
		file * current = head;
		while(current != NULL)
			if(current->name == n)
				return current;
			else 
				current = current->next;
			
		return NULL;
	}
	
	// return the number of file in file manager
	int getSize(){
		file * current = head;
		int sum = 0;
		while(current != NULL){
			sum++;
			current = current->next;
		}
		return sum;
	}
	
	
	// sort the list by name (descendant)
	void SortByNameDesc(){
		if(getSize() <= 1)
			return;
		
		File_Manager new_f;
		file * maximum , * current;
		
		while( !isEmpty() ){
			maximum = head;
			if(head->next != NULL){
				current = head->next;
				while(current != NULL){
					if(maximum->name < current->name)
						maximum = current;
					
					current = current->next;
				}
			}
			new_f.Add(maximum->name , maximum->size);
			Delete(maximum->name);
			
		}
		head = new_f.head;
		
	}
	
	// sort the list by name (ascendant)
	void SortByNameAsc(){
		if(getSize() <= 1)
			return;
		
		File_Manager new_f;
		file * minimum , * current;
		
		while( !isEmpty() ){
			minimum = head;
			if(head->next != NULL){
				current = head->next;
				while(current != NULL){
					if(minimum->name > current->name)
						minimum = current;
					
					current = current->next;
				}
			}
			new_f.Add(minimum->name , minimum->size);
			Delete(minimum->name);
			
		}
		head = new_f.head;
		
	}
	
	
	
	// sort the list by size (descendant)
	void SortBySizeDesc(){
		if(getSize() <= 1)
			return;
		
		File_Manager new_f;
		file * maximum , * current; 
		
		while( !isEmpty() ){
			maximum = head;
			if(head->next != NULL){
				current = head->next;
				while(current != NULL){
					if(maximum->size < current->size)
						maximum = current;
					
					current= current->next;
				}
			}
			new_f.Add(maximum->name , maximum->size);
			Delete(maximum->name);
			
		}
		head = new_f.head;
	}
	
	
	// sort the list by size (ascendant)
	void SortBySizeAsc(){
		if(getSize() <= 1)
			return;
		
		File_Manager new_f;
		file * minimum , * current; 
		
		while( !isEmpty() ){
			minimum = head;
			if(head->next != NULL){
				current = head->next;
				while(current != NULL){
					if(minimum->size > current->size)
						minimum = current;
					
					current= current->next;
				}
			}
			new_f.Add(minimum->name , minimum->size);
			Delete(minimum->name);
			
		}
		head = new_f.head;
	}
	
	
	
	// print the list from head to tail
	void print(){
		if(isEmpty()){
			cout << "file manager is empty!" << endl;
			return;
		}
			
		file * current = head;
		cout << "file name : size : time" << endl;
		while( current != NULL){
			current->print();
			current = current->next;
		}
	}
};

int main() {
	
	File_Manager fm;
	fm.Add("Background" , 23);
	fm.Add("Applications" , 230);
	fm.Add("Desktop" , 500);
	fm.Add("Decuments" , 300);
	fm.Add("Images" , 5000);
	fm.Add("Videos" , 10000);
	
	cout << "Desc : " << endl;
	fm.SortByNameDesc();
	fm.print();
	
	cout << "Asc : " << endl;
	fm.SortByNameAsc();
	fm.print();
	*/
	
	
	
	return 0;
}


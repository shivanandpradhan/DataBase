// Project on DataBase 

#include<bits/stdc++.h>
using namespace std;


// class for creating any DataBase.
class createObject{
	
	public:
		string name;              // name of the DataBase
		vector <string> str;
		vector <string> number;
		vector <string> decimal;
		
		// creataing a map which will helps in knowing that there is not any duplicacy in the column names.
		map < string, pair< int, string> > mp;
		
		 void createObjects(){
		 	
		 	// ignore used for ignoring new line so getline doesnot causes error.		 	
		 	cin.ignore(10000, '\n');
		 	
			cout<<"\n Enter the name of your DataBase : "; getline(cin, name);
			
			// make the database name to upper Case().
			transform(name.begin(), name.end(), name.begin(), ::toupper);
			
			cout<<"\n\n\tSet Columns(Fields) for your "<<name<<" DataBase\n\n"<<endl;
			
		 	// string input
		 	getInputs("str");
		 	
		 	// integer input
		 	getInputs("int");
		 	
		 	// float input
		 	getInputs("float");
		 	
		 	cout<<"\n\n\t\tDataBAse: "<<name<<" is setted now."<<endl<<endl<<endl;
		 }

		 
		 void getInputs(string type){
		 	
		 	cout<<"\n ------------ * Enter Field Name having (type -> " << type << ") * ------------"<<endl;
		 	
		 	//local variables
		 	int varCount = 0;
		 	string temp;	
		 	
		 	// getting input until user type done.
		 	do{
		 		cout<<"\n\tEnter \"done\" without quotes if you don\'t want to add field of type - " << type << "."<<endl;
				cout<<"\n  Enter var no. "<< varCount + 1 <<" (type - " << type << ") : "; cin >> temp;
				
				// if user not type done then add it to the vector - number
				if (temp != "done"){
					
					// checking duplicacy
					if(mp.find(temp) == mp.end()){
						
						// assining the data inside the map if key is not in the map
						mp[temp] = make_pair(varCount++, type);
					
						// pushing the data inside the vector based on the type of data
						if (type == "int")
							number.push_back(temp); // pushing the data inside the string variable.
						
						else if (type == "str")
							str.push_back(temp);
							
						else if (type == "float")
							decimal.push_back(temp);
					}
					else{
						
						cout<<"\n\t\tThis name already Exists. Try Another Name.\n\n";
					}
					
				} 
		 	}while(temp != "done");
		 	
		 	cout<<endl;	
		 	
		 }
		 
		 
		 // updating map on delete of element
		void updateMap(string type){
			
			for (int i = 0;  i < str.size(); i++) {
				
				if (type == "str")	{	
					mp[str[i]] = make_pair(i, type);
				}
				else if (type == "int"){		
					mp[number[i]] = make_pair(i, type);	
				}
				else if (type == "float"){
					mp[decimal[i]] = make_pair(i, type);	
				}
				
			}	
		}
		 
};

// class for creating instance for the DataBase.
class createInstance {
		 	
	public:
		
		// creating a vector objects for storing the data related to string, integer and float
	 	vector<string> stringData;
	 	vector<int> integerData;
		vector<float> floatData;
		
		// constructor
		createInstance(){ };
		
		// constructor
		createInstance(createObject &p){
			// getting the string inputs.
			stringInput(&p);
			
			// getting the integer inputs
			integerInput(&p);
			
			// getting the flaot inputs.
			floatInput(&p);			
		}
		 	
		 	
		 	
		// getting the string inputs	
 		void stringInput(createObject *p){
 			
		 	string s;
			
			// used for avoiding getline input problem
			cin.ignore(100, '\n');
			
			// run it for all the string variables defined in vector str of createObject
		 	for(int i = 0; i < p->str.size(); i++){ 
			 	
				cout<<" Enter "<<p->str[i]<<" (string) : "; 
				getline(cin, s);
				
				stringData.push_back(s); // push the new data inside stringData vector.	 		
				 		
			}cout<<endl;
		}
		 		
		// getting the integer inputs
		void integerInput(createObject *p){
		 			
 			int in;
		 		
			// run it for all the integers variables defined in vector number of createObject
		 	for(int i = 0; i < p->number.size(); i++){
		 							
				cout<<" Enter "<<p->number[i]<<" (int) : "; cin >> in;
				 		
				integerData.push_back(in); // push the new data inside integerData vector.
				 		
			}cout<<endl;
		}
		 	
		//getting the float inputs	
		void floatInput(createObject *p){
		 			
 			float deci;
		 	
		 	// run it for all the flaat variables defined in vector decimal of createObject
		 	for(int i = 0; i < p->decimal.size(); i++){
		 							
				cout<<" Enter "<<p->decimal[i]<<" (float) : "; cin >> deci;
				 		
				floatData.push_back(deci); // push the new data inside flaotData vector.
				 		
			}cout<<endl;
		}
		 	
};


// global variable storing object and its instances
// where object is the data base name and instance will hold data related to the database
vector< pair < createObject , vector<createInstance> > > databaseManager;


//print the instance of the DataBase (Data Base - Details)
void printInstance(vector< createInstance > &obj_instance, createObject *p){
	
	cout<<"\n------------------------------------------------------------------------------------------"<<endl;
	cout << "                                   "<< p->name <<" Details                              "<<endl;
	cout<<"------------------------------------------------------------------------------------------"<<endl;
	cout<<endl;
	
	for (int i = 0; i < obj_instance.size(); i++){
		
		cout<<"   Serial No. -> "<<i+1<<endl<<endl;
		
		//printing string;
		for (int j = 0; j < obj_instance[i].stringData.size(); j++){
			
			cout<<"\t"<<p->str[j]<<" : "<<obj_instance[i].stringData[j]<<endl; 
			
		}
		
		//printing number;
		for (int j = 0; j < obj_instance[i].integerData.size(); j++){
			
			cout<<"\t"<<p->number[j]<<" : "<<obj_instance[i].integerData[j]<<endl; 
			
		}
	
		//printing  float
		for (int j = 0; j < obj_instance[i].floatData.size(); j++){
			
			cout<<"\t"<<p->decimal[j]<<" : "<<obj_instance[i].floatData[j]<<endl; 
			
		}
		cout<<endl;
	}
	
}


//printing the column
void printColumn(createObject *obj){
	
	//printing string type column;
	for (int j = 0; j < obj->str.size(); j++){
			
		cout<<"\t"<<obj->str[j]; 
			
	}
		
	//printing numberic column;
	for (int j = 0; j < obj->number.size(); j++){
			
		cout<<"\t"<<obj->number[j]; 
			
	}
	
	//printing  float type column
	for (int j = 0; j < obj->decimal.size(); j++){
			
		cout<<"\t"<<obj->decimal[j];
			
	}
	cout<<endl<<endl;
	
}


// printing the instance row - wise
void printInstanceRow(vector< createInstance > &obj_instance, createObject *p){
	
	cout<<"\n------------------------------------------------------------------------------------------"<<endl;
	cout << "                                   "<< p->name <<" Details                              "<<endl;
	cout<<"------------------------------------------------------------------------------------------"<<endl<<endl;
	cout<<endl;
	
	// printing the column
	printColumn(p);
	
	for (int i = 0; i < obj_instance.size(); i++){
		
		//printing string;
		for (int j = 0; j < obj_instance[i].stringData.size(); j++){
			
			cout<<"\t"<<obj_instance[i].stringData[j]; 
			
		}
		
		//printing number;
		for (int j = 0; j < obj_instance[i].integerData.size(); j++){
			
			cout<<"\t"<<obj_instance[i].integerData[j]; 
			
		}
	
		//printing  float
		for (int j = 0; j < obj_instance[i].floatData.size(); j++){
			
			cout<<"\t"<<obj_instance[i].floatData[j]; 
			
		}
		cout<<endl;
	}
	
}


// print database name with  its contents
void printDataBase(vector< pair < createObject , vector<createInstance> > > &db){
	
	// run the loop for all the contents of DataBaseManager vector
	for(int i = 0; i < db.size(); i++){
		
		cout<<"\t"<<i+1<<". "<<db[i].first.name<<endl<<endl; // printing the database name;
		printInstance(db[i].second, &db[i].first);			// printing the contents of database	
	}
	
}

// print database only
void printDataBaseOnly(vector< pair < createObject , vector<createInstance> > > &db){
	
	// run the loop as much time as the size of the vector databaseManager is.
	for(int i = 0; i < db.size(); i++){
		
		cout<<"\t"<<i+1<<". "<<db[i].first.name<<endl; // printing the database name.
		
	}
	cout<<endl;
	
}


// printing data based on the user enter the column name
void printData(vector< pair <int, string> > &data, vector< createInstance > &obj_instance, createObject *p){
	
	cout<<"\n\n------------------------------- DataBase Details ------------------------------------\n\n";
	
	// this represent the name of the column

	for(int i = 0; i < data.size(); i++){
		
		
		if(data[i].second == "str"){
			cout<<"\t"<< p->str[data[i].first];
		}
			
		else if(data[i].second == "int"){
			cout<<"\t"<< p->number[data[i].first];
		}
		
		else if(data[i].second == "float"){
			cout<<"\t"<< p->decimal[data[i].first];
		}
	}cout<<endl<<endl;
	cout<<endl;
	
	// this is for printing the data present inside the obj_instance;
	for(int j = 0;  j < obj_instance.size(); j++) {
	
		for( int i = 0; i < data.size(); i++){
			
			if(data[i].second == "str"){
				cout<<"\t"<<obj_instance[j].stringData[data[i].first];
			}
			
			else if(data[i].second == "int"){
				cout<<"\t"<< obj_instance[j].integerData[data[i].first];
			}
			
			else if(data[i].second == "float"){
				cout<<"\t"<< obj_instance[j].floatData[data[i].first];
				
			}	
			
		}cout<<endl;
	
	}
	
}

// update Field of string type
void updateFieldString( pair<int, string> &p, string rep, string dat, vector< createInstance > &obj){
	
	for (int i = 0; i < obj.size(); i++){
		
		if (obj[i].stringData[p.first] == rep) obj[i].stringData[p.first] = dat;
	
	}
	
}

// update Field of int type
void updateFieldInteger( pair<int, string> &p, int rep, int dat, vector< createInstance > &obj){
	
	for (int i = 0; i < obj.size(); i++){
		
		if (obj[i].integerData[p.first] == rep) obj[i].integerData[p.first] = dat;		
		
	}
		
}

// update field of float type
void updateFieldFloat( pair<int, string> &p, float rep, float dat, vector< createInstance > &obj){
	
	for (int i = 0; i < obj.size(); i++){
		
		if (obj[i].floatData[p.first] == rep) obj[i].floatData[p.first] = dat;		
		
	}
		
}


// deleting the column name as well as deleting the whole object of that column as well.
void deleteColumn(pair<int , string > &p, vector < createInstance > &obj_i, createObject * obj){
	
	// if column is of type string
	if (p.second == "str"){
			

		int lstColumn = obj->str.size() - 1; // last column index
		
		// swap the  given field of obj to the last field in obj 
		// so to delete it fast.
		// and there is no need of swapping if we want to delete the last field.
		
		if (p.first != lstColumn){
			
			// swapp now
			
			string temp = obj->str[p.first];
		
			obj->str[p.first] = obj->str[lstColumn];
			
			obj->str[lstColumn] = temp;
		}
		
		// popping the elemnt
		obj->str.pop_back();
		
		// last index for items in string Data in object instance.
		int lastIndex = obj_i[0].stringData.size() - 1;
		
		for (int i = 0; i < obj_i.size(); i++){
			
			// swap the item with last and then pop left to delete data from the instance
			
			if (p.first != lastIndex) {
				
				string dat = obj_i[i].stringData[p.first];
				obj_i[i].stringData[p.first] = obj_i[i].stringData[lastIndex];
				obj_i[i].stringData[lastIndex] = dat;
				
			}
			
			//popping the last element.
			obj_i[i].stringData.pop_back();
			
		}
	}
	
	// if column is of type integer.
	else if (p.second == "int"){
		
		int lstColumn = obj->number.size() - 1;
		
		// swapping if p.first not equals to lstColumn
		
		if (p.first != lstColumn) {
			
			string temp = obj->number[p.first];
			obj->number[p.first] = obj->number[lstColumn];
			obj->number[lstColumn] = temp;
			
		}
	
		// popping the item
		obj->number.pop_back();
		
		
		int lastIndex = obj_i[0].integerData.size() - 1;
		
		for (int i = 0; i < obj_i.size(); i++){
			
			// swap the item with last and then pop left to delete data from the instance
			
			if (p.first != lastIndex) {
				int dat = obj_i[i].integerData[p.first];
				obj_i[i].integerData[p.first] = obj_i[i].integerData[lastIndex];
				obj_i[i].integerData[lastIndex] = dat;
			}
		
			obj_i[i].integerData.pop_back();
			
		}
	}
	// if column is of type float
	else if (p.second == "float"){
		
		
		int lstColumn = obj->decimal.size() - 1;
	
		if (p.first != lstColumn){
			string temp = obj->decimal[p.first];
			obj->decimal[p.first] = obj->decimal[lstColumn];
			obj->decimal[lstColumn] = temp;
		}	
		
		obj->decimal.pop_back();
		
		int lastIndex = obj_i[0].floatData.size() - 1;
		
		for (int i = 0; i < obj_i.size(); i++){
			
			// swap the item with last and then pop left to delete data from the instance
			if (p.first == lstColumn){
				
				float dat = obj_i[i].floatData[p.first];
				obj_i[i].floatData[p.first] = obj_i[i].floatData[lastIndex];
				obj_i[i].floatData[lastIndex] = dat;
			
			}
			
			obj_i[i].floatData.pop_back();
			
		}		
	}
	
}


// delte the whole data's of an object in a database whose data match with deleted data
void deleteFieldString(pair<int , string > &p, string dat, vector < createInstance > &obj ){
	
	for (int i = 0; i < obj.size(); i++){
			
		if (obj[i].stringData[p.first] == dat){
				
			obj.erase(obj.begin() + i); // erasing the whole row as data matches here
				
		}
			
	}
		
}

// delte the whole data's of an object in a database whose data match with deleted data
void deleteFieldInteger(pair<int , string > &p, int dat, vector < createInstance > &obj ){
		
	for (int i = 0; i < obj.size(); i++){
			
		if (obj[i].integerData[p.first] == dat){
				
			obj.erase(obj.begin() + i); // erasing the whole row as data matches here
				
		}
	}

}

// delte the whole data's of an object in a database whose data match with deleted data
void deleteFieldFloat(pair<int , string > &p, float dat, vector < createInstance > &obj ){

	for (int i = 0; i < obj.size(); i++){
			
		if (obj[i].floatData[p.first] == dat){
				
			obj.erase(obj.begin() + i); // erasing the whole row as data matches here
				
		}
	}

}

// function for storing data permanently in csv file format.
void saveDataBase(vector< pair < createObject , vector<createInstance> > > &db ){
	
	// output stream
	ofstream of;
	
	// go through all the Data bases and their contents
	for (int i = 0;  i < db.size(); i++){
	
		// creating a file name based on the database name
		string temp = db[i].first.name + ".csv";
		
		of.open(temp.c_str()); // opening of a file for storage.
		
		of << db[i].first.name <<endl<<endl; // printing the database name 
		
		
		// printing a row with column name
		
		// string type column
		for (int j = 0; j < db[i].first.str.size(); j++){
			
			of << db[i].first.str[j] << ",";
			
		}
		
		// integer type column
		for (int j = 0; j < db[i].first.number.size(); j++){
			
			of << db[i].first.number[j] << ",";
			
		}
		
		// float type column
		for (int j = 0; j < db[i].first.decimal.size(); j++){
			
			of << db[i].first.decimal[j] << ",";
			
		}of << endl<<endl;
		
		
		
		// printing the contents of the database.
		for (int j = 0; j < db[i].second.size(); j++){
			
			// printing the contents of string typed.
			for (int k = 0; k < db[i].second[j].stringData.size(); k++){
				
				of << db[i].second[j].stringData[k] << "," ;
				
			}
			
			// printing the contents of integer typed.
			for (int k = 0; k < db[i].second[j].integerData.size(); k++){
				
				of << db[i].second[j].integerData[k] << "," ;
				
			}
			
			// printing the contents of float typed.
			for (int k = 0; k < db[i].second[j].floatData.size(); k++){
				
				of << db[i].second[j].floatData[k] << "," ;
				
			}of <<endl;
			
		}
		
		cout<<"\n\tFile Created for "<< db[i].first.name <<" Database and data Added."<<endl<<endl;
		
		of.close(); // closing a output stream in order to open a new database file.
	}
	
}


// main function.
int main(){
	
	int choice;
	
	bool outside;
	
	do{
		
		cout<<"\n\t----------------------------------------"<<endl;
		cout<<"\t| 1. Create a DataBase.                |"<<endl;
		cout<<"\t| 2. Visit Existing DataBase           |"<<endl;
		cout<<"\t| 3. See DataBase with their data      |"<<endl;
		cout<<"\t| 4. Exit from the Program             |"<<endl;
		cout<<"\t| 5. Delete DataBase                   |"<<endl;
		cout<<"\t| 6. Save DataBase                     |"<<endl;
		cout<<"\t----------------------------------------"<<endl;
		
		cout<<"\n\tEnter Your Choice : "; cin >> choice;
		cout<<endl;
		
		createObject Person;
		vector< createInstance > obj_instance;
		
		switch(choice){
			
			case 1:{
				
				Person.createObjects();
				
				int db_choice;
				
				outside = true; 
				
				goto DataBase;
				
				DataBase : 

				
					do{
						
						cout<<"\n**********************************************************************************"<<endl;
									
						cout<<endl<<endl<<"\n\t1. Add Data in "<<Person.name<<" Database."<<endl;
						cout<<"\n\t2. Print the Records of "<<Person.name<<" DataBase."<<endl;
						cout<<"\n\t3. Print the Records Row wise."<<endl;
						cout<<"\n\t4. Enter name of columns which you want to visit in DataBase."<<endl;
						cout<<"\n\t5. Exit from "<<Person.name<<" DataBase."<<endl<<endl;
						cout<<"\n\t6. Update"<<endl;
						cout<<"\n\t7. Delete"<<endl;
						cout<<"\n\t8. Save Current DataBase."<<endl<<endl;
						
						
						cout<<"\n\t\tEnter your choice : "; cin >> db_choice;
						cout<<endl;
						
						switch(db_choice){
							
							case 1 :
								{
									cout<<"\n-------------------- Input for the DataBase ---------------------"<<endl;
									createInstance X(Person);
									obj_instance.push_back(X);
									cout<<"\n\tData is added into the "<<Person.name<<" DataBase.\n\n";
									break;
								}
							case 2 :
								printInstance(obj_instance,&Person);
								break;
								
							case 3 : {
								
								printInstanceRow(obj_instance,&Person);
								
								break;
							}
							
							case 4 : {
								
								vector< pair <int, string> > search;
								
								string field;
								
								do{
									cout<<"\n\tEnter \"done\" without quotes if you don\'t want to enter any more column."<<endl;
									
									cout<<"\n\tEnter the name of column : "; cin >> field;
									
									search.push_back(Person.mp[field]);
									
									
								}while(field != "done");
								
								printData(search, obj_instance, &Person);
								
								break;
							}
							
							case 5:{
								cout<<"\n**********************************************************************************"<<endl;
								
								if (outside)
									databaseManager.push_back(make_pair(Person, obj_instance));
								
								break;
							}
							
							case 6:{
								
								int update_choice;
								
								do{
									cout<<"\n\n\t1. Update Column"<<endl;
									cout<<"\t2. Update field"<<endl;
									cout<<"\t3. Exit from Update"<<endl;
									
									cout<<"\n\t Enter your choice : "; cin >> update_choice;
									
									switch(update_choice){
										
										case 1: {										// getting the new string
												
												string s;
												cout<<"Name of column you want to update : "; cin >> s;
												
									
												// checking if column is in dataBase.
												if (Person.mp.find(s) != Person.mp.end()){
													
													// getting a new column
													string newCol;
													cout<<"Enter a new Column name : "; cin >> newCol;
													
													pair <int, string> x = Person.mp[s];
													
													// updating the column name inside the DataBase
													if (x.second == "str"){
														Person.str[x.first] = newCol;
													}
													else if (x.second == "int"){
														Person.number[x.first] = newCol;
													}
													else if (x.second == "float"){
														Person.decimal[x.first] = newCol;
													}
													
													// make a new Key newCol with same value as s has.
													Person.mp[newCol] = Person.mp[s];
													
													// clear the key s
													Person.mp.erase(s);
												}
												else{
													cout<<"\tColumn is not in DataBase"<<endl; 
													cout<<"\tEnter  a valid column name."<<endl<<endl;
												}
												
												break;
											}
										
										case 2:{
											
											string col;
											cout<<"Enter the column name : "; cin >> col;
											
											if(Person.mp.find(col) != Person.mp.end()){
												
												pair <int, string> x = Person.mp[col];
												
												// this can be refactor as we have same logic and data type is of different kind
												if (x.second == "str"){
													string rep, dat;
													
													cout<<"Enter the string data you want to replace : "; cin >> rep;
													cout<<"Enter new string data you want to put : "; cin >> dat;
													
													updateFieldString( x,rep,dat,obj_instance);
												}
												
												else if (x.second == "int"){
													int rep, dat;
													
													cout<<"Enter integer value you want to replace : "; cin >> rep;
													cout<<"Enter new integer value you want to put : "; cin >> dat;
													
													updateFieldInteger( x,rep,dat,obj_instance);																	
												}
	//											
												else if (x.second == "float"){
													float rep, dat;
													
													cout<<"Enter the float value you want to replace : "; cin >> rep;
													cout<<"Enter new float value you want to put : "; cin >> dat;
													
													updateFieldFloat( x,rep,dat,obj_instance);													
												}
												
											}
											break;
										}
											
										case 3: 
											break;
											
										default: 
											cout<<"Enter a valid Choice."<<endl;
									}
								}while(update_choice != 3);
								break;
							}
							
							case 7:{
								
								int del_choice;
								
								do{
									
									cout<<"\n\t1. Delete Column : "<<endl;
									cout<<"\t2. Delete Field : "<<endl;
									cout<<"\t3. Exit From Program : "<<endl<<endl;
									
									cout<<"\n\tEnter Your Choice : "; cin >> del_choice;
									
									switch (del_choice){
										
										case 1 :{
											
											string col;
											cout<<"Enter the Column : "; cin >> col;
										
											if (Person.mp.find(col) != Person.mp.end() ){
												deleteColumn(Person.mp[col], obj_instance, &Person);
										
												// erasing the key as it is removed and also update the Map
												string type = Person.mp[col].second;
												Person.mp.erase(col);
												Person.updateMap(type);	
											}
											else{
												cout<<"\n\tThis field is not in the DataBase.\n\n";
											}
											break;
											
										}
										
										case 2 : {
											
											string col;
											cout<<"Enter the column name : "; cin >> col;
											
											if(Person.mp.find(col) != Person.mp.end()){
												
												pair <int, string> x = Person.mp[col];
												
												// this can be refactor as we have same logic and data type is of different kind
												if (x.second == "str"){
													
													string rep;
													
													cin.ignore(1000, '\n');
													cout<<"Enter the string data you want to delete : "; getline(cin, rep);
													
													deleteFieldString(x, rep, obj_instance);
													
												}
												
												else if (x.second == "int"){
													int rep;
													
													cout<<"Enter integer value you want to delete : "; cin >> rep;
													
													
													deleteFieldInteger(x, rep, obj_instance);																	
												}
	//											
												else if (x.second == "float"){
													float rep;
													
													cout<<"Enter the float value you want to delete : "; cin >> rep;
												
													deleteFieldFloat( x, rep, obj_instance);													
												}
											
											}
											else{
												cout<<"\n\t This field is not in the DataBase.\n\n";
											}
											
											break;
										}							
																												
										case 3 : 
											 break;
									}
									
								} while(del_choice != 3);
								
								
								
								break;
							}
							
							case 8:{
								
								// saving current database.
								
								//creating a vector that will contains the database and its contents.
								vector < pair <createObject, vector < createInstance >  > > forFile;
								forFile.push_back(make_pair(Person, obj_instance));
								
								// saving the database.
								saveDataBase(forFile);
								break;
							}
							
							default:
								cout<<"Enter a Valid choice."<<endl;
						}
						
					} while(db_choice != 5);
				
				break;
			}
							
			case 2:{
				printDataBaseOnly(databaseManager);
				
				int move;
				cout<<"\tEnter database number where you want to visit (type -1 to exit) : "; cin >> move;
				
				if ((move > 0) && (move <= databaseManager.size())) {
					
					Person = databaseManager[move-1].first;
					obj_instance = databaseManager[move - 1].second;
					
					outside = false; // make outside to false so, same item don't copy itself again in the databaseManager.
					
					goto DataBase;
					
				}
				else{
					cout<<"\n\t No such DataBase Number exist\n\n";
				}
				
				break;
			}
				
				
			case 3:{
				printDataBase(databaseManager);
				break;
			}
				
			case 4:{
				cout<<"\n\n\t --- Exit from the Program --- "<<endl;
				break;
			}
			case 5:{
				
				printDataBaseOnly(databaseManager);
				
				int del;
				cout<<"\tEnter database number which you want to delete (type -1 to exit) : "; cin >> del;
				
				if ((del > 0) && (del <= databaseManager.size())) {
					
					del--;
					
					// iterator pointing to the first element of the databaseManager.
					vector< pair < createObject , vector<createInstance> > >::iterator i = databaseManager.begin();
					
					// erasing the items from the databaseManager.
					databaseManager.erase(i + del );
					
				}
				else{
					cout<<"\n\t No such DataBase Number exist\n\n";
				}
				
				break;
			}
			
			case 6:{
				
				saveDataBase(databaseManager);
				
				break;
			}
			
			default:
				cout<<"\n\tEnter a Valid Choice.\n"<<endl;
				break;
				
		}
	}while(choice != 4);
	
	return 0;
}

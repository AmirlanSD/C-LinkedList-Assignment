#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct Date {
	int day;
	int month;
	int year;
}; // (Codescracker, 2020)

struct Tutor {
	int tutorID;
	string tutorName;
    struct Date tutorDateJoined;
    struct Date tutorDateTerminated;
	int tutorHourlyRate;
	string tutorPhone;
	string tutorAddress;
    int tutorCentreCode;
    string tutorCentreName;
    int tutorSubjectCode;
    string tutorSubjectName;
    int tutorRating;

	Tutor * next;
    Tutor * back;
} *head, *temp, *newnode, *tail, *previous, *newhead, *newtail;


Tutor * createNewNode(int id, string name, int dateJoinedDay, int dateJoinedMonth, int dateJoinedYear, int terminatedDay, 
int terminatedMonth, int terminatedYear, int hourlyRate, 
string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating); // (Weaknessforcats, 2013)

void AddTutor(int id, string name, int dateJoinedDay, int dateJoinedMonth, int dateJoinedYear, int terminatedDay, 
int terminatedMonth, int terminatedYear, int hourlyRate, 
string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating);

void DisplayAll();
void DisplaySortedAll();
void SearchTutorID();
void SearchTutorRating();

void SortTutorID(int id, string name, int dateJoinedDay, int dateJoinedMonth, int dateJoinedYear, int terminatedDay, 
int terminatedMonth, int terminatedYear, int hourlyRate, 
string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating);

void SortTutorHourlyRate(int id, string name, int dateJoinedDay, int dateJoinedMonth, int dateJoinedYear, int terminatedDay, 
int terminatedMonth, int terminatedYear, int hourlyRate, 
string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating);

void SortTutorRating(int id, string name, int dateJoinedDay, int dateJoinedMonth, int dateJoinedYear, int terminatedDay, 
int terminatedMonth, int terminatedYear, int hourlyRate, 
string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating);

void ModifyTutor();
void DeleteTutor();



int main() {
	Tutor Tutor;
    int tutorID;
	string tutorName;
    int tutorDateJoinedDay;
	int tutorDateJoinedMonth; 
	int tutorDateJoinedYear; 
	int tutorDateTerminatedDay; 
	int tutorDateTerminatedMonth; 
	int tutorDateTerminatedYear;
	int tutorHourlyRate;
	string tutorPhone;
	string tutorAddress;
    int tutorCentreCode;
    string tutorCentreName;
    int tutorSubjectCode;
    string tutorSubjectName;
    int tutorRating;

    int choice;
	int flag = 0;
	bool havedata = false;

    head = NULL;
	tail = NULL;
	

	AddTutor(1, "Amirlan", 22, 12, 2010, 22, 12, 2020, 70, "+601128540706", "Endah", 457, "Bukit Jalil", 111, "Biology", 5);
	AddTutor(2, "Shan", 1, 5, 2018, 23, 8, 2021, 80, "+60232312121", "Parkhill", 321, "Cheras", 222, "Math", 3);
	AddTutor(3, "Isa", 2, 1, 2008, 14, 11, 2015, 50, "+60353535353", "One South", 457, "Bukit Jalil", 333, "History", 2);
	AddTutor(4, "Adam", 15, 7, 2000, 31, 4, 2023, 65, "+604545454545", "KLCC", 457, "Bukit Jalil", 444, "C++", 4);
	AddTutor(5, "Hank", 11, 3, 2020, 3, 9, 2024, 40, "+605656565656", "Subang", 869, "Bukit Bintang", 555, "Poetry", 1);
	AddTutor(6, "Arthur", 4, 12, 2017, 24, 5, 2020, 80, "+607878787878", "Endah", 321, "Cheras", 666, "Physics", 5);
	AddTutor(7, "Ivy", 29, 6, 2013, 6, 10, 2015, 50, "+60898989898", "Publika", 869, "Bukit Bintang", 333, "History", 4);
	AddTutor(8, "Aisha", 12, 8, 2014, 5, 10, 2026, 80, "+60121212121", "KLCC", 321, "Cheras", 444, "C++", 5);
	AddTutor(9, "Jacob", 5, 7, 2019, 1, 12, 2025, 40, "+602424242422", "East Lake", 869, "Bukit Bintang", 222, "Math", 2);
	AddTutor(10, "Maggie", 30, 5, 2012, 17, 3, 2029, 75, "+609595955959", "One South", 457, "Bukit Jalil", 555, "Poetry", 3);

    cout << "---------------------------------------------------------" << endl;
	cout << "Menu" << endl;
	cout << "1) Add a New Tutor" << endl;
	cout << "2) Display All Tutor Records" << endl;
	cout << "3) Search Tutor by Tutor ID" << endl;
    cout << "4) Search Tutor by overall performance - Rating" << endl;
	cout << "5) Sort and display by Tutor ID" << endl;  //All sorting function should be in ascending order
	cout << "6) Sort and display by Hourly Pay Rate" << endl;
	cout << "7) Sort and display by Overall Performance" << endl;
	cout << "8) Modify a Tutor Record" << endl;
	cout << "9) Delete a tutor Record" << endl;
    cout << "0) Exit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	while (choice != 0) {
		switch (choice)	{
		case 1:
			temp = head;
            cout << endl;
			havedata = false;
			if (head == NULL) { //checking if there is nothing in loop
				tutorID = 1;
			} else {
				tutorID = tail->tutorID + 1; //enter id automated
			}
			cout << "Enter Name: ";
			getchar();
			getline(cin, tutorName);
			cout << "Enter Tutor Year of Joined: ";
			while(havedata != true) {
				cin.clear();
				cin >> tutorDateJoinedYear; // (Codescracker, 2020; Weaknessforcats, 2013)

				if(cin.fail()) { 
					cout << "Year of Joined is integer, please enter agian: "; //checking the year if it is not integer
					cin.clear();
					cin.ignore();
				} else {
					havedata = true;
				}	
			}
			havedata = false;
			cout << "Enter Tutor Month of Joined: ";
			while(havedata != true) {
				cin.clear();
				cin >> tutorDateJoinedMonth; 
				if(cin.fail()) { 
					cout << "Month  of Joined is integer, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (tutorDateJoinedMonth > 12 || tutorDateJoinedMonth < 1) {
					cout << "Month of Joined should be between 1 or 12, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else {
					havedata = true;
				}	
			}
			havedata = false;
			cout << "Enter Tutor Day of Joined: ";
			while(havedata != true) {
				cin.clear();
				cin >> tutorDateJoinedDay;
				if(cin.fail()) { 
					cout << "Day of Joined is integer, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (tutorDateJoinedMonth == 1 || tutorDateJoinedMonth == 3 || tutorDateJoinedMonth == 5 || tutorDateJoinedMonth == 7 || tutorDateJoinedMonth == 8 || tutorDateJoinedMonth == 10 || tutorDateJoinedMonth == 12) {
					if (tutorDateJoinedDay > 31 || tutorDateJoinedDay < 1) { // checking if the month is may or july than day should be between 1 and 31 
						cout << "Date of Joined should be between 1 and 31, please enter agian: ";
						cin.clear();
						cin.ignore();
					} else {
						havedata = true;
					}
				} else if (tutorDateJoinedMonth == 4 || tutorDateJoinedMonth == 6 || tutorDateJoinedMonth == 9 || tutorDateJoinedMonth == 11) {
					if (tutorDateJoinedDay > 30 || tutorDateJoinedDay < 1) {
						cout << "Date of Joined should be between 1 and 30, please enter agian: ";
						cin.clear();
						cin.ignore();
					} else {
						havedata = true;
					}
				} else if (tutorDateJoinedMonth == 2) {
					if ((tutorDateJoinedYear % 4 == 0) && (tutorDateJoinedYear % 100 != 0) || (tutorDateJoinedYear % 400 == 0)) { // checking for leap year
						if (tutorDateJoinedDay > 29 || tutorDateJoinedDay < 1) {
							cout << "Date of Joined should be between 1 and 29, please enter agian: ";
							cin.clear();
							cin.ignore();
						} else {
							havedata = true;
						}
					} else {
						if (tutorDateJoinedDay > 28 || tutorDateJoinedDay < 1) {
							cout << "Date of Joined should be between 1 and 28, please enter agian: ";
							cin.clear();
							cin.ignore();
						} else {
							havedata = true;
						}
					}
				} else {
					havedata = true;
				}	
			}
			havedata = false;
			cout << "Enter Tutor Year of Terminated: ";
			while(havedata != true) {
				cin.clear();
				cin >> tutorDateTerminatedYear;
				if(cin.fail()) { 
					cout << "Year of Terminated is integer, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (tutorDateTerminatedYear < tutorDateJoinedYear) {
					cout << "Year of Terminated should be high than Tutor Year of Joined, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else {
					havedata = true;
				}	
			}
			havedata = false;
			cout << "Enter Tutor Month of Terminated: ";
			while(havedata != true) {
				cin.clear();
				cin >> tutorDateTerminatedMonth;
				if(cin.fail()) { 
					cout << "Month of Terminated is integer, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (tutorDateTerminatedMonth > 12) {
					cout << "Month of Terminated should be between 1 and 12, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (tutorDateTerminatedMonth < 1) {
					cout << "Month of Terminated should be between 1 and 12, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else {
					havedata = true;
				}	
			}
			havedata = false;
			cout << "Enter Tutor Day of Terminated: ";
			while(havedata != true) {
				cin.clear();
				cin >> tutorDateTerminatedDay;
				if(cin.fail()) { 
					cout << "Date of Terminated is integer, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (tutorDateTerminatedMonth == 1 || tutorDateTerminatedMonth == 3 || tutorDateTerminatedMonth == 5 || tutorDateTerminatedMonth == 7 || tutorDateTerminatedMonth == 8 || tutorDateTerminatedMonth== 10 || tutorDateTerminatedMonth == 12) {
					if (tutorDateTerminatedDay > 31 || tutorDateTerminatedDay < 1) {
						cout << "Date of Terminated should be between 1 and 31, please enter agian: ";
						cin.clear();
						cin.ignore();
					} else {
						havedata = true;
					}
				} else if (tutorDateJoinedMonth == 4 || tutorDateJoinedMonth == 6 || tutorDateJoinedMonth == 9 || tutorDateJoinedMonth == 11) {
					if (tutorDateTerminatedDay > 30 || tutorDateTerminatedDay < 1) {
						cout << "Date of Terminated should be between 1 and 30, please enter agian: ";
						cin.clear();
						cin.ignore();
					} else {
						havedata = true;
					}
				} else if (tutorDateJoinedMonth == 2) {
					if ((tutorDateTerminatedYear % 4 == 0) && (tutorDateTerminatedYear % 100 != 0) || (tutorDateTerminatedYear % 400 == 0)) {
						if (tutorDateTerminatedDay > 29 || tutorDateTerminatedDay < 1) {
							cout << "Date of Terminated should be between 1 and 29, please enter agian: ";
							cin.clear();
							cin.ignore();
						} else {
							havedata = true;
						}
					} else {
						if (tutorDateTerminatedDay > 28 || tutorDateTerminatedDay < 1) {
							cout << "Date of Terminated should be between 1 and 28, please enter agian: ";
							cin.clear();
							cin.ignore();
						} else {
							havedata = true;
						}
					}
				} else {
					havedata = true;
				}	
			}
			havedata = false;
			cout << "Enter Tutor Hourly Rate: ";
			while(havedata != true) {
				cin.clear();
				cin >> tutorHourlyRate;
				if(cin.fail()) { 
					cout << "Tutor Hourly Rate is integer, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (tutorHourlyRate < 40 || tutorHourlyRate > 80) {
					cout << "Tutor Hourly Rate should be between 40 and 80, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else {
					havedata = true;
				}	
			}
			havedata = false;
			cout << "Enter Tutor Phone Number: ";
			cin >> tutorPhone;
 		    cout << "Enter Tutor Address: ";
			getchar();
			getline(cin, tutorAddress);
			
    		cout << "Enter Tutor Centre Code: ";
			cin >> tutorCentreCode;
			temp = head;
			while(temp != NULL) {
				if(cin.fail()) { 
					cout << "Centre Code is integer, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (to_string(temp->tutorCentreCode).find(to_string(tutorCentreCode)) != string::npos) {
					tutorCentreName = temp->tutorCentreName; //checking if centre arleady exist, so code automated fill the name 
					flag = 1;
				} else {
					cout << "";
				}
				temp = temp->next;
			}
			if (flag == 0) {
					cout << "Enter Tutor Centre Name: ";
					getchar();
					getline(cin, tutorCentreName);
			}
			flag = 0;
		    cout << "Enter Tutor Subject Code: ";
			temp = head;
			cin >> tutorSubjectCode;
			while(temp != NULL) {
				if(cin.fail()) { 
					cout << "Subject Code is integer, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (to_string(temp->tutorCentreCode).find(to_string(tutorCentreCode)) != string::npos) {
					if (to_string(temp->tutorSubjectCode).find(to_string(tutorSubjectCode)) != string::npos) { //checking if centre arleady exist and subject code too, so it fill the name 
						tutorSubjectName = temp->tutorSubjectName;
						flag = 1;
						break;
					}
				} else {
					cout << "";
				}

				temp = temp->next;
			}
			if (flag == 0) {
					cout << "Enter Tutor Subject Name: ";
					getchar();
					getline(cin, tutorSubjectName);
			}
			havedata = false;		
		    cout << "Enter Tutor Rating: ";
			while(havedata != true) {
				cin.clear();
				cin >> tutorRating;
				if(cin.fail()) { 
					cout << "Tutor rating is integer, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else if (tutorRating < 1 || tutorRating > 5) {
					cout << "Tutor rating should be between 1 and 5, please enter agian: ";
					cin.clear();
					cin.ignore();
				} else {
					havedata = true;
				}	
			}
            AddTutor(tutorID, tutorName, tutorDateJoinedDay, tutorDateJoinedMonth, tutorDateJoinedYear, tutorDateTerminatedDay, tutorDateTerminatedMonth, tutorDateTerminatedYear, 
			tutorHourlyRate, tutorPhone, tutorAddress, tutorCentreCode, tutorCentreName, tutorSubjectCode, tutorSubjectName, tutorRating); // (Codescracker, 2020; Weaknessforcats, 2013)
			break;
        case 2:
            cout << endl;
			DisplayAll();
			break;
        case 3:
            cout << endl;
			SearchTutorID();
			break;
        case 4:
            cout << endl;
			SearchTutorRating();
			break;
        case 5:
            cout << endl;
			newhead = newtail = NULL;
    		temp = head;
    		while (temp != NULL) {
        		SortTutorID(temp->tutorID, temp->tutorName, temp->tutorDateJoined.day, 
				temp->tutorDateJoined.month, temp->tutorDateJoined.year, temp->tutorDateTerminated.day, 
				temp->tutorDateTerminated.month, temp->tutorDateTerminated.year, temp->tutorHourlyRate, 
				temp->tutorPhone, temp->tutorAddress, temp->tutorCentreCode, temp->tutorCentreName, 
				temp->tutorSubjectCode, temp->tutorSubjectName, temp->tutorRating);
    		    
				temp = temp->next;
            }
            DisplaySortedAll();
			break;
        case 6:
            cout << endl;
			newhead = newtail = NULL;
    		temp = head;
    		while (temp != NULL) {
        		SortTutorHourlyRate(temp->tutorID, temp->tutorName, temp->tutorDateJoined.day, temp->tutorDateJoined.month, temp->tutorDateJoined.year, temp->tutorDateTerminated.day, 
				temp->tutorDateTerminated.month, temp->tutorDateTerminated.year, temp->tutorHourlyRate, temp->tutorPhone, temp->tutorAddress, temp->tutorCentreCode, temp->tutorCentreName, 
				temp->tutorSubjectCode, temp->tutorSubjectName, temp->tutorRating);
    		    temp = temp->next;
            }
			DisplaySortedAll();
			break;
        case 7:
            cout << endl;
			newhead = newtail = NULL;
    		temp = head;
    		while (temp != NULL) {
        		SortTutorRating(temp->tutorID, temp->tutorName, temp->tutorDateJoined.day, temp->tutorDateJoined.month, temp->tutorDateJoined.year, temp->tutorDateTerminated.day, 
				temp->tutorDateTerminated.month, temp->tutorDateTerminated.year, temp->tutorHourlyRate, temp->tutorPhone, temp->tutorAddress, temp->tutorCentreCode, temp->tutorCentreName, 
				temp->tutorSubjectCode, temp->tutorSubjectName, temp->tutorRating);
    		    temp = temp->next;
            }
			DisplaySortedAll();
			break;
        case 8:
			cout << endl;
			ModifyTutor();
			break;
        case 9:
            cout << endl;
            DeleteTutor();
			break;

		default:
			cout << "Invalid selection." << endl;
		}
		cout << endl;
        cout << endl;
        cout << endl;
		cout << "---------------------------------------------------------" << endl;
	    cout << "Menu" << endl;
	    cout << "1) Add a New Tutor" << endl;
	    cout << "2) Display All Tutor Records" << endl;
	    cout << "3) Search Tutor by Tutor ID" << endl;
        cout << "4) Search Tutor by overall performance - Rating" << endl;
	    cout << "5) Sort and display by Tutor ID" << endl;
	    cout << "6) Sort and display by Hourly Pay Rate" << endl;
	    cout << "7) Sort and display by Overall Performance" << endl;
	    cout << "8) Modify a Tutor Record" << endl;
	    cout << "9) Delete a tutor Record" << endl;
        cout << "0) Exit" << endl;
	    cout << "Enter your choice: ";
	    cin >> choice;
	}
	return 0;
}


Tutor * createNewNode (int id, string name, int dateJoinedDay, int dateJoinedMonth, int dateJoinedYear, 
int terminatedDay, int terminatedMonth, int terminatedYear, int hourlyRate, 
string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating) {
	Tutor * createnewnode = new Tutor;
	createnewnode->tutorID = id;
	createnewnode->tutorName = name;
    createnewnode->tutorDateJoined.day = dateJoinedDay;
	createnewnode->tutorDateJoined.month = dateJoinedMonth;
	createnewnode->tutorDateJoined.year = dateJoinedYear;
	createnewnode->tutorDateTerminated.day = terminatedDay;
	createnewnode->tutorDateTerminated.month = terminatedMonth;
	createnewnode->tutorDateTerminated.year = terminatedYear;
	createnewnode->tutorHourlyRate = hourlyRate;
	createnewnode->tutorPhone = phone;
	createnewnode->tutorAddress = address;
    createnewnode->tutorCentreCode = centerCode;
    createnewnode->tutorCentreName = centreName;
    createnewnode->tutorSubjectCode = subjectCode;
    createnewnode->tutorSubjectName = subjectName;
    createnewnode->tutorRating = rating;
	createnewnode->next = NULL;
    createnewnode->back = NULL;
	return createnewnode;
}

void AddTutor(int id, string name, int dateJoinedDay, int dateJoinedMonth, 
int dateJoinedYear, int terminatedDay, int terminatedMonth, int terminatedYear, 
int hourlyRate, string phone, string address, int centerCode, 
string centreName, int subjectCode, string subjectName, int rating) {

	Tutor * newnode = createNewNode(id, name, dateJoinedDay, 
	dateJoinedMonth, dateJoinedYear, terminatedDay, 
	terminatedMonth, terminatedYear, hourlyRate, 
	phone, address, centerCode, centreName, subjectCode, 
	subjectName, rating);

	newnode->tutorID = id;
	newnode->next = NULL;
    newnode->back = NULL;
    if (head == NULL) {
        head = tail = newnode;
    } else {
        newnode->back = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void DisplayAll() {
	temp = head;
	while (temp != NULL) {
		cout << temp->tutorID << ", ";
		cout << temp->tutorName << ", ";
		cout << temp->tutorDateJoined.day << "/";
		cout << temp->tutorDateJoined.month << "/";
		cout << temp->tutorDateJoined.year << ", ";
		cout << temp->tutorDateTerminated.day << "/";
		cout << temp->tutorDateTerminated.month << "/";
		cout << temp->tutorDateTerminated.year << ", ";
		cout << temp->tutorHourlyRate << ", ";
		cout << temp->tutorPhone << ", ";
        cout << temp->tutorAddress << ", ";
        cout << temp->tutorCentreCode << ", ";
        cout << temp->tutorCentreName << ", ";
        cout << temp->tutorSubjectCode << ", ";
        cout << temp->tutorSubjectName << ", ";
        cout << temp->tutorRating << endl;
		temp = temp->next;
	}
	cout << endl;
}

//Search function which is used liner search (jit_t et al., 2020)
void SearchTutorID() {
	int id;
	temp = head; bool havedata = false;
	cout << "Enter ID: ";
	cin >> id;
    while (temp != NULL) {
        if (to_string(temp->tutorID).find(to_string(id)) != string::npos) {
			cout << temp->tutorID << ", ";
			cout << temp->tutorName << ", ";
			cout << temp->tutorDateJoined.day << "/";
			cout << temp->tutorDateJoined.month << "/";
			cout << temp->tutorDateJoined.year << ", ";
			cout << temp->tutorDateTerminated.day << "/";
			cout << temp->tutorDateTerminated.month << "/";
			cout << temp->tutorDateTerminated.year << ", ";
			cout << temp->tutorHourlyRate << ", ";
			cout << temp->tutorPhone << ", ";
        	cout << temp->tutorAddress << ", ";
        	cout << temp->tutorCentreCode << ", ";
        	cout << temp->tutorCentreName << ", ";
        	cout << temp->tutorSubjectCode << ", ";
        	cout << temp->tutorSubjectName << ", ";
        	cout << temp->tutorRating << endl;
            havedata = true;
        }
        temp = temp->next;
    }
    if (havedata == false) {
        cout << "Record Not Found" << endl;
    }
    cout << endl;
}

//Search function which is used liner search (jit_t et al., 2020)
void SearchTutorRating() {
	int rating;
	temp = head; bool havedata = false;
	cout << "Enter Tutor Rating: ";
	cin >> rating;
    while (temp != NULL) {
        if (to_string(temp->tutorRating).find(to_string(rating)) != string::npos) {
            cout << temp->tutorID << ", ";
			cout << temp->tutorName << ", ";
			cout << temp->tutorDateJoined.day << "/";
			cout << temp->tutorDateJoined.month << "/";
			cout << temp->tutorDateJoined.year << ", ";
			cout << temp->tutorDateTerminated.day << "/";
			cout << temp->tutorDateTerminated.month << "/";
			cout << temp->tutorDateTerminated.year << ", ";
			cout << temp->tutorHourlyRate << ", ";
			cout << temp->tutorPhone << ", ";
        	cout << temp->tutorAddress << ", ";
       		cout << temp->tutorCentreCode << ", ";
        	cout << temp->tutorCentreName << ", ";
        	cout << temp->tutorSubjectCode << ", ";
        	cout << temp->tutorSubjectName << ", ";
        	cout << temp->tutorRating << endl;
            havedata = true;
        }
        temp = temp->next;
    }
    if (havedata == false) {
        cout << "Record Not Found" << endl;
    }
    cout << endl;
}

//Sort function which is used Insertion sort (chitranayal, PIYUSHKUMAR19, PuneetChaurasia and rathbhupendra, 2020)
void SortTutorID(int id, string name, int dateJoinedDay, int dateJoinedMonth,
int dateJoinedYear, int terminatedDay, int terminatedMonth, int terminatedYear, 
int hourlyRate, string phone, string address, int centerCode, string centreName, 
int subjectCode, string subjectName, int rating) {

	Tutor * newnode = createNewNode(id, name, dateJoinedDay, dateJoinedMonth, 
	dateJoinedYear, terminatedDay, terminatedMonth, terminatedYear, hourlyRate, 
	phone, address, centerCode, centreName, subjectCode, subjectName, rating);
	newnode->tutorID = id;
	newnode->next = NULL;
    newnode->back = NULL;
    if (newhead ==  NULL) {
        newhead = newtail = newnode;
    } else if (id <= newhead->tutorID) {
        newnode->next = newhead;
        newhead->back = newnode;
        newhead = newnode;
    } else {
        Tutor * newtemp = newhead;
        while (newtemp->next != NULL) {
            if (id <= newtemp->next->tutorID)
                break;
            newtemp = newtemp->next;
        }
        newnode->next = newtemp->next;
        newnode->back = newtemp;
        if (newtemp->next == NULL) {
            newtail = newnode;
        } else {
            newtemp->next->back = newnode; 
        }
        newtemp->next = newnode;
    }
}

//Sort function which is used Insertion sort (chitranayal, PIYUSHKUMAR19, PuneetChaurasia and rathbhupendra, 2020)
void SortTutorHourlyRate(int id, string name, int dateJoinedDay, int dateJoinedMonth, int dateJoinedYear, int terminatedDay, int terminatedMonth, int terminatedYear, int hourlyRate, 
string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating) {
	Tutor * newnode = createNewNode(id, name, dateJoinedDay, dateJoinedMonth, dateJoinedYear, terminatedDay, terminatedMonth, terminatedYear, hourlyRate, phone, 
	address, centerCode, centreName, subjectCode, subjectName, rating);

	newnode->tutorHourlyRate = hourlyRate;
	newnode->next = NULL;
    newnode->back = NULL;

    if (newhead ==  NULL) {
        newhead = newtail = newnode;
    } else if (hourlyRate <= newhead->tutorHourlyRate) {
        newnode->next = newhead;
        newhead->back = newnode;
        newhead = newnode;
    } else {
        Tutor * newtemp = newhead;
        while (newtemp->next != NULL) {
            if (hourlyRate <= newtemp->next->tutorHourlyRate)
                break;
            newtemp = newtemp->next;
        }
        newnode->next = newtemp->next;
        newnode->back = newtemp;
        if (newtemp->next == NULL) {
            newtail = newnode;
        } else {
            newtemp->next->back = newnode; 
        }
        newtemp->next = newnode;
    }
}


//Sort function which is used Insertion sort (chitranayal, PIYUSHKUMAR19, PuneetChaurasia and rathbhupendra, 2020)
void SortTutorRating(int id, string name, int dateJoinedDay, int dateJoinedMonth, int dateJoinedYear, int terminatedDay, int terminatedMonth, int terminatedYear, int hourlyRate, 
string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating) {
	Tutor * newnode = createNewNode(id, name, dateJoinedDay, dateJoinedMonth, dateJoinedYear, terminatedDay, terminatedMonth, terminatedYear, hourlyRate, phone, 
	address, centerCode, centreName, subjectCode, subjectName, rating);

	newnode->tutorRating = rating;
	newnode->next = NULL;
    newnode->back = NULL;

    if (newhead ==  NULL) {
        newhead = newtail = newnode;
    } else if (rating <= newhead->tutorRating) {
        newnode->next = newhead;
        newhead->back = newnode;
        newhead = newnode;
    } else {
        Tutor * newtemp = newhead;
        while (newtemp->next != NULL) {
            if (rating <= newtemp->next->tutorRating)
                break;
            newtemp = newtemp->next;
        }
        newnode->next = newtemp->next;
        newnode->back = newtemp;
        if (newtemp->next == NULL) {
            newtail = newnode;
        } else {
            newtemp->next->back = newnode; 
        }
        newtemp->next = newnode;
    }
}

void ModifyTutor() {
	int id;
	string phone;
	string address;
	temp = head; bool havedata = false;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter Tutor Phone Number: ";
	cin >> phone;
    cout << "Enter Tutor Address: ";
	getchar();
	getline(cin, address);
	while (temp != NULL) {
		if (id == temp->tutorID) {
			cout << "Tutor ID: " << temp->tutorID << endl;
			cout << "Tutor Name: " << temp->tutorName << endl;
			cout << "Tutor old Phone: " << temp->tutorPhone << endl;
			cout << "Tutor old Address: " << temp->tutorAddress << endl;
			cout << endl; 
			cout << "Tutor new Phone: " << phone << endl;
			cout << "Tutor new Address: " << address << endl;
			temp->tutorPhone = phone;
			temp->tutorAddress = address;
			havedata = true;
		}
		temp = temp->next;
	}
	if (havedata == false) {
		cout << "Record Not Found" << endl;
	}
	cout << endl;
}

void DeleteTutor() {
	int id;
	cout << "Enter ID: ";
	cin >> id;
    if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	} else if (id == head->tutorID) {
		temp = head->next;
		cout << head->tutorID  << " is deleted now!" << endl;
		if (temp == NULL) {
			tail = NULL;
		} else {
			temp->back = NULL;}
		delete head;
		head = temp;
	} else {
		temp = head; 
		previous = NULL;
		while (id != temp->tutorID ) {
			previous = temp;
			temp = temp->next;
			if (temp == NULL) {
				cout << "No value in the list. No deletion needed! \n";
				return;}
		}
		previous->next = temp->next;
		if (temp->next != NULL) {
			temp->next->back = previous;
		} else {
			tail = previous;}
		cout << temp->tutorID  << " is deleted now!" << endl;
		delete temp;}
}


void DisplaySortedAll() {
	temp = newhead; 

	while (temp != NULL) {
		cout << temp->tutorID << ", ";
		cout << temp->tutorName << ", ";
		cout << temp->tutorDateJoined.day << "/";
		cout << temp->tutorDateJoined.month << "/";
		cout << temp->tutorDateJoined.year << ", ";
		cout << temp->tutorDateTerminated.day << "/";
		cout << temp->tutorDateTerminated.month << "/";
		cout << temp->tutorDateTerminated.year << ", ";
		cout << temp->tutorHourlyRate << ", ";
		cout << temp->tutorPhone << ", ";
        cout << temp->tutorAddress << ", ";
       	cout << temp->tutorCentreCode << ", ";
        cout << temp->tutorCentreName << ", ";
        cout << temp->tutorSubjectCode << ", ";
        cout << temp->tutorSubjectName << ", ";
        cout << temp->tutorRating << endl;
		temp = temp->next;
	}
	cout << endl;
}

//referens
// Chitranayal, PIYUSHKUMAR19, PuneetChaurasia and rathbhupendra, (2020). Insertion Sort - Geeksforgeeks. [online] GeeksforGeeks. Available at: https://www.geeksforgeeks.org/insertion-sort/ [Accessed 7 May 2020].
// Codescracker, (2020). C++ Nested Data Structure. [online] Codescracker.com. Available at: https://codescracker.com/cpp/cpp-nested-structures.htm [Accessed 13 May 2020].
// Jit_t, RishabhPrabhu, DrRoot_, ApekshikPanigrahi and GaneshJ, (2020). Linear Search - Geeksforgeeks. [online] GeeksforGeeks. Available at: https://www.geeksforgeeks.org/linear-search/ [Accessed 7 May 2020].
// Weaknessforcats, (2013). Nested Linked List - C / C++. [online] Bytes.com. Available at: https://bytes.com/topic/c/answers/948519-nested-linked-list [Accessed 13 May 2020].
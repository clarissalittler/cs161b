#include <iostream>
using namespace std;

const int numStudents = 30;

struct Student {
  string name;
  double grade;
  bool auditing;
};

void enterStudents(Student s[],
		   int &size){
  string input = "";
  
  cout << "Enter the name and grade of students in the class." << endl;
  
  do {
    cout << "Please enter the name of the student: ";
    cin >> s[size].name;
    cout << "Enter their grade in the course: ";
    cin >> s[size].grade;
    cout << "Are they auditing the course?: ";
    cin >> s[size].auditing;
    
    size++;
    
    cout << "Continue y/n?: ";
    cin >> input;
  }while(input == "y" && size < numStudents);
  
}

int main(){
  // first example of parallel arrays

  Student students[numStudents];
  
  int currStudents = 0;

  enterStudents(students,currStudents);
  
  cout << "Here's the course roster: " << endl;
  for(int i=0; i < currStudents; i++){
    cout << students[i].name << ": " << students[i].grade;
    if(students[i].auditing) {
      cout << " auditing=y" << endl;
    }
    else{
      cout << " auditing=n" << endl;
    }
  }
  
  return 0;
}

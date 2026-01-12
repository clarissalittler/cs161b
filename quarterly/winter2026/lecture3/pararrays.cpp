#include <iostream>
using namespace std;

const int numStudents = 30;

void enterStudents(double g[],string n[], bool a[],
		   int &size){
  string input = "";
  bool keepGoing = true;
  
  cout << "Enter the name and grade of students in the class." << endl;
  
  do {
    cout << "Please enter the name of the student: ";
    cin >> n[size];
    cout << "Enter their grade in the course: ";
    cin >> g[size];
    cout << "Are they auditing the course?: ";
    cin >> a[size];
    
    size++;
    
    cout << "Continue y/n?: ";
    cin >> input;
  }while(input == "y");
  
}

int main(){
  // first example of parallel arrays
  double grades[numStudents];
  string names[numStudents];
  bool audits[numStudents];
  
  int currStudents = 0;

  enterStudents(grades,names,audits,currStudents);
  
  cout << "Here's the course roster: " << endl;
  for(int i=0; i < currStudents; i++){
    cout << names[i] << ": " << grades[i];
    if(audits[i]) {
      cout << " auditing=y" << endl;
    }
    else{
      cout << " auditing=n" << endl;
    }
  }
  
  return 0;
}

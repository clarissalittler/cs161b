# Practice Exercises (Hour-Scale)

These exercises are designed to take roughly an hour each for a typical student and to practice the exact skills used in the projects. Each week only uses concepts that have been introduced up to that point.

## Concept boundaries by week

- Week 0: console I/O, variables, arithmetic, `if/else`, `for`/`while`/`do` loops, simple functions, fixed-size arrays
- Week 1: pointers, references, pointer arithmetic, C-style strings (`char[]`), `cin.getline`
- Week 2: 2D arrays, structs, arrays of structs, `std::string`
- Week 4: file I/O (`ifstream`/`ofstream`), line-based input, menu loops, `switch`
- Week 6: dynamic memory (`new`/`delete`), dynamic 2D arrays
- Week 8: linked lists, stacks/queues with nodes and pointers
- Week 10: templates, `std::vector`, iterators or range-based loops

---

## Week 0 Exercises

### W0.1 Score buckets and histogram

Write a program that:
- Prompts for `N` (1 to 50) and reads `N` integer scores (0 to 100) into an array.
- Computes min, max, and average.
- Counts scores in these buckets: 0-59, 60-69, 70-79, 80-89, 90-100.
- Prints a text histogram with one `*` per score in each bucket.

Requirements:
- Use functions for at least: `readInt`, `findMin`, `findMax`, `average`, `countInRange`.
- Use only fixed-size arrays (no `std::vector`).

### W0.2 Rotate and search

Write a program that:
- Reads `N` (1 to 30) integers into an array.
- Reads a rotation amount `k` and rotates the array to the right by `k`.
- Prompts for a target value and prints the index of the first match or `-1`.
- Prints the rotated array.

Requirements:
- Use a helper function `rotateRight(int arr[], int n, int k)`.
- Use a helper function `linearSearch(int arr[], int n, int target)`.

### W0.3 Guessing game with duplicate detection

Write a number guessing game that:
- Picks a secret number from 1 to 100.
- Allows up to 7 guesses.
- Tracks previous guesses in an array; if the user repeats a guess, warn them and do not count it.
- Prints whether each guess is too high, too low, or correct.

Requirements:
- Use `readInt` input validation.
- Use an array to store up to 20 guesses.

### W0.4 Running totals and statistics

Write a program that:
- Reads up to 100 integers, stopping early if the user enters `0`.
- Reports: count, sum, average, number of positives, number of negatives, and largest absolute value.

Requirements:
- Use a loop that stops on `0` or after 100 values.
- Use functions for at least two of the computed values.

---

## Week 1 Exercises

### W1.1 C-string toolkit

Write a program that:
- Prompts for two words (no spaces) into `char` arrays.
- Implements and uses: `ourStrlen`, `ourStrcpy`, `ourStrcat`, and `ourStrcmp`.
- Prints the lengths, comparison result, and concatenated string.

Requirements:
- Use only C-style strings (`char[]`), no `std::string`.

### W1.2 Pointer-based array utilities

Write a program that:
- Reads `N` integers into an array.
- Uses pointer arithmetic in functions to compute sum, min, max.
- Reverses the array in place using pointers and prints the result.

Requirements:
- Functions must use pointer arithmetic (no `arr[i]` in the body).

### W1.3 Line filter and normalization

Write a program that:
- Reads a full line of text (up to 200 chars) using `cin.getline`.
- Creates a new char array containing only letters and spaces.
- Converts letters to lowercase.
- Prints the cleaned line.

Requirements:
- Use C-style strings and manual character checks.

### W1.4 Hangman-lite

Write a program that:
- Uses a fixed secret word (C-string).
- Shows a masked version with underscores.
- Prompts for letter guesses until the word is complete or 6 wrong guesses.
- Prints win/lose results.

Requirements:
- Use helper functions like `checkGuess` and `isComplete`.
- Use C-style strings only.

---

## Week 2 Exercises

### W2.1 Seating chart

Write a program that:
- Maintains a 10x10 `char` seating chart (`'O'` open, `'X'` taken).
- Provides a menu to reserve, cancel, print, and count open seats.
- Validates row/column input.

Requirements:
- Use a 2D array and helper functions for menu actions.

### W2.2 Matrix stats

Write a program that:
- Reads a 5x5 matrix of integers.
- Prints row sums, column sums, min, max, and the main diagonal sum.

Requirements:
- Use functions for row sums and column sums.

### W2.3 Inventory with structs

Write a program that:
- Defines `struct Item { string name; int qty; double price; }`.
- Uses a menu to add items, restock by name, sell by name, and print total value.

Requirements:
- Use an array of up to 50 items.
- Use functions for add, find, and totals.

### W2.4 Map scan

Write a program that:
- Stores an 8x8 map with characters `#`, `.`, `S`, and `T`.
- Counts walls vs open cells.
- Finds and prints the coordinates of `S` and `T`.
- Reports the Manhattan distance between `S` and `T`.

Requirements:
- Use a 2D array and loops; no pathfinding required.

---

## Week 4 Exercises

### W4.1 File line stats

Write a program that:
- Opens a text file named `input.txt`.
- Counts lines and finds the longest line (by length).
- Prints the line count and the longest line.

Requirements:
- Use `ifstream` and `getline`.

### W4.2 CSV pets mini-db

Write a program that:
- Reads `pets.txt` with lines like `name,species,age` into a struct array.
- Provides a menu to add a pet, delete the last pet, list pets, and save/quit.

Requirements:
- Use `char[]` fields in the struct.
- Use `ifstream`/`ofstream` with `getline` and delimiters.

### W4.3 Filtered copy

Write a program that:
- Reads `input.txt` line by line.
- Prompts for a minimum length `L`.
- Writes only lines with length >= `L` to `filtered.txt`.

Requirements:
- Use `char[]` for lines and `strlen` to measure length.

### W4.4 Score report file

Write a program that:
- Reads integers from `scores.txt` (one per line).
- Computes count, min, max, average, and count above average.
- Writes a report to `report.txt` and also prints a summary.

Requirements:
- Use file I/O and arrays.

---

## Week 6 Exercises

### W6.1 Dynamic grid stats

Write a program that:
- Prompts for rows and columns.
- Allocates a dynamic 2D `int` array and fills it from user input.
- Computes and prints row sums and column sums.
- Frees all dynamic memory.

### W6.2 P1 invert and save

Write a program that:
- Reads a P1 image from a file (prompt for the filename).
- Allocates a dynamic 2D array for pixels.
- Inverts the image and writes it to `out.p1`.
- Frees all memory.

### W6.3 P1 horizontal mirror

Write a program that:
- Reads a P1 image as in W6.2.
- Flips the image horizontally (mirror each row).
- Writes the result to `mirror.p1`.

### W6.4 Dynamic array growth

Write a program that:
- Reads integers until `-1` is entered.
- Stores them in a dynamic array that doubles capacity when full.
- Prints the final array and size, then frees memory.

---

## Week 8 Exercises

### W8.1 Linked-list stack

Write a program that:
- Implements a stack with a linked list.
- Supports push, pop, peek, isEmpty, and clear.
- Provides a simple menu to interact with the stack.

### W8.2 Linked-list queue with size

Write a program that:
- Implements a queue with head and tail pointers.
- Tracks size without traversing the list.
- Supports enqueue, dequeue, peek, and print.

### W8.3 Sorted insert list

Write a program that:
- Maintains a linked list of integers in ascending order.
- Inserts each new value in sorted position.
- Prints the list after each insert.

### W8.4 Delete by value

Write a program that:
- Builds a linked list from user input.
- Provides a menu option to delete the first occurrence of a value.
- Prints the list and reports if the value was not found.

---

## Week 10 Exercises

### W10.1 Template stats

Write a program that:
- Implements template functions `sum`, `min`, `max`, `average`.
- Demonstrates them with an `int` array and a `double` array.

### W10.2 Vector median

Write a program that:
- Reads integers into a `vector<int>` until `-1` is entered.
- Sorts the vector using a simple selection sort.
- Prints min, max, average, and median.

### W10.3 2D vector workbook

Write a program that:
- Builds a `vector<vector<int>>` of size `R x C` from input.
- Computes row sums and column sums.
- Prints the grid and the sums.

### W10.4 Template clamp

Write a program that:
- Implements `template <typename T> T clamp(T v, T lo, T hi)`.
- Tests it with both `int` and `double` values.

---

## Solutions

### Solution W0.1

```cpp
#include <iostream>
using namespace std;

int readInt(int low, int high){
  int v;
  cin >> v;
  while(cin.fail() || v < low || v > high){
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Try again: ";
    cin >> v;
  }
  return v;
}

int findMin(int arr[], int n){
  int m = arr[0];
  for(int i = 1; i < n; i++){
    if(arr[i] < m){ m = arr[i]; }
  }
  return m;
}

int findMax(int arr[], int n){
  int m = arr[0];
  for(int i = 1; i < n; i++){
    if(arr[i] > m){ m = arr[i]; }
  }
  return m;
}

double average(int arr[], int n){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += arr[i];
  }
  return static_cast<double>(sum) / n;
}

int countInRange(int arr[], int n, int low, int high){
  int count = 0;
  for(int i = 0; i < n; i++){
    if(arr[i] >= low && arr[i] <= high){
      count++;
    }
  }
  return count;
}

void printBucket(const char* label, int count){
  cout << label << ": ";
  for(int i = 0; i < count; i++){
    cout << '*';
  }
  cout << " (" << count << ")" << endl;
}

int main(){
  int scores[50];
  cout << "How many scores (1-50)? ";
  int n = readInt(1, 50);
  for(int i = 0; i < n; i++){
    cout << "Score (0-100): ";
    scores[i] = readInt(0, 100);
  }

  cout << "Min: " << findMin(scores, n) << endl;
  cout << "Max: " << findMax(scores, n) << endl;
  cout << "Avg: " << average(scores, n) << endl;

  printBucket("0-59", countInRange(scores, n, 0, 59));
  printBucket("60-69", countInRange(scores, n, 60, 69));
  printBucket("70-79", countInRange(scores, n, 70, 79));
  printBucket("80-89", countInRange(scores, n, 80, 89));
  printBucket("90-100", countInRange(scores, n, 90, 100));

  return 0;
}
```

### Solution W0.2

```cpp
#include <iostream>
using namespace std;

void rotateRight(int arr[], int n, int k){
  if(n == 0){ return; }
  k = k % n;
  int temp[30];
  for(int i = 0; i < n; i++){
    temp[(i + k) % n] = arr[i];
  }
  for(int i = 0; i < n; i++){
    arr[i] = temp[i];
  }
}

int linearSearch(int arr[], int n, int target){
  for(int i = 0; i < n; i++){
    if(arr[i] == target){ return i; }
  }
  return -1;
}

int main(){
  int arr[30];
  int n;
  cout << "N (1-30): ";
  cin >> n;
  if(n < 1 || n > 30){ return 0; }

  for(int i = 0; i < n; i++){
    cout << "Value " << i << ": ";
    cin >> arr[i];
  }

  int k;
  cout << "Rotate right by k: ";
  cin >> k;
  rotateRight(arr, n, k);

  int target;
  cout << "Target: ";
  cin >> target;
  cout << "Index: " << linearSearch(arr, n, target) << endl;

  cout << "Rotated: ";
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
```

### Solution W0.3

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int readInt(int low, int high){
  int v;
  cin >> v;
  while(cin.fail() || v < low || v > high){
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Try again: ";
    cin >> v;
  }
  return v;
}

bool alreadyGuessed(int guesses[], int count, int g){
  for(int i = 0; i < count; i++){
    if(guesses[i] == g){ return true; }
  }
  return false;
}

int main(){
  srand(static_cast<unsigned int>(time(0)));
  int secret = rand() % 100 + 1;
  int guesses[20];
  int used = 0;
  int remaining = 7;

  while(remaining > 0){
    cout << "Guess (1-100): ";
    int g = readInt(1, 100);
    if(alreadyGuessed(guesses, used, g)){
      cout << "You already guessed that." << endl;
      continue;
    }
    guesses[used++] = g;

    if(g == secret){
      cout << "You win!" << endl;
      return 0;
    } else if(g < secret){
      cout << "Too low." << endl;
    } else {
      cout << "Too high." << endl;
    }
    remaining--;
    cout << "Guesses left: " << remaining << endl;
  }

  cout << "You lose. Secret was " << secret << endl;
  return 0;
}
```

### Solution W0.4

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int maxAbs(int a, int b){
  int aa = abs(a);
  int bb = abs(b);
  return (aa > bb) ? aa : bb;
}

int main(){
  int count = 0;
  int sum = 0;
  int positives = 0;
  int negatives = 0;
  int maxAbsVal = 0;

  while(count < 100){
    int v;
    cout << "Enter value (0 to stop): ";
    cin >> v;
    if(v == 0){ break; }
    sum += v;
    count++;
    if(v > 0){ positives++; }
    if(v < 0){ negatives++; }
    maxAbsVal = maxAbs(maxAbsVal, v);
  }

  if(count == 0){
    cout << "No data." << endl;
    return 0;
  }

  double avg = static_cast<double>(sum) / count;
  cout << "Count: " << count << endl;
  cout << "Sum: " << sum << endl;
  cout << "Avg: " << avg << endl;
  cout << "Positives: " << positives << endl;
  cout << "Negatives: " << negatives << endl;
  cout << "Max abs: " << maxAbsVal << endl;

  return 0;
}
```

### Solution W1.1

```cpp
#include <iostream>
using namespace std;

int ourStrlen(char s[]){
  int i = 0;
  while(s[i] != '\0'){ i++; }
  return i;
}

void ourStrcpy(char dest[], char src[]){
  int i = 0;
  while(src[i] != '\0'){
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

void ourStrcat(char dest[], char src[]){
  int d = ourStrlen(dest);
  int i = 0;
  while(src[i] != '\0'){
    dest[d + i] = src[i];
    i++;
  }
  dest[d + i] = '\0';
}

int ourStrcmp(char a[], char b[]){
  int i = 0;
  while(a[i] != '\0' && b[i] != '\0'){
    if(a[i] < b[i]){ return -1; }
    if(a[i] > b[i]){ return 1; }
    i++;
  }
  if(a[i] == '\0' && b[i] == '\0'){ return 0; }
  return (a[i] == '\0') ? -1 : 1;
}

int main(){
  char w1[50];
  char w2[50];
  char combined[120];

  cout << "Word 1: ";
  cin >> w1;
  cout << "Word 2: ";
  cin >> w2;

  cout << "Len1: " << ourStrlen(w1) << endl;
  cout << "Len2: " << ourStrlen(w2) << endl;
  cout << "Cmp: " << ourStrcmp(w1, w2) << endl;

  ourStrcpy(combined, w1);
  ourStrcat(combined, w2);
  cout << "Concat: " << combined << endl;

  return 0;
}
```

### Solution W1.2

```cpp
#include <iostream>
using namespace std;

int sumArray(int* arr, int n){
  int sum = 0;
  for(int* p = arr; p < arr + n; p++){
    sum += *p;
  }
  return sum;
}

int minArray(int* arr, int n){
  int m = *arr;
  for(int* p = arr + 1; p < arr + n; p++){
    if(*p < m){ m = *p; }
  }
  return m;
}

int maxArray(int* arr, int n){
  int m = *arr;
  for(int* p = arr + 1; p < arr + n; p++){
    if(*p > m){ m = *p; }
  }
  return m;
}

void reverseArray(int* arr, int n){
  int* left = arr;
  int* right = arr + n - 1;
  while(left < right){
    int temp = *left;
    *left = *right;
    *right = temp;
    left++;
    right--;
  }
}

int main(){
  int arr[50];
  int n;
  cout << "N: ";
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cout << "Sum: " << sumArray(arr, n) << endl;
  cout << "Min: " << minArray(arr, n) << endl;
  cout << "Max: " << maxArray(arr, n) << endl;

  reverseArray(arr, n);
  cout << "Reversed: ";
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
```

### Solution W1.3

```cpp
#include <iostream>
using namespace std;

bool isLetter(char c){
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char toLower(char c){
  if(c >= 'A' && c <= 'Z'){
    return c + ('a' - 'A');
  }
  return c;
}

int main(){
  char line[200];
  char out[200];

  cout << "Enter a line: ";
  cin.getline(line, 200);

  int j = 0;
  for(int i = 0; line[i] != '\0'; i++){
    if(isLetter(line[i]) || line[i] == ' '){
      out[j++] = toLower(line[i]);
    }
  }
  out[j] = '\0';

  cout << "Cleaned: " << out << endl;
  return 0;
}
```

### Solution W1.4

```cpp
#include <iostream>
using namespace std;

int ourStrlen(char s[]){
  int i = 0;
  while(s[i] != '\0'){ i++; }
  return i;
}

bool checkGuess(char g, char secret[], char partial[]){
  bool found = false;
  for(int i = 0; secret[i] != '\0'; i++){
    if(secret[i] == g){
      partial[i] = g;
      found = true;
    }
  }
  return found;
}

bool isComplete(char secret[], char partial[]){
  for(int i = 0; secret[i] != '\0'; i++){
    if(secret[i] != partial[i]){ return false; }
  }
  return true;
}

int main(){
  char secret[50] = "program";
  char partial[50];
  int len = ourStrlen(secret);
  for(int i = 0; i < len; i++){
    partial[i] = '_';
  }
  partial[len] = '\0';

  int wrong = 0;
  while(wrong < 6){
    cout << "Word: " << partial << endl;
    cout << "Guess a letter: ";
    char g;
    cin >> g;

    if(!checkGuess(g, secret, partial)){
      wrong++;
      cout << "Wrong. Left: " << (6 - wrong) << endl;
    } else if(isComplete(secret, partial)){
      cout << "You win!" << endl;
      return 0;
    }
  }

  cout << "You lose. Word was " << secret << endl;
  return 0;
}
```

### Solution W2.1

```cpp
#include <iostream>
using namespace std;

const int R = 10;
const int C = 10;

void initChart(char chart[R][C]){
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      chart[i][j] = 'O';
    }
  }
}

void printChart(char chart[R][C]){
  cout << "  ";
  for(int j = 0; j < C; j++){
    cout << j << " ";
  }
  cout << endl;
  for(int i = 0; i < R; i++){
    cout << i << " ";
    for(int j = 0; j < C; j++){
      cout << chart[i][j] << " ";
    }
    cout << endl;
  }
}

int countOpen(char chart[R][C]){
  int count = 0;
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      if(chart[i][j] == 'O'){ count++; }
    }
  }
  return count;
}

bool validPos(int r, int c){
  return r >= 0 && r < R && c >= 0 && c < C;
}

int main(){
  char chart[R][C];
  initChart(chart);

  int choice;
  do {
    cout << "1) Reserve 2) Cancel 3) Print 4) Count open 0) Quit: ";
    cin >> choice;
    if(choice == 1){
      int r, c;
      cout << "Row col: ";
      cin >> r >> c;
      if(validPos(r, c) && chart[r][c] == 'O'){
        chart[r][c] = 'X';
      } else {
        cout << "Invalid or taken." << endl;
      }
    } else if(choice == 2){
      int r, c;
      cout << "Row col: ";
      cin >> r >> c;
      if(validPos(r, c) && chart[r][c] == 'X'){
        chart[r][c] = 'O';
      } else {
        cout << "Invalid or not taken." << endl;
      }
    } else if(choice == 3){
      printChart(chart);
    } else if(choice == 4){
      cout << "Open seats: " << countOpen(chart) << endl;
    }
  } while(choice != 0);

  return 0;
}
```

### Solution W2.2

```cpp
#include <iostream>
using namespace std;

const int N = 5;

void rowSums(int m[N][N], int out[N]){
  for(int i = 0; i < N; i++){
    int sum = 0;
    for(int j = 0; j < N; j++){
      sum += m[i][j];
    }
    out[i] = sum;
  }
}

void colSums(int m[N][N], int out[N]){
  for(int j = 0; j < N; j++){
    int sum = 0;
    for(int i = 0; i < N; i++){
      sum += m[i][j];
    }
    out[j] = sum;
  }
}

int main(){
  int m[N][N];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> m[i][j];
    }
  }

  int minV = m[0][0];
  int maxV = m[0][0];
  int diag = 0;
  for(int i = 0; i < N; i++){
    diag += m[i][i];
    for(int j = 0; j < N; j++){
      if(m[i][j] < minV){ minV = m[i][j]; }
      if(m[i][j] > maxV){ maxV = m[i][j]; }
    }
  }

  int rs[N];
  int cs[N];
  rowSums(m, rs);
  colSums(m, cs);

  cout << "Row sums: ";
  for(int i = 0; i < N; i++){ cout << rs[i] << " "; }
  cout << endl;
  cout << "Col sums: ";
  for(int i = 0; i < N; i++){ cout << cs[i] << " "; }
  cout << endl;
  cout << "Min: " << minV << " Max: " << maxV << " Diag: " << diag << endl;

  return 0;
}
```

### Solution W2.3

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Item {
  string name;
  int qty;
  double price;
};

int findItem(Item items[], int n, const string& name){
  for(int i = 0; i < n; i++){
    if(items[i].name == name){ return i; }
  }
  return -1;
}

void addItem(Item items[], int& n){
  if(n >= 50){ return; }
  cout << "Name: ";
  cin >> items[n].name;
  cout << "Qty: ";
  cin >> items[n].qty;
  cout << "Price: ";
  cin >> items[n].price;
  n++;
}

double totalValue(Item items[], int n){
  double total = 0.0;
  for(int i = 0; i < n; i++){
    total += items[i].qty * items[i].price;
  }
  return total;
}

void listItems(Item items[], int n){
  for(int i = 0; i < n; i++){
    cout << items[i].name << " qty=" << items[i].qty
         << " price=" << items[i].price << endl;
  }
}

int main(){
  Item items[50];
  int n = 0;
  int choice;
  do {
    cout << "1) Add 2) Restock 3) Sell 4) List 5) Total 0) Quit: ";
    cin >> choice;
    if(choice == 1){
      addItem(items, n);
    } else if(choice == 2){
      string name;
      int amt;
      cout << "Item name: ";
      cin >> name;
      cout << "Add qty: ";
      cin >> amt;
      int idx = findItem(items, n, name);
      if(idx >= 0){ items[idx].qty += amt; }
    } else if(choice == 3){
      string name;
      int amt;
      cout << "Item name: ";
      cin >> name;
      cout << "Sell qty: ";
      cin >> amt;
      int idx = findItem(items, n, name);
      if(idx >= 0 && items[idx].qty >= amt){ items[idx].qty -= amt; }
    } else if(choice == 4){
      listItems(items, n);
    } else if(choice == 5){
      cout << "Total value: " << totalValue(items, n) << endl;
    }
  } while(choice != 0);

  return 0;
}
```

### Solution W2.4

```cpp
#include <iostream>
using namespace std;

const int R = 8;
const int C = 8;

int main(){
  char map[R][C] = {
    {'#','#','#','#','#','#','#','#'},
    {'#','S','.','.','.','#','.','#'},
    {'#','.','#','#','.','#','.','#'},
    {'#','.','.','#','.','.','.','#'},
    {'#','#','.','#','#','#','.','#'},
    {'#','.','.','.','.','#','.','#'},
    {'#','.','#','#','T','#','.','#'},
    {'#','#','#','#','#','#','#','#'}
  };

  int walls = 0;
  int open = 0;
  int sr = -1, sc = -1, tr = -1, tc = -1;

  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      if(map[i][j] == '#'){ walls++; }
      else { open++; }
      if(map[i][j] == 'S'){ sr = i; sc = j; }
      if(map[i][j] == 'T'){ tr = i; tc = j; }
    }
  }

  cout << "Walls: " << walls << " Open: " << open << endl;
  cout << "S at (" << sr << "," << sc << ")" << endl;
  cout << "T at (" << tr << "," << tc << ")" << endl;
  int dist = (sr - tr); if(dist < 0){ dist = -dist; }
  int dist2 = (sc - tc); if(dist2 < 0){ dist2 = -dist2; }
  cout << "Manhattan distance: " << (dist + dist2) << endl;

  return 0;
}
```

### Solution W4.1

```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
  ifstream in("input.txt");
  if(!in){
    cout << "Could not open input.txt" << endl;
    return 1;
  }

  char line[256];
  int count = 0;
  int longest = 0;
  char longestLine[256] = "";

  while(in.getline(line, 256)){
    count++;
    int len = strlen(line);
    if(len > longest){
      longest = len;
      strcpy(longestLine, line);
    }
  }

  cout << "Lines: " << count << endl;
  cout << "Longest: " << longestLine << endl;

  return 0;
}
```

### Solution W4.2

```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Pet {
  char name[50];
  char species[50];
  int age;
};

void loadPets(const char* filename, Pet pets[], int& n){
  ifstream in(filename);
  n = 0;
  if(!in){ return; }
  while(true){
    Pet p;
    in.getline(p.name, 50, ',');
    in.getline(p.species, 50, ',');
    in >> p.age;
    in.ignore(256, '\n');
    if(in.fail()){ break; }
    pets[n++] = p;
  }
}

void savePets(const char* filename, Pet pets[], int n){
  ofstream out(filename);
  for(int i = 0; i < n; i++){
    out << pets[i].name << ',' << pets[i].species << ',' << pets[i].age << endl;
  }
}

void listPets(Pet pets[], int n){
  for(int i = 0; i < n; i++){
    cout << pets[i].name << " is a " << pets[i].species
         << " age " << pets[i].age << endl;
  }
}

int main(){
  Pet pets[100];
  int n;
  loadPets("pets.txt", pets, n);

  int choice;
  do {
    cout << "1) Add 2) Delete last 3) List 0) Save/Quit: ";
    cin >> choice;
    if(choice == 1 && n < 100){
      cout << "Name: ";
      cin >> pets[n].name;
      cout << "Species: ";
      cin >> pets[n].species;
      cout << "Age: ";
      cin >> pets[n].age;
      n++;
    } else if(choice == 2 && n > 0){
      n--;
    } else if(choice == 3){
      listPets(pets, n);
    }
  } while(choice != 0);

  savePets("pets.txt", pets, n);
  return 0;
}
```

### Solution W4.3

```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
  ifstream in("input.txt");
  if(!in){
    cout << "Could not open input.txt" << endl;
    return 1;
  }
  ofstream out("filtered.txt");

  int minLen;
  cout << "Minimum length: ";
  cin >> minLen;

  char line[256];
  while(in.getline(line, 256)){
    if(static_cast<int>(strlen(line)) >= minLen){
      out << line << endl;
    }
  }

  return 0;
}
```

### Solution W4.4

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ifstream in("scores.txt");
  if(!in){
    cout << "Could not open scores.txt" << endl;
    return 1;
  }

  int scores[200];
  int n = 0;
  while(in >> scores[n]){
    n++;
    if(n >= 200){ break; }
  }
  if(n == 0){ return 0; }

  int minV = scores[0];
  int maxV = scores[0];
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += scores[i];
    if(scores[i] < minV){ minV = scores[i]; }
    if(scores[i] > maxV){ maxV = scores[i]; }
  }
  double avg = static_cast<double>(sum) / n;
  int above = 0;
  for(int i = 0; i < n; i++){
    if(scores[i] > avg){ above++; }
  }

  ofstream out("report.txt");
  out << "Count: " << n << endl;
  out << "Min: " << minV << endl;
  out << "Max: " << maxV << endl;
  out << "Avg: " << avg << endl;
  out << "Above avg: " << above << endl;

  cout << "Report written to report.txt" << endl;
  return 0;
}
```

### Solution W6.1

```cpp
#include <iostream>
using namespace std;

int main(){
  int rows, cols;
  cout << "Rows: ";
  cin >> rows;
  cout << "Cols: ";
  cin >> cols;

  int** grid = new int*[rows];
  for(int i = 0; i < rows; i++){
    grid[i] = new int[cols];
  }

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cin >> grid[i][j];
    }
  }

  cout << "Row sums: ";
  for(int i = 0; i < rows; i++){
    int sum = 0;
    for(int j = 0; j < cols; j++){
      sum += grid[i][j];
    }
    cout << sum << " ";
  }
  cout << endl;

  cout << "Col sums: ";
  for(int j = 0; j < cols; j++){
    int sum = 0;
    for(int i = 0; i < rows; i++){
      sum += grid[i][j];
    }
    cout << sum << " ";
  }
  cout << endl;

  for(int i = 0; i < rows; i++){
    delete[] grid[i];
  }
  delete[] grid;

  return 0;
}
```

### Solution W6.2

```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct P1 {
  int width;
  int height;
  int** pixels;
};

int main(){
  char filename[100];
  cout << "Input P1 file: ";
  cin >> filename;

  ifstream in(filename);
  if(!in){
    cout << "Could not open file." << endl;
    return 1;
  }

  char header[10];
  in.getline(header, 10);
  if(strcmp(header, "P1") != 0){
    cout << "Not P1." << endl;
    return 1;
  }

  P1 img;
  in >> img.width >> img.height;
  in.ignore(256, '\n');

  img.pixels = new int*[img.height];
  for(int i = 0; i < img.height; i++){
    img.pixels[i] = new int[img.width];
  }

  for(int i = 0; i < img.height; i++){
    for(int j = 0; j < img.width; j++){
      in >> img.pixels[i][j];
    }
  }

  for(int i = 0; i < img.height; i++){
    for(int j = 0; j < img.width; j++){
      img.pixels[i][j] = !img.pixels[i][j];
    }
  }

  ofstream out("out.p1");
  out << "P1" << endl;
  out << img.width << " " << img.height << endl;
  for(int i = 0; i < img.height; i++){
    for(int j = 0; j < img.width; j++){
      out << img.pixels[i][j] << " ";
    }
    out << endl;
  }

  for(int i = 0; i < img.height; i++){
    delete[] img.pixels[i];
  }
  delete[] img.pixels;

  return 0;
}
```

### Solution W6.3

```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct P1 {
  int width;
  int height;
  int** pixels;
};

int main(){
  char filename[100];
  cout << "Input P1 file: ";
  cin >> filename;

  ifstream in(filename);
  if(!in){
    cout << "Could not open file." << endl;
    return 1;
  }

  char header[10];
  in.getline(header, 10);
  if(strcmp(header, "P1") != 0){
    cout << "Not P1." << endl;
    return 1;
  }

  P1 img;
  in >> img.width >> img.height;
  in.ignore(256, '\n');

  img.pixels = new int*[img.height];
  for(int i = 0; i < img.height; i++){
    img.pixels[i] = new int[img.width];
  }

  for(int i = 0; i < img.height; i++){
    for(int j = 0; j < img.width; j++){
      in >> img.pixels[i][j];
    }
  }

  for(int i = 0; i < img.height; i++){
    for(int j = 0; j < img.width / 2; j++){
      int tmp = img.pixels[i][j];
      img.pixels[i][j] = img.pixels[i][img.width - 1 - j];
      img.pixels[i][img.width - 1 - j] = tmp;
    }
  }

  ofstream out("mirror.p1");
  out << "P1" << endl;
  out << img.width << " " << img.height << endl;
  for(int i = 0; i < img.height; i++){
    for(int j = 0; j < img.width; j++){
      out << img.pixels[i][j] << " ";
    }
    out << endl;
  }

  for(int i = 0; i < img.height; i++){
    delete[] img.pixels[i];
  }
  delete[] img.pixels;

  return 0;
}
```

### Solution W6.4

```cpp
#include <iostream>
using namespace std;

int main(){
  int capacity = 4;
  int size = 0;
  int* arr = new int[capacity];

  while(true){
    int v;
    cout << "Value (-1 to stop): ";
    cin >> v;
    if(v == -1){ break; }

    if(size == capacity){
      int newCap = capacity * 2;
      int* bigger = new int[newCap];
      for(int i = 0; i < size; i++){
        bigger[i] = arr[i];
      }
      delete[] arr;
      arr = bigger;
      capacity = newCap;
    }

    arr[size++] = v;
  }

  cout << "Size: " << size << " Capacity: " << capacity << endl;
  for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  delete[] arr;
  return 0;
}
```

### Solution W8.1

```cpp
#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

void push(Node*& top, int v){
  Node* n = new Node;
  n->value = v;
  n->next = top;
  top = n;
}

bool pop(Node*& top, int& out){
  if(top == nullptr){ return false; }
  Node* temp = top;
  out = temp->value;
  top = top->next;
  delete temp;
  return true;
}

bool peek(Node* top, int& out){
  if(top == nullptr){ return false; }
  out = top->value;
  return true;
}

void clear(Node*& top){
  while(top != nullptr){
    Node* temp = top;
    top = top->next;
    delete temp;
  }
}

int main(){
  Node* top = nullptr;
  int choice;
  do {
    cout << "1) Push 2) Pop 3) Peek 0) Quit: ";
    cin >> choice;
    if(choice == 1){
      int v;
      cout << "Value: ";
      cin >> v;
      push(top, v);
    } else if(choice == 2){
      int v;
      if(pop(top, v)){
        cout << "Popped: " << v << endl;
      } else {
        cout << "Empty." << endl;
      }
    } else if(choice == 3){
      int v;
      if(peek(top, v)){
        cout << "Top: " << v << endl;
      } else {
        cout << "Empty." << endl;
      }
    }
  } while(choice != 0);

  clear(top);
  return 0;
}
```

### Solution W8.2

```cpp
#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

void enqueue(Node*& head, Node*& tail, int& size, int v){
  Node* n = new Node;
  n->value = v;
  n->next = nullptr;
  if(tail == nullptr){
    head = tail = n;
  } else {
    tail->next = n;
    tail = n;
  }
  size++;
}

bool dequeue(Node*& head, Node*& tail, int& size, int& out){
  if(head == nullptr){ return false; }
  Node* temp = head;
  out = temp->value;
  head = head->next;
  if(head == nullptr){ tail = nullptr; }
  delete temp;
  size--;
  return true;
}

bool peek(Node* head, int& out){
  if(head == nullptr){ return false; }
  out = head->value;
  return true;
}

void printQueue(Node* head){
  Node* cur = head;
  while(cur != nullptr){
    cout << cur->value << " ";
    cur = cur->next;
  }
  cout << endl;
}

void clear(Node*& head, Node*& tail, int& size){
  while(head != nullptr){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  tail = nullptr;
  size = 0;
}

int main(){
  Node* head = nullptr;
  Node* tail = nullptr;
  int size = 0;
  int choice;
  do {
    cout << "1) Enqueue 2) Dequeue 3) Peek 4) Print 0) Quit: ";
    cin >> choice;
    if(choice == 1){
      int v;
      cout << "Value: ";
      cin >> v;
      enqueue(head, tail, size, v);
    } else if(choice == 2){
      int v;
      if(dequeue(head, tail, size, v)){
        cout << "Dequeued: " << v << endl;
      } else {
        cout << "Empty." << endl;
      }
    } else if(choice == 3){
      int v;
      if(peek(head, v)){
        cout << "Front: " << v << endl;
      } else {
        cout << "Empty." << endl;
      }
    } else if(choice == 4){
      printQueue(head);
      cout << "Size: " << size << endl;
    }
  } while(choice != 0);

  clear(head, tail, size);
  return 0;
}
```

### Solution W8.3

```cpp
#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

void insertSorted(Node*& head, int v){
  Node* n = new Node;
  n->value = v;
  n->next = nullptr;

  if(head == nullptr || v < head->value){
    n->next = head;
    head = n;
    return;
  }

  Node* cur = head;
  while(cur->next != nullptr && cur->next->value <= v){
    cur = cur->next;
  }
  n->next = cur->next;
  cur->next = n;
}

void printList(Node* head){
  Node* cur = head;
  while(cur != nullptr){
    cout << cur->value << " ";
    cur = cur->next;
  }
  cout << endl;
}

void clear(Node*& head){
  while(head != nullptr){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main(){
  Node* head = nullptr;
  while(true){
    int v;
    cout << "Value (-1 to stop): ";
    cin >> v;
    if(v == -1){ break; }
    insertSorted(head, v);
    printList(head);
  }
  clear(head);
  return 0;
}
```

### Solution W8.4

```cpp
#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

void pushFront(Node*& head, int v){
  Node* n = new Node;
  n->value = v;
  n->next = head;
  head = n;
}

bool deleteValue(Node*& head, int v){
  if(head == nullptr){ return false; }
  if(head->value == v){
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
  }
  Node* cur = head;
  while(cur->next != nullptr && cur->next->value != v){
    cur = cur->next;
  }
  if(cur->next == nullptr){ return false; }
  Node* temp = cur->next;
  cur->next = cur->next->next;
  delete temp;
  return true;
}

void printList(Node* head){
  Node* cur = head;
  while(cur != nullptr){
    cout << cur->value << " ";
    cur = cur->next;
  }
  cout << endl;
}

void clear(Node*& head){
  while(head != nullptr){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main(){
  Node* head = nullptr;
  int choice;
  do {
    cout << "1) Add front 2) Delete value 3) Print 0) Quit: ";
    cin >> choice;
    if(choice == 1){
      int v;
      cout << "Value: ";
      cin >> v;
      pushFront(head, v);
    } else if(choice == 2){
      int v;
      cout << "Delete value: ";
      cin >> v;
      if(!deleteValue(head, v)){
        cout << "Not found." << endl;
      }
    } else if(choice == 3){
      printList(head);
    }
  } while(choice != 0);

  clear(head);
  return 0;
}
```

### Solution W10.1

```cpp
#include <iostream>
using namespace std;

template <typename T>
T sum(T arr[], int n){
  T s = 0;
  for(int i = 0; i < n; i++){
    s += arr[i];
  }
  return s;
}

template <typename T>
T minVal(T arr[], int n){
  T m = arr[0];
  for(int i = 1; i < n; i++){
    if(arr[i] < m){ m = arr[i]; }
  }
  return m;
}

template <typename T>
T maxVal(T arr[], int n){
  T m = arr[0];
  for(int i = 1; i < n; i++){
    if(arr[i] > m){ m = arr[i]; }
  }
  return m;
}

template <typename T>
double average(T arr[], int n){
  return static_cast<double>(sum(arr, n)) / n;
}

int main(){
  int a[5] = {1,2,3,4,5};
  double b[4] = {2.5, 3.5, 1.0, 4.0};

  cout << "int sum: " << sum(a, 5) << " min: " << minVal(a,5)
       << " max: " << maxVal(a,5) << " avg: " << average(a,5) << endl;
  cout << "double sum: " << sum(b, 4) << " min: " << minVal(b,4)
       << " max: " << maxVal(b,4) << " avg: " << average(b,4) << endl;

  return 0;
}
```

### Solution W10.2

```cpp
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& v){
  for(size_t i = 0; i < v.size(); i++){
    size_t minIdx = i;
    for(size_t j = i + 1; j < v.size(); j++){
      if(v[j] < v[minIdx]){ minIdx = j; }
    }
    int temp = v[i];
    v[i] = v[minIdx];
    v[minIdx] = temp;
  }
}

int main(){
  vector<int> v;
  while(true){
    int x;
    cin >> x;
    if(x == -1){ break; }
    v.push_back(x);
  }
  if(v.empty()){ return 0; }

  selectionSort(v);

  int minV = v.front();
  int maxV = v.back();
  int sum = 0;
  for(size_t i = 0; i < v.size(); i++){
    sum += v[i];
  }
  double avg = static_cast<double>(sum) / v.size();

  double median;
  if(v.size() % 2 == 1){
    median = v[v.size() / 2];
  } else {
    int mid = v.size() / 2;
    median = (v[mid - 1] + v[mid]) / 2.0;
  }

  cout << "Min: " << minV << endl;
  cout << "Max: " << maxV << endl;
  cout << "Avg: " << avg << endl;
  cout << "Median: " << median << endl;

  return 0;
}
```

### Solution W10.3

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int rows, cols;
  cout << "Rows: ";
  cin >> rows;
  cout << "Cols: ";
  cin >> cols;

  vector<vector<int>> grid(rows, vector<int>(cols));
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cin >> grid[i][j];
    }
  }

  vector<int> rowSum(rows, 0);
  vector<int> colSum(cols, 0);
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      rowSum[i] += grid[i][j];
      colSum[j] += grid[i][j];
    }
  }

  cout << "Grid:" << endl;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << grid[i][j] << " ";
    }
    cout << "| sum=" << rowSum[i] << endl;
  }

  cout << "Col sums: ";
  for(int j = 0; j < cols; j++){
    cout << colSum[j] << " ";
  }
  cout << endl;

  return 0;
}
```

### Solution W10.4

```cpp
#include <iostream>
using namespace std;

template <typename T>
T clamp(T v, T lo, T hi){
  if(v < lo){ return lo; }
  if(v > hi){ return hi; }
  return v;
}

int main(){
  int a = clamp(5, 0, 3);
  int b = clamp(2, 0, 3);
  double c = clamp(3.14, 0.0, 2.5);

  cout << "a=" << a << " b=" << b << " c=" << c << endl;
  return 0;
}
```

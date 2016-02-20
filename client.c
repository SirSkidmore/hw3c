#include <stdio.h>

#include "student.h"
#include "operations.c"

// forward declare top_level_menu so we can always call it
void top_level_menu(int n, student_t students[]);

student_t update_record_menu(student_t student) {
  int input;
  input = 0;

  while(input != 7) {
    printf("Enter your option:\n");
    printf("1. name\n");
    printf("2. contact number\n");
    printf("3. address\n");
    printf("4. assignment\n");
    printf("5. midterm\n");
    printf("6. final\n");
    printf("7. go back\n");
    scanf("%d", &input);

    student = update_student_record(input, student);
  }

  return student;
}

void top_level_menu(int n, student_t students[]) {
  int input;
  
  printf("Enter your option:\n");
  printf("1. Update Record\n");
  printf("2. Print all student records\n");
  printf("3. Find out average of class\n");
  printf("4. Quit\n");
  scanf("%d", &input);

  switch(input) {
  case 1:
    printf("Enter student number: ");
    scanf("%d", &input);

    if (((input - 1) > n) || ((input - 1) < 0)) {
      printf("not a valid student ID\n");
      break;
    }
    students[input - 1] = update_record_menu(students[input - 1]);
    break;
  case 2:
    print_students(n, students);
    break;
  case 3:
    students_average(n, students);
    break;
  case 4:
    return;
  default:
    printf("Option not recognized.\n");
    break;
  }
   
  top_level_menu(n, students);
}

int main(int argc, char *argv[]) {
  int n;

  printf("Enter the no of students to be created: ");
  scanf("%d", &n);

  student_t students[n];
  int i;
  for(i = 0; i < n; i++) {
    students[i] = create_student();
  }

  // top level options (update, print, average, quit
  // takes the number of students and the array of students
  top_level_menu(n, students);
  
  return 0;
}

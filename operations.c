#include <string.h>
#include "student.h"

student_t create_student() {
  student_t temp_student;
  university_t temp_uni;
  personal_t temp_personal;

  temp_personal.name[0] = '\0';
  temp_personal.contact[0] = '\0';
  temp_personal.address[0] = '\0';

  temp_uni.assignment = 0;
  temp_uni.midterm = 0;
  temp_uni.final = 0;
  temp_uni.total = 0;

  temp_student.personal = temp_personal;
  temp_student.university = temp_uni;

  return temp_student;
}

void print_student(int n, student_t student) {
  printf("Student Number: %d\n", n);
  printf("\tPersonal Details:\n");
  printf("\t\tName: %s\n", student.personal.name);
  printf("\t\tPhone Number: %s\n", student.personal.contact);
  printf("\t\tAddress: %s\n", student.personal.address);
  printf("\tUniversity Record:\n");
  printf("\t\tAssignment grade: %d\n", student.university.assignment);
  printf("\t\tMidterm grade: %d\n", student.university.midterm);
  printf("\t\tFinal grade: %d\n", student.university.final);
  printf("\t\tTotal grade: %d\n", student.university.total);
}

void print_students(int n, student_t students[]) {
  int i;
  for(i = 0; i < n; i++) {
    print_student(i, students[i]);
  }
}

void students_average(int n, student_t students[]) {
  int i, total;
  total = 0;
  for(i = 0; i < n; i++) {
    total += students[i].university.total;
  }

  printf("Class average: %d\n", total / n);
}

int calculate_grade_total(student_t student) {
  int total;
  total  = student.university.assignment;
  total += student.university.midterm;
  total += student.university.final;

  return total / 3;
}

student_t update_student_record(int field, student_t student) {
  switch(field) {
  case 1:
    printf("Enter student name: ");
    char name[64];
    scanf("\n%64[^\n]", name);
    strcpy(student.personal.name, name);
  case 2:
    printf("Enter address: ");
    char addr[64];
    scanf("\n%64[^\n]", addr);
    strcpy(student.personal.address, addr);
  case 3:
    printf("Enter phone no: ");
    char phone[64];
    scanf("\n%64[^\n]", phone);
    strcpy(student.personal.contact, phone);
  case 4:
    printf("Enter assignment score: ");
    int input;
    scanf("%d", &input);
    student.university.assignment = input;
    student.university.total = calculate_grade_total(student);
  case 5:
    printf("Enter midterm score: ");
    scanf("%d", &input);
    student.university.midterm = input;
    student.university.total = calculate_grade_total(student);
  case 6:
    printf("Enter final score: ");
    scanf("%d", &input);
    student.university.final = input;
    student.university.total = calculate_grade_total(student);
  }

  return student;
}

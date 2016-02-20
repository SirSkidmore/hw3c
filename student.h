#ifndef STUDENT_H_
#define STUDENT_H_

/* header files make using structs across multiple files easier 
 * because including a .c file from multiple places will result
 * in possible recursive includes */

typedef struct Personal {
  char name[64];
  char contact[20];
  char address[64];
} personal_t;

typedef struct University {
  int assignment;
  int midterm;
  int final;
  int total;
} university_t;

typedef struct Student {
  personal_t personal;
  university_t university;
} student_t;

#endif

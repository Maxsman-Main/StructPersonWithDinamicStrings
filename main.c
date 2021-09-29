#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person{
  int age;
  char *name;
}Person;

Person makePerson(int age, char* name){
  Person man;
  man.age = age;
  man.name = name;
  return man;
}

int isCorrectPersonAge(int age){
  if(age == 0){
    return 0;
  }
  return 1;
}

int isCorrectPersonName(char* name){
  if(name == NULL || name[0] == '\n'){
    return 0;
  }
  return 1;
}

char* inputName(){
  /*
  Функция считывает имя и динамически выделяет
  для него память.
  */
  printf("Enter your name: \n");
  char character;
  char* name;
  int i = 0;
  name = malloc(sizeof(char) * i);
  while(character != '\n'){
    character = getc(stdin);
    name = realloc(name, (i + 1) * sizeof(char));
    name[i] = character;
    i += 1;
  }
  return name;
}

int inputAge(){
  int age;
  printf("Enter yor age: \n");
  scanf("%d", &age);  
  return age;
}

void outPerson(Person man){
  printf("%d, %s \n", man.age, man.name);
  /*
  Цикл нужен для того, чтобы можно было
  корректно считать следующее имя.
  */
  while(getchar() != '\n'){
    continue;
  }
}

int main(void) {
  while(1){
    int age; char* name;
    name = inputName();
    if(!isCorrectPersonName(name)){
      break;
    }
    age = inputAge();
    if(!isCorrectPersonAge(age)){
      break;
    }
    Person man = makePerson(age, name);
    outPerson(man);
  }
}
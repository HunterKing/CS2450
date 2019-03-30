#include <stdio.h>
#include <string.h>
#include "structures.h"

void getOnePerson(person_t* person)
{
	printf("Enter full name: ");
	scanf("%s", person->name);
 	printf("Enter ssn: ");
 	scanf("%s", person->ssn);
 	printf("Enter year of birth: ");
 	scanf("%d", &person->yearOfBirth);
}

void printOnePerson(person_t person)
{
	printf("%s:%s:%d\n", person.name, person.ssn, person.yearOfBirth);
}

void getPeople(person_t people[], int count)
{
	for(int i = 0; i < count; i++)
	{
		getOnePerson(&people[i]);
	}
}

void printPeople(person_t people[], int count)
{
	for(int i = 0; i < count; i++)
	{
		printOnePerson(people[i]);
	}
}
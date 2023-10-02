#include <stdio.h>
#define SIZE 15
int main() 
{
for (int i=0; i < SIZE; i++) for (int j=0; j <=SIZE; j++) printf(
(j==SIZE)?"\n":(j==i)?"*":" ");
return 0;
}

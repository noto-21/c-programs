#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
if (argc < 2)
{
printf("usage: ./a.out <SIZE>\n");
return 1;
}
// Size should be an even number
int end = atoi(argv[1]);
if (end % 2 == 1)
{
end--;
}
// Generate output
for (int i=0; i <= end/2; i++)
{
for (int j=end/2-1; j >= 0; j--)
{
if (j < i) {
printf("*");
} else {
printf(" ");
}
}
printf("*");
for (int j=0; j < end/2; j++)
{
if (j < i) {
printf("*");
} else {
printf(" ");
}
}
printf("\n");
}
}

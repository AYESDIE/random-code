#include <stdio.h>

int AND(int A, int B)
{
  printf("\n %d AND %d", A, B);
  return (A && B);
}

int OR(int A, int B)
{
  printf("\n %d OR %d", A, B);
  return (A || B);
}

int NOT(int A)
{
  printf("\n NOT %d", A);
  return !A;
}

int NAND(int A, int B)
{
  printf("\n %d NAND %d", A, B);
  return !(A && B);
}

int NOR(int A, int B)
{
  printf("\n %d NOR %d", A, B);
  return !(A || B);
}

int XOR(int A, int B)
{
  printf("\n %d XOR %d", A, B);
  return ((!(A && B) && (A || B)));
}

int XNOR(int A, int B)
{
  printf("\n %d XNOR %d", A, B);
  return !((!(A && B) && (A || B)));
}

int main() {
  int A = 1;
  int B = 0;

  printf(" = %d\n", AND(A, B));
  printf(" = %d\n", OR(A, B));
  printf(" = %d\n", NOT(B));
  printf(" = %d\n", NAND(A, B));
  printf(" = %d\n", NOR(A, B));
  printf(" = %d\n", XOR(A, B));
  printf(" = %d\n", XNOR(A, B));

  return 0;
}
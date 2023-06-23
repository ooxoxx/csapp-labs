int read_six_numbers(char *input, char *x) { return 6; }

int phase_6(char *input) {
  int *rsp = 0;
  int *r13 = rsp;
  int n = read_six_numbers(input, (char *)r13);
  int *r14 = rsp;
  for (int r12d = 0;;) {
    int *rbp = r13;

    // each number no larger than 6
    if (*r13 > 6) {
      // bomb
      return -1;
    }

    r12d += 1;
    if (r12d == 6) {
      break;
    }

    // 6 unique numbers
    int ebx = r12d;
    do {
      int eax = *(rsp + 4 * ebx);
      if (eax == *rbp) {
        // bomb
        return -1;
      }
      ebx += 1;
    } while (ebx <= 5);

    r13 += 4;
  }
  int rsi = *(rsp + 18);
  int *rax = r14;
  int ecx = 7;
  int edx = ecx;
  edx -= *rax;
  *rax = edx;
  rax += 4;

  return 0;
}

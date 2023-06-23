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
  int *rsi = rsp + 24;
  int *rax = r14;
  int ecx = 7;

  // gdb:<phase_6+95> bomb.asm:0x401160
  do {
    *rax = ecx - *rax;
    rax += 4;
  } while (rax != rsi);

  long rdx = 0x6032d0;
  // bomb.asm: 0x401197
  for (long j = 0; j != 24; j += 4) {
    ecx = *(rsp + j);
    if (ecx > 1) {
      for (int i = 1; i != ecx; i++) {
        // 0x4011176
        rdx = *(int *)(rdx + 8);
      }
    }
    // 0x401183
    *(rsp + 2 * j + 32) = rdx;
    j += 4;
  }

  // bomb.asm:0x4011ab
  long rbx = *(32 + rsp);
  rax = rsp + 40;
  rsi = rsp + 80;
  long rcx = rbx;
  // 0x4011bd
  while (rsi != rax) {
    int rdx = *rax;
    *(int *)(rcx + 8) = rdx;
    rax += 8;
    rcx = rdx;
  }
  // 0x4011d2
  *(int *)(rdx + 8) = 0;
  for (int ebp = 5; ebp != 0; ebp--) {
    rax = (int *)*(long *)(rbx + 8);
    rax = (int *)(long)*rax;
    if (*(int *)rbx < (long)rax) {
      // bomb!
      return -1;
    }
    rbx = *((long *)rbx + 8);
  }

  // 332 168 924 691 477 443
  // 6    5   4    3  2  1

  return 0;
}

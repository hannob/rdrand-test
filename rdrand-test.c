/*
   The code has been derived from systemd:
   https://github.com/systemd/systemd/blob/master/src/basic/random-util.c

   SPDX-License-Identifier: LGPL-2.1+
*/

#include <stdio.h>

int main() {
  unsigned char success;
  unsigned long v;
  asm volatile("rdrand %0;"
               "setc %1"
               : "=r"(v), "=qm"(success));

  printf("success: %i  value: %lx\n", success, v);
}

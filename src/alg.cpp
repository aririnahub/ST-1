// Copyright 2025 UNN-CS
#include "alg.h"

#include <cstdint>

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;

  for (uint64_t i = 3; i * i <= value; i += 2) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  if (n == 1) return 2;

  uint64_t cnt = 1;
  uint64_t num = 3;
  uint64_t lastPrime = 2;

  while (cnt < n) {
    if (checkPrime(num)) {
      cnt++;
      lastPrime = num;
    }
    num += 2;
  }
  return lastPrime;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;

  uint64_t num = value + 1;
  if (num % 2 == 0) num++;

  while (!checkPrime(num)) {
    num += 2;
  }
  return num;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  uint64_t sum = 2;
  for (uint64_t i = 3; i < hbound; i += 2) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

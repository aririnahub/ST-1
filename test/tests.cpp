// Copyright 2025 UNN-CS

#include <gtest/gtest.h>

#include <cstdint>

#include "alg.h"

// checkPrime
TEST(st1, checkPrimeSmall) {
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
  EXPECT_TRUE(checkPrime(5));
  EXPECT_TRUE(checkPrime(7));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(6));
  EXPECT_FALSE(checkPrime(8));
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(10));
}

TEST(st2, checkPrimeMedium) {
  EXPECT_TRUE(checkPrime(11));
  EXPECT_TRUE(checkPrime(13));
  EXPECT_TRUE(checkPrime(17));
  EXPECT_TRUE(checkPrime(19));
  EXPECT_TRUE(checkPrime(23));
  EXPECT_TRUE(checkPrime(29));
  EXPECT_TRUE(checkPrime(31));
  EXPECT_FALSE(checkPrime(21));
  EXPECT_FALSE(checkPrime(25));
  EXPECT_FALSE(checkPrime(27));
}

// Тесты для nPrime
TEST(st3, nPrimeFirst) {
  EXPECT_EQ(nPrime(1), 2);
  EXPECT_EQ(nPrime(2), 3);
  EXPECT_EQ(nPrime(3), 5);
  EXPECT_EQ(nPrime(4), 7);
  EXPECT_EQ(nPrime(5), 11);
  EXPECT_EQ(nPrime(6), 13);
  EXPECT_EQ(nPrime(7), 17);
  EXPECT_EQ(nPrime(8), 19);
  EXPECT_EQ(nPrime(9), 23);
  EXPECT_EQ(nPrime(10), 29);
}

TEST(st4, nPrimeMore) {
  EXPECT_EQ(nPrime(15), 47);
  EXPECT_EQ(nPrime(20), 71);
  EXPECT_EQ(nPrime(25), 97);
  EXPECT_EQ(nPrime(30), 113);
  EXPECT_EQ(nPrime(40), 173);
  EXPECT_EQ(nPrime(50), 229);
}

// Тесты для nextPrime
TEST(st5, nextPrimeSimple) {
  EXPECT_EQ(nextPrime(2), 3);
  EXPECT_EQ(nextPrime(3), 5);
  EXPECT_EQ(nextPrime(4), 5);
  EXPECT_EQ(nextPrime(5), 7);
  EXPECT_EQ(nextPrime(6), 7);
  EXPECT_EQ(nextPrime(7), 11);
  EXPECT_EQ(nextPrime(8), 11);
  EXPECT_EQ(nextPrime(9), 11);
  EXPECT_EQ(nextPrime(10), 11);
}

TEST(st6, nextPrimeComplex) {
  EXPECT_EQ(nextPrime(11), 13);
  EXPECT_EQ(nextPrime(12), 13);
  EXPECT_EQ(nextPrime(13), 17);
  EXPECT_EQ(nextPrime(14), 17);
  EXPECT_EQ(nextPrime(15), 17);
  EXPECT_EQ(nextPrime(16), 17);
  EXPECT_EQ(nextPrime(17), 19);
  EXPECT_EQ(nextPrime(18), 19);
  EXPECT_EQ(nextPrime(19), 23);
  EXPECT_EQ(nextPrime(20), 23);
}

TEST(st7, nextPrimeLarge) {
  EXPECT_EQ(nextPrime(97), 101);
  EXPECT_EQ(nextPrime(98), 101);
  EXPECT_EQ(nextPrime(99), 101);
  EXPECT_EQ(nextPrime(100), 101);
  EXPECT_EQ(nextPrime(101), 103);
  EXPECT_EQ(nextPrime(113), 127);
  EXPECT_EQ(nextPrime(114), 127);
}

// Тесты для sumPrime
TEST(st8, sumPrime1) {
  uint64_t res = sumPrime(500000);
  uint64_t expected = 9914236195;
  EXPECT_EQ(expected, res);
}

TEST(st9, sumPrime2) {
  uint64_t res = sumPrime(20);
  uint64_t expected = 77;
  EXPECT_EQ(expected, res);
}

TEST(st10, checkAndNPrime) {
  uint64_t prime10 = nPrime(10);
  EXPECT_EQ(prime10, 29);
  EXPECT_TRUE(checkPrime(prime10));

  uint64_t prime20 = nPrime(20);
  EXPECT_EQ(prime20, 71);
  EXPECT_TRUE(checkPrime(prime20));
}

TEST(st16, nextAndNPrime) {
  uint64_t prime = nPrime(15);
  EXPECT_EQ(nextPrime(prime), nPrime(16));
  EXPECT_EQ(nextPrime(prime), 53);

  uint64_t prime2 = nPrime(25);
  EXPECT_EQ(nextPrime(prime2), 101);
}

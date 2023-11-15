#!/bin/bash

rm s21_grep.txt grep.txt

echo TEST_1_grep.TXT
echo test 1
./s21_grep int test_1_grep.txt >> s21_grep.txt
grep int test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 2
./s21_grep -l int test_1_grep.txt >> s21_grep.txt
grep -l int test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 3
./s21_grep -e int test_1_grep.txt >> s21_grep.txt
grep -e int test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 4
./s21_grep -n int test_1_grep.txt >> s21_grep.txt
grep -n int test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 5
./s21_grep -s int test_1000_grep.txt >> s21_grep.txt
grep -s int test_1000_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 6
./s21_grep -h int test_1_grep.txt >> s21_grep.txt
grep -h int test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 7
./s21_grep -v int test_1_grep.txt >> s21_grep.txt
grep -v int test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 8
./s21_grep -c int test_1_grep.txt >> s21_grep.txt
grep -c int test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 9
./s21_grep -i iNt test_1_grep.txt >> s21_grep.txt
grep -i iNt test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 10
./s21_grep -in iNt test_1_grep.txt >> s21_grep.txt
grep -in iNt test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 11
./s21_grep -iv iNt test_1_grep.txt >> s21_grep.txt
grep -iv iNt test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 12
./s21_grep -f pattern.txt test_1_grep.txt >> s21_grep.txt
grep -f pattern.txt test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test 13
./s21_grep -o trc  test_1_grep.txt >> s21_grep.txt
grep -o trc  test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo TEST_2_grep.TXT
echo test 1
./s21_grep int test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep int test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 2
./s21_grep -l int test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -l int test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 3
./s21_grep -e int test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -e int test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 4
./s21_grep -n int test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -n int test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 5
./s21_grep -s int test_1000_grep.txt >> s21_grep.txt
grep -s int test_1000_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 6
./s21_grep -h int test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -h int test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 7
./s21_grep -v int test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -v int test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 8
./s21_grep -c int test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -c int test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 9
./s21_grep -i iNt test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -i iNt test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 10
./s21_grep -in iNt test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -in iNt test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 11
./s21_grep -iv iNt test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -iv iNt test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
echo test 12
./s21_grep -f pattern.txt test_1_grep.txt test_2_grep.txt >> s21_grep.txt
grep -f pattern.txt test_1_grep.txt test_2_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test 13
./s21_grep -o trc pattern.txt test_1_grep.txt >> s21_grep.txt
grep -o trc pattern.txt test_1_grep.txt >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt


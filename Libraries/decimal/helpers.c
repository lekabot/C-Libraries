#include "helpers.h"

int get_bit(int number, int position) {
    int mask = 1 << position;
    return (number & mask) >> position;
}

int set_bit_to_zero(int number, int position) {
   return number &= ~(1 << position);
}

int set_bit_to_one(int number, int position) {
   return number |= 1 << position;
}
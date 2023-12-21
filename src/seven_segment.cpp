#include "../include/seven_segment.hpp"

void zero(int digit) {
    digitalWrite(digit, LOW);
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, LOW);
}


void one(int digit) {
    digitalWrite(digit, 0);
    digitalWrite(A, 0);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
}

void two(int digit) {
    digitalWrite(digit, 0);
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 0);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 0);
    digitalWrite(G, 1);
}

void three(int digit) {
    digitalWrite(digit, 0);
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 1);
}

void four(int digit) {
    digitalWrite(digit, 0);
    digitalWrite(A, 0);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
}

void five(int digit) {
    digitalWrite(digit, 0);
    digitalWrite(A, 1);
    digitalWrite(B, 0);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 0);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
}

void six(int digit) {
    digitalWrite(digit, 0);
    digitalWrite(A, 1);
    digitalWrite(B, 0);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
}

void seven(int digit) {
    digitalWrite(digit, 0);
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 0);
    digitalWrite(G, 0);
}

void eight(int digit) {
    digitalWrite(digit, 0);
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
}

void nine(int digit) {
    digitalWrite(digit, 0);
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 0);
    digitalWrite(E, 0);
    digitalWrite(F, 1);
    digitalWrite(G, 1);
}

void calibrate() {
    zero(D1);
    zero(D2);
    zero(D3);
    zero(D4);

    delay(1000);

    one(D1);
    one(D2);
    one(D3);
    one(D4);

    delay(1000);

    two(D1);
    two(D2);
    two(D3);
    two(D4);

    delay(1000);

    three(D1);
    three(D2);
    three(D3);
    three(D4);

    delay(1000);

    four(D1);
    four(D2);
    four(D3);
    four(D4);

    delay(1000);

    five(D1);
    five(D2);
    five(D3);
    five(D4);

    delay(1000);

    six(D1);
    six(D2);
    six(D3);
    six(D4);

    delay(1000);

    seven(D1);
    seven(D2);
    seven(D3);
    seven(D4);

    delay(1000);

    eight(D1);
    eight(D2);
    eight(D3);
    eight(D4);

    delay(1000);

    nine(D1);
    nine(D2);
    nine(D3);
    nine(D4);

    delay(1000);
}

void reset() {
    digitalWrite(D1, 0);
    digitalWrite(D2, 0);
    digitalWrite(D3, 0);
    digitalWrite(D4, 0);
    digitalWrite(A, 1);
    digitalWrite(B, 1);
    digitalWrite(C, 1);
    digitalWrite(D, 1);
    digitalWrite(E, 1);
    digitalWrite(F, 1);
    digitalWrite(G, 0);
}
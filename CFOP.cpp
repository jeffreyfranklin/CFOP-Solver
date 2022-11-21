#include <iostream>
#include <cmath>
#include <cstdint>
#include <bits/stdc++.h>
using namespace std;

// Constants
const uint8_t WHITE = 0, GREEN = 1, RED = 2, BLUE = 3, ORANGE = 4, YELLOW = 5;

// Global Variables
uint64_t frontFace = 0, backFace = 0, leftFace = 0, rightFace = 0, upFace = 0, downFace = 0;
int moveCount = 0;

#pragma region Utility Functions

void SetByte(uint64_t *bytes, uint8_t byte, int pos) {
    *bytes &= ~((uint64_t)0xff << (8*pos)); // Clear the current byte
    *bytes |= ((uint64_t)byte << (8*pos));  // Set the new byte
}

uint8_t GetByte(uint64_t bytes, int index) {
    return bytes >> 8 * index;
}

static inline uint64_t rotl64 (uint64_t n, unsigned int c) {
    const unsigned int mask = (CHAR_BIT*sizeof(n) - 1);  // assumes width is a power of 2.

    // assert ( (c<=mask) &&"rotate by type width or more");
    c &= mask;
    return (n<<c) | (n>>( (-c)&mask ));
}

static inline uint64_t rotr64 (uint64_t n, unsigned int c) {
    const unsigned int mask = (CHAR_BIT*sizeof(n) - 1);

    // assert ( (c<=mask) &&"rotate by type width or more");
    c &= mask;
    return (n>>c) | (n<<( (-c)&mask ));
}

#pragma endregion

#pragma region Front Face Moves

void F() {
    cout<<"F ";
    moveCount++;
    frontFace = rotl64(frontFace, 16);
    uint8_t leftBytes[3], rightBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&leftFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&rightFace, upBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&upFace, leftBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&downFace, rightBytes[i], j % 8);
    }
}

void FPrime() {
    cout<<"F' ";
    moveCount++;
    frontFace = rotr64(frontFace, 16);
    uint8_t leftBytes[3], rightBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&leftFace, upBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&rightFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&upFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&downFace, leftBytes[i], j % 8);
    }
}

void F2() {
    cout<<"F2 ";
    moveCount++;
    frontFace = rotl64(frontFace, 32);
    uint8_t leftBytes[3], rightBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&leftFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&rightFace, leftBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&upFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&downFace, upBytes[i], j % 8);
    }
}

#pragma endregion

#pragma region Back Face Moves

void B() {
    cout<<"B ";
    moveCount++;
    backFace = rotl64(backFace, 16);
    uint8_t leftBytes[3], rightBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&leftFace, upBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&rightFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&upFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&downFace, leftBytes[i], j % 8);
    }
}

void BPrime() {
    cout<<"B' ";
    moveCount++;
    backFace = rotr64(backFace, 16);
    uint8_t leftBytes[3], rightBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&leftFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&rightFace, upBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&upFace, leftBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&downFace, rightBytes[i], j % 8);
    }
}

void B2() {
    cout<<"B2 ";
    moveCount++;
    backFace = rotl64(backFace, 32);
    uint8_t leftBytes[3], rightBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&leftFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&rightFace, leftBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&upFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&downFace, upBytes[i], j % 8);
    }
}

#pragma endregion

#pragma region Left Face Moves

void L() {
    cout<<"L ";
    moveCount++;
    leftFace = rotl64(leftFace, 16);
    uint8_t frontBytes[3], backBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&frontFace, upBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&backFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&upFace, backBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&downFace, frontBytes[i], j % 8);
    }
}

void LPrime() {
    cout<<"L' ";
    moveCount++;
    leftFace = rotr64(leftFace, 16);
    uint8_t frontBytes[3], backBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&frontFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&backFace, upBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&upFace, frontBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&downFace, backBytes[i], j % 8);
    }
}

void L2() {
    cout<<"L2 ";
    moveCount++;
    leftFace = rotl64(leftFace, 32);
    uint8_t frontBytes[3], backBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&frontFace, backBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&backFace, frontBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&upFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&downFace, upBytes[i], j % 8);
    }
}

#pragma endregion

#pragma region Right Face Moves

void R() {
    cout<<"R ";
    moveCount++;
    rightFace = rotl64(rightFace, 16);
    uint8_t frontBytes[3], backBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&frontFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&backFace, upBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&upFace, frontBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&downFace, backBytes[i], j % 8);
    }
}

void RPrime() {
    cout<<"R' ";
    moveCount++;
    rightFace = rotr64(rightFace, 16);
    uint8_t frontBytes[3], backBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&frontFace, upBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&backFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&upFace, backBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&downFace, frontBytes[i], j % 8);
    }
}

void R2() {
    cout<<"R2 ";
    moveCount++;
    rightFace = rotl64(rightFace, 32);
    uint8_t frontBytes[3], backBytes[3], upBytes[3], downBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        upBytes[i] = GetByte(upFace, j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        downBytes[i] = GetByte(downFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&frontFace, backBytes[i], j % 8);
    }
    for(int i = 0, j = 6; i < 3; ++i, ++j) {
        SetByte(&backFace, frontBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&upFace, downBytes[i], j % 8);
    }
    for(int i = 0, j = 2; i < 3; ++i, ++j) {
        SetByte(&downFace, upBytes[i], j % 8);
    }
}

#pragma endregion

#pragma region Up Face Moves

void U() {
    cout<<"U ";
    moveCount++;
    upFace = rotl64(upFace, 16);
    uint8_t frontBytes[3], backBytes[3], leftBytes[3], rightBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&frontFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&backFace, leftBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&leftFace, frontBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&rightFace, backBytes[i], j % 8);
    }
}

void UPrime() {
    cout<<"U' ";
    moveCount++;
    upFace = rotr64(upFace, 16);
    uint8_t frontBytes[3], backBytes[3], leftBytes[3], rightBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&frontFace, leftBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&backFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&leftFace, backBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&rightFace, frontBytes[i], j % 8);
    }
}

void U2() {
    cout<<"U2 ";
    moveCount++;
    upFace = rotl64(upFace, 32);
    uint8_t frontBytes[3], backBytes[3], leftBytes[3], rightBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&frontFace, backBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&backFace, frontBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&leftFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 0; i < 3; ++i, ++j) {
        SetByte(&rightFace, leftBytes[i], j % 8);
    }
}

#pragma endregion

#pragma region Down Face Moves

void D() {
    cout<<"D ";
    moveCount++;
    downFace = rotl64(downFace, 16);
    uint8_t frontBytes[3], backBytes[3], leftBytes[3], rightBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&frontFace, leftBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&backFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&leftFace, backBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&rightFace, frontBytes[i], j % 8);
    }
}

void DPrime() {
    cout<<"D' ";
    moveCount++;
    downFace = rotr64(downFace, 16);
    uint8_t frontBytes[3], backBytes[3], leftBytes[3], rightBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&frontFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&backFace, leftBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&leftFace, frontBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&rightFace, backBytes[i], j % 8);
    }
}

void D2() {
    cout<<"D2 ";
    moveCount++;
    downFace = rotl64(downFace, 32);
    uint8_t frontBytes[3], backBytes[3], leftBytes[3], rightBytes[3];
    // Stores affected bytes
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        frontBytes[i] = GetByte(frontFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        backBytes[i] = GetByte(backFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        leftBytes[i] = GetByte(leftFace, j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        rightBytes[i] = GetByte(rightFace, j % 8);
    }
    // Move affected bytes to their new locations
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&frontFace, backBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&backFace, frontBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&leftFace, rightBytes[i], j % 8);
    }
    for(int i = 0, j = 4; i < 3; ++i, ++j) {
        SetByte(&rightFace, leftBytes[i], j % 8);
    }
}

#pragma endregion

void SolveCross() {
    uint8_t prefer[4] = {ORANGE, BLUE, RED, GREEN};
    for(int i = 0; i < 4; ++i) {
        if(GetByte(upFace, 1)==YELLOW && GetByte(backFace, 1)==prefer[i]) { U2(); F2(); goto nextPiece; }
        if(GetByte(upFace, 3)==YELLOW && GetByte(rightFace, 1)==prefer[i]) { U(); F2(); goto nextPiece; }
        if(GetByte(upFace, 5)==YELLOW && GetByte(frontFace, 1)==prefer[i]) { F2(); goto nextPiece; }
        if(GetByte(upFace, 7)==YELLOW && GetByte(leftFace, 1)==prefer[i]) { UPrime(); F2(); goto nextPiece; }

        if(GetByte(downFace, 1)==YELLOW && GetByte(frontFace, 5)==prefer[i]) { goto nextPiece; }
        if(GetByte(downFace, 3)==YELLOW && GetByte(rightFace, 5)==prefer[i]) { R2(); U(); F2(); goto nextPiece; }
        if(GetByte(downFace, 5)==YELLOW && GetByte(backFace, 5)==prefer[i]) { B2(); U2(); F2(); goto nextPiece; }
        if(GetByte(downFace, 7)==YELLOW && GetByte(leftFace, 5)==prefer[i]) { L2(); UPrime(); F2(); goto nextPiece; }

        if(GetByte(leftFace, 1)==YELLOW && GetByte(upFace, 7)==prefer[i]) { L(); FPrime(); LPrime(); goto nextPiece; }
        if(GetByte(leftFace, 3)==YELLOW && GetByte(frontFace, 7)==prefer[i]) { FPrime(); goto nextPiece; }
        if(GetByte(leftFace, 5)==YELLOW && GetByte(downFace, 7)==prefer[i]) { LPrime(); FPrime(); goto nextPiece; }
        if(GetByte(leftFace, 7)==YELLOW && GetByte(backFace, 3)==prefer[i]) { L2(); FPrime(); L2(); goto nextPiece; }

        if(GetByte(rightFace, 1)==YELLOW && GetByte(upFace, 3)==prefer[i]) { RPrime(); F(); R(); goto nextPiece; }
        if(GetByte(rightFace, 3)==YELLOW && GetByte(backFace, 7)==prefer[i]) { R2(); F(); R2(); goto nextPiece; }
        if(GetByte(rightFace, 5)==YELLOW && GetByte(downFace, 3)==prefer[i]) { R(); F(); goto nextPiece; }
        if(GetByte(rightFace, 7)==YELLOW && GetByte(frontFace, 3)==prefer[i]) { F(); goto nextPiece; }

        if(GetByte(frontFace, 1)==YELLOW && GetByte(upFace, 5)==prefer[i]) { UPrime(); RPrime(); F(); R(); goto nextPiece; }
        if(GetByte(frontFace, 3)==YELLOW && GetByte(rightFace, 7)==prefer[i]) { R(); U(); RPrime(); F2(); goto nextPiece; }
        if(GetByte(frontFace, 5)==YELLOW && GetByte(downFace, 1)==prefer[i]) { FPrime(); R(); U(); RPrime(); F2(); goto nextPiece; }
        if(GetByte(frontFace, 7)==YELLOW && GetByte(leftFace, 3)==prefer[i]) { LPrime(); UPrime(); L(); F2(); goto nextPiece; }

        if(GetByte(backFace, 1)==YELLOW && GetByte(upFace, 1)==prefer[i]) { U(); RPrime(); F(); R(); goto nextPiece; }
        if(GetByte(backFace, 3)==YELLOW && GetByte(leftFace, 7)==prefer[i]) { L(); UPrime(); LPrime(); F2(); goto nextPiece; }
        if(GetByte(backFace, 5)==YELLOW && GetByte(downFace, 5)==prefer[i]) { BPrime(); L(); UPrime(); LPrime(); F2(); goto nextPiece; }
        if(GetByte(backFace, 7)==YELLOW && GetByte(rightFace, 3)==prefer[i]) { RPrime(); U(); R(); F2(); }

        nextPiece:
        if(i < 3) { D(); }
    }
}

void SolveFirstLayerCorners() {
    uint8_t prefer[4][2] = {{GREEN, RED}, {ORANGE, GREEN}, {BLUE, ORANGE}, {RED, BLUE}};
    for(int i = 0; i < 4; ++i) {
        cout<<endl<<"Corner "<<i+1<<": ";
        if(GetByte(backFace, 0)==YELLOW && GetByte(rightFace, 2)==prefer[i][0] && GetByte(upFace, 2)==prefer[i][1]) { FPrime(); U(); F(); goto nextPiece; }
        if(GetByte(backFace, 2)==YELLOW && GetByte(upFace, 0)==prefer[i][0] && GetByte(leftFace, 0)==prefer[i][1]) { R(); U2(); RPrime(); goto nextPiece; }
        if(GetByte(backFace, 4)==YELLOW && GetByte(leftFace, 6)==prefer[i][0] && GetByte(downFace, 6)==prefer[i][1]) { BPrime(); R(); U2(); RPrime(); B(); goto nextPiece; }
        if(GetByte(backFace, 6)==YELLOW && GetByte(downFace, 4)==prefer[i][0] && GetByte(rightFace, 4)==prefer[i][1]) { B(); FPrime(); U(); F(); BPrime(); goto nextPiece; }

        if(GetByte(leftFace, 0)==YELLOW && GetByte(backFace, 2)==prefer[i][0] && GetByte(upFace, 0)==prefer[i][1]) { FPrime(); U2(); F(); goto nextPiece; }
        if(GetByte(leftFace, 2)==YELLOW && GetByte(upFace, 6)==prefer[i][0] && GetByte(frontFace, 0)==prefer[i][1]) { R(); UPrime(); RPrime(); goto nextPiece; }
        if(GetByte(leftFace, 4)==YELLOW && GetByte(frontFace, 6)==prefer[i][0] && GetByte(downFace, 0)==prefer[i][1]) { LPrime(); R(); UPrime(); RPrime(); L(); goto nextPiece; }
        if(GetByte(leftFace, 6)==YELLOW && GetByte(downFace, 6)==prefer[i][0] && GetByte(backFace, 4)==prefer[i][1]) { L(); U(); LPrime(); FPrime(); U(); F(); goto nextPiece; }

        if(GetByte(downFace, 0)==YELLOW && GetByte(leftFace, 4)==prefer[i][0] && GetByte(frontFace, 6)==prefer[i][1]) { LPrime(); U2(); L(); FPrime(); U(); F(); goto nextPiece; }
        if(GetByte(downFace, 2)==YELLOW && GetByte(frontFace, 4)==prefer[i][0] && GetByte(rightFace, 6)==prefer[i][1]) { goto nextPiece; }
        if(GetByte(downFace, 4)==YELLOW && GetByte(rightFace, 4)==prefer[i][0] && GetByte(backFace, 6)==prefer[i][1]) { B(); U2(); BPrime(); R(); UPrime(); RPrime(); goto nextPiece; }
        if(GetByte(downFace, 6)==YELLOW && GetByte(backFace, 4)==prefer[i][0] && GetByte(leftFace, 6)==prefer[i][1]) { L(); UPrime(); LPrime(); FPrime(); U2(); F(); goto nextPiece; }

        if(GetByte(frontFace, 0)==YELLOW && GetByte(leftFace, 2)==prefer[i][0] && GetByte(upFace, 6)==prefer[i][1]) { UPrime(); R(); U(); RPrime(); goto nextPiece; }
        if(GetByte(frontFace, 2)==YELLOW && GetByte(upFace, 4)==prefer[i][0] && GetByte(rightFace, 0)==prefer[i][1]) { FPrime(); UPrime(); F(); goto nextPiece; }
        if(GetByte(frontFace, 4)==YELLOW && GetByte(rightFace, 6)==prefer[i][0] && GetByte(downFace, 2)==prefer[i][1]) { R(); UPrime(); RPrime(); FPrime(); UPrime(); F(); goto nextPiece; }
        if(GetByte(frontFace, 6)==YELLOW && GetByte(downFace, 0)==prefer[i][0] && GetByte(leftFace, 4)==prefer[i][1]) { F(); U2(); F2(); U(); F(); goto nextPiece; }

        if(GetByte(rightFace, 0)==YELLOW && GetByte(frontFace, 2)==prefer[i][0] && GetByte(upFace, 4)==prefer[i][1]) { R(); U(); RPrime(); goto nextPiece; }
        if(GetByte(rightFace, 2)==YELLOW && GetByte(upFace, 2)==prefer[i][0] && GetByte(backFace, 0)==prefer[i][1]) { U2(); R(); UPrime(); RPrime(); goto nextPiece; }
        if(GetByte(rightFace, 4)==YELLOW && GetByte(backFace, 6)==prefer[i][0] && GetByte(downFace, 4)==prefer[i][1]) { RPrime(); U2(); R2(); UPrime(); RPrime(); goto nextPiece; }
        if(GetByte(rightFace, 6)==YELLOW && GetByte(downFace, 2)==prefer[i][0] && GetByte(frontFace, 4)==prefer[i][1]) { R(); U(); RPrime(); UPrime(); R(); U(); RPrime(); goto nextPiece; }

        if(GetByte(upFace, 0)==YELLOW && GetByte(leftFace, 0)==prefer[i][0] && GetByte(backFace, 2)==prefer[i][1]) { U2(); R(); U2(); RPrime(); UPrime(); R(); U(); RPrime(); goto nextPiece; }
        if(GetByte(upFace, 2)==YELLOW && GetByte(backFace, 0)==prefer[i][0] && GetByte(rightFace, 2)==prefer[i][1]) { U(); R(); U2(); RPrime(); UPrime(); R(); U(); RPrime(); goto nextPiece; }
        if(GetByte(upFace, 4)==YELLOW && GetByte(rightFace, 0)==prefer[i][0] && GetByte(frontFace, 2)==prefer[i][1]) { R(); U2(); RPrime(); UPrime(); R(); U(); RPrime(); goto nextPiece; }
        if(GetByte(upFace, 6)==YELLOW && GetByte(frontFace, 0)==prefer[i][0] && GetByte(leftFace, 2)==prefer[i][1]) { UPrime(); R(); U2(); RPrime(); UPrime(); R(); U(); RPrime(); }

        nextPiece:
        D();
    }
}

#pragma region Middle Layer Edge Algorithms

void FrontLeftEdge() {
    UPrime(); LPrime(); U(); L(); U(); F(); UPrime(); FPrime();
}

void FrontRightEdge() {
    U(); R(); UPrime(); RPrime(); UPrime(); FPrime(); U(); F();
}

void BackLeftEdge() {
    U(); L(); UPrime(); LPrime(); UPrime(); BPrime(); U(); B();
}

void BackRightEdge() {
    UPrime(); RPrime(); U(); R(); U(); B(); UPrime(); BPrime();
}

void LeftBackEdge() {
    UPrime(); BPrime(); U(); B(); U(); L(); UPrime(); LPrime();
}

void LeftFrontEdge() {
    U(); F(); UPrime(); FPrime(); UPrime(); LPrime(); U(); L();
}

void RightFrontEdge() {
    UPrime(); FPrime(); U(); F(); U(); R(); UPrime(); RPrime();
}

void RightBackEdge() {
    U(); B(); UPrime(); BPrime(); UPrime(); RPrime(); U(); R();
}

#pragma endregion

void SolveMiddleLayerEdges() {
    // Solve Green-Red Edge
    cout<<endl<<"Green-Red Edge: ";
    if(GetByte(frontFace, 1)==GREEN && GetByte(upFace, 5)==RED) { FrontRightEdge(); goto orangeGreen; }
    if(GetByte(frontFace, 3)==GREEN && GetByte(rightFace, 7)==RED) { goto orangeGreen; }    // Correct
    if(GetByte(frontFace, 7)==GREEN && GetByte(leftFace, 3)==RED) { LeftFrontEdge(); U(); FrontRightEdge(); goto orangeGreen; }

    if(GetByte(backFace, 1)==GREEN && GetByte(upFace, 1)==RED) { U2(); FrontRightEdge(); goto orangeGreen; }
    if(GetByte(backFace, 3)==GREEN && GetByte(leftFace, 7)==RED) { LeftBackEdge(); U(); FrontRightEdge(); goto orangeGreen; }
    if(GetByte(backFace, 7)==GREEN && GetByte(rightFace, 3)==RED) { RightBackEdge(); UPrime(); FrontRightEdge(); goto orangeGreen; }

    if(GetByte(leftFace, 1)==GREEN && GetByte(upFace, 7)==RED) { UPrime(); FrontRightEdge(); goto orangeGreen; }
    if(GetByte(leftFace, 3)==GREEN && GetByte(frontFace, 7)==RED) { FrontLeftEdge(); U2(); FrontRightEdge(); goto orangeGreen; }
    if(GetByte(leftFace, 7)==GREEN && GetByte(backFace, 3)==RED) { BackLeftEdge(); FrontRightEdge(); goto orangeGreen; }

    if(GetByte(rightFace, 1)==GREEN && GetByte(upFace, 3)==RED) { U(); FrontRightEdge(); goto orangeGreen; }
    if(GetByte(rightFace, 3)==GREEN && GetByte(backFace, 7)==RED) { BackRightEdge(); FrontRightEdge(); goto orangeGreen; }
    if(GetByte(rightFace, 7)==GREEN && GetByte(frontFace, 3)==RED) { FrontRightEdge(); U2(); FrontRightEdge(); goto orangeGreen; }

    if(GetByte(upFace, 1)==GREEN && GetByte(backFace, 1)==RED) { U(); RightFrontEdge(); goto orangeGreen; }
    if(GetByte(upFace, 3)==GREEN && GetByte(rightFace, 1)==RED) { RightFrontEdge(); goto orangeGreen; }
    if(GetByte(upFace, 5)==GREEN && GetByte(frontFace, 1)==RED) { UPrime(); RightFrontEdge(); goto orangeGreen; }
    if(GetByte(upFace, 7)==GREEN && GetByte(leftFace, 1)==RED) { U2(); RightFrontEdge(); goto orangeGreen; }

    orangeGreen:
    // Solve Orange-Green Edge
    cout<<endl<<"Orange-Green Edge: ";
    if(GetByte(frontFace, 1)==ORANGE && GetByte(upFace, 5)==GREEN) { U(); LeftFrontEdge(); goto blueOrange; }
    if(GetByte(frontFace, 7)==ORANGE && GetByte(leftFace, 3)==GREEN) { LeftFrontEdge(); U2(); LeftFrontEdge(); goto blueOrange; }

    if(GetByte(backFace, 1)==ORANGE && GetByte(upFace, 1)==GREEN) { UPrime(); LeftFrontEdge(); goto blueOrange; }
    if(GetByte(backFace, 3)==ORANGE && GetByte(leftFace, 7)==GREEN) { LeftBackEdge(); U2(); LeftFrontEdge(); goto blueOrange; }
    if(GetByte(backFace, 7)==ORANGE && GetByte(rightFace, 3)==GREEN) { RightBackEdge(); LeftFrontEdge(); goto blueOrange; }

    if(GetByte(leftFace, 1)==ORANGE && GetByte(upFace, 7)==GREEN) { LeftFrontEdge(); goto blueOrange; }
    if(GetByte(leftFace, 3)==ORANGE && GetByte(frontFace, 7)==GREEN) { goto blueOrange; }   // Correct
    if(GetByte(leftFace, 7)==ORANGE && GetByte(backFace, 3)==GREEN) { BackLeftEdge(); U(); LeftFrontEdge(); goto blueOrange; }

    if(GetByte(rightFace, 1)==ORANGE && GetByte(upFace, 3)==GREEN) { U2(); LeftFrontEdge(); goto blueOrange; }
    if(GetByte(rightFace, 3)==ORANGE && GetByte(backFace, 7)==GREEN) { BackRightEdge(); U(); LeftFrontEdge(); goto blueOrange; }

    if(GetByte(upFace, 1)==ORANGE && GetByte(backFace, 1)==GREEN) { U2(); FrontLeftEdge(); goto blueOrange; }
    if(GetByte(upFace, 3)==ORANGE && GetByte(rightFace, 1)==GREEN) { U(); FrontLeftEdge(); goto blueOrange; }
    if(GetByte(upFace, 5)==ORANGE && GetByte(frontFace, 1)==GREEN) { FrontLeftEdge(); goto blueOrange; }
    if(GetByte(upFace, 7)==ORANGE && GetByte(leftFace, 1)==GREEN) { UPrime(); FrontLeftEdge(); goto blueOrange; }

    blueOrange:
    // Solve Blue-Orange Edge
    cout<<endl<<"Blue-Orange Edge: ";
    if(GetByte(frontFace, 1)==BLUE && GetByte(upFace, 5)==ORANGE) { U2(); BackLeftEdge(); goto redBlue; }

    if(GetByte(backFace, 1)==BLUE && GetByte(upFace, 1)==ORANGE) { BackLeftEdge(); goto redBlue; }
    if(GetByte(backFace, 3)==BLUE && GetByte(leftFace, 7)==ORANGE) { goto redBlue; }    // Correct
    if(GetByte(backFace, 7)==BLUE && GetByte(rightFace, 3)==ORANGE) { RightBackEdge(); U(); BackLeftEdge(); goto redBlue; }

    if(GetByte(leftFace, 1)==BLUE && GetByte(upFace, 7)==ORANGE) { U(); BackLeftEdge(); goto redBlue; }
    if(GetByte(leftFace, 7)==BLUE && GetByte(backFace, 3)==ORANGE) { BackLeftEdge(); U2(); BackLeftEdge(); goto redBlue; }

    if(GetByte(rightFace, 1)==BLUE && GetByte(upFace, 3)==ORANGE) { UPrime(); BackLeftEdge(); goto redBlue; }
    if(GetByte(rightFace, 3)==BLUE && GetByte(backFace, 7)==ORANGE) { BackRightEdge(); U2(); BackLeftEdge(); goto redBlue; }

    if(GetByte(upFace, 1)==BLUE && GetByte(backFace, 1)==ORANGE) { UPrime(); LeftBackEdge(); goto redBlue; }
    if(GetByte(upFace, 3)==BLUE && GetByte(rightFace, 1)==ORANGE) { U2(); LeftBackEdge(); goto redBlue; }
    if(GetByte(upFace, 5)==BLUE && GetByte(frontFace, 1)==ORANGE) { U(); LeftBackEdge(); goto redBlue; }
    if(GetByte(upFace, 7)==BLUE && GetByte(leftFace, 1)==ORANGE) { LeftBackEdge(); goto redBlue; }

    redBlue:
    // Solve Red-Blue Edge
    cout<<endl<<"Red-Blue Edge: ";
    if(GetByte(frontFace, 1)==RED && GetByte(upFace, 5)==BLUE) { UPrime(); RightBackEdge(); return; }

    if(GetByte(backFace, 1)==RED && GetByte(upFace, 1)==BLUE) { U(); RightBackEdge(); return; }
    if(GetByte(backFace, 7)==RED && GetByte(rightFace, 3)==BLUE) { RightBackEdge(); U2(); RightBackEdge(); return; }

    if(GetByte(leftFace, 1)==RED && GetByte(upFace, 7)==BLUE) { U2(); RightBackEdge(); return; }

    if(GetByte(rightFace, 1)==RED && GetByte(upFace, 3)==BLUE) { RightBackEdge(); return; }
    if(GetByte(rightFace, 3)==RED && GetByte(backFace, 7)==BLUE) { return; }    // Correct

    if(GetByte(upFace, 1)==RED && GetByte(backFace, 1)==BLUE) { BackRightEdge(); return; }
    if(GetByte(upFace, 3)==RED && GetByte(rightFace, 1)==BLUE) { UPrime(); BackRightEdge(); return; }
    if(GetByte(upFace, 5)==RED && GetByte(frontFace, 1)==BLUE) { U2(); BackRightEdge(); return; }
    if(GetByte(upFace, 7)==RED && GetByte(leftFace, 1)==BLUE) { U(); BackRightEdge(); return; }
}

void OLL() {
    // Solved
    if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(upFace, 5)==WHITE &&
        GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { return; }
    
    for(int i = 0; i < 4; ++i) {
        // Dots 1-4
        if(GetByte(leftFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(leftFace, 1)==WHITE) { R(); U2(); R2(); F(); R(); FPrime(); U2(); RPrime(); F(); R(); FPrime(); return; }

        if(GetByte(backFace, 2)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(leftFace, 1)==WHITE) { F(); RPrime(); FPrime(); R(); U2(); F(); RPrime(); FPrime(); R2(); U2(); RPrime(); return; }
        
        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(leftFace, 1)==WHITE) { F(); U(); R(); UPrime(); RPrime(); FPrime(); U(); F(); R(); U(); RPrime(); UPrime(); FPrime(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(leftFace, 1)==WHITE) { F(); U(); R(); UPrime(); RPrime(); FPrime(); UPrime(); F(); R(); U(); RPrime(); UPrime(); FPrime(); return; }

        // Square Shapes 5-6
        if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { RPrime(); F2(); L(); F(); LPrime(); F(); R(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(leftFace, 1)==WHITE) { F(); UPrime(); R2(); D(); RPrime(); UPrime(); R(); DPrime(); R2(); U(); FPrime(); return; }

        // Small Lightning Bolts 7-8
        if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(leftFace, 1)==WHITE) { B(); L(); FPrime(); L(); F(); L2(); BPrime(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(leftFace, 1)==WHITE) { R(); U2(); RPrime(); U2(); RPrime(); F(); R(); FPrime(); return; }

        // Fish Shapes 9-10
        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U(); RPrime(); UPrime(); RPrime(); F(); R2(); U(); RPrime(); UPrime(); FPrime(); return; }

        if(GetByte(backFace, 2)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U(); RPrime(); U(); RPrime(); F(); R(); FPrime(); R(); U2(); RPrime(); return; }

        // Small Lightning Bolts pt.2 11-12
        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { FPrime(); LPrime(); UPrime(); L(); U(); F(); R(); B(); U(); BPrime(); UPrime(); RPrime(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { F(); R(); U(); R2(); F(); R(); F2(); U(); F(); U2(); FPrime(); return; }

        // Knight Move Shape 13-16
        if(GetByte(backFace, 2)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { F(); U(); R(); UPrime(); R2(); FPrime(); R(); U(); R(); UPrime(); RPrime(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { RPrime(); F(); R(); U(); RPrime(); FPrime(); R(); F(); UPrime(); FPrime(); return; }

        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { RPrime(); FPrime(); R(); LPrime(); UPrime(); L(); U(); RPrime(); F(); R(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { RPrime(); F(); R(); U(); RPrime(); UPrime(); FPrime(); R(); UPrime(); RPrime(); U2(); R(); return; }

        // Dots pt.2 17-20
        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(leftFace, 1)==WHITE) { R(); U(); RPrime(); U(); RPrime(); F(); R(); FPrime(); U2(); RPrime(); F(); R(); FPrime(); return; }

        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(leftFace, 1)==WHITE) { F(); RPrime(); FPrime(); R(); U2(); F(); RPrime(); FPrime(); R(); UPrime(); R(); UPrime(); RPrime(); return; }

        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(leftFace, 1)==WHITE) { RPrime(); U2(); F(); R(); U(); RPrime(); UPrime(); F2(); U2(); F(); R(); return; }

        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(leftFace, 1)==WHITE) { LPrime(); RPrime(); FPrime(); U2(); L2(); U2(); L2(); U2(); L2(); F(); L(); R(); return; }

        // Crosses 21-27
        if(GetByte(backFace, 2)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U2(); RPrime(); UPrime(); R(); U(); RPrime(); UPrime(); R(); UPrime(); RPrime(); return; }
            
        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U2(); R2(); UPrime(); R2(); UPrime(); R2(); U2(); R(); return; }

        if(GetByte(backFace, 2)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { R2(); DPrime(); R(); U2(); RPrime(); D(); R(); U2(); R(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U(); R(); D(); RPrime(); UPrime(); R(); DPrime(); R2(); return; }

        if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { RPrime(); F(); R(); BPrime(); RPrime(); FPrime(); R(); B(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U2(); RPrime(); UPrime(); R(); UPrime(); RPrime(); return; }

        if(GetByte(backFace, 2)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U(); RPrime(); U(); R(); U2(); RPrime(); return; }

        // Corners Oriented 28
        if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { R2(); F2(); L(); F(); LPrime(); F2(); R(); FPrime(); R(); return; }

        // Awkward Shapes 29-30
        if(GetByte(backFace, 2)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U(); RPrime(); UPrime(); R(); UPrime(); RPrime(); FPrime(); UPrime(); F(); R(); U(); RPrime(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { F(); RPrime(); F(); R2(); UPrime(); RPrime(); UPrime(); R(); U(); RPrime(); F2(); return; }

        // P Shapes 31-32
        if(GetByte(backFace, 2)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(leftFace, 1)==WHITE) { RPrime(); UPrime(); F(); U(); R(); UPrime(); RPrime(); FPrime(); R(); return; }

        if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { L(); U(); FPrime(); UPrime(); LPrime(); U(); L(); F(); LPrime(); return; }

        // T Shape 33
        if(GetByte(backFace, 2)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U(); RPrime(); UPrime(); RPrime(); F(); R(); FPrime(); return; }

        // C Shape 34
        if(GetByte(leftFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U(); R2(); UPrime(); RPrime(); F(); R(); U(); R(); UPrime(); FPrime(); return; }

        // Fish Shape pt.2 35
        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(leftFace, 1)==WHITE) { R(); U2(); R2(); F(); R(); FPrime(); R(); U2(); RPrime(); return; }

        // W Shape 36
        if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(leftFace, 1)==WHITE) { LPrime(); UPrime(); L(); UPrime(); LPrime(); U(); L(); U(); L(); FPrime(); LPrime(); F(); return; }

        // Fish Shape pt.3 37
        if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { F(); RPrime(); FPrime(); R(); U(); R(); UPrime(); RPrime(); return; }

        // W Shape pt.2 38
        if(GetByte(backFace, 2)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U(); RPrime(); U(); R(); UPrime(); RPrime(); UPrime(); RPrime(); F(); R(); FPrime(); return; }

        // Big Lightning Bolts 39-40
        if(GetByte(backFace, 2)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { L(); FPrime(); LPrime(); UPrime(); L(); U(); F(); UPrime(); LPrime(); return; }

        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { RPrime(); F(); R(); U(); RPrime(); UPrime(); FPrime(); U(); R(); return; }

        // Awkward Shapes pt.2 41-42
        if(GetByte(backFace, 2)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { R(); U(); RPrime(); U(); R(); U2(); RPrime(); F(); R(); U(); RPrime(); UPrime(); FPrime(); return; }

        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { RPrime(); UPrime(); R(); UPrime(); RPrime(); U2(); R(); F(); R(); U(); RPrime(); UPrime(); FPrime(); return; }

        // P Shapes pt.2 43-44
        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(leftFace, 1)==WHITE) { FPrime(); UPrime(); LPrime(); U(); L(); F(); return; }

        if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { F(); U(); R(); UPrime(); RPrime(); FPrime(); return; }

        // T Shape pt.2 45
        if(GetByte(leftFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { F(); R(); U(); RPrime(); UPrime(); FPrime(); return; }

        // C Shape pt.2 46
        if(GetByte(upFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(leftFace, 1)==WHITE) { RPrime(); UPrime(); RPrime(); F(); R(); FPrime(); U(); R(); return; }

        // Small L Shapes 47-50
        if(GetByte(backFace, 2)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(leftFace, 1)==WHITE) { RPrime(); UPrime(); RPrime(); F(); R(); FPrime(); RPrime(); F(); R(); FPrime(); U(); R(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { F(); R(); U(); RPrime(); UPrime(); R(); U(); RPrime(); UPrime(); FPrime(); return; }

        if(GetByte(backFace, 2)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { R(); BPrime(); R2(); F(); R2(); B(); R2(); FPrime(); R(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(leftFace, 1)==WHITE) { FPrime(); R(); U2(); RPrime(); U2(); RPrime(); F2(); R(); FPrime(); return; }

        // I Shapes 51-52
        if(GetByte(backFace, 2)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { F(); U(); R(); UPrime(); RPrime(); U(); R(); UPrime(); RPrime(); FPrime(); return; }

        if(GetByte(backFace, 2)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(leftFace, 1)==WHITE) { R(); U(); RPrime(); U(); R(); UPrime(); B(); UPrime(); BPrime(); RPrime(); return; }

        // Small L Shapes pt.2 53-54
        if(GetByte(leftFace, 0)==WHITE && GetByte(upFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { F(); R(); U(); RPrime(); UPrime(); FPrime(); R(); U(); RPrime(); UPrime(); RPrime(); F(); R(); FPrime(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(rightFace, 1)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(upFace, 5)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { F(); RPrime(); FPrime(); R(); U2(); F2(); L(); F(); LPrime(); F(); return; }

        // I Shapes pt.2 55-56
        if(GetByte(backFace, 2)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(backFace, 0)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(frontFace, 2)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(frontFace, 0)==WHITE && GetByte(upFace, 7)==WHITE) { RPrime(); F(); R(); U(); R(); UPrime(); R2(); FPrime(); R2(); UPrime(); RPrime(); U(); R(); U(); RPrime(); return; }

        if(GetByte(leftFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(rightFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(rightFace, 0)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(leftFace, 2)==WHITE && GetByte(upFace, 7)==WHITE) { RPrime(); F(); R(); FPrime(); U2(); R(); UPrime(); RPrime(); U(); FPrime(); U2(); F(); return; }

        // Corners Oriented pt.2 57
        if(GetByte(upFace, 0)==WHITE && GetByte(backFace, 1)==WHITE && GetByte(upFace, 2)==WHITE && GetByte(upFace, 3)==WHITE && GetByte(upFace, 4)==WHITE && GetByte(frontFace, 1)==WHITE &&
            GetByte(upFace, 6)==WHITE && GetByte(upFace, 7)==WHITE) { LPrime(); R(); U(); RPrime(); UPrime(); L(); RPrime(); F(); R(); FPrime(); return; }

        U();
    }
}

void PLL() {
    // Solved
    if(GetByte(frontFace, 0)==GetByte(frontFace, 1) && GetByte(frontFace, 1)==GetByte(frontFace, 2) &&
        GetByte(backFace, 0)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(backFace, 2)) { goto adjustUpperFace; }

    for(int i = 0; i < 4; ++i) {
        // Aa Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 1) && GetByte(frontFace, 1)==GetByte(rightFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(leftFace, 0) &&
            GetByte(backFace, 0)==GetByte(backFace, 2) && GetByte(backFace, 2)==GetByte(rightFace, 1)) { RPrime(); F(); RPrime(); B2(); R(); FPrime(); RPrime(); B2(); R2(); break; }

        // Ab Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 2) && GetByte(frontFace, 2)==GetByte(rightFace, 1) && GetByte(frontFace, 1)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(leftFace, 2) &&
            GetByte(backFace, 1)==GetByte(backFace, 2) && GetByte(backFace, 2)==GetByte(rightFace, 0)) { R(); BPrime(); R(); F2(); RPrime(); B(); R(); F2(); R2(); break; }

        // F Perm
        if(GetByte(frontFace, 0)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(rightFace, 2) && GetByte(frontFace, 1)==GetByte(backFace, 2) && GetByte(backFace, 2)==GetByte(rightFace, 0) &&
            GetByte(frontFace, 2)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(rightFace, 1)) { RPrime(); UPrime(); FPrime(); R(); U(); RPrime(); UPrime(); RPrime(); F(); R2(); UPrime(); RPrime(); UPrime(); R(); U(); RPrime(); U(); R(); break; }

        // Ga Perm
        if(GetByte(frontFace, 0)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(rightFace, 2) && GetByte(frontFace, 1)==GetByte(frontFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 0) &&
            GetByte(backFace, 2)==GetByte(leftFace, 1) && GetByte(leftFace, 1)==GetByte(rightFace, 0)) { L2(); F2(); LPrime(); U2(); LPrime(); U2(); L(); FPrime(); LPrime(); UPrime(); L(); U(); L(); FPrime(); L2(); break; }

        // Gb Perm
        if(GetByte(frontFace, 0)==GetByte(rightFace, 1) && GetByte(rightFace, 1)==GetByte(rightFace, 2) && GetByte(frontFace, 1)==GetByte(backFace, 2) && GetByte(backFace, 2)==GetByte(rightFace, 0) &&
            GetByte(frontFace, 2)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(leftFace, 1)) { RPrime(); UPrime(); R(); U(); DPrime(); R2(); U(); RPrime(); U(); R(); UPrime(); R(); UPrime(); R2(); D(); break; }

        // Gc Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 1) && GetByte(frontFace, 1)==GetByte(backFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(leftFace, 0) &&
            GetByte(backFace, 0)==GetByte(leftFace, 2) && GetByte(leftFace, 2)==GetByte(rightFace, 1)) { R2(); F2(); R(); U2(); R(); U2(); RPrime(); F(); R(); U(); RPrime(); UPrime(); RPrime(); F(); R2(); break; }

        // Gd Perm
        if(GetByte(frontFace, 0)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(rightFace, 2) && GetByte(frontFace, 1)==GetByte(leftFace, 0) && GetByte(leftFace, 0)==GetByte(leftFace, 2) &&
            GetByte(frontFace, 2)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(leftFace, 1)) { R(); U(); RPrime(); UPrime(); D(); R2(); UPrime(); R(); UPrime(); RPrime(); U(); RPrime(); U(); R2(); DPrime(); break; }

        // Ja Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 1) && GetByte(frontFace, 1)==GetByte(frontFace, 2) && GetByte(backFace, 0)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(leftFace, 2) &&
            GetByte(backFace, 2)==GetByte(rightFace, 0) && GetByte(rightFace, 0)==GetByte(rightFace, 1)) { RPrime(); U(); LPrime(); U2(); R(); UPrime(); RPrime(); U2(); R(); L(); break; }

        // Jb Perm
        if(GetByte(frontFace, 0)==GetByte(rightFace, 1) && GetByte(rightFace, 1)==GetByte(rightFace, 2) && GetByte(frontFace, 1)==GetByte(frontFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 0) &&
            GetByte(backFace, 1)==GetByte(backFace, 2) && GetByte(backFace, 2)==GetByte(rightFace, 0)) { R(); U(); RPrime(); FPrime(); R(); U(); RPrime(); UPrime(); RPrime(); F(); R2(); UPrime(); RPrime(); break; }

        // Ra Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 1) && GetByte(frontFace, 1)==GetByte(rightFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(rightFace, 1) &&
            GetByte(backFace, 1)==GetByte(leftFace, 0) && GetByte(leftFace, 0)==GetByte(leftFace, 2)) { R(); U(); RPrime(); FPrime(); R(); U2(); RPrime(); U2(); RPrime(); F(); R(); U(); R(); U2(); RPrime(); break; }

        // Rb Perm
        if(GetByte(frontFace, 0)==GetByte(backFace, 2) && GetByte(backFace, 2)==GetByte(leftFace, 1) && GetByte(frontFace, 1)==GetByte(frontFace, 2) && GetByte(frontFace, 2)==GetByte(leftFace, 0) &&
            GetByte(backFace, 0)==GetByte(leftFace, 2) && GetByte(leftFace, 2)==GetByte(rightFace, 1)) { LPrime(); UPrime(); L(); F(); LPrime(); U2(); L(); U2(); L(); FPrime(); LPrime(); UPrime(); LPrime(); U2(); L(); U(); break; }

        // T Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 1) && GetByte(frontFace, 1)==GetByte(rightFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(leftFace, 1) &&
            GetByte(backFace, 1)==GetByte(backFace, 2) && GetByte(backFace, 2)==GetByte(rightFace, 0)) { R(); U(); RPrime(); UPrime(); RPrime(); F(); R2(); UPrime(); RPrime(); UPrime(); R(); U(); RPrime(); FPrime(); break; }

        // E Perm
        if(GetByte(frontFace, 0)==GetByte(backFace, 2) && GetByte(backFace, 2)==GetByte(leftFace, 1) && GetByte(frontFace, 1)==GetByte(leftFace, 0) && GetByte(leftFace, 0)==GetByte(rightFace, 2) &&
            GetByte(frontFace, 2)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(leftFace, 1)) { R(); BPrime(); RPrime(); F(); R(); B(); RPrime(); FPrime(); R(); B(); RPrime(); F(); R(); BPrime(); RPrime(); FPrime(); break; }

        // Na Perm
        if(GetByte(frontFace, 0)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(backFace, 2) && GetByte(frontFace, 1)==GetByte(frontFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 0) &&
            GetByte(leftFace, 0)==GetByte(leftFace, 1) && GetByte(leftFace, 1)==GetByte(rightFace, 0)) { L(); UPrime(); R(); U2(); LPrime(); U(); RPrime(); L(); UPrime(); R(); U2(); LPrime(); U(); RPrime(); break; }

        // Nb Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 1) && GetByte(frontFace, 1)==GetByte(backFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(backFace, 1) &&
            GetByte(leftFace, 0)==GetByte(leftFace, 1) && GetByte(leftFace, 1)==GetByte(rightFace, 2)) { RPrime(); U(); LPrime(); U2(); R(); UPrime(); L(); RPrime(); U(); LPrime(); U2(); R(); UPrime(); L(); break; }

        // V Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 1) && GetByte(frontFace, 1)==GetByte(backFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(rightFace, 1) &&
            GetByte(backFace, 1)==GetByte(leftFace, 0) && GetByte(leftFace, 0)==GetByte(rightFace, 2)) { RPrime(); U2(); R(); U2(); L(); UPrime(); RPrime(); U(); LPrime(); U(); L(); UPrime(); R(); U(); LPrime(); break; }

        // Y Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 1) && GetByte(frontFace, 1)==GetByte(backFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(leftFace, 1) &&
            GetByte(backFace, 1)==GetByte(leftFace, 2) && GetByte(leftFace, 2)==GetByte(rightFace, 0)) { F(); R(); UPrime(); RPrime(); UPrime(); R(); U(); RPrime(); FPrime(); R(); U(); RPrime(); UPrime(); RPrime(); F(); R(); FPrime(); break; }

        // H Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 2) && GetByte(frontFace, 2)==GetByte(backFace, 1) && GetByte(frontFace, 1)==GetByte(backFace, 0) && GetByte(backFace, 0)==GetByte(backFace, 2) &&
            GetByte(leftFace, 0)==GetByte(leftFace, 2) && GetByte(leftFace, 2)==GetByte(rightFace, 1)) { L(); R(); U2(); LPrime(); RPrime(); FPrime(); BPrime(); U2(); F(); B(); break; }

        // Ua Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 2) && GetByte(frontFace, 2)==GetByte(leftFace, 1) && GetByte(frontFace, 1)==GetByte(rightFace, 0) && GetByte(rightFace, 0)==GetByte(rightFace, 2) &&
            GetByte(backFace, 0)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(backFace, 2)) { R(); UPrime(); R(); U(); R(); U(); R(); UPrime(); RPrime(); UPrime(); R2(); break; }

        // Ub Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 2) && GetByte(frontFace, 2)==GetByte(rightFace, 1) && GetByte(frontFace, 1)==GetByte(leftFace, 0) && GetByte(leftFace, 0)==GetByte(leftFace, 2) &&
            GetByte(backFace, 0)==GetByte(backFace, 1) && GetByte(backFace, 1)==GetByte(backFace, 2)) { R2(); U(); R(); U(); RPrime(); UPrime(); RPrime(); UPrime(); RPrime(); U(); RPrime(); break; }

        // Z Perm
        if(GetByte(frontFace, 0)==GetByte(frontFace, 2) && GetByte(frontFace, 2)==GetByte(rightFace, 1) && GetByte(frontFace, 1)==GetByte(rightFace, 0) && GetByte(rightFace, 0)==GetByte(rightFace, 2) &&
            GetByte(backFace, 0)==GetByte(backFace, 2) && GetByte(backFace, 2)==GetByte(leftFace, 1)) { R(); BPrime(); RPrime(); B(); F(); RPrime(); F(); BPrime(); RPrime(); B(); R(); F2(); break; }

        U();
    }

    adjustUpperFace:
    if(GetByte(frontFace, 1)==ORANGE) { U(); }
    if(GetByte(frontFace, 1)==BLUE) { U2(); }
    if(GetByte(frontFace, 1)==RED) { UPrime(); }
}

void CharToBits(uint64_t *side, char input, int index) {
    if(input == 'g') {
        SetByte(side, GREEN, index);
    } else if(input == 'b') {
        SetByte(side, BLUE, index);
    } else if(input == 'o') {
        SetByte(side, ORANGE, index);
    } else if(input == 'r') {
        SetByte(side, RED, index);
    } else if(input == 'w') {
        SetByte(side, WHITE, index);
    } else if(input == 'y') {
        SetByte(side, YELLOW, index);
    }
}

char BitsToChar(uint64_t side, int index) {
    uint8_t bits = GetByte(side, index);
    if(bits == GREEN) {
        return 'g';
    } else if (bits == BLUE) {
        return 'b';
    } else if (bits == ORANGE) {
        return 'o';
    } else if (bits == RED) {
        return 'r';
    } else if (bits == WHITE) {
        return 'w';
    } else if (bits == YELLOW) {
        return 'y';
    }
    return '?';
}

void Display(uint64_t side) {
    for(int i = 0; i < 8; ++i) {
        cout<<BitsToChar(side, i)<<" ";
    }
    cout<<endl<<endl;
}

int main() {
    cout<<"Rubik's Cube Solver"<<endl<<endl;
    cout<<"Input:"<<endl<<endl;
    cout<<"Green Side: ";
    for(int i = 0; i < 8; ++i) {
        char input; cin>>input; CharToBits(&frontFace, input, i);
    }
    cout<<"Blue Side: ";
    for(int i = 0; i < 8; ++i) {
        char input; cin>>input; CharToBits(&backFace, input, i);
    }
    cout<<"Orange Side: ";
    for(int i = 0; i < 8; ++i) {
        char input; cin>>input; CharToBits(&leftFace, input, i);
    }
    cout<<"Red Side: ";
    for(int i = 0; i < 8; ++i) {
        char input; cin>>input; CharToBits(&rightFace, input, i);
    }
    cout<<"White Side: ";
    for(int i = 0; i < 8; ++i) {
        char input; cin>>input; CharToBits(&upFace, input, i);
    }
    cout<<"Yellow Side: ";
    for(int i = 0; i < 8; ++i) {
        char input; cin>>input; CharToBits(&downFace, input, i);
    }

    cout<<"\n-------------------------------------------------\n"<<endl;

    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;

    auto t1 = high_resolution_clock::now();

    cout<<"Make these moves in this exact order with green in the front and white on top to solve your Rubik's Cube:"<<endl<<endl;
    cout<<"Cross: ";
    SolveCross();
    cout<<endl;
    cout<<"First Layer Corners";
    SolveFirstLayerCorners();
    cout<<endl;
    cout<<"Middle Layer Edges";
    SolveMiddleLayerEdges();
    cout<<endl;
    cout<<"OLL: ";
    OLL();
    cout<<endl;
    cout<<"PLL: ";
    PLL();
    cout<<endl;

    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, milli> ms_double = t2 - t1;

    cout << "\nExecution Time: " << ms_int.count() << "ms\n";
    cout << ms_double.count() << "ms\n";
    cout << "\nMove Count: " << moveCount << endl;

    cout<<"\n-------------------------------------------------"<<endl<<endl;
    cout<<"Your Rubik's Cube is now SOLVED!\n\nOutput:"<<endl;
    cout<<"Green Side : ";
    Display(frontFace);
    cout<<"Blue Side : ";
    Display(backFace);
    cout<<"Orange Side : ";
    Display(leftFace);
    cout<<"Red Side : ";
    Display(rightFace);
    cout<<"White Side : ";
    Display(upFace);
    cout<<"Yellow Side : ";
    Display(downFace);
    return 0;
}

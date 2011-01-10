/*
 * File: main.cpp
 *
 * Copyright © 2011, Sean Chapel
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "DataBuffer.hpp"

#include <iostream>

int testServer();
int testDataBuffer();

int main(int argc, char** argv)
{
    int numTests = 2;
    int testsPassed = 0;

    DataBuffer buffer;
    size_t bufferSize = 0;


    // Do write/size testing
    std::cout << "writing: char 'a'" << std::endl;
    buffer.write('a');
    bufferSize += sizeof(char);

    std::cout << "writing: int '2'" << std::endl;
    buffer.write((int)2);
    bufferSize += sizeof(int);

    std::cout << "writing: long '3'" << std::endl;
    buffer.write((long)3);
    bufferSize += sizeof(long);

    std::cout << "writing: float '4.0f'" << std::endl;
    buffer.write((float)4.0f);
    bufferSize += sizeof(float);

    std::cout << "writing: double '5.0f'" << std::endl;
    buffer.write((double)5.0f);
    bufferSize += sizeof(double);

    std::cout << "writing: short '6'" << std::endl;
    buffer.write((short)6);
    bufferSize += sizeof(short);

    std::cout << "writing: string 'testing a string'" << std::endl;
    buffer.write(std::string("testing a string"));
    bufferSize += sizeof(char) * 17; // string + null character


    std::cout << "buffer size should be: " << bufferSize << std::endl;
    std::cout << "buffer size is: " << buffer.size() << std::endl;
    if(buffer.size() == bufferSize)
    {
        std::cout << "size test: [PASSED]" << std::endl;
        testsPassed++;
    }
    else
    {
        std::cout << "size test: [FAILED]" << std::endl;
    }

    std::cout << std::endl << std::endl;



    // do reading test
    buffer.rewind();

    char c = buffer.readChar();
    std::cout << "read char: 'a' == '" << c << "'" << std::endl;

    int i = buffer.readInt();
    std::cout << "read int: 2 == " << i << std::endl;

    long l = buffer.readLong();
    std::cout << "read long: 3 == " << l << std::endl;

    float f = buffer.readFloat();
    std::cout << "read float: 4.0f == " << f << std::endl;

    double d = buffer.readDouble();
    std::cout << "read double: 5.0f == " << d << std::endl;

    short s = buffer.readShort();
    std::cout << "read short: 6 == " << s << std::endl;

    std::string str = buffer.readString();
    std::cout << "read string: 'testing a string' == '" << str << "'" << std::endl;

    if((c == 'a') &&
       (i == 2) &&
       (l == 3) &&
       (f == 4.0f) &&
       (d == 5.0f) &&
       (s == 6) &&
       (str == std::string("testing a string")))
    {
        std::cout << "content test: [PASSED]" << std::endl;
        testsPassed++;
    }
    else
    {
        std::cout << "content test: [FAILED]" << std::endl;
    }


    std::cout << std::endl << std::endl;

    std::cout << "Passed " << testsPassed << " test and failed " << numTests - testsPassed << std::endl;


    return 0;
}
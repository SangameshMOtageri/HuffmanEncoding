#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include "pch.h"

using namespace std;

extern "C" __declspec(dllexport) int heapmainfunc(int val, int index, string cmd);

extern "C" __declspec(dllexport) int huffman(char* input, unsigned int len);

extern "C" __declspec(dllexport) char testvect(char a);

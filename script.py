#!/bin/python3
import os
import sys

if len(sys.argv) > 1:
    name = sys.argv[1]
    with open(name + '.cpp', 'w+') as f:
        f.write('''
#include <bits/stdc++.h>
using namespace std;

namespace p{0}{{
    int main() {{
        return 0;
    }}
}}

int main() {{ 
    return p{0}::main(), 0; 
}}
'''.format(name)
        )

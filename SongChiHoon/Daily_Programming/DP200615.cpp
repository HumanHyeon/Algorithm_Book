// "./"과 "../" 이 포함된 파일 경로를 "./"과 "../"이 없는 유닉스 파일 경로로 바꾸시오.

// "./"는 현재의 위치를 뜻하고, "../"는 상위 디렉토리를 뜻합니다.



// Given a file path containing "./" and "../", convert the path to a unix standard file path that does not contain "./" and "../".



// input: "/usr/bin/../"

// output: "/usr/"



// input: "/usr/./bin/./test/../"

// output: "/usr/bin/"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


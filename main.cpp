#include <iostream>
using namespace std;
#include "string.h"

int main(int argc, char **argv)
{
    String s1("Hello, World!"); 
    String s2 = "Hello, World!"; 
    String s3;
    cout << s2 << endl; 
    cin >> s3;
    cout << s3.length() << endl;
    s3.stringtoup();
    cout << s3 << endl;
    s3.stringtolow();
    cout << s3 << endl;
    if (s3 == s2){
        cout << "true equal" << endl;
    }
    else{
        cout << "false not equal" << endl;
    }
    if(s3 > s2){
        cout << "true s3>s2" << endl;
    } else{
        cout << "false s3<=s2" << endl;
    }
    s3 = s3 + s2;
    cout << s3 << endl;
    cout << s2[2] << endl;
    return 0;
}

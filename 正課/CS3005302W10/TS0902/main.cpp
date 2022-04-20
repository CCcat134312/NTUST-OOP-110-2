// Name: 林信佑
// Date: 2022/4/20 下午 03:39:24
// Last Update: 2022/4/20 下午 03:39:24
// Problem statement: Namespace
#include <iostream>

#include "user.h"
#include "password.h"
using namespace std;
using namespace Authenticate;

int main()
{
    inputUserName();
    inputPassword();
    cout << "Your username is " << getUserName() <<
        " and your password is: " <<
        getPassword() << endl;
    return 0;
}

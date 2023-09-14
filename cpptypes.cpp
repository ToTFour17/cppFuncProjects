#include <iostream>
using namespace std;

int main()
{
    int shortok = SHRT_MIN;
    int shortok1 = SHRT_MAX;

    int intok = INT32_MIN;
    int intok1 = INT32_MAX;

    long long ling = LLONG_MIN;
    long long ling1 = LLONG_MAX;

    unsigned short signa = 0;
    unsigned short signa1 = USHRT_MAX;
    unsigned int signa2 = 0;
    unsigned int signa3 = UINT32_MAX;
    unsigned long long signa4 = 0;
    unsigned long long signa5 = ULLONG_MAX;

    float flek = FLT_MIN;
    float flek1 = FLT_MAX;

    double dabl = DBL_MIN;
    double dabl1 = DBL_MAX;

    bool byblik = 0;
    bool byblik1 = 1;

    char chyr = 0;
    char chyr1 = 255;

        cout << "type\t\t\t|byte\t|min\t\t\t|max" << endl;
        cout << "short\t\t\t|" << sizeof(short) << "\t|" << shortok << "\t\t\t|" << shortok1 << endl;
        cout << "int\t\t\t|" << sizeof(int) << "\t|" << intok << "\t\t|" << intok1 << endl;
        cout << "long long\t\t|" << sizeof(long long) << "\t|" << ling << "\t|" << ling1 << endl;
        cout << "unsigned short\t\t|" << sizeof(unsigned short) << "\t|" << signa << "\t\t\t|" << signa1 << endl;
        cout << "unsigned int\t\t|" << sizeof(unsigned int) << "\t|" << signa2 << "\t\t\t|" << signa3 << endl;
        cout << "unsigned long long\t|" << sizeof(unsigned long long) << "\t|" << signa4 << "\t\t\t|" << signa5 << endl;
        cout << "float\t\t\t|" << sizeof(float) << "\t|" << flek << "\t\t|" << flek1 << endl;
        cout << "double\t\t\t|" << sizeof(double) << "\t|" << dabl << "\t\t|" << dabl1 << endl;
        cout << "bool\t\t\t|" << sizeof(bool) << "\t|" << byblik << "\t\t\t|" << byblik1 << endl;
        cout << "char\t\t\t|" << sizeof(char) << "\t|" << chyr << "\t\t\t|" << chyr1 << endl;
        




     
      
     
 
}

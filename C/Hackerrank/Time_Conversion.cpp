#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string time_spec=s.substr(8,s.length());
    string modded_time;
    transform(time_spec.begin(),time_spec.end(),time_spec.begin() ,::toupper);
     int hour;
    if(time_spec=="AM"){
        modded_time=s.substr(0,8);
        hour=stoi(s.substr(0, 2),nullptr,10);
        if(hour==12)
            modded_time="00"+modded_time.substr(2,6);
    }
    else{

        hour=stoi(s.substr(0, 2),nullptr,10);
        if(hour!=12)
            hour+=12;
        modded_time=to_string(hour)+s.substr(2, 6);
    }
    return modded_time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

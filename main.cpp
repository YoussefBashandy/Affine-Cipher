#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Welcome! \n";
    cout << "What do you want to do? \n";
    cout << "1-Cipher a message \n";
    cout << "2-Decipher a message \n";
    cout << "3-End \n";
    int answer;
    cin >> answer;

    if (answer == 1){
        cout << "Enter the parameters a & b: \n";
        cout << "a & b must be co-prime numbers \na=";
        int a;
        int b;
        cin >> a;
        cout << "b=";
        cin >> b;
        string Msg;
        cout << "Enter a message you want to cipher: ";
        cin >> Msg;
        string cipher = "";
        for (int i=0; i<Msg.length(); i++){
            char letter;
            letter = ((((a * (Msg[i]-65) + b) % 26) + 65));
            cipher = cipher + letter;
        }

        cout << "The cipher is " << cipher;
    }

    if (answer == 2) {
        cout << "Enter the parameters a & b & c: \na=";
        int a;
        int b;
        int c;
        cin >> a;
        cout << "b=";
        cin >> b;
        cout << "c=";
        cin >> c;
        while (((a*c)%26)!=1){
            cout << "Error" << endl;
            cout << "Enter the parameter c which satisfy the equation (a*c)%26=1 \n";
            cout << "c=";
            cin >> c;
        }
        string Cipher;
        cout << "Enter the cipher you want to decode: ";
        cin >> Cipher;
        string Message = "";
        for (int i=0; i<Cipher.length(); i++){
            char partical;
            int x;
            int y;
            x = (c * ((Cipher[i] - 65) - b));
            if (x < 0){
                y = ((26 + (x % 26)) % 26);
            }
            if (x >= 0){
                y = x % 26;
            }
            partical = y + 65;
            Message = Message + partical;
        }
        cout << "The message is " << Message;
    }

    if (answer == 3){
        cout << "Thank you, Good bye!";
    }
    return 0;
}

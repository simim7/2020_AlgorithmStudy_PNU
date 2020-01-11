#include <iostream>
#include <string>

using namespace std;

int main(void)
{
   string word;
   getline(cin,word);   
   
   const int length = word.length();
   bool is_pelindrome = true;
   
   for(int i=0;i<length;++i){
      if(word[i]!=word[length-1-i]){
         is_pelindrome = false;
      }
   }
   cout << is_pelindrome << endl;
   
   
   
   return 0;
}



#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

/* Look for all **'s and complete them */

// --------- Two DFAs ---------------------------------

// WORD DFA 
// RE:   ** \w*((a,e,i,o,u)|n)\b   WORD1 
//          \w*(I|E)\b             WORD2
bool word (string s)
{
  int state = 0;
  int charpos = 0;
  while (s[charpos] != '\0') 
    {
      char letter = s[charpos];
      if(state == 0 &&(s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||            
                       s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || 
                       s[charpos] == 'E'))
        state = 9;
      else 
        if(state == 0 && (s[charpos] == 'c'))
        state = 6;
      else
        if(state == 0 && s[charpos] == 's')
        state = 5;
      else
        if(state == 0 && s[charpos] == 't')
          state = 3;
      else
        if(state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||         
                          s[charpos] == 'y' || s[charpos] == 'j'))
          state = 8;
      else
        if(state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' ||         
                          s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' ||         
                          s[charpos] == 'p' || s[charpos] == 'r'))
          state = 2;
      else
        if(state == 2 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||         
                          s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' ||         
                          s[charpos] == 'E'))
          state = 9;
      else
        if(state == 2 && s[charpos] == 'y')
          state = 8;
      else
        if( state == 3 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||        
                          s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' ||                       
                          s[charpos] == 'E'))
          state = 9;
      else
        if(state == 3 && s[charpos] == 's')
          state = 8;
      else
        if( state == 4 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || 
                          s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' ||
                          s[charpos] == 'E'))
          state = 9;
      else
        if(state == 4 && s[charpos] == 'h')
          state = 8;
      else
        if(state == 5 && s[charpos] == 'h')
          state = 8;
      else
        if(state == 5 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || 
                          s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' ||
                          s[charpos] == 'E'))
          state = 9;
      else
        if(state == 6 && s[charpos] == 'h')
          state = 8;
      else
        if(state == 7 && s[charpos] == 'n')
          state = 0;
      else
        if(state == 8 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||
                          s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || 
                          s[charpos] == 'E'))
          state = 9;
      else
        if(state == 9 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || 
                          s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' ||
                          s[charpos] == 'E'))
          state = 9;
      else
        if(state == 9 && s[charpos] == 'n')
          state = 10;
      else
        if(state == 9 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' ||          
                          s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' ||                   
                          s[charpos] == 'r'))
          state = 2;
      else
        if(state == 9 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||                   
                          s[charpos] == 'y' || s[charpos] == 'j'))
          state = 8;
      else
        if(state == 9 && s[charpos] == 't')
          state = 3;
      else
        if(state == 9 && s[charpos] == 's')
          state = 4;
      else
        if(state == 9 && s[charpos] == 'c')
          state = 6;
      else
        if(state == 10 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' ||                
                           s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' ||                         
                          s[charpos] == 'E'))
          state = 9;
      else
        if(state == 10 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' ||                  
                          s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' ||                     
                          s[charpos] == 'p' || s[charpos] == 'r'))
          state = 2;
      else
        if(state == 10 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' ||
                          s[charpos] == 'y' || s[charpos] == 'j'))
          state = 8;
      else
        if(state == 10 && s[charpos] == 't')
          state = 3;
      else
        if(state == 10 && s[charpos] == 's')
          state = 5;
      else
        if(state == 10 && s[charpos] == 'c')
          state = 6;
      else
        if(state == 10 && s[charpos] == 'y')
          state = 8;
      else return false;

      charpos++;
    }
  
  if(state == 0 || state == 9 || state == 10)
  {
    return true;
  } else return false;
}

// PERIOD DFA 
bool period (string s)
{  // complete this **
  if(s[0] == '.') return true;
  else return false;
}

// ------ Three  Tables -------------------------------------

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {WORD1, WORD2, VERB, VERBNEG, 
                VERBPAST, VERBPASTNEG, IS, WAS, 
                OBJECT, SUBJECT, DESTINATION, 
                PRONOUN, CONNECTOR, PERIOD, ERROR, EOFM};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"WORD1", "WORD2", "VERB", "VERBNEG", 
                "VERBPAST", "VERBPASTNEG", "IS", "WAS", 
                "OBJECT", "SUBJECT", "DESTINATION", 
                "PRONOUN", "CONNECTOR", "PERIOD", "ERROR", "EOFM"}; 

//reservedwords table to be set up here. 
//corresponding keywords with tokentype
std::map<std::string, tokentype> reservedWords = {
    {"masu", VERB},
    {"masen", VERBNEG},
    {"mashita", VERBPAST},
    {"masendeshita", VERBPASTNEG},
    {"desu", IS},
    {"deshita", WAS},
    {"o", OBJECT},
    {"wa", SUBJECT},
    {"ni", DESTINATION},
    {"watashi", PRONOUN},
    {"anata", PRONOUN},
    {"kare", PRONOUN},
    {"kanojo", PRONOUN},
    {"sore", PRONOUN},
    {"mata", CONNECTOR},
    {"soshite", CONNECTOR},
    {"shikashi", CONNECTOR},
    {"dakara", CONNECTOR},
    {"eofm", EOFM}
};
map<string, tokentype> :: iterator iter;

// ** a.out should work without any additional files.

// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Simon Hausmaninger
int scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin
  fin >> w;
  // 1. If it is eofm, return right now.   
  if (w == "eofm") 
  {
    return -1; 
  }
  /*  **
  2. Call the token functions (word and period) 
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.
*/

  if(period(w))
  {
    tt = PERIOD;
  }
  else if(word(w))
  {
    /*
  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.
*/
    //check against reserved words
    iter = reservedWords.find(w);
    if(iter != reservedWords.end())
    {
      tt = iter -> second;
    } 
    //Check if WORD2
    else if(w[w.length()-1] == 'I' || w[w.length()-1] == 'E') 
    {
      tt = WORD2;
    }
    //Check if WORD1
    else if(w[w.length()-1] == 'n' || w[w.length()-1] == 'a' || w[w.length()-1] == 'i' ||        
            w[w.length()-1] == 'u' || w[w.length()-1] == 'e' || w[w.length()-1] == 'o')
    {
      tt = WORD1;
    }
  }
  //if not word or period, then error
  else
  {
    tt = ERROR;
    cout << "LEXICAL ERROR: " << w << " is not a valid token" << endl;
  }
    /*
  4. Return the token type & string  (pass by reference)
  */
    return 0;
}//the end of scanner



// The temporary test driver to just call the scanner repeatedly  
int main()
{
  //debug - change word inside () and boolean  to whatever outcome is unexpected
  if(word("sensei") != true)
  {
    cout << "bugged" << endl;
  }
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments  
       if (theword == "eofm") break;  // stop now
       cout << "\"" << theword << "\"" << " is token type " << tokenName[thetype] << endl << endl;
       //cout << "Type is:" << tokenName[thetype] << endl;
         
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end


// WordCount.cpp

#include "WordCount.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(const std::string & word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	// STUB.

  int count = 0;
  for(int i = 0; i<100;i++)
    {
      for(int j = 0; j<(int) table[i].size(); j++)
      {
        count = count + (int) table[i].at(j).second;
          
      }
    }
  return count;
  
}

int WordCount::getNumUniqueWords() const {
	// STUB
  int count = 0;

  for(int i = 0; i<100; i++)
    {
      count = count +(int) table[i].size();
    }
  

  return count;

  
}

int WordCount::getWordCount(const std::string & word) const {
	// STUB
	std::string s = makeValidWord(word);

  int h = (int) hash(s);

  int count = 0;
  bool inside = false;

  for(int i = 0; (i<(int) table[h].size()&&!inside); i++)
    {
      if(table[h].at(i).first==s)
      {
        count = table[h].at(i).second;
        inside = true;
      }
      
    }

  return count;
  
}
	
int WordCount::incrWordCount(const std::string & word) {
	// STUB
	std::string s = makeValidWord(word);

  int h = (int) hash(s);
  bool inside = false;

  for(int i = 0; (i<(int) table[h].size()&&!inside); i++)
    {
      if(table[h].at(i).first==s)
      {
        table[h].at(i).second = table[h].at(i).second + 1;
        
        return table[h].at(i).second;
      }
      
    }
  if(!inside)
  {
    std::pair <std::string, int> p(s, 1);
    table[h].push_back(p);

    return 1;
    
  }

  


  
	return -1;
}

int WordCount::decrWordCount(const std::string & word) {
	// STUB
	std::string s = makeValidWord(word);

  int h = (int) hash(s);
  bool inside = false;

  for(int i = 0; (i<(int) table[h].size()&&!inside); i++)
    {
      if(table[h].at(i).first==s)
      {
        table[h].at(i).second = table[h].at(i).second - 1;
        if(table[h].at(i).second==0)
        {
          table[h].erase(table[h].begin() + i);
          return 0;
        }
        
        return table[h].at(i).second;
      }
      
    }
  if(!inside)
  {

    return -1;
    
  }
}

bool WordCount::isWordChar(char c) {
	// STUB


	return isalpha(c);
}
std::string WordCount::makeValidWord(const std::string & word) {
	// STUB
  std::string s = "";

  std::string f = "-''";

  for(int i = 0; i<(int) word.size() ; i++)
    {
      char c = word.at(i);
      char hyphen = f.at(1);

      char apo = f.at(0);
      if((isWordChar(c))||(c==hyphen)||(c==apo))
      {
        s = s + (char) tolower(c);
      }
      
    }

  bool startsAlpha = false;

  int size = (int) s.size();
  if(size==0)
  {
    return "";
  }
  for(int i = 0; ((i< size) && (!startsAlpha)); i++)
  {
    if(isWordChar(s.at(i)))
    {
      startsAlpha = true;
    }
    else
    {
      s = s.substr(1);
      size = size - 1;
      i = i-1;
    }
  }
  bool endsAlpha = false;

  size = (int) s.size();

  if(size==0)
  {
    return "";
  }
  for(int i = size - 1; i>=0 && !endsAlpha; i--)
  {
    if(isWordChar(s.at(i)))
    {
      endsAlpha = true;
      return s;
    }
    else
    {
      if (s.size()==1)
      {
        return "";
      }
      s = s.substr(0 , i);
      size = size - 1;
    }
  }
  }

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	// STUB
  std::vector<std::string> words;
  for (int i = 0; i<100; i++)
  {
    for(int j = 0; j<(int) table[i].size(); i++)
    {
      
      words.push_back(table[i].at(j).first);
        
    }
      
  }
  std::sort(words.begin() , words.end());
  for(int i = (int) words.size() - 1; i>=0; i--)
  {
    int occurences = getWordCount(words.at(i));
    out<<words.at(i)<<","<<occurences<<endl;
      
  }
  return ;

  
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
  
  // bool compareInterval(std::pair<std::string,int> i1, std::pair<std::string,int>  i2)
  // {
  //   if(i1.second<i2.second)
  //   {
  //     return true;
  //   }
  //   else if (i1.first<i2.first)
  //   {
  //     return true;
  //   }
  //   return false;
  // }
	// STUB




  
  
  std::vector<std::pair<std::string,int>> words;
  for (int i = 0; i<100; i++)
  {
    for(int j = 0; j<(int) table[i].size(); i++)
    {
      words.push_back(table[i].at(j));
        
    }
  }

  
  std::sort(words.begin(), words.end(), [](std::pair<std::string,int> &a, std::pair<std::string,int> &b)
  {
    return ((a.second<b.second)||(a.second==b.second&&a.first<b.first)); });

  //sort(words.begin() , words.end() , compareInterval);
  

  

  for(int i = 0 ; i<(int) words.size() ; i++)
  {
    int c = words.at(i).second;
    std::string wordle = words.at(i).first;
    out<<wordle<<","<<c<<endl;
    
      
  }
  
  return;


}

void WordCount::addAllWords(const std::string& text) {
	// STUB


  std::string s = text;



  std::string word = "";

  std::vector<std::string> words;

  std::string empty = " /nt";
  char space = empty.at(0);
  char t = empty.at(3);

  char dash = empty.at(1);
  char n = empty.at(2);

  char two = *"";
  

  for(int i = 0; i<(int) s.size() ; i++)
    {
      char one = s.at(i);
      if(i!=s.size() - 1)
      {
        two = s.at(i+1);
      }
      if(one==space)
      {
        
        if(word.size()>0)
        {
          
          words.push_back(makeValidWord(word));
        }
        word = "";
      }
      else if ((i<(int) s.size()-1) && (one==dash) &&(two==n || two==t))
      {
        i = i + 1;
        if(word.size() > 0)
        {
          words.push_back(makeValidWord(word));
        }
        word = "";
      }
      else
      {
        word = word + one;

      }
      
      
  }

  if((int) word.size()>0)
  {
    words.push_back(word);
  }

  for(int i = 0 ; i<(int) words.size() ; i++)
   {
     incrWordCount(words.at(i));
     
      
      
   }





  return ;
}



int main()
{
  WordCount b;

  b.incrWordCount("be");
  b.incrWordCount("be");
  b.incrWordCount("ce");


  

  b.dumpWordsSortedByWord(std::cout);

  b.addAllWords("be My guest to the yarn");



  b.dumpWordsSortedByWord(std::cout);
  return 0;
}


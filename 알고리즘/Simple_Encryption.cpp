using namespace std;

string enc(string text)
{
  string even="";
  string odd="";
  for(int i=0;i<text.size();i++)
  {
    if(i%2==1)
      even+=text[i];
    else
      odd+=text[i];
    
  }
  return even+odd;
}



std::string encrypt(std::string text, int n)
{
  if(n==0 || text.empty())
    return text;
   string s = text;
  for(int i=1;i<=n;i++)
    s = enc(s);
  
  return s;
}

std::string decrypt(std::string encryptedText, int n)
{
  string k = encryptedText;
  if(n<=0 || k.empty())
    return k;
  
  int len = k.size();
  int split=0;
  if(len%2==0)
    split = len/2;
  else
    split=(len-1)/2;
  
  string first = k.substr(0, split);
  string second = k.substr(split);
  
  string res;
  for(int i=0;i<len;i++)
  {
    if(i%2==0)
      res+=second[i/2];
    else
      res+=first[(i-1)/2];
  }
    
  
  
  
    return decrypt(res, n-1);
}


/* BESTCODE

std::string encrypt(std::string text, int n)
{
    if (n <= 0) return text;

    const unsigned stringSize = text.size();
    
    for (unsigned i = 0; i < n; i++) 
    {
        std::string eText;
        
        for (unsigned j = 1; j < stringSize; j += 2)
            eText.push_back(text[j]); 
        for (unsigned j = 0; j < stringSize; j += 2)
            eText.push_back(text[j]);
            
        text = eText;
    }

    return text;
}

std::string decrypt(std::string text, int n)
{
    if (n <= 0) return text;

    const unsigned stringSize = text.size();
    const unsigned stringSizeHalf = stringSize / 2;
    
    for (unsigned i = 0; i < n; i++) 
    {
        std::string dText;
        
        for (unsigned j = 0; j < stringSizeHalf; j++) 
        {
            dText.push_back(text[j+stringSizeHalf]);
            dText.push_back(text[j]);
        }
        
        if (stringSize & 1)
            dText.push_back(text[stringSize - 1]);
            
        text = dText;
    }
 
    return text;
}













*/

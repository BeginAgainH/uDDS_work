// Don't modify this file as it will be overwritten.
//
#include "IDL_UserDataType.h"

UserDataType::UserDataType(const UserDataType &IDL_s){
  data = IDL_s.data;
  encode_data = IDL_s.encode_data;
}

UserDataType& UserDataType::operator= (const UserDataType &IDL_s){
  if (this == &IDL_s) return *this;
  data = IDL_s.data;
  encode_data = IDL_s.encode_data;
  return *this;
}

void UserDataType::Marshal(CDR *cdr) const {
  cdr->PutString(data);
  cdr->PutString(encode_data);
}

void UserDataType::UnMarshal(CDR *cdr){
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(data != NULL )
    {
        delete data;
        data = NULL;
    }
    data = IDL_str;
  }
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(encode_data != NULL )
    {
        delete encode_data;
        encode_data = NULL;
    }
    encode_data = IDL_str;
  }
}


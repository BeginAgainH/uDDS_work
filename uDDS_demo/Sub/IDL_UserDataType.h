// Don't modify this file as it will be overwritten.
//
#include "CDR/CDR.h"
#include "ReturnCode.h"
#include "BasicTypes.h"

#ifndef IDL_UserDataType_hh
#define IDL_UserDataType_hh

#ifndef UserDataType_defined
#define UserDataType_defined

struct UserDataType {
  UserDataType()
	{
		data = new char[255];
		data[0]= '\0';
		encode_data = new char[255];
		encode_data[0]= '\0';
	}

  UserDataType(const UserDataType  &IDL_s);

  ~UserDataType(){
		delete data;
		data = NULL;
		delete encode_data;
		encode_data = NULL;
	}

  	int StructSize()
	{
		int strSize = 0;
		strSize += sizeof(UserDataType);
		strSize += strlen(data);
		strSize += strlen(encode_data);
		return strSize;
	}
  UserDataType& operator= (const UserDataType &IDL_s);

  void Marshal(CDR *cdr) const;
  void UnMarshal(CDR *cdr);

  char* data;
char* encode_data;
  
};

typedef sequence<UserDataType> UserDataTypeSeq;

#endif




#endif /*IDL_UserDataType_hh */
